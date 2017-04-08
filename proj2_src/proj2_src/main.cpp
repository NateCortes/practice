#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "element.h"

class heap;

//Heap implementation for CSE310 class
//Nate Cortes
//T-Th 6:00pm
//1207430649
//Purpose:
//	Generates and manipulates a Heap data structure.


int main(){
	
	char input;					//initial menu input
	int run = 1, count, inp_int, s_input, t_input;	//loop counter, total input file counter, file input, secondary menu input, tertiary menu input
	element buffer[4096]; 				//allocate an element buffer of 4Kb
	FILE* librarian;				//FILE object to read input from HEAPinput.txt
	heap cur_heap(0);				//heap declaration

	while( run == 1){				//begin loop
	
	std::cout<<"\n--input choice--"<<std::endl;	//starts menu
	std::cout<<"Stop (S)"<<std::endl;
	std::cout<<"Initilaize (C n)"<<std::endl;
	std::cout<<"Read Array (R)"<<std::endl;
	std::cout<<"Print Heap (W)"<<std::endl;
	std::cout<<"Insert Into Heap (I k)"<<std::endl;
	std::cout<<"Delete Min (D)"<<std::endl;
	std::cout<<"Decrease Key (K i v)"<<std::endl;
	
	std::cin>>input;				//take char input
		
	switch(toupper(input)){				//select case

		case('S'):
			run = 0;
			break;
		case('C'):
			std::cin>>s_input;
			std::cout<<"secondary input: "<<s_input<<std::endl;
			cur_heap = initialize( s_input);
			std::cout<<cur_heap.capacity<<std::endl;
			break;
		case('R'):
			librarian = fopen("./HEAPinput.txt", "r");
			if (librarian == NULL)  { std::cout << "could not open file"; break;}
			
			fseek(librarian,0,SEEK_SET);
			fscanf(librarian, "%i", &count);
			
			//stores total of text file integers at end of array
			buffer[4095] = element( count);
			std::cout<<"count: "<<buffer[4095].key<<std::endl;

			
			count = 0;
			while(!feof(librarian)){	
				fseek(librarian, 1, SEEK_CUR);
       				fscanf(librarian, "%i", &inp_int);
				buffer[count] = element( inp_int);
				std::cout<<"elem: "<<buffer[count].key<<std::endl;
				count = count + 1;
			}
						
			if(count > cur_heap.capacity){
				element update[count];
				delete[] cur_heap.sack;
				cur_heap.capacity = count;
				cur_heap.sack = update; 
			}

			build_heap( &cur_heap, buffer);
				
			fclose( librarian);	
			break;
		case('W'):
			print_heap( &cur_heap);
			break;
		case('I'):
			std::cin>>s_input;
			std::cout<<"secondary input: "<<s_input <<std::endl;
			insert( &cur_heap, s_input);
			break;
		case('D'):
			std::cout<<delete_min( &cur_heap);
			break;
		case('K'):	
			std::cin>>s_input;
			std::cin>>t_input;
			std::cout<<"secondary input: "<<s_input<<" | "<<t_input <<std::endl;
			decrease_key( &cur_heap, s_input, t_input);
			break;
		default:
			std::cout<<"default case"<<std::endl;

		}
				
		count = 0;
		std::cin.ignore();
	}
	
	std::cout<<"program quitting"<<std::endl;
	delete[] cur_heap.sack;
	return 0;
}
