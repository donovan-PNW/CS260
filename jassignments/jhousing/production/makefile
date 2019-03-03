all: housing 

housing: hashtable.o family.o familymgr.o housinghelper.o
	g++ -g -Wall -std=c++11 -no-pie hashtable.o family.o familymgr.o housinghelper.o -o housing

hashtable.o: hashtable.cpp
	g++ -g -Wall -std=c++11 -no-pie hashtable.cpp -c

family.o: family.cpp
	g++ -g -Wall -std=c++11 -no-pie family.cpp -c

familymgr.o: familymgr.cpp
	g++ -g -Wall -std=c++11 -no-pie familymgr.cpp -c

housinghelper.o: housinghelper.cpp
	g++ -g -Wall -std=c++11 -no-pie housinghelper.cpp -c

make clean:
	rm -rf housing *.o

#testhashtable.o: testhashtable.cpp
#	g++ -g -Wall -std=c++11 -no-pie testhashtable.cpp -c

#testfamily.o: testfamily.cpp
#	g++ -g -Wall -std=c++11 -no-pie testfamily.cpp -c
#
#runner: hashtable.o testhashtable.o family.o
#	g++ -g -Wall -std=c++11 -no-pie hashtable.o testhashtable.o family.o -o runner

#famjam: testfamily.o family.o
#	g++ -g -Wall -std=c++11 -no-pie testfamily.o family.o -o famjam

