SHELL := /bin/bash

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
build_dir := $(abspath $(lastword $(MAKEFILE_LIST))/../build)

update-submodules:
	git submodule update --init --recursive

build-release:
	mkdir -p ./build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=Release && \
	make

build-relwithdebinfo:
	mkdir -p ./build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && \
	make

build-debug:
	mkdir -p ./build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=Debug && \
	make

run-example:
	cd ${build_dir} && ./massSpringDamperSystem

