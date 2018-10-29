#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD adventurer

int main(){
	int assertCheck=0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState testState;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	int checkGameInit, checkActionBefore, checkActionAfter, checkCardBefore, checkCardAfter;
	
	printf("----------------- Testing Card: %s ----------------\n", "adventurer");
	
	initializeGame(numPlayers, k, seed, &testState);
	player = whoseTurn(&testState);

	//Check number of Cards in hand before
	checkCardBefore = testState->handCount[player];
	printf("Check number of cards in hand before\n");
	assert(checkCardBefore >= 0);

	//Play card
	cardEffect(TESTCARD, 0, 0, 0, &testState, 4, 0);
	
	//Check number of Cards in hand after
	checkCardAfter = testState->handCount[player];
	printf("Check number of cards in hand after\n");
	assert(checkCardAfter >= 0);

	//User gets 2 more cards in hand
	printf("Check that hand has two more cards after than before\n");
	if(!(assert(checkCardAfter == (checkCardBefore+2)))
		printf("TEST FAILED.\n");
	else
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}