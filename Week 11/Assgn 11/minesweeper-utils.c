#include <stdio.h>
#include <stdlib.h>
#include "minesweeper-utils.h"
#include <stdbool.h>


typedef struct
{
char state;
bool is_visible;
} Tile;// tile type includes char 1 byte and bool 2 bytes (just use sizeof)

// Row points to type tile
typedef Tile* Row;

typedef struct Map 
{
unsigned short int width;
unsigned short int height;
Row* grid; // tile** grid grid is a pointer that points to a pointer that points to tile
} Map;

Map* create_map(unsigned short int width, unsigned short int height)
{
    //we have a given height and width. we need to allocate memory
    Map* map = (Map*)malloc(sizeof(map));
    map->width = width;
    map->height = height;
    if(!map)//if fail
    {
        return NULL;
    }
    map->grid = malloc(height * sizeof(Row));
    if(!map->grid)//if fail
    {
        return NULL;
    }

    for(int i = 0; i<height; i++)
    {
        map->grid[i] = malloc(width * sizeof(Tile));
        if (!map->grid[i])//if fail
            {
                return NULL;
            }

    }

    return map;
}

void destroy_map(Map* map)
{
    //free
    for(int i = 0; i<map->height;i++)
    {
        free(map->grid[i]);
    }
    free(map->grid);
    free(map);
    // loop with variables in the struct.
}

void set_tile(Map* map, unsigned short int column, unsigned short int row, char state, bool is_visible)
{
//inital state of tiles
    map->grid[row][column].state = state;
    map->grid[row][column].is_visible = is_visible;
}

void print_map(const Map* map)
{ 
    printf(" "); //table format
    for(int i=0;i<map->width;i++)
    {  
        printf(" %d",i);     //table formatting
    }
    printf("\n"); //formating

    for(int i =0; i<map->height; i++)
    {
        printf("%d|",i); // table formatting
        for(int j = 0; j <map->width; j++)
        {
           
            if(map->grid[i][j].is_visible)
            {
                printf("%c|", map->grid[i][j].state);
            }
            else
            {
                printf(" |");
            } 
        }
        printf("\n");
    }
}

void initialize_map(Map* map, float probability)
{
    int r;
    for(short unsigned int i =0; i<map->height; i++)
    {
        for(short unsigned int j = 0; j <map->width; j++)
        {

            //put false if req
            r = rand()%100;
            
            if(r>=probability*100)
            {
                set_tile(map, j, i, BOMB, 0);
            }
            else
            {
                set_tile(map, j, i, '0', 0); // bool false also usable 
            }
        }
    }
    
    //int count = 0;

    for(int i = 0; i < map->height; i++) // go thru all variables
    {
        for(int j = 0; j < map->width; j++)
        {
            if(map->grid[i][j].state!=BOMB)//if not bomb
            {
                for (int h = (i-1); h< (i+2); h++)//check adjacent
                {   
                    if (h>=0 && h<map->height)//ifonly valid
                    {
                        
                        for(int w = (j-1); w < (j+2); w++)
                        {
                            if (w>=0 && w<map->width)//if only valid array
                            {

                                if(map->grid[h][w].state == BOMB) //add && if not itself condition if needed 
                                {
                                    //count++;
                                    map->grid[i][j].state++;//if bomb, incremen
                                }
                            }
                        } 
                    }  
                }
              // map->grid[i][j].state += (char)count;
            }
        }
    }

}

void reveal_all_tiles(Map* map)
{
    for(int i=0;i<map->height;i++)
    {
        for(int j=0;j<map->width;j++)
        {
            map->grid[i][j].is_visible=true;           
        }     
    }
}

bool all_empty_tiles_visible(const Map* map)
{
    for(int i=0;i<map->height;i++)
    {
        for(int j=0;j<map->width;j++)
        {
            if(map->grid[i][j].state!='X' && map->grid[i][j].is_visible==false)
            {          
                return false;           
            }
        }     
    }
    return true;
}

bool is_bomb_tile(Map* map,	unsigned short int column,	unsigned short int row)
{
        if(row>=map->height || column>=map->width)
        {   
            printf("Error: wrong column or row specified.\n");
            return false;
        }
        
        if(map->grid[row][column].state=='X')
        {
            map->grid[row][column].is_visible = 1;   
            return true;
        }
        else 
        {
            map->grid[row][column].is_visible = 1;
            return false;
        }               
}

        