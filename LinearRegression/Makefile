CC=g++
SRC := $(PWD)/src
CFLAGS := -std=c++11 
INCLUDE_DIR := $(PWD)/include

#all : data_handler.o data.o main.o 

main: gradient.o dataSet.o 
	$(CC) $(CFLAGS) -o main gradient.o dataSet.o 
gradient.o : $(SRC)/gradientDescent.cc
	$(CC) $(CFLAGS) -c $(SRC)/gradientDescent.cc -o gradient.o  -I$(PWD)/include 
dataSet.o : $(SRC)/dataSet.cc
	$(CC) $(CFLAGS) -c $(SRC)/dataSet.cc -o dataSet.o  -I$(PWD)/include 


clean:
	rm dataSet.o
	rm gradent.o
	main