cmake_minimum_required(VERSION 3.10)

set(LIBRARY_NAME 
    store
)

set(PROJECT_NAME
    store
)

set(SOURCE_DIR
    src
)

set(SOURCE
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Product.cpp
    ${SOURCE_DIR}/Property.cpp
    ${SOURCE_DIR}/Store.cpp
)

# set the project name
project(${PROJECT_NAME})

include_directories(./include ./${SOURCE_DIR})

# add the executable
add_executable(${PROJECT_NAME} ${SOURCE})



