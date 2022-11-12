CXXFLAGS = -Wall -g

PROGS = test_bateau

all: $(PROGS)

test_bateau: test_bateau.o class.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test_bateau.o: test_bateau.cpp class.hpp
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o *~ $(PROGS)
