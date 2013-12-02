#!/bin/bash

# Script produces all binaries for onvifsdk

# BuildScript name
bs="buildOSDK"

SCRIPT=`realpath $0`
# BuildScript working directory
SC_DIR=`dirname $SCRIPT`

source ${SC_DIR}/helperFunc.sh

# go to bin dir
mkdir $SC_DIR/bin
cd $SC_DIR/bin

# dir for OnvifSDK
if [ ! -f "${SC_DIR}/bin/OnvifSDK-b/libOnvifSDK.a" ]; then
	mkdir OnvifSDK-b
	cd OnvifSDK-b
	cmake ../../OnvifSDK || checkErr "OnvifSDK config failed"
	make || checkErr "OnvifSDK make failed"
	cd ..
fi
# dir for Client
mkdir client
cd client
cmake ../../examples/OnvifClient -DSDKLIB="$SC_DIR/bin/OnvifSDK-b/libOnvifSDK.a" || checkErr "OnvifClient config failed"
make || checkErr "OnvifClient make failed"
cd ..
# dir for Server
mkdir server
cd server
cmake ../../examples/OnvifServer -DSDKLIB="$SC_DIR/bin/OnvifSDK-b/libOnvifSDK.a" || checkErr "OnvifServer config failed"
make || checkErr "OnvifServer make failed"
cd ../..

succMessage "We are all good"
