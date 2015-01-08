# Naomi Zarrilli
# Makefile for Shapeways test
#

CXX = clang++
FLAGS = -std=c++11 -Wall -Wextra -Wconversion -g

shapewaystest: artistMap.h artistMap.cpp artistData.h artistData.cpp main.cpp
	${CXX} ${FLAGS} -o shapewaystest artistMap.cpp artistData.cpp main.cpp

clean:
	rm -f shapewaystest
