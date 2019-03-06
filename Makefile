CC = gcc 
CXX = g++

BINS := unit_tests

SRCS := $(wildcard *.c)
SRCS += $(wildcard *.cpp)

CXXFLAGS = -Wall -g

LDFLAGS += -lm

obj := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: test_string_utils test_object_info

unit_tests: main.o test_string_utils.o
	${CXX} ${LDFLAGS} $< -o $@
		
test_object_info:  main.o ArgumentParser.o string_utils.o ObjectInfo.o test_object_info.o
	${CXX} ${LDFLAGS} $^ -o $@
		
test_string_utils: main.o string_utils.o test_string_utils.o
	${CXX} ${LDFLAGS} $^ -o $@
		
%.o: %.cpp
	@echo "Creating object.."
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -rvf *.o *.exe
	
test : test_string_utils test_object_info
	./test_object_info.exe