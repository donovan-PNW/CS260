all: productionFunction

productionFunction: functions.o main.o
	g++ -g -Wall -std=c++11 functions.o main.o -o productionFunction

functions.o: functions.cpp 
	g++ -g -c -Wall -std=c++11 functions.cpp

main.o: main.cpp 
	g++ -g -c -Wall -std=c++11 main.cpp

make clean:
	rm -rf *.o productionFunction
