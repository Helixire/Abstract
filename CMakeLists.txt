cmake_minimum_required (VERSION 3.1.0)
project(Abstract)

include_directories(src)

set(SRC_COMMON "RException.cpp")
set(SRC_LIST "RThread.cpp" "RMutex.cpp")

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
find_package(Threads REQUIRED)
target_link_libraries(Abstract Threads::Threads)


add_executable(tes test-suite.cpp)
target_link_libraries(tes Abstract)