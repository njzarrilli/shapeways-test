#
# Makefile for Shapeways test
#

CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -g

shapewaystest: artistMap.h artistMap.cpp artist.h artist.cpp main.cpp
	${CXX} ${FLAGS} -o shapewaystest artistMap.cpp artist.cpp main.cpp

clean:
	rm -f shapewaystest
