 
CFLAGS= -Wall -Wextra -g -c 
CCPP= g++
SRC = ./src
LIB = ./lib
OBJ = ./obj
BIN = ./bin
OBJECTS=   $(OBJ)/Article.o $(OBJ)/Articles.o $(OBJ)/Commande.o $(OBJ)/Commandes.o $(OBJ)/Client.o $(OBJ)/Clients.o $(OBJ)/fonctions.o $(OBJ)/Livraison.o $(OBJ)/Livraisons.o 
MAINOBJECTS= $(OBJ)/main.o
TESTOBJECTS= $(OBJ)/test.o
do : commerce
$(OBJ)/Client.o: $(SRC)/Client/Client.h  $(SRC)/Cellule/Cellule.h
	$(CCPP) $(CFLAGS) $(SRC)/Client/Client.cpp -o $(OBJ)/Client.o
$(OBJ)/Clients.o: $(SRC)/Client/Clients.h $(SRC)/Cellule/Cellule.h
	$(CCPP) $(CFLAGS) $(SRC)/Client/Clients.cpp -o $(OBJ)/Clients.o
$(OBJ)/Article.o: $(SRC)/Article/Article.h 
	$(CCPP) $(CFLAGS) $(SRC)/Article/Article.cpp -o $(OBJ)/Article.o
$(OBJ)/Articles.o: $(SRC)/Article/Articles.h
	$(CCPP) $(CFLAGS) $(SRC)/Article/Articles.cpp -o $(OBJ)/Articles.o
$(OBJ)/Commande.o: $(SRC)/Commande/Commande.h 
	$(CCPP) $(CFLAGS) $(SRC)/Commande/Commande.cpp -o $(OBJ)/Commande.o
$(OBJ)/Commandes.o: $(SRC)/Commande/Commandes.h
	$(CCPP) $(CFLAGS) $(SRC)/Commande/Commandes.cpp -o $(OBJ)/Commandes.o
$(OBJ)/Livraison.o: $(SRC)/Livraison/Livraison.h 
	$(CCPP) $(CFLAGS) $(SRC)/Livraison/Livraison.cpp -o $(OBJ)/Livraison.o
$(OBJ)/Livraisons.o:  $(SRC)/Livraison/Livraisons.h
	$(CCPP) $(CFLAGS) $(SRC)/Livraison/Livraisons.cpp -o $(OBJ)/Livraisons.o
$(OBJ)/fonctions.o: $(SRC)/fonctions/fonctions.h $(SRC)/Client/Client.h $(SRC)/Article/Article.h $(SRC)/Commande/Commande.h
	$(CCPP) $(CFLAGS) $(SRC)/fonctions/fonctions.cpp  -o $(OBJ)/fonctions.o -lm
$(OBJ)/Cellule.o: $(SRC)/Cellule/Cellule.h 
	$(CCPP) $(CFLAGS) $(SRC)/Cellule/Cellule.cpp -o $(OBJ)/Cellule.o
$(OBJ)/main.o: $(SRC)/main/main.h $(SRC)/Client/Client.h $(SRC)/Article/Articles.h $(SRC)/Article/Article.h $(SRC)/Commande/Commandes.h $(SRC)/Commande/Commande.h $(SRC)/Client/Clients.h  $(SRC)/Livraison/Livraison.h $(SRC)/Livraison/Livraisons.h
	$(CCPP) $(CFLAGS) $(SRC)/main/main.cpp -o $(OBJ)/main.o
$(OBJ)/test.o: $(SRC)/test/main.h $(SRC)/Client/Client.h $(SRC)/Article/Articles.h $(SRC)/Article/Article.h $(SRC)/Commande/Commandes.h $(SRC)/Commande/Commande.h $(SRC)/Client/Clients.h  $(SRC)/Livraison/Livraison.h $(SRC)/Livraison/Livraisons.h
	$(CCPP) $(CFLAGS) $(SRC)/test/main.cpp  -o $(OBJ)/test.o

 
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