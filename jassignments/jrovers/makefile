all: rovertotal
	
rovertotal: queue.o stack.o scandata.o resultdata.o rover.o rovercontrol.o
	g++ -g -std=c++11 -no-pie -Wall queue.o stack.o scandata.o resultdata.o rover.o rovercontrol.o -o rovertotal

queue.o: queue.cpp
	g++ -g -std=c++11 -no-pie -c queue.cpp

#testqueue.o: testqueue.cpp
#	g++ -g -std=c++11 -no-pie -c testqueue.cpp

stack.o: stack.cpp
	g++ -g -std=c++11 -no-pie -c stack.cpp

scandata.o: scandata.cpp
	g++ -g -std=c++11 -no-pie -c scandata.cpp

#teststack.o: teststack.cpp
#	g++ -g -std=c++11 -no-pie -c teststack.cpp

resultdata.o: resultdata.cpp
	g++ -g -std=c++11 -no-pie -c resultdata.cpp

rover.o: rover.cpp
	g++ -g -std=c++11 -no-pie -c rover.cpp

rovercontrol.o: rovercontrol.cpp
	g++ -g -std=c++11 -no-pie -c rovercontrol.cpp

make clean:
	rm -rf rovertotal *.o
