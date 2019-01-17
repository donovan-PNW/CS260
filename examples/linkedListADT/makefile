all: exec

exec: data.o driver.o linkedlist.o
	g++ -g -no-pie data.o driver.o linkedlist.o -o exec

data.o: data.cpp
	g++ -g data.cpp -c

driver.o: driver.cpp
	g++ -g driver.cpp -c

linkedlist.o: linkedlist.cpp
	g++ -g linkedlist.cpp -c

make clean:
	rm -rf data.o driver.o linkedlist.o exec

