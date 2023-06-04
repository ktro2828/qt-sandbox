cmake_minimum_required(VERSION 3.14)
project(qt-sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
  Qt5
  COMPONENTS Core Widgets
  REQUIRED)

add_executable(qt_hello src/qt_hello.cpp)
target_link_libraries(qt_hello PRIVATE Qt5::Core Qt5::Widgets)

# add_executable(qt_watch src/qt_watch.cpp) target_link_libraries(qt_watch
# PRIVATE Qt5::Core Qt5::Widgets)
