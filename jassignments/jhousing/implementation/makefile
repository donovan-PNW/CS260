all: runner

runner: family.o testfamily.o
	g++ -g -Wall -std=c++11 -no-pie family.o testfamily.o -o runner

family.o: family.cpp
	g++ -g -Wall -std=c++11 -no-pie family.cpp -c

testfamily.o: testfamily.cpp
	g++ -g -Wall -std=c++11 -no-pie testfamily.cpp -c
