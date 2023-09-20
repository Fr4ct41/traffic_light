#!/usr/bin/env bash

clear

#set -x
set -e -o pipefail


main() {

    local SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]:-$0}"; )" &> /dev/null && pwd 2> /dev/null; )";
    local WC_ROOT="$SCRIPT_DIR/.."

    local outDir="$WC_ROOT/outDir"
    local cmakeBuildDir="$outDir/cmakeBuildDir"

    mkdir -p "$outDir"
    #rm -rf "$outDir"

    local thirdParty="$WC_ROOT/3rdParty"
    local llvmRoot="C:/Program Files/LLVM"
    local CMAKEBINPATH="D:/C++/Cmake/bin"

    echo "CONFIGURING"
        
    local params=()

    params+=("$CMAKEBINPATH/cmake.exe")
    params+=(-DCMAKE_C_COMPILER="$llvmRoot/bin/clang")
    params+=(-DCMAKE_CXX_COMPILER="$llvmRoot/bin/clang++")
    params+=(-S "$WC_ROOT")
    params+=(-B "$cmakeBuildDir")

    
    #params+=(--debug-trycompile)
    params+=(-DCMAKE_EXPORT_COMPILE_COMMANDS=1)
    "${params[@]}"

    

    echo "BUILDING"
    local params=()
    params+=("$CMAKEBINPATH/cmake.exe")
    params+=(--build "$cmakeBuildDir")
    params+=(--verbose)
    "${params[@]}"

    
    "$cmakeBuildDir/T_int"

    echo "SUCCESS"
    
}

main


