all: dstat.o
	gcc -o test dstat.o
dstat.o: dstat.c
	gcc -c dstat.c
clean:
	rm *.o
run: all
	./test
