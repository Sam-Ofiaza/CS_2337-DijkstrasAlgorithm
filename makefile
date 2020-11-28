test1: clean compile testSimple
test2: clean compile testFiveElement
test3: clean compile testCantGoAnywhere
test4: clean compile testCanGoEverywhere

clean:
	rm -f test
  
compile: main.cpp
	g++ -I . -o test main.cpp DijkstraAlgorithm.cpp Graph.cpp Vertex.cpp
  
testSimple:
	./test 0

testFiveElement:
	./test 1

testCantGoAnywhere:
	./test 2

testCanGoEverywhere:
	./test 3

