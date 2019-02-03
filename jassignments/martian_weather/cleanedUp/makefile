all: exec
	
exec: weatherdata.o datalogger.o linkedlist.o weatherlog.o
	g++ -g -std=c++11 -no-pie -Wall weatherdata.o datalogger.o linkedlist.o weatherlog.o -o exec

weatherdata.o: weatherdata.cpp
	g++ -g -std=c++11 -no-pie -c weatherdata.cpp

datalogger.o: datalogger.cpp
	g++ -g -std=c++11 -no-pie -c datalogger.cpp

linkedlist.o: linkedlist.cpp
	g++ -g -std=c++11 -no-pie -c linkedlist.cpp

weatherlog.o: weatherlog.cpp
	g++ -g -std=c++11 -no-pie -c weatherlog.cpp

make clean:
	rm -rf exec *.o
