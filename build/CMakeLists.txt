
SET(CMAKE_CXX_STANDARD 14)

PROJECT(masic)

PROJECT(masic_test)

ADD_EXECUTABLE(test)
TARGET_SOURCES(
	test
PUBLIC
	../src/tests/main.cc
	../src/tests/dummy.cc
	)

TARGET_INCLUDE_DIRECTORIES(
	test
PUBLIC
	../includes
	)
