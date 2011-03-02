# -*- mode: Makefile; -*-
# -----------------------------------------
# project direfal-010

CC = g++
BIN = refal2.exe
OP = ./src#  #Object path
SP = ./src#  #Source path
OBJ = $(OP)/main.o $(OP)/system.o $(OP)/DataChain.o $(OP)/DataContainer.o $(OP)/res.o
SRC = $(SP)/main.cpp $(SP)/system.cpp $(SP)/DataChain.cpp $(SP)/DataContainer.cpp $(SP)/res.cc
LNK = -lexpat # --allow-multiply-definitions
INCLUDE += -I./include
AC = -g -O3 -Wall -pg

$(BIN): $(OBJ)
	$(CC) $(AC) $(INCLUDE) $(OBJ)  -o $(BIN) $(LNK)
all: $(BIN)

$(OP)/res.o: ./fn.ref ./fn2.ref
	./refal51 fn2.ref
	$(CC) $(AC) $(INCLUDE) -c $(SP)/res.cc -o $(OP)/res.o
	
$(OP)/DataChain.o: $(SP)/DataChain.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/DataChain.cpp -o $(OP)/DataChain.o
	
$(OP)/DataContainer.o: $(SP)/DataContainer.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/DataContainer.cpp -o $(OP)/DataContainer.o
	
$(OP)/system.o: $(SP)/system.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/system.cpp -o $(OP)/system.o
	
$(OP)/main.o: $(SP)/main.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/main.cpp -o $(OP)/main.o
	

clean:
	rm -f $(BIN)
	rm -f $(OBJ)



