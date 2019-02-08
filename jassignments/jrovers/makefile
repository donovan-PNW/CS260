all: exec
	
exec: queue.o testqueue.o resultdata.o 
	g++ -g -std=c++11 -no-pie -Wall queue.o testqueue.o resultdata.o -o exec

queue.o: queue.cpp
	g++ -g -std=c++11 -no-pie -c queue.cpp

testqueue.o: testqueue.cpp
	g++ -g -std=c++11 -no-pie -c testqueue.cpp

resultdata.o: resultdata.cpp
	g++ -g -std=c++11 -no-pie -c resultdata.cpp

make clean:
	rm -rf exec *.o
