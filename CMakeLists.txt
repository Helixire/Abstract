cmake_minimum_required (VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 11)
project(Abstract)

include_directories(src)

set(SRC_COMMON "RException.cpp" "RLocker.cpp")
set(SRC_LIST "RThread.cpp" "RMutex.cpp" "RSemaphore.cpp")

if (UNIX)
  message("Setting up Linux")
  set(SRC_PATH "src/lin/")
else()
  message("Setting up Window")
  set(SRC_PATH "src/win/")
endif()

set(SRCS "")
foreach(i ${SRC_LIST})
    LIST(APPEND SRCS "${SRC_PATH}${i}")
endforeach(i)
foreach(i ${SRC_COMMON})
    LIST(APPEND SRCS "src/${i}")
endforeach(i)
add_library(Abstract ${SRCS})
target_include_directories (Abstract PUBLIC src)
find_package(Threads REQUIRED)
target_link_libraries(Abstract Threads::Threads)


# Test suite

option(Test "Test" OFF)


if (Test)
	add_executable(Abstract-test test-suite.cpp)
	target_link_libraries(Abstract-test Abstract)
endif()
