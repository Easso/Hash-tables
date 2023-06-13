all: openhttest orderedhttest

openhttest: openhttest.cpp hash_double.cpp student.cpp
	g++ -std=c++11 openhttest.cpp hash_double.cpp student.cpp -o openhttest
	
orderedhttest: orderedhttest.cpp hash_chaining.cpp student.cpp
	g++ -std=c++11 orderedhttest.cpp hash_chaining.cpp student.cpp -o orderedhttest
