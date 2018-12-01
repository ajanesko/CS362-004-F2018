#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TESTUNIT "getCost"

void main (int argc, char** argv)	
{
	int cardNumber;
	
 	printf("----------------- Testing Unit: %s ----------------\n", TESTCARD);
	//------------Test for Curse cost------------//
	cardNumber = curse;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 0)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Estate cost------------//
	cardNumber = estate;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 2)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Duchy cost------------//
	cardNumber = duchy;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 5)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Province cost------------//
	cardNumber = province;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 8)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Copper cost------------//
	cardNumber = copper;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 0)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Silver cost------------//
	cardNumber = silver;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 0)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Gold cost------------//
	cardNumber = gold;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 6)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Adventurer cost------------//
	cardNumber = adventurer;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 6)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Council Room cost------------//
	cardNumber = council_room;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 5)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Feast cost------------//
	cardNumber = feast;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Gardens cost------------//
	cardNumber = gardens;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Mine cost------------//
	cardNumber = mine;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 5)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Remodel cost------------//
	cardNumber = remodel;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Smithy cost------------//
	cardNumber = smithy;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Village cost------------//
	cardNumber = village;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 3)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Baron cost------------//
	cardNumber = baron;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Great Hall cost------------//
	cardNumber = great_hall;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 3)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Minion cost------------//
	cardNumber = minion;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 5)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Steward cost------------//
	cardNumber = steward;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 3)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Tribute cost------------//
	cardNumber = tribute;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 5)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Ambassador cost------------//
	cardNumber = ambassador;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 3)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Cutpurse cost------------//
	cardNumber = cutpurse;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Embargo cost------------//
	cardNumber = embargo;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 2)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Outpost cost------------//
	cardNumber = outpost;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 5)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Salvager cost------------//
	cardNumber = salvager;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Sea Hag cost------------//
	cardNumber = sea_hag;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
	//------------Test for Treasure Map cost------------//
	cardNumber = treasure_map;
	
	printf("\nTesting for %d cost\n", cardNumber);
 	if(getCost(cardNumber) == 4)
		printf("Passed when testing %d cost\n", cardNumber);
	else
		printf("Failed when testing %d cost\n", cardNumber);
	
 	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTUNIT);	
}