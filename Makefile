# -*- mode: Makefile; -*-
# -----------------------------------------
# project direfal-010

CC = g++
BIN = refal51
OP = ./src#  #Object path
SP = ./src#  #Source path
OBJ = $(OP)/SAXLoaderHeap.o $(OP)/direfal.o $(OP)/SAXLoader_expat.o $(OP)/data.o $(OP)/function.o $(OP)/main.o $(OP)/program.o $(OP)/session.o $(OP)/symbols.o $(OP)/system.o $(OP)/variables.o 
SRC = $(SP)/SAXLoaderHeap.cpp $(OP)/direfal.cpp $(SP)/SAXLoader_expat.cpp $(SP)/data.cpp $(SP)/function.cpp $(SP)/main.cpp $(SP)/program.cpp $(SP)/session.cpp $(SP)/symbols.cpp $(SP)/system.cpp $(SP)/variables.cpp 
LNK = -lexpat # --allow-multiply-definitions
#INCLUDE += -I./include
AC = -g -Wall# --pedantic


$(BIN): $(OBJ)
	$(CC) $(AC) $(INCLUDE) $(OBJ)  -o $(BIN) $(LNK)
all: $(BIN)

$(OP)/variables.o: $(SP)/variables.cpp
	$(CC) $(AC) -c $(SP)/variables.cpp -o $(OP)/variables.o
	
$(OP)/system.o: $(SP)/system.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/system.cpp -o $(OP)/system.o
	
$(OP)/symbols.o: $(SP)/symbols.cpp
	$(CC) $(AC) -c $(SP)/symbols.cpp -o $(OP)/symbols.o
	
$(OP)/session.o: $(SP)/session.cpp
	$(CC) $(AC) -c $(SP)/session.cpp -o $(OP)/session.o
	
$(OP)/program.o: $(SP)/program.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/program.cpp -o $(OP)/program.o
	
$(OP)/main.o: $(SP)/main.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/main.cpp -o $(OP)/main.o
	
$(OP)/function.o: $(SP)/function.cpp
	$(CC) $(AC) -c $(SP)/function.cpp -o $(OP)/function.o
	
$(OP)/direfal.o: $(SP)/direfal.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/direfal.cpp -o $(OP)/direfal.o
$(OP)/data.o: $(SP)/data.cpp
	$(CC) $(AC) -c $(SP)/data.cpp -o $(OP)/data.o

$(OP)/SAXLoader_expat.o: $(SP)/SAXLoader_expat.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/SAXLoader_expat.cpp -o $(OP)/SAXLoader_expat.o

$(OP)/SAXLoaderHeap.o: $(SP)/SAXLoaderHeap.cpp
	$(CC) $(AC) $(INCLUDE) -c $(SP)/SAXLoaderHeap.cpp -o $(OP)/SAXLoaderHeap.o

clean:
	rm -f $(BIN)
	rm -f $(OBJ)



