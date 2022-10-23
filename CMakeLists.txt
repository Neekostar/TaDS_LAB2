cmake_minimum_required(VERSION 3.23)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp Menu/MyMenu.cpp Menu/MyMenuItem.cpp Menu/MyMenu.h Menu/MyMenuItem.h Models/BinaryTree.cpp Models/BinaryTree.h Models/Errors.cpp Models/Errors.h)
