assgn2.x: main.o student.o
	g++ -o assgn2.x -std=c++11 main.o student.o
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
student.o: student.h student.cpp
	g++ -c -std=c++11 student.h
	g++ -c -std=c++11 student.cpp

test.x: studentTest.o student.o
	g++ -o test.x -std=c++11 studentTest.o student.o
studentTest.o: studentTest.cpp
	g++ -c -std=c++11 studentTest.cpp

clear:
	-rm *.o
	-rm *.hgch
test.x: studentTest.o student.o
    g++ -o test.x -std=c++11 studentTest.o student.o

studentTest.o: studentTest.cpp
    g++ -c -std=c++11 studentTest.cpp