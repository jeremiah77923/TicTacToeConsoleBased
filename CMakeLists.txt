cmake_minimum_required(VERSION 3.24)
project(TicTacToeConsoleBased)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToeConsoleBased main.cpp Board.cpp Board.h BoardOperations.cpp BoardOperations.h trees.h fltk-1.3.8/abi-version.ide)
