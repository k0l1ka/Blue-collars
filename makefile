all: bolt nut1 nut2 clean

realization.o: realization.cpp 
	g++ -c realization.cpp 

bolt: bolt.o realization.o
	 g++ -o bolt bolt.o realization.o

bolt.o: bolt.cpp 
	 g++ -c bolt.cpp

nut1: nut1.o realization.o
	g++ -o nut1 nut1.o realization.o

nut1.o: nut1.cpp 
	g++ -c nut1.cpp

nut2: nut2.o realization.o
	g++ -o nut2 nut2.o realization.o

nut2.o: nut2.cpp 
	g++ -c nut2.cpp

clean:
	 rm *.o
