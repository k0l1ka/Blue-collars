all: ev1 eg1 eg2 

realization.o: realization.cpp header.h
	g++ -c realization.cpp header.h 

ev1: v1.o realization.o
	 g++ -o ev1 v1.o realization.o

v1.o: v1.cpp header.h
	 g++ -c v1.cpp header.h

eg1: g1.o realization.o
	g++ -o eg1 g1.o realization.o

g1.o: g1.cpp header.h
	g++ -c g1.cpp header.h

eg2: g2.o realization.o
	g++ -o eg2 g2.o realization.o

g2.o: g2.cpp header.h
	g++ -c g2.cpp header.h

clean:
	 rm v1.o ev1 g1.o eg1 g2.o eg2 realization.o
