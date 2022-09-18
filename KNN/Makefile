CC=g++
SRC := $(PWD)/src
CFLAGS := -std=c++11 
INCLUDE_DIR := $(PWD)/include

#all : data_handler.o data.o main.o 

main: data_handler.o data.o knn.o
	$(CC) $(CFLAGS) -o main data.o data_handler.o knn.o 
knn.o: $(SRC)/knn.cc
	$(CC) $(CFLAGS) -c $(SRC)/knn.cc -o knn.o data_handler.o data.o -I$(PWD)/include -I$(PWD)/../include

data_handler.o:$(SRC)/../../src/data_handler.cc
	$(CC) -c $(CFLAGC) $(SRC)/../../src/data_handler.cc -o data_handler.o -I$(PWD)/../include
data.o:$(SRC)/../../src/data.cc
	$(CC) -c $(CFLAGC) $(SRC)/../../src/data.cc -o data.o -I$(PWD)/../include
clean:
	rm data.o
	rm data_handler.o
	rm main