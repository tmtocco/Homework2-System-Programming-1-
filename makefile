output: main.o caesar.o
	gcc -Wall main.o caesar.o -o a.out -lm

main.o: main.c
	gcc -c main.c

caesar.o: caesar.c
	gcc -c caesar.c

clean:
	rm *.o
	rm a.out
