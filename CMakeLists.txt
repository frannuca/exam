project(exam)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SOURCES  ${CMAKE_SOURCE_DIR}/exam.cpp )
set(HEADERS  ${CMAKE_SOURCE_DIR}/Point.h ${CMAKE_SOURCE_DIR}/romans.h)

message(STATUS "/////////////////////////" ${SOURCES})
message(STATUS "/////////////////////////" ${HEADERS})

#Add compile target
add_executable(exam ${SOURCES} ${HEADERS})
		