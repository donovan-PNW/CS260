all: exec
	
exec: stack.o teststack.o 
	g++ -g -std=c++11 -no-pie -Wall stack.o teststack.o -o exec

stack.o: stack.cpp
	g++ -g -std=c++11 -no-pie -c stack.cpp

teststack.o: teststack.cpp
	g++ -g -std=c++11 -no-pie -c teststack.cpp

make clean:
	rm -rf exec *.o
