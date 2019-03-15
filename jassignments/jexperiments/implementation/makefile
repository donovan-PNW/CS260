all: treeTest
	
treeTest: plant.o planttree.o testtree.o
	g++ -g -Wall -std=c++11 plant.o planttree.o testtree.o -o treeTest

plant.o: plant.cpp
	g++ -g -Wall -std=c++11 plant.cpp -c

planttree.o: planttree.cpp
	g++ -g -Wall -std=c++11 planttree.cpp -c

testtree.o: testtree.cpp
	g++ -g -Wall -std=c++11 testtree.cpp -c

make clean:
	rm -rf *.o treeTest out
