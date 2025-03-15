#!/bin/bash

clang-tidy --checks="-*,cppcoreguidelines-*,clang-analyzer-*,concurency-*,-cppcoreguidelines-non-private-member-variables-in-classes,-cppcoreguidelines-explicit-virtual-functions" sources/ADUL/*.cpp include/ADUL/*