cmake_minimum_required(VERSION 3.14)

project(ScannerCode-barre LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core SerialPort)

add_executable(ScannerCode-barre main.cpp myport.h myport.cpp)
target_link_libraries(ScannerCode-barre Qt${QT_VERSION_MAJOR}::Core Qt5::SerialPort)
