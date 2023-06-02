all: a.out

a.out:
	g++ -std=c++11 main.cpp

test: a.out
	./a.out
	
test1: a.out
	./a.out test1_500_1000.txt
	
test2: a.out
	./a.out test1_50000_100000.txt
	
test3: a.out
	./a.out test2_5000_10000.txt
	
test4: a.out
	./a.out test2_30000_71245.txt
	
clean:
	rm a.out
