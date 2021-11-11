#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and Stack.o to executable main
main: main.o Stack.o
	g++ -g -o main main.o Stack.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the Stack.cpp to Stack.o
Stack.o: Stack.cpp
	g++ -g -c Stack.cpp

#compile the Stack.cpp to Stack.o
Stack.hpp.gch: Stack.hpp
	g++ -g -c Stack.hpp

#remove built files
clean:
	rm -rf *.o *.gch *.exe *~
