
CC = g++
OBJECTS = bst_start.cpp

%.o : %.c 
	$(CC) -C $<

run:	$(OBJECTS)
	$(CC) -o $@ $^
	./run

clean:
	rm *.o

cleanALL:
	rm *.o run