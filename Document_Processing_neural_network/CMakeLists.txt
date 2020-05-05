cmake_minimum_required (VERSION 3.8)
# project(neural_network LANGUAGES CUDA CXX)
project(neural_network LANGUAGES CXX)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DDEBUG)
endif()

# option
option(MNIST "mnist demo" ON)

# find cuda
#find_package(CUDA)
#include_directories(${CUDA_INCLUDE_DIRS})
#set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -gencode arch=compute_61,code=sm_61")
#set(CMAKE_CUDA_FLAGS_DEBUG "${CMAKE_CUDA_FLAGS_DEBUG} -g -G")
#set(CMAKE_CUDA_FLAGS_RELEASE "${CMAKE_CUDA_FLAGS_RELEASE} -O2")
 

 find_package(OpenMP)

if (OPENMP_FOUND)

 set (CMAKE_CUDA_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_CUDA_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_package(OpenMP)



if(OpenMP_CXX_FOUND)
 message("openmp found")
    
endif()

if (CMAKE_COMPILER_IS_GNUCXX)
     set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -std=c++14")
    # set(CMAKE_CUDA_FLAGS "QMAKE_CXXFLAGS += -std=c++14")
  
endif()


if (MSVC)
    # warning
    message("here in msvc")
    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} gflags /r +hpa -Xcompiler=\"/wd 4819\"")

    if (NOT CMAKE_BUILD_TYPE STREQUAL Debug)
        #set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -O2")
    endif()

endif()

# add cuda source
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/cuda/*.hpp)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/cuda/*.cpp)

source_group("Include" FILES ${HEADERS})
source_group("Source" FILES ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/cuda)

# add cuda library
 add_library(cu STATIC ${SOURCES})
# target_link_libraries(cu PUBLIC cuda)
#target_link_libraries(cu)



SET (BOOST_ROOT "C:/Program Files/boost_1_55_0/boost")
SET (BOOST_INCLUDEDIR "C:/Program Files/boost_1_55_0/boost")
SET (BOOST_LIBRARYDIR "C:/Program Files/boost_1_55_0/libs")

SET (BOOST_MIN_VERSION "1.55.0")
set (Boost_NO_BOOST_CMAKE ON)
FIND_PACKAGE(Boost ${BOOST_MIN_VERSION} REQUIRED)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Fatal error: Boost (version >= 1.55) required.")
else()
  message(STATUS "Setting up BOOST")
  message(STATUS " Includes - ${Boost_INCLUDE_DIRS}")
  message(STATUS " Library  - ${Boost_LIBRARY_DIRS}")
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif (NOT Boost_FOUND)

# mnist demo
if (MNIST) 
    set(MINIST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/mnist)
    file(GLOB MINIST_SRCS ${MINIST_DIR}/*.cpp)

    add_executable(mnist ${MINIST_SRCS})
    target_include_directories(mnist PRIVATE ${MINIST_DIR})
    target_link_libraries(mnist PUBLIC OpenMP::OpenMP_CXX cu ${Boost_LIBRARY_DIR})
endif()





















