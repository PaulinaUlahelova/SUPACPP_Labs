#Makefile for SUPA C++ Assignment 1
#PAULINA ULAHELOVA, 22/11/2026

#variables (macros) - compiler, flags and file names are written in one place
CC=g++ 					#name of the compiler
FLAGS=-std=c++20 -Wall  #compiler flags
TARGET=AnalyseData
OBJECTS=AnalyseData.o CustomFunctions.o

#Link the object files into the executable
${TARGET}: ${OBJECTS}
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}

#compile each .cxx into a .o (recompile if the .cxx or the header changes)
AnalyseData.o: AnalyseData.cxx CustomFunctions.h
	${CC} ${FLAGS} -c AnalyseData.cxx

CustomFunctions.o: CustomFunctions.cxx CustomFunctions.h
	${CC} ${FLAGS} -c CustomFunctions.cxx

#remove compiled files
clean:
	rm -f *.o ${TARGET}