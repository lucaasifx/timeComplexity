BIN = .\bin
OBJ = .\obj
SRC = .\src
INCLUDE = .\include
OUTPUT = .\output
INPUT = .\input

all: libed app

libed: \
	$(OBJ)/ordenation.o

app:
	gcc $(SRC)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

run:
	$(BIN)\app < $(INPUT)\dataB.txt > $(OUTPUT)\ordQuick.txt
	
result:
	$(BIN)\app < $(INPUT)\dataB.txt > $(OUTPUT)\heapS.txt

clear:
	del /q $(BIN)\*
	del /q $(OBJ)\*
