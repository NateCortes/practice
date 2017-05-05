CC = g++
OBJECTS = main.o util.o heap.o

run : $(OBJECTS)
	$(CC) $(OBJECTS) -o proj2
	./proj2

%.o : %.c
	$(CC) -c $<

clean :
	rm *.o

cleanAll :
	rm  *.o proj2
