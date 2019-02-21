all: runner

famjam: testfamily.o family.o
	g++ -g -Wall -std=c++11 -no-pie testfamily.o family.o -o famjam

runner: hashtable.o testhashtable.o family.o
	g++ -g -Wall -std=c++11 -no-pie hashtable.o testhashtable.o family.o -o runner

hashtable.o: hashtable.cpp
	g++ -g -Wall -std=c++11 -no-pie hashtable.cpp -c

testhashtable.o: testhashtable.cpp
	g++ -g -Wall -std=c++11 -no-pie testhashtable.cpp -c

family.o: family.cpp
	g++ -g -Wall -std=c++11 -no-pie family.cpp -c

make clean:
	rm -rf runner hashtable.o testhashtable.o family.o testfamily.o

#runner: family.o testfamily.o
#	g++ -g -Wall -std=c++11 -no-pie family.o testfamily.o -o runner


testfamily.o: testfamily.cpp
	g++ -g -Wall -std=c++11 -no-pie testfamily.cpp -c


#make clean:
#	rm -rf runner family.o testfamily.o

