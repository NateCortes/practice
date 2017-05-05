CC = g++
ODIR=./obj
OBJECTS = main.o util.o heap.o graph.o

%.o : %.c
	$(CC) -c $< 

run : $(OBJECTS)
	$(CC) -o $@ $^
	rm *.o
	./run

clean :
	rm *.o

cleanAll :
	rm  *.o run
