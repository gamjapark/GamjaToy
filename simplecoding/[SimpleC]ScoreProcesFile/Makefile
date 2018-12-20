ScoreProcessFile.out: main.o student.o
	gcc -o ScoreProcessFile.out main.o student.o student.h
student.o: student.c student.h
	gcc -c student.c
main.o: main.c student.h
	gcc -c main.c
clean:
	rm -f student.o main.o
