#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TESTUNIT "buyCard"

void main (int argc, char** argv)	
{
	struct gameState testState;
	int supplyPos = gold;
	
 	printf("----------------- Testing Unit: %s ----------------\n", TESTUNIT);
	//------------Test for not enough coins------------//
	testState.numBuys = 2;
	testState.coins = 4;
	
	printf("\nTesting for not enough coins\n");
 	if(buyCard(supplyPos, &testState) == -1)
		printf("Passed when testing %d coins\n", testState.coins);
	else
		printf("Failed when testing %d coins\n", testState.coins);
	
	//------------Test for exact coins------------//
	testState.numBuys = 2;
	testState.coins = 6;
	
	printf("\nTesting for exact coins\n");
 	if(buyCard(supplyPos, &testState) == 0)
		printf("Passed when testing %d coins\n", testState.coins);
	else
		printf("Failed when testing %d coins\n", testState.coins);
	
	//------------Test for more than enough coins------------//
	testState.numBuys = 2;
	testState.coins = 10;
	
	printf("\nTesting for more than enough coins\n");
 	if(buyCard(supplyPos, &testState) == 0)
		printf("Passed when testing %d coins\n", testState.coins);
	else
		printf("Failed when testing %d coins\n", testState.coins);
	
	//------------Test for not enough buys------------//
	testState.numBuys = 0;
	testState.coins = 10;
	
	printf("\nTesting for not enough buys\n");
 	if(buyCard(supplyPos, &testState) == -1)
		printf("Passed when testing %d buys\n", testState.numBuys);
	else
		printf("Failed when testing %d buys\n", testState.numBuys);
	
	//------------Test for exact buys------------//
	testState.numBuys = 1;
	testState.coins = 10;
	
	printf("\nTesting for not enough buys\n");
 	if(buyCard(supplyPos, &testState) == 0)
		printf("Passed when testing %d buys\n", testState.numBuys);
	else
		printf("Failed when testing %d buys\n", testState.numBuys);
	
	//------------Test for more than enough buys------------//
	testState.numBuys = 10;
	testState.coins = 10;
	
	printf("\nTesting for more than enough buys\n");
 	if(buyCard(supplyPos, &testState) == 0)
		printf("Passed when testing %d buy\n", testState.numBuys);
	else
		printf("Failed when testing %d buys\n", testState.numBuys);
	
		
 	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTUNIT);	
}
