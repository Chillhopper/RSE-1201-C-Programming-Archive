// TODO
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "minesweeper-utils.h"



typedef struct{
	char state;
	bool is_visible;
} Tile;

typedef Tile* Row;//Row contains the address of a tile

struct Map{
	short int ht;
	short int wth;
	Row* grid;//grid is an array of rows (pointers to tiles)
};



//there is only 1 grid 
Map* create_map(unsigned short int width, unsigned short int height){	
    Map grd;
	grd.ht = height;
	grd.wth = width;
	grd.grid[height][width];
	Map* address = (Map*)malloc(sizeof(grd)); 
	*address = grd;

	/*for(int i = 0; i<height; i++){
		for(int j = 0; j<width; j++){
			grd.grid[i][j];
		}
	}
	grd.grid 
	
	/*Map arr[height][width];
	Map* address = (int*)malloc(sizeof(arr)); 
	*address = arr;

	
    return address; */
}

void destroy_map(Map* map){
	free(map);
}

void set_tile(Map* map, unsigned short int column, unsigned short int row, char state, bool is_visible){
	(*map).grid[row][column].state = state;
	map -> grid[row][column].is_visible = is_visible;
}

void initialize_map(Map* map, float probability){
	short int height = map -> ht;
	short int width = map -> wth;
	for(int i = 0; i<height; i++){
		for(int j=0; i<width;i++){
			map ->grid[i][j].is_visible = false;
			int r = rand()%100;
			if(r >= probability*100){
				map ->grid[i][j].is_visible = false;
				map ->grid[i][j].state = BOMB;
			}else{
				map ->grid[i][j].state = 0;
			}
			
		}
	}

	for(int i = 0; i<height; i++){
		for(int j=0; i<width;i++){	
			if(map ->grid[i][j].state != BOMB){
				map ->grid[i][j].state = 1; //Idk what adjascent means, placeholder code.
			}
		}
	}	
}

void print_map(const Map* map){
	short int height = map -> ht;
	short int width = map -> wth;
	for(int i = 0; i<height; i++){
		for(int j=0; i<width;i++){
			if(map -> grid[i][j].state != BOMB){
				printf(" |");
			}
		}
	}
}

void reveal_all_tiles(Map* map);

bool all_empty_tiles_visible(const Map* map);

bool is_bomb_tile(
	Map* map,
	unsigned short int column,
	unsigned short int row
);