 
CFLAGS= -Wall -Wextra -g -c 
CCPP= g++
SRC = ./src
LIB = ./lib
OBJ = ./obj
BIN = ./bin
OBJECTS= $(OBJ)/lang.o $(OBJ)/relations.o  $(OBJ)/Article.o $(OBJ)/Articles.o $(OBJ)/Commande.o $(OBJ)/Commandes.o $(OBJ)/Client.o $(OBJ)/Clients.o $(OBJ)/fonctions.o $(OBJ)/Livraison.o $(OBJ)/Livraisons.o 
MAINOBJECTS= $(OBJ)/main.o
TESTOBJECTS= $(OBJ)/test.o
HEADER= $(SRC)/lang/lang.h $(SRC)/Cellule/Cellule.h $(SRC)/relations/relations.h $(SRC)/Client/Client.h $(SRC)/Client/Clients.h  $(SRC)/Article/Article.h $(SRC)/Article/Articles.h $(SRC)/Commande/Commande.h $(SRC)/Commande/Commandes.h $(SRC)/fonctions/fonctions.h $(SRC)/Livraison/Livraison.h $(SRC)/Livraison/Livraisons.h
do : commerce
$(OBJ)/Client.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/Client/Client.cpp -o $(OBJ)/Client.o
$(OBJ)/Clients.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/Client/Clients.cpp -o $(OBJ)/Clients.o
$(OBJ)/Article.o: $(HEADER) 
	$(CCPP) $(CFLAGS) $(SRC)/Article/Article.cpp -o $(OBJ)/Article.o
$(OBJ)/Articles.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/Article/Articles.cpp -o $(OBJ)/Articles.o
$(OBJ)/Commande.o: $(HEADER) 
	$(CCPP) $(CFLAGS) $(SRC)/Commande/Commande.cpp -o $(OBJ)/Commande.o
$(OBJ)/Commandes.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/Commande/Commandes.cpp -o $(OBJ)/Commandes.o
$(OBJ)/Livraison.o: $(HEADER) 
	$(CCPP) $(CFLAGS) $(SRC)/Livraison/Livraison.cpp -o $(OBJ)/Livraison.o
$(OBJ)/Livraisons.o:  $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/Livraison/Livraisons.cpp -o $(OBJ)/Livraisons.o
$(OBJ)/relations.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/relations/relations.cpp  -o $(OBJ)/relations.o 
$(OBJ)/fonctions.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/fonctions/fonctions.cpp  -o $(OBJ)/fonctions.o -lm
$(OBJ)/Cellule.o: $(HEADER) 
	$(CCPP) $(CFLAGS) $(SRC)/Cellule/Cellule.cpp -o $(OBJ)/Cellule.o
$(OBJ)/main.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/main/main.cpp -o $(OBJ)/main.o
$(OBJ)/test.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/test/main.cpp  -o $(OBJ)/test.o
$(OBJ)/lang.o: $(HEADER)
	$(CCPP) $(CFLAGS) $(SRC)/lang/lang.cpp  -o $(OBJ)/lang.o	
commerce: ${OBJECTS} ${MAINOBJECTS}
	g++ -o $(BIN)/commerce ${OBJECTS} ${MAINOBJECTS}
clean: 
	rm -rf $(OBJ)/*.o
	rm -rf $(BIN)/test
	rm -rf $(BIN)/commerce
run: commerce
	./$(BIN)/commerce
test: ${OBJECTS} ${TESTOBJECTS}   
	g++ -o $(BIN)/test ${OBJECTS} ${TESTOBJECTS}
runtest: test
	./$(BIN)/test	