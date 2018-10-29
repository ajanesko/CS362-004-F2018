#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD village

void main() 
{
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player=0;
	struct gameState testState, copy;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Village Card----------\n");

	// copy the game testDtate to a tcopy
	memcpy(&copy, &testState, sizeof(struct gameState));
	cardEffect(TESTCARD, choice1, choice2, choice3, &testState, handPos, &bonus);

	//Set player turn
	player = whoseTurn(&testState);
	
	// Checks if card was drawn
	if((testState->handCount[player]+1) == copy->handCount[player])
	{
		printf("Passed test of village card added to hand.\n");
	}
	else
	{
		printf("Failed test of village card added to hand.\n");
	}
	
	//Checks if the action +2 was added to player
	if((testState.numActions+2) == copy->numActions)
	{
		printf("Passed test of village action added.\n");
	}
	else
	{
		printf("Failed test of village action added.\n");
	}
	
	printf("----------End Testing Village Card----------\n");
}
