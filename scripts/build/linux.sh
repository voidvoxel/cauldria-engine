#!/usr/bin/env bash

# Target options
TARGET_ARCH=$1
TARGET_OS=linux
TARGET_PLATFORM=$TARGET_OS-$TARGET_ARCH

# Clean the build environment.
scripts/clean.sh

# C compiler
CC=gcc

# C compiler flags
CC_FLAGS_INCLUDE="-Iinclude/ -Idependencies/lua/ -Idependencies/raylib/include/"
CC_FLAGS_LIBS="-lm"
CC_FLAGS="$CC_FLAGS_INCLUDE $CC_FLAGS_LIBS"
CC_FLAGS_LUA_PREFIX="-O2 -std=c99"
CC_FLAGS_LUA_LIBS="-lm"
CC_FLAGS_LIBLUA="$CC_FLAGS_LUA_LIBS -DMAKE_LIB"
CC_FLAGS_LUA="$CC_FLAGS_LUA_LIBS -DMAKE_LUA"

# Linker
LD=ld
LD_FLAGS_F=""
LD_FLAGS="$LD_FLAGS_F -Llib/ -l:libraylib.a"

# Lua source files
LIBLUA_SOURCE_FILES=dependencies/lua/onelua.c
LUA_SOURCE_FILES=$LIBLUA_SOURCE_FILES

build_liblua () {
    $CC $CC_FLAGS_LUA_PREFIX -c $LIBLUA_SOURCE_FILES -o build/liblua.o $CC_FLAGS_LIBLUA
    ar rcs lib/liblua.a build/liblua.o
}

build_lua () {
    $CC $CC_FLAGS_LUA_PREFIX $LUA_SOURCE_FILES -o bin/lua $CC_FLAGS_LUA
}

# Compile a source file into an object file.
build_executable () {
    submodule=$1
    source_files=src/$submodule/$*.c
    executable_file=bin/$submodule

    # Compile the source file into an object file.
    $CC $source_files build/liblua.o -o $executable_file $CC_FLAGS
}

build_all_lib () {
    build_liblua
    return 0
}

build_all_bin () {
    build_lua
    build_executable cauldria_engine
}

build_all () {
    build_all_lib
    build_all_bin
}

initialize_build_environment () {
    mkdir -p bin
    mkdir -p build
    mkdir -p lib
}

initialize_libraylib () {
    cp dependencies/raylib/lib/$TARGET_PLATFORM/libraylib.a lib/
}

initialize () {
    initialize_build_environment
    initialize_libraylib
}

# Build
build () {
    initialize
    build_all
}

build
