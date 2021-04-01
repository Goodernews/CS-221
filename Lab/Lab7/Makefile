XX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++2a -O0 -g 
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)


highest: highest.o
	$(CXX) $(LDFLAGS) -o $@ $^
	

test: test.o 
	$(CXX) $(LDFLAGS) -o $@ $^


all: source-stats.wc highest 

source-stats.wc: source.txt
	wc source.txt > source-stats.wc

clean:
	rm -f *.o
	rm -f *-stats.wc
	rm test 
	rm highest
