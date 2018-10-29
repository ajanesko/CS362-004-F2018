#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TESTUNIT "whoseTurn"

void main (int argc, char** argv)	
{
	struct gameState testState;
	
 	printf("----------------- Testing Unit: %s ----------------\n", TESTCARD);
	//------------Test: Player 1 Turn, Checking if Player 1------------//
	testState.whoseTurn = 0; //Player 1
	
	printf("\nTesting: whoseTurn=Player 1\n");
 	if(whoseTurn(&testState) == 0)
		printf("Passed when testing Player %d coins\n", testState.whoseTurn);
	else
		printf("Failed when testing Player %d coins\n", testState.whoseTurn);
	
	//------------Test: Player 2 Turn, Checking if Player 2------------//
	testState.whoseTurn = 1; //Player 2
	
	printf("\nTesting: whoseTurn=Player 1\n");
 	if(whoseTurn(&testState) == 0)
		printf("Passed when testing Player %d coins\n", testState.whoseTurn);
	else
		printf("Failed when testing Player %d coins\n", testState.whoseTurn);
	
	//------------Test: Player 3 Turn, Checking if Player 3------------//
	testState.whoseTurn = 2; //Player 3
	
	printf("\nTesting: whoseTurn=Player 1\n");
 	if(whoseTurn(&testState) == 0)
		printf("Passed when testing Player %d coins\n", testState.whoseTurn);
	else
		printf("Failed when testing Player %d coins\n", testState.whoseTurn);
	
 	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTUNIT);	
}