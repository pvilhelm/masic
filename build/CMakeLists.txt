
SET(CMAKE_CXX_STANDARD 17)

PROJECT(masic)

PROJECT(masic_test)

ADD_EXECUTABLE(test)
TARGET_SOURCES(
	test
PUBLIC
	../src/tests/main.cc
	../src/tests/dummy.cc
	../src/tests/test_util_text.cc
	)

TARGET_INCLUDE_DIRECTORIES(
	test
PUBLIC
	../includes
	)
