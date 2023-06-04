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

# dir
add_executable(dir src/dir.cpp)
target_link_libraries(dir PRIVATE Qt5::Core)

# cursor
add_executable(cursor src/cursor.cpp)
target_link_libraries(cursor PRIVATE Qt5::Core Qt5::Widgets)

# button
add_executable(button src/button.cpp)
set_target_properties(button PROPERTIES AUTOMOC TRUE)
target_link_libraries(button PRIVATE Qt5::Core Qt5::Widgets)

# menu
add_executable(menu src/menu.cpp)
set_target_properties(menu PROPERTIES AUTOMOC TRUE)
target_link_libraries(menu PRIVATE Qt5::Core Qt5::Widgets)

# timer
add_executable(timer src/timer.cpp)
target_link_libraries(timer PRIVATE Qt5::Core Qt5::Widgets)
