CC=g++
SRC := $(PWD)/src
CFLAGS := -std=c++11 
INCLUDE_DIR := $(PWD)/include

#all : data_handler.o data.o main.o 

main: dataSet.o 
	$(CC) $(CFLAGS) -o main dataSet.o
dataSet.o : $(SRC)/dataSet.cc
	$(CC) $(CFLAGS) -c $(SRC)/dataSet.cc -o dataSet.o  -I$(PWD)/include 


clean:
	rm dataSet.o
	main