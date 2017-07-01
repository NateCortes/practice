CC = g++
OBJECTS = Stacktesting.o stack.o

%.o : %.c
	$(CC) -c $<

run : $(OBJECTS)
	$(CC) -o $@ $^
	rm *.o
	./$@

clean: 
	rm *.o

cleanALL:
	rm *.o