###
project(OnvifSDK)
cmake_minimum_required(VERSION 2.8)


if("${SIGRLOG_OUTPUT}" STREQUAL "")
    message( FATAL_ERROR "Provide SIGRLOG_OUTPUT" )
endif()
# SIGRLOG_CURRLEVEL:
# level of verboseness of the logger range [0..4]
add_definitions(-DSIGRLOG_CURRLEVEL=4)
# SIGRLOG_OUTPUT:
# destinations of the logger output
# 0 - none, 1 - console only, 2 - file only, 3 - console and file
add_definitions(-DSIGRLOG_OUTPUT=${SIGRLOG_OUTPUT})
# SIGRLOG_FILENAME
# output filename for logger
add_definitions(-DSIGRLOG_FILENAME=\"oxxServerLog.ini\")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(GSOAP 2.8.15 REQUIRED)
message(STATUS "The GSOAP version: ${GSOAP_VERSION}")
message(STATUS "The GSOAP include directory: ${GSOAP_INCLUDE_DIR}")
message(STATUS "The GSOAP libraries: ${GSOAP_LIBRARIES}")
message(STATUS "The GSOAP import directory: ${GSOAP_IMPORT_DIR}")
message(STATUS "The GSOAP plugin directory: ${GSOAP_PLUGIN_DIR}") 

add_definitions(-DWITH_PURE_VIRTUAL)
add_definitions(-DWITH_NONAMESPACES)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

### generate stubs
set(OSDK_GEN_SOURCE_DIR ${PROJECT_BINARY_DIR}/src)
add_subdirectory(xml)

if(NOT IS_DIRECTORY ${OSDK_GEN_SOURCE_DIR})
    file(MAKE_DIRECTORY ${OSDK_GEN_SOURCE_DIR})

    execute_process(
        COMMAND ${GSOAP_WSDL2H} -jgxP -oweb.h  -t${PROJECT_SOURCE_DIR}/typemapWeb.dat
        ${XML_WSDL_DIR}/devicemgmt.wsdl ${XML_WSDL_DIR}/deviceio.wsdl
        ${XML_WSDL_DIR}/display.wsdl ${XML_WSDL_DIR}/recording.wsdl
        ${XML_WSDL_DIR}/replay.wsdl ${XML_WSDL_DIR}/search.wsdl
        ${XML_WSDL_DIR}/receiver.wsdl ${XML_WSDL_DIR}/event.wsdl
        ${XML_WSDL_DIR}/remotediscovery.wsdl ${XML_WSDL_DIR}/analytics.wsdl
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )

    ### Symlinks to gsoap imports
    execute_process(
        COMMAND ln -s ${GSOAP_IMPORT_DIR}/stlvector.h stlvector.h
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
    execute_process(
        COMMAND ln -s ${GSOAP_IMPORT_DIR}/soap12.h soap12.h
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
    
    file(APPEND ${PROJECT_BINARY_DIR}/web.h
        "struct SOAP_ENV__Header {\n"
        "char*            wsa__MessageID 0;"
        "_wsa__RelatesTo *wsa__RelatesTo 0;"
        "_wsa__From      *wsa__From      0;"
        "_wsa__ReplyTo   *wsa__ReplyTo   0;"
        "_wsa__FaultTo   *wsa__FaultTo   0;"
        "char*            wsa__To        0;"
        "char*            wsa__Action    0;"
        "wsd__AppSequenceType *wsd__AppSequence 0;"
        "};"
    )

    execute_process(
        COMMAND ${GSOAP_SOAPCPP2} -2abjnxLw web.h -dsrc -pWeb -I${GSOAP_IMPORT_DIR} -I${GSOAP_IMPORT_DIR}/..
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
    # Fix here (adding ONVIF-Topics namespace to the namespace table)
    execute_process(
        COMMAND sed -i "/{\"tse\", \"http:\\/\\/www.onvif.org\\/ver10\\/search\\/wsdl\", NULL, NULL},/a    {\"tns1\", \"http://www.onvif.org/ver10/events\", NULL, NULL},"
        ${PROJECT_BINARY_DIR}/src/Web.nsmap
    )

    # rough fix for Wsdd naming in XML.
    foreach(NAME "WebRemoteDiscoveryBindingProxy" "WebRemoteDiscoveryBindingService" "WebC")
        execute_process(
            COMMAND sed -i s/dn:/wsd:/g ${PROJECT_BINARY_DIR}/src/${NAME}.cpp
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        )
    endforeach()
    # another hack to force WsddRemoteDiscoveryBindingProxy parse wsd:ProbeMatches field in the ProbeResponse properly
    execute_process(
        COMMAND sed -i "s@dn__ProbeResponse->soap_get(soap,[[:space:]]\"wsd:ProbeResponse\",[[:space:]]\"wsd:ProbeMatchesType\");@dn__ProbeResponse->soap_get(soap, \"wsd:ProbeMatches\", \"wsd:ProbeMatchesType\");@"
        ${PROJECT_BINARY_DIR}/src/WebRemoteDiscoveryBindingProxy.cpp
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
    # hack to support visibility of header fields    
    execute_process(
        COMMAND sed -i "/struct SOAP_ENV__Header/i \ class wsa__EndpointReferenceType; \ class wsa__Relationship;"
        ${PROJECT_BINARY_DIR}/src/WebStub.h
    )

    aux_source_directory(${OSDK_GEN_SOURCE_DIR} OSDK_GEN_FILES)
endif()

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    message( STATUS "Adding GSOAP Debug flags" )
    set( CMAKE_C_FLAGS "${CFLAGS} -DDEBUG" )
    set( CMAKE_CXX_FLAGS "${CXXFLAGS} -DDEBUG" )
endif()

# list project files
include_directories(${PROJECT_SOURCE_DIR}/../common
                    ${PROJECT_SOURCE_DIR}/gen/include
                    ${PROJECT_SOURCE_DIR}/include                    
                    ${PROJECT_SOURCE_DIR}/Eventing
                    ${PROJECT_SOURCE_DIR}/WsDiscovery
                    ${OSDK_GEN_SOURCE_DIR}
                    ${PROJECT_BINARY_DIR})
                

set(HEADERS
    ${PROJECT_SOURCE_DIR}/../common/sigrlog.h
    ${PROJECT_SOURCE_DIR}/../common/helpers.h
    ${PROJECT_SOURCE_DIR}/gen/include/stdsoap2.h
    ${PROJECT_SOURCE_DIR}/include/stringGenerator.h
    ${PROJECT_SOURCE_DIR}/include/BaseServer.h
    ${PROJECT_SOURCE_DIR}/include/BaseClient.h
    ${PROJECT_SOURCE_DIR}/include/OnvifSDK.h)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/gen/source/stdsoap2.cpp
    ${PROJECT_SOURCE_DIR}/source/BaseServer.cpp
    ${PROJECT_SOURCE_DIR}/source/BaseClient.cpp
    ${PROJECT_SOURCE_DIR}/../common/helpers.cpp)

file(GLOB WSD_FILES ${PROJECT_SOURCE_DIR}/WsDiscovery/*)
file(GLOB EVNT_FILES ${PROJECT_SOURCE_DIR}/Eventing/*)

file(GLOB OSDK_HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB OSDK_SOURCES ${PROJECT_SOURCE_DIR}/source/*.cpp)

add_library(OnvifSDK STATIC     ${SOURCES} ${HEADERS}
                                ${OSDK_GEN_FILES}
                                ${EVNT_FILES}
                                ${WSD_FILES}
                                ${OSDK_HEADERS}
                                ${OSDK_SOURCES})

target_link_libraries(OnvifSDK pthread)

