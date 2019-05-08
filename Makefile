 
CFLAGS= -Wall -Wextra -g -c 
CCPP= g++
SRC = ./src
LIB = ./lib
OBJ = ./obj
BIN = ./bin
OBJECTS= $(OBJ)/Cellule.o $(OBJ)/main.o $(OBJ)/Article.o $(OBJ)/Commande.o $(OBJ)/Client.o $(OBJ)/fonctions.o $(OBJ)/Livraison.o $(OBJ)/Data.o
do : commerce
$(OBJ)/Client.o: $(SRC)/Client/Client.h $(SRC)/Client/Clients.h $(SRC)/Cellule/Cellule.h
	$(CCPP) $(CFLAGS) $(SRC)/Client/Client.cpp -o $(OBJ)/Client.o
	$(CCPP) $(CFLAGS) $(SRC)/Client/Clients.cpp -o $(OBJ)/Clients.o
$(OBJ)/Article.o: $(SRC)/Article/Article.h $(SRC)/Article/Articles.h
	$(CCPP) $(CFLAGS) $(SRC)/Article/Article.cpp -o $(OBJ)/Article.o
	$(CCPP) $(CFLAGS) $(SRC)/Article/Articles.cpp -o $(OBJ)/Articles.o
$(OBJ)/Commande.o: $(SRC)/Commande/Commande.h $(SRC)/Commande/Commandes.h
	$(CCPP) $(CFLAGS) $(SRC)/Commande/Commande.cpp -o $(OBJ)/Commande.o
	$(CCPP) $(CFLAGS) $(SRC)/Commande/Commandes.cpp -o $(OBJ)/Commandes.o
$(OBJ)/Livraison.o: $(SRC)/Livraison/Livraison.h $(SRC)/Livraison/Livraisons.h
	$(CCPP) $(CFLAGS) $(SRC)/Livraison/Livraison.cpp -o $(OBJ)/Livraison.o
	$(CCPP) $(CFLAGS) $(SRC)/Livraison/Livraisons.cpp -o $(OBJ)/Livraisons.o
$(OBJ)/fonctions.o: $(SRC)/fonctions/fonctions.h 
	$(CCPP) $(CFLAGS) $(SRC)/fonctions/fonctions.cpp -o $(OBJ)/fonctions.o
$(OBJ)/Cellule.o: $(SRC)/Cellule/Cellule.h 
	$(CCPP) $(CFLAGS) $(SRC)/Cellule/Cellule.cpp -o $(OBJ)/Cellule.o
$(OBJ)/Data.o: $(SRC)/Data/Data.h 
	$(CCPP) $(CFLAGS) $(SRC)/Data/Data.cpp -o $(OBJ)/Data.o
$(OBJ)/main.o: $(SRC)/main/main.h $(SRC)/Client/Client.h $(SRC)/Article/Articles.h $(SRC)/Article/Article.h $(SRC)/Commande/Commandes.h $(SRC)/Commande/Commande.h $(SRC)/Client/Clients.h  $(SRC)/Livraison/Livraison.h $(SRC)/Livraison/Livraisons.h
	$(CCPP) $(CFLAGS) $(SRC)/main/main.cpp -o $(OBJ)/main.o

 
commerce: ${OBJECTS}
	g++ -o $(BIN)/commerce ${OBJECTS} 
clean:
	rm -rf $(OBJ)/*.o
run:
	./$(BIN)/commerce