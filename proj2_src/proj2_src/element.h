#ifndef ELEMENT_H
#define ELEMENT_H	

struct element{
	int key;
	element(): key(0){};
	element( int k):key(k){};		
	~element(){};
};

#endif
