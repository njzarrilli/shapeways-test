#
# Makefile for Shapeways test
#

CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -g

shapewaystest: artistsList.h artistsList.cpp main.cpp
	${CXX} ${FLAGS} -o shapewaystest artistsList.cpp main.cpp

clean:
	rm -f shapewaystest
