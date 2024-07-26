test: test.c queue.o
	cc $^ -o $@

queue.o: queue.c queue.h
	cc -c queue.c

show: 
	./test

clean:
	rm *.o
