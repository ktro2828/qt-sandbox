cmake_minimum_required(VERSION 3.14)
project(ros2_qt)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
find_package(OpenCV REQUIRED)
find_package(
  Qt5
  COMPONENTS Core Widgets
  REQUIRED)
ament_auto_find_build_dependencies()

set(QT_LIBRARIES Qt5::Core Qt5::Widgets)

include_directories(include SYSTEM ${OpenCV_INCLUDE_DIRS})

ament_auto_add_executable(img_viewer src/img_viewer.cpp)
set_target_properties(img_viewer PROPERTIES AUTOMOC TRUE)
target_link_libraries(img_viewer ${OpenCV_LIBS} ${QT_LIBRARIES})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()
