#
# Copyright (C) 2016 Pixameter Corporation. All rights reserved.
#
# The information and source code contained herein is the exclusive
# property of Pixameter Corporation. and may not be disclosed, examined
# or reproduced in whole or in part without explicit written
# authorization from the company.
#
# ----------------------------------------------------------------------------
#

cmake_minimum_required(VERSION 2.6)

PROJECT(Pixameter)

ENABLE_TESTING()

if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11") # requires gcc >= 4.7
endif(UNIX)

### OpenCV ###
FIND_PACKAGE(OpenCV 3 REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})


# Eigen # This project is tested with Eigen 3.3.1
# FIND_PACKAGE(Eigen3 REQUIRED)  # We don't need this because it is header only, all we need is the path

set(EIGEN3_INCLUDE_DIR "" CACHE STRING "Path to Eigen")
message(STATUS "Eigen path: ${EIGEN3_INCLUDE_DIR}")
include_directories(${EIGEN3_INCLUDE_DIR})

# Custom project
add_subdirectory(src)

# Add non-compiled files to the project
add_custom_target(
README.md
)
