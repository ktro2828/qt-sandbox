cmake_minimum_required(VERSION 3.14)
project(qt-sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
  Qt5
  COMPONENTS Core Widgets
  REQUIRED)

# hello
add_executable(hello src/hello.cpp)
target_link_libraries(hello PRIVATE Qt5::Core Qt5::Widgets)

# date
add_executable(date src/date.cpp)
target_link_libraries(date PRIVATE Qt5::Core)

# container
add_executable(container src/container.cpp)
target_link_libraries(container PRIVATE Qt5::Core)

# file
add_executable(file src/file.cpp)
target_link_libraries(file PRIVATE Qt5::Core)

# fir
add_executable(dir src/dir.cpp)
target_link_libraries(dir PRIVATE Qt5::Core)

# add_executable(qt_watch src/qt_watch.cpp) target_link_libraries(qt_watch
# PRIVATE Qt5::Core Qt5::Widgets)
