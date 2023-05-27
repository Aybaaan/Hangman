#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

main ()
{
	srand(time(NULL));
	char words[][16] = {"work", "coding", "cat", "dog", 
	                     "boy", "leopard", "ghost", "dragon", 
						 "user", "random", "input"};
	
	// rng generator
	int randomizer = rand()%11;
	int correctflag=0, wordsguessed=0, life=6;
	
	int length = strlen(words[randomizer]);
	int wordposition [8] = {0,0,0,0,0,0,0,0}, loopIndex=0, quit=0, repeat=0;
	int k = 0; //--

	
	// actualguess yung input na ibibigay ng user, playerguess magstore
	char playerguess [16];
	char actualguess;
	char wrongans[5] = {' ',' ',' ',' ',' '};
	char tryagain [3];
	
	//space for randomizer
	
	//printf("%s\n",words[randomizer]);
	
	int random = 0;
		for (loopIndex=0; loopIndex<10; loopIndex++){
			int random = rand ();
			int randomizer = random % 11;
		}
		
//	printf ("Guess the word (type 'quit' to quit the game):");

	//game itself
		while (correctflag<length)
		{
			
	
		printf("H A N G M A N\n\n");
		
		switch(life){
		case 1: printf("+----+\n|  o\n| /|\\ \n|\\/ \n");
				break;
		case 2: printf("+----+\n|  o\n| /|\\ \n|\\ \n ");
				break;
		case 3: printf("+----+\n|  o\n| /| \n|\\ \n");
				break;
		case 4: printf("+----+\n|  o\n| /\n|\\ \n");
				break;
		case 5: printf("+----+\n|  o\n|\n|\\ \n");
				break;
		case 6: printf("+----+\n|  \n|\n|\\ \n");
				break;
		}


		// to show the missed letters
		printf("\n\nMissed letters: ");
			for(loopIndex=0; loopIndex<length; loopIndex++)
				printf("%c ", wrongans[loopIndex]);
		
		// to show the correct letters in the mystery word and its position
		printf("\nMystery word: "); 
		for(loopIndex=0; loopIndex<length;loopIndex++){
			if(wordposition[loopIndex] == 1) 
				printf("%c ", words[randomizer][loopIndex]);
			else 
				printf("_ ");	
		}
			
		printf("\n");
	//	printf ("\nNumbers of letters guessed: %d\n", correctflag);
		printf("Guess a letter: ");
		fgets(playerguess, 16, stdin);
		printf("\n\n");
		actualguess = playerguess [0];	
		wordsguessed = correctflag;
			
	//under game itself: the actual positions of letters are being guessed.
			for (loopIndex=0 ; loopIndex<length; loopIndex++){
				
			// to prevent repetitive inputs
				if (wordposition[loopIndex] == 1){
				continue;
				}
			// for actual input and counting of correct inputs
				if (actualguess == words[randomizer][loopIndex]){
					wordposition[loopIndex] = 1;
					correctflag++;
				}
			}
		
	//For wrong words (counter)
		if (wordsguessed == correctflag){
			life--;
			wrongans[k] = actualguess; 
			k++;
			if (life == 0){
				printf("H A N G M A N\n\n");
				printf("\n+----+\n|  o\n| /|\\ \n|\\/ \\ \n");
				printf ("\nGame Over.\n\n");
				
				// TRY AGAIN TRIGGER
				printf("Would you like to try again? yes/no\n\n");
				fgets (playerguess, 16, stdin);
				
				if (strncmp (playerguess, "no", 2) == 0){
					quit = 1;
					break;
					}
				else if (strncmp(playerguess, "yes", 3) == 0){
					quit = 2;
					break;
					}
				}
		}
		
	}	//while loop end

	if (correctflag == length){
		printf ("\n\nYes! The secret word is '%s'! You have won!\n\n\n", words[randomizer]);
	
	// TRY AGAIN TRIGGER
	
	printf ("Would you like to try again? yes/no \n");
	fgets (playerguess, 16, stdin);
		if (strncmp (playerguess, "no", 2) == 0){
				quit = 1;
			}
		else if (strncmp(playerguess, "yes", 3) == 0){
				quit = 2;
		}
	}
		//for quitting
	
	if (quit == 1){
		printf ("\n\n\nThe user Exited the game.\n");
			system("cls");
			printf("The user has exited the game.");
		return 0;
	}
	else if (quit == 2){
		printf ("\n\n\n");
		system("cls");
		return main (); 
	}
}
