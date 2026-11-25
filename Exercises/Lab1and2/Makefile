#Makefile for SUPA C++ Assignment 1
#PAULINA ULAHELOVA, 25/11/2026
#HOW to USE (from the Lab1and2 folder):
# -> make					= this builds the AnalyseData program
# -> ./AnalyseData			= this runs it
# -> make clean				= this deletes the compiled files so they can be rebuild from scratch


#VARIABLES (macros): written once here, used below as ${NAME} 
#changing the compiler or flag only needs editing in one place

#name of the compiler:
CC=g++ 

#compiler flag:				
FLAGS=-std=c++20 -Wall

#name of the final program:
TARGET=AnalyseData

#the compiled pieces that get joined into the program:
OBJECTS=AnalyseData.o CustomFunctions.o

#LINKING:
#Link the object files into the executable AnalyseData
${TARGET}: ${OBJECTS}
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}

#COMPILING:
#compile each .cxx into a .o (recompile if the .cxx or the header changes)
AnalyseData.o: AnalyseData.cxx CustomFunctions.h
	${CC} ${FLAGS} -c AnalyseData.cxx

CustomFunctions.o: CustomFunctions.cxx CustomFunctions.h
	${CC} ${FLAGS} -c CustomFunctions.cxx

#CLEANING UP:
#remove compiled files
#.PHONY tells make that "clean" is a command and not a file it should build
.PHONY: clean
clean:
	rm -f *.o ${TARGET}