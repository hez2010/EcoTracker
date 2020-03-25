cmake_minimum_required(VERSION 2.8)
project(EcoTracker)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR})

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-O2 -lm")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_DIRS})

file(GLOB eco_srcs
	${CMAKE_CURRENT_LIST_DIR}/*.hpp
	${CMAKE_CURRENT_LIST_DIR}/*.h
	${CMAKE_CURRENT_LIST_DIR}/eco.cc
	${CMAKE_CURRENT_LIST_DIR}/feature_extractor.cc
	${CMAKE_CURRENT_LIST_DIR}/feature_operator.cc
	${CMAKE_CURRENT_LIST_DIR}/ffttools.cc
	${CMAKE_CURRENT_LIST_DIR}/fhog.cc
	${CMAKE_CURRENT_LIST_DIR}/interpolator.cc
	${CMAKE_CURRENT_LIST_DIR}/metrics.cc
	${CMAKE_CURRENT_LIST_DIR}/optimize_scores.cc
	${CMAKE_CURRENT_LIST_DIR}/regularization_filter.cc
	${CMAKE_CURRENT_LIST_DIR}/sample_update.cc
	${CMAKE_CURRENT_LIST_DIR}/scale_filter.cc
	${CMAKE_CURRENT_LIST_DIR}/training.cc
	${CMAKE_CURRENT_LIST_DIR}/EcoTrackerExtern.cc)

if(SIMD GREATER 0)
	set(eco_srcs ${eco_srcs} ${CMAKE_CURRENT_LIST_DIR}/gradient.cpp)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_SIMD -msse4")
endif()

if(MULTI_THREAD GREATER 0)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_MULTI_THREAD -pthread")
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lpthread")
endif()

#compile eco library
add_library(ecotracker SHARED ${eco_srcs})
target_link_libraries(ecotracker ${OpenCV_LIBS})

install(TARGETS ecotracker
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
)
