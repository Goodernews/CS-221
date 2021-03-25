CXX=g++-8
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  test_hforest test_htree test_tree decoder


htree.o:
	g++ htree.cc

test_htree.o:
	g++ test_htree.cc

hforest.o:
	g++ hforest.cc
test_hforest.o:
	g++ test_hforest.cc

test_htree: htree.o test_htree.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_hforest: hforest.o test_hforest.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_htree test_hforest

test: all
	./test_hforest
	./test_huffman
	./test_bitio
