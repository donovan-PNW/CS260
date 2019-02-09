all: test
	
test: queue.o resultdata.o testqueue.o
	g++ -g -std=c++11 -no-pie -Wall queue.o resultdata.o testqueue.o -o test 

queue.o: queue.cpp
	g++ -g -std=c++11 -no-pie -c queue.cpp

testqueue.o: testqueue.cpp
	g++ -g -std=c++11 -no-pie -c testqueue.cpp

resultdata.o: resultdata.cpp
	g++ -g -std=c++11 -no-pie -c resultdata.cpp


make clean:
	rm -rf test rovertotal *.o
