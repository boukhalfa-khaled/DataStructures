infixToPostFix: infixToPostFix.c stack.o
	cc $^ -o $@

stack.o: stack.c stack.h
	cc -c stack.c -o $@

clean:
	rm *.o
