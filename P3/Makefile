SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/voraz_maximo $(BIN)/PD_maximo $(BIN)/PD_operaciones

# ************ Generación de documentación ******************
tar:
	cd .. &&	tar -czvf P3.tgz P3 && mv P3.tgz P3/P3.tgz

# ************ Compilación de módulos ************
$(BIN)/voraz_maximo: $(OBJ)/voraz_maximo.o
	$(CXX) -o $(BIN)/voraz_maximo  $(OBJ)/voraz_maximo.o

$(OBJ)/voraz_maximo.o: $(SRC)/voraz_maximo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/voraz_maximo.cpp -o $(OBJ)/voraz_maximo.o

$(BIN)/PD_maximo: $(OBJ)/PD_maximo.o
	$(CXX) -o $(BIN)/PD_maximo  $(OBJ)/PD_maximo.o

$(OBJ)/PD_maximo.o: $(SRC)/PD_maximo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/PD_maximo.cpp -o $(OBJ)/PD_maximo.o

$(BIN)/PD_operaciones: $(OBJ)/PD_operaciones.o
	$(CXX) -o $(BIN)/PD_operaciones  $(OBJ)/PD_operaciones.o

$(OBJ)/PD_operaciones.o: $(SRC)/PD_operaciones.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/PD_operaciones.cpp -o $(OBJ)/PD_operaciones.o
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ P3.tgz

mrproper : clean
	-rm $(BIN)/* doc/html/*
