cmake_minimum_required(VERSION 3.5)
project(CmTutSqrt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

# set a version number to be populated by CMake
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file that will be generated from CMake
# with the version number
configure_file(
        "${PROJECT_SOURCE_DIR}/Tutorial.Config.h.in"
        "${PROJECT_BINARY_DIR}/Tutorial.Config.h"
)

# since the generated .h file will be in the binary directory,
# add that to the include directories

include_directories("${PROJECT_BINARY_DIR}")

# Add the MathFunctions library?
option (USE_MYMATH
        "Use provided math implementation?" ON)

if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

add_executable(CmTutSqrt ${SOURCE_FILES})
target_link_libraries(CmTutSqrt ${EXTRA_LIBS})


enable_testing()
include(CTest)
add_test (TutorialComp25 CmTutSqrt 25)
set_tests_properties(TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
add_test (TutorialNegative CmTutSqrt -25)
set_tests_properties(TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is nan")
add_test (TutorialCompSmall CmTutSqrt 0.0001)
set_tests_properties(TutorialCompSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
