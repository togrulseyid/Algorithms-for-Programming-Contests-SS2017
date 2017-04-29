cmake_minimum_required(VERSION 3.7)
project(Algorithms_for_Programming_Contests_SS2017)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)
set(SOURCE_FILES_A src/week1/QuestionA.cpp src/main.cpp)
set(SOURCE_FILES_B src/week1/QuestionB.cpp)
set(SOURCE_FILES_C src/week1/QuestionC.cpp)
set(SOURCE_FILES_D src/week1/QuestionD.cpp)
set(SOURCE_FILES_E src/week1/QuestionE.cpp)

add_executable(Question ${SOURCE_FILES})
add_executable(QuestionA ${SOURCE_FILES_A})
add_executable(QuestionB ${SOURCE_FILES_B})
add_executable(QuestionC ${SOURCE_FILES_C})
add_executable(QuestionD ${SOURCE_FILES_D})
add_executable(QuestionE ${SOURCE_FILES_E})