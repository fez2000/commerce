OBJECTS= main.o article.o commande.o client.o fonctions.o livraison.o data.o histo.o
CFLAGS= -Wall -Wextra -g -c 
CPP= g++
do : shell
%.o: %.cpp %.h header.h
	$(CPP) $(CFLAGS)  $< -o $@  
shell: ${OBJECTS}
	g++ -o shell ${OBJECTS} 
clean:
	rm -rf *.o