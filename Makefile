OBJECTS= main.o article.o commande.o client.o fonctions.o livraison.o data.o 
CFLAGS= -Wall -Wextra -g -c 
CPP= g++
do : commerce
%.o: %.cpp %.h header.h
	$(CPP) $(CFLAGS)  $< -o $@  
commerce: ${OBJECTS}
	g++ -o commerce ${OBJECTS} 
clean:
	rm -rf *.o