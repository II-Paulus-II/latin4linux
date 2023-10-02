#!/bin/bash

${MAKE="make"}

# Build dir
BUILD_DIR="build"

# src dir
SRC_DIR="$(pwd)/src"

# bin dir
BIN_DIR="$(pwd)/bin"

# Check if build dir exists, if not, make it
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir $BUILD_DIR
fi

# Check if bin dir exists, if not, make it
if [ ! -d "$BIN_DIR" ]; then
    echo "Creating bin directory..."
    mkdir $BIN_DIR
fi

# Change to BUILD_DIR
cd "$BUILD_DIR"

cmake "$SRC_DIR" -DCMAKE_INSTALL_PREFIX=$BIN_DIR
$MAKE clean
$MAKE install