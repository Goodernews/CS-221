CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++2a -O0 -g 
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)
all:  cities tsp

cities: cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

tsp: cities.o tsp.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
		$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<
clean:
		rm -rf *.o tsp cities

test: tsp
	./tsp five.tsv
	./tsp linear.tsv
