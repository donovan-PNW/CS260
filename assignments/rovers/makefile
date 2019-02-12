all: roverexecutable
	
roverexecutable: queue.o stack.o scandata.o resultdata.o rover.o rovercontrol.o
	g++ -g -std=c++11 -Wall -ggdb3 queue.o stack.o scandata.o resultdata.o rover.o rovercontrol.o -o roverexecutable

queue.o: queue.cpp
	g++ -g -std=c++11 -Wall -c queue.cpp -ggdb3

#testqueue.o: testqueue.cpp
#	g++ -g -std=c++11 -c testqueue.cpp

stack.o: stack.cpp
	g++ -g -std=c++11 -Wall -c stack.cpp -ggdb3

scandata.o: scandata.cpp
	g++ -g -std=c++11 -Wall -c scandata.cpp -ggdb3

#teststack.o: teststack.cpp
#	g++ -g -std=c++11 -c teststack.cpp

resultdata.o: resultdata.cpp
	g++ -g -std=c++11 -Wall -c resultdata.cpp -ggdb3

rover.o: rover.cpp
	g++ -g -std=c++11 -Wall -c rover.cpp -ggdb3

rovercontrol.o: rovercontrol.cpp
	g++ -g -std=c++11 -Wall -c rovercontrol.cpp -ggdb3

make clean:
	rm -rf roverexecutable *.o
