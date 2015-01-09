# Naomi Zarrilli
# Makefile for Shapeways test
#

CXX = clang++
FLAGS = -std=c++11 -Wall -Wextra -Wconversion -g

shapewaystest: artistData.h artistData.cpp artistMap.h artistMap.cpp main.cpp
	${CXX} ${FLAGS} -o shapewaystest artistData.cpp artistMap.cpp main.cpp

clean:
	rm -f shapewaystest
