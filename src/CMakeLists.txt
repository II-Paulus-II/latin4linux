cmake_minimum_required(VERSION 3.10)

project(latin)

add_executable(latin 
    main.cpp 
    verbs.cpp
    )

target_include_directories(latin PRIVATE ${CMAKE_SOURCE_DIR})

install(TARGETS latin DESTINATION ${CMAKE_INSTALL_PREFIX})