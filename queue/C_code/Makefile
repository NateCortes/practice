CC = gcc
OBJECTS = OStesting.o 

%.o : %.c
	$(CC) -c $<

run : $(OBJECTS)
	$(CC) -o $@ $^
	rm *.o
	./run
clean: 
	rm *.o

cleanALL: 
	rm *.o run;