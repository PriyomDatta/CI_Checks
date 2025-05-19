cmake_minimum_required(VERSION 3.10)

# Project name
project(Module_01)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(INTERFACE_FILES
    Interface/src/intf.cpp
)

set(SOURCE_FILES
    Mod/src/Mod_000.cpp
)

set(TEST_FILES 
    Test/Test_Mod_000.cpp
    Test/mock/Mock.cpp
)

# Add the library
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${INTERFACE_FILES})

# Make the library available for own modules
target_include_directories(${PROJECT_NAME} PRIVATE Mod/inc)

# Make the library available for other and own modules
target_include_directories(${PROJECT_NAME} PUBLIC Interface/inc)

# Add conditional compilation based on TEST flag
if(TEST)

    #Include Google Test
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
        )
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    #Add test executable
    add_executable(testexe ${SOURCE_FILES} ${TEST_FILES} )
    set_target_properties(testexe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
    target_link_libraries(testexe gtest gtest_main)

else()
    message(STATUS "TEST flag is not set.")
endif()
