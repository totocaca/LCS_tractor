cmake_minimum_required(VERSION 2.8.3)
FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
FIND_PACKAGE(Boost COMPONENTS python)

SET(EIGEN3_INCLUDE_DIR "/usr/local/include/eigen3")
SET(Boost_INCLUDE_DIRS "/usr/include/boost")
set(CMAKE_CXX_FLAGS "-O3 -march=native ${CMAKE_CXX_FLAGS}")
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR})
LINK_LIBRARIES(${Boost_LIBRARIES} -lpython2.7 -lboost_python)

PYTHON_ADD_MODULE(tricubic tricubic.cpp)


