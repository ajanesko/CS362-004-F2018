#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD smithy

void main() 
{
    int seed = 1000;
    int numPlayers = 2;
	struct gameState testState, copy;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int cardsInHandBefore;
	int cardsInHandAfter;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &testState);

	printf("\n----------Testing Smithy Card----------\n");

	// copy the game testDtate to a tcopy
	memcpy(&copy, &testState, sizeof(struct gameState));

	//Set player turn
	player = whoseTurn(&testState);
	
	//Check number of cards in players hand before
	cardsInHandBefore = testState->handCount[player];
	printf("Checking number of cards in hand before\n");
	assert(cardsInHandBefore >= 0);
	
	//Card effect
	cardEffect(TESTCARD, 0, 0, 0, &testState, 4, 0);
	
	//Check number of cards in players hand after
	cardsInHandBefore = testState->handCount[player];
	printf("Checking number of cards in hand after is 2 greater\n");
	assert(cardsInHandAfter == (cardsInHandBefore+2));	
	
	//Discard Test: Check if card was discarded
	if(testState.discardCount[player] != copy.discardCount[player])
		printf("Smithy discarded successfully, Smithy fully successfuly\n");	
	else
		printf("Smithy discard failed\n");
	
	printf("----------End Testing Smithy Card----------\n");
}
