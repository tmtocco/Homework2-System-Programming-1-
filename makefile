output: main.o 
	gcc *.o

main.o: main.c 
	gcc -c main.c
	echo "nothing"

clean:
	rm *.o
	rm a.out

easy:
	./a.out textfile.txt encrypted.txt 25