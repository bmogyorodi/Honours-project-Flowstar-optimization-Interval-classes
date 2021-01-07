CXX = g++
include makefile.local
LIBS = -lmpfr -lgmp -lgsl -lgslcblas -lm -lglpk
CFLAGS = -I . -I $(GMP_HOME) -g -O3 -std=c++11
LINK_FLAGS = -g -L$(GMP_LIB_HOME) 
OBJS = Interval.o IntervalTest.o
 

Tester: $(OBJS)
	g++ -O3 -w $(LINK_FLAGS) -o $@ $^ $(LIBS)



%.o: %.cc
	$(CXX) -O3 -c $(CFLAGS) -o $@ $<
%.o: %.cpp
	$(CXX) -O3 -c $(CFLAGS) -o $@ $<
%.o: %.c
	$(CXX) -O3 -c $(CFLAGS) -o $@ $<


clean: 
	rm -f Interval.o IntervalTest.o
