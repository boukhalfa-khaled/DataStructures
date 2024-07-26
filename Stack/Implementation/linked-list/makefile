test: test.c stack.o
	cc $^ -o $@

stack.o: stack.c stack.h
	cc -c stack.c

clean:
	rm *.o
