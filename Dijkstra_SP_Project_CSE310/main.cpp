#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util.h"
#include "element.h"

class graph;

//Heap implementation for CSE310 class
//Nate Cortes
//T-Th 6:00pm
//1207430649
//Purpose:
//	Graph implementation for 
//	Dijktsra's Shortest Path Algorithm


int main(){
	
	char input;					//initial menu input
	int run = 1;					//loop counter, 
	int v, e, inp_int, s_input, t_input;		//vertecies, edges, file input, secondary menu input, tertiary menu input
	int i;
	int file_inp[3];				//holds v, u, and w from input file lines
	FILE* librarian;				//FILE object to read input from GRAPHinput.txt
	graph* curr_graph = new graph( 0, 0);		//graph declaration

	while( run == 1){				//begin program loop
	
	std::cout<<"\n--input choice--"<<std::endl;	//prints menu
	std::cout<<"Stop (S)"<<std::endl;
	std::cout<<"Read Graph (R)"<<std::endl;
	std::cout<<"Print Graph Edges (W)"<<std::endl;
	std::cout<<"Find Shortest Path(P s t)"<<std::endl;
	//std::cout<<"Find Shortest Path with Heap Output(Q s t)"<<std::endl;

	std::cin>>input;				//take char input
	std::cout<<std::endl;
	switch(toupper(input)){				//select case
		case('S'):	
			run = 0;
			break;
		case('R'):
			std::cout<<"opening file"<<std::endl;
			librarian = fopen("./GRAPHinput.txt", "r");
			if (librarian == NULL)  { std::cout << "could not open file"; break;}	
	
			fseek(librarian,0,SEEK_SET);
			fscanf(librarian, "%i", &v);
			fseek(librarian, 1, SEEK_CUR);
			fscanf(librarian, "%i", &e);
			
			std::cout<<"constructing graph"<<std::endl;
			delete curr_graph;
			curr_graph = new graph( e, v);
			
			i=0;
			while( i<e && !feof(librarian)){
				fscanf(librarian, "%i", &file_inp);
				fscanf(librarian, "%i", &file_inp[1]);
				fscanf(librarian, "%i", &file_inp[2]);
				
				curr_graph->add_edge( (file_inp[0])-1 , (file_inp[1]), file_inp[2]);
				i++;
			}			
			std::cout<<"graph built"<<std::endl;


			fclose( librarian);
			std::cout<<"closing file"<<std::endl;	
			break;
		case('W'):
			print_graph( curr_graph);
			break;
		case('P'):	
			std::cin>>s_input;
			std::cin>>t_input;
				
			if(s_input <= 0 || s_input > curr_graph->vertecies){ 
				std::cout<<"First input out of bounds"<<std::endl;
			}	
			else if(t_input <= 0 || t_input > curr_graph->vertecies){ 
				std::cout<<"Second input out of bounds"<<std::endl;
			}
			else if( curr_graph->adjacencies[ s_input-1]->next == NULL){
				std::cout<<"There are no paths starting from "<<s_input<<std::endl;
			}
			else{
				Dijktsra_SP( curr_graph, s_input, t_input);
			
				std::cout<<"\n--Shortest Path--"<<std::endl;
				std::cout<<"distance: "<<curr_graph->adjacencies[ t_input - 1]->distance<<std::endl;
				std::cout<<"path: ";
				print_parent_path( curr_graph->adjacencies[ t_input - 1], curr_graph);
				std::cout<<"\n-----------------\n"<<std::endl;			
			}

			break;
		default:
			std::cout<<"default case"<<std::endl;

		}
				
		std::cin.ignore();
	}
	
	std::cout<<"--program quitting--"<<std::endl;
	delete curr_graph;
	return 0;
}
