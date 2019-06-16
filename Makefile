CC		:= gcc
C_FLAGS := -Wall -Wextra -g	#-g作为调试时使用，若要发布请去掉-g

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
RM			:= del
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	-del $(BIN)\$(EXECUTABLE)
run: all
	.\$(BIN)\$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS)  -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)