cmake_minimum_required(VERSION 3.15)
project(
    ADUL
    VERSION 0.1.6
    LANGUAGES CXX
    DESCRIPTION "Alivka's Different Utilities Library"
)

# ----------------------------
# Build Configuration Options
# ----------------------------
option(ADUL_BUILD_SHARED_LIBS "Build shared libraries" ON)
option(ADUL_BUILD_STATIC_LIBS "Build static libraries" ON)

# ----------------------------
# Compiler Settings
# ----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------
# Output Directories
# ----------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add PIC for all targets
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -fPIC)
endif()

# ----------------------------
# Object Library 
# ----------------------------

file(GLOB ADUL_sources "sources/*/*.cpp")
add_library(ADUL_objects OBJECT ${ADUL_sources}
)

# Force PIC for object library
set_target_properties(ADUL_objects PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

target_include_directories(ADUL_objects 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)


# ----------------------------
# Shared Library 
# ----------------------------
if(ADUL_BUILD_SHARED_LIBS)
    add_library(ADUL_shared SHARED $<TARGET_OBJECTS:ADUL_objects>)
    
    set_target_properties(ADUL_shared PROPERTIES
        OUTPUT_NAME ADUL
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
    )

    target_compile_definitions(ADUL_shared 
        PRIVATE ADUL_BUILD_SHARED
        PUBLIC ADUL_USE_SHARED
    )
endif()

# ----------------------------
# Static Library
# ----------------------------
if(ADUL_BUILD_STATIC_LIBS)
    add_library(ADUL_static STATIC $<TARGET_OBJECTS:ADUL_objects>)
    set_target_properties(ADUL_static PROPERTIES
        OUTPUT_NAME ADUL
    )
    target_compile_definitions(ADUL_static PRIVATE ADUL_STATIC_DEFINE)
endif()

# ----------------------------
# Installation
# ----------------------------
include(GNUInstallDirs)  # Add this line

# Install headers
install(DIRECTORY include/ 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "ADUL.hpp"
)

# Install shared library
if(ADUL_BUILD_SHARED_LIBS)
    install(TARGETS ADUL_shared
        EXPORT ADULTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endif()

# Install static library
if(ADUL_BUILD_STATIC_LIBS)
    install(TARGETS ADUL_static
        EXPORT ADULTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()

# Install target exports
install(EXPORT ADULTargets
    FILE ADULConfig.cmake
    NAMESPACE ADUL::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ADUL
)

# Generate package config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ADULConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ADULConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ADUL
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ADULConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ADULConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ADUL
)
