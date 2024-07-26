test :test.c queue.o
	gcc $^ -o $@


queue.o: queue.c queue.h
	gcc -c  queue.c

show:
	./test

clean:
	rm *.o
