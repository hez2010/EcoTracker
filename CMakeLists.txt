cmake_minimum_required(VERSION 3.1)

project(EcoTracker)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-O2")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_DIRS})

find_package(Threads REQUIRED)

set(ECO_SRCS 
	eco.cc						eco.hpp
	feature_extractor.cc		feature_extractor.hpp
	feature_operator.cc			feature_operator.hpp
	ffttools.cc					ffttools.hpp
	fhog.cc						fhog.hpp
	interpolator.cc				interpolator.hpp
	metrics.cc					metrics.hpp
	optimize_scores.cc			optimize_scores.hpp
	regularization_filter.cc	regularization_filter.hpp
	sample_update.cc			sample_update.hpp
	scale_filter.cc				scale_filter.hpp
	training.cc					training.hpp
	EcoTrackerExtern.cc			EcoTrackerExtern.hpp)

if(SIMD GREATER 0)
	set(ECO_SRCS ${ECO_SRCS} gradient.cpp)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_SIMD -msse4")
endif()

if(MULTI_THREAD GREATER 0)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_MULTI_THREAD")
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
endif()

#compile eco library
add_library(ecotracker SHARED ${ECO_SRCS})
target_link_libraries(ecotracker ${OpenCV_LIBS} Threads::Threads)

install(TARGETS ecotracker)
