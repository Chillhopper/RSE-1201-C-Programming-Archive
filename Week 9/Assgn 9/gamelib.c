/*!
@file q.c
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 9
@date 10/11/2022
@brief This file contains functions definitions for del_card(), load_game() and display_game()
*//*________________________________________________________________*/

#include <stdio.h>
#include "gamelib.h"
#include "string.h"

/*!
@brief deletes a card from an array by moving every element over by 1 index
@param word - Card game[], CardIndex position, int size
@return nothing
*//*_____________________________________________________________*/ 
//position should be inclusive of startinh from 0
void del_card(Card game[], CardIndex position, int size){
	int index = size-1;
	for(int i = (int)position; i<index; i++){
		game[i] = game[i+1];
	}
}

/*!
@brief loads data about cards from input into an array of struct Cards each containing value of suit and rank
@param word - const char str[], Card game[]
@return nothing
*//*_____________________________________________________________*/ 
void load_game(const char str[], Card game[]){
	size_t len = strlen(str);
	memset(game, 0, N);
	int count = 0;
	for(size_t i = 0u; i<len-2; i+=3){
		if(1){
			game[count].suit = str[i];
			game[count].rank = str[i+1];

			
			count++;
			

		}
	}

}

/*!
@brief sorts a game of cards according to the rules of Solitaire Accordion
@param word - Card game[]
@return nothing
*//*_____________________________________________________________*/ 
void play_game(Card game[]){
	int size = 0;
	while((char)game[size].rank){
        size++;
    }
	int index = size-1;
	if(index>0){

		for(int i = 0; i<index; i++){
			if(i == 0){
				continue;
			}
			//starts at card index 1
			if(i<=2){
				if(game[i].suit == game[i-1].suit || game[i].rank == game[i-1].rank){
					game[i-1] = game[i];
					del_card(game, (CardIndex)(i), size);

					i = 0;
					index--;
				}
			}

			if(i>=3){
				//compare 3 to left
				if(game[i].suit == game[i-3].suit || game[i].rank == game[i-3].rank){
					game[i-3] = game[i];
					del_card(game, (CardIndex)(i), size);

					i = 0;
					index--;
				}

				//compare 1 to left
				else if(game[i].suit == game[i-1].suit || game[i].rank == game[i-1].rank){
					game[i-1] = game[i];
					del_card(game, (CardIndex)(i), size);

					i = 0;
					index--;
				}else{
					continue;
				}

			}

		} 

		
	}else{
		
		}
}	




/*!
@brief prints all card data inside the array passed in
@param word - const Card game[]
@return nothing
*//*_____________________________________________________________*/ 
void display_game(const Card game[]){
	int size = 0;
	while((char)game[size].rank){
        size++;
    }
	int index = size-1;
	for(int i = 0; i <= index; i++){
		printf("%c%c ", game[i].suit, game[i].rank);
		if(game[i].rank == '0'){
			break;
		}
		
	}
	printf("\n");
}
