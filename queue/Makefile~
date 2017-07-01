CC = g++ 
OBJECTS = OStesting.o queue.o

%.o : %.c
	$(CC) -c $<

run : $(OBJECTS)
	$(CC) -o $@ $^
	rm *.o
	./run
clean: 
	rm *.o

cleanALL: 
	rm *.o run