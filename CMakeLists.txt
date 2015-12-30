cmake_minimum_required(VERSION 3.4.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/dependencies/cmake")

project(emcpp VERSION 1.0.0.0 LANGUAGES CXX)

# project settings
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# include cotire
include(cotire)

# include catch
add_subdirectory(dependencies/catch)
include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)

# include lest
add_subdirectory(dependencies/lest)
include_directories(${LEST_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)

# define source files
set(SOURCES
    main.cc
    01_typededuction.cc
    35_tasks.cc
)

# define output
add_executable(emcpp ${SOURCES})
target_compile_features(emcpp PRIVATE cxx_constexpr cxx_decltype_auto)
cotire(emcpp)