cmake_minimum_required(VERSION 3.17)

project(cpp_white_belt_gTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(cpp_white_belt_gTest "tests.cpp")

#[[ADD_SUBDIRECTORY(ext/gtestbuilded/gtest)]]

target_include_directories( "${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/gtestbuilded/gtest/inc" )
target_link_libraries( "${PROJECT_NAME}" debug ${CMAKE_CURRENT_SOURCE_DIR}/gtestbuilded/gtest/lib/x64/windows/Debug/gtestd.lib)
target_link_libraries( "${PROJECT_NAME}" optimized ${CMAKE_CURRENT_SOURCE_DIR}/gtestbuilded/gtest/lib/x64/windows/Release/gtest.lib)
target_link_libraries( "${PROJECT_NAME}" debug ${CMAKE_CURRENT_SOURCE_DIR}/gtestbuilded/gtest/lib/x64/windows/Debug/gmockd.lib)
target_link_libraries( "${PROJECT_NAME}" optimized ${CMAKE_CURRENT_SOURCE_DIR}/gtestbuilded/gtest/lib/x64/windows/Release/gmock.lib)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
set_property(TARGET "${PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")