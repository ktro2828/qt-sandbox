cmake_minimum_required(VERSION 3.14)
project(watch-app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(WATCH_TYPE
    "cv"
    CACHE STRING "mode of watch, cv or qt")

message("Watch type: " ${WATCH_TYPE})
if(${WATCH_TYPE} MATCHES "cv")
  find_package(OpenCV REQUIRED)
  if(OpenCV_FOUND)
    message("OpenCV version: " ${OpenCV_VERSION})
  else()
    message(FATAL_ERROR "Can not find OpenCV")
  endif()
elseif(${WATCH_TYPE} MATCHES "qt")
  find_package(
    Qt5
    COMPONENTS Core Widgets
    REQUIRED)
else()
  message(FATAL_ERROR "Unexpected WATCH_TYPE: `" ${WATCH_TYPE}
                      "`, use (cv, qt)")
endif()

add_subdirectory(src)
