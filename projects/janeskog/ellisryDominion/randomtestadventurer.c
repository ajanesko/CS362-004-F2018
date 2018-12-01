#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUM_OF_TESTS 10000

int main()
{
	struct gameState G;
	int seed, players = 2, curPlayer = 0, deckSize, handSize, randomCard, randNum, 
		coinCountCur = 0, coinCountBefore = 0, copperTest = 0, silverTest = 0,
		goldTest = 0, passed = 0, failed = 0, result = 1, i, j, x, y, z;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	
	// Set rand seed
	srand(time(NULL));
	
	printf("Begin Running Random Test for Adventurer Card.\n");
	
	for(i = 0; i < NUM_OF_TESTS; i++)
	{
		printf("Test #%d\n", i+1);
		
		// Random seed
		seed = rand() % (5000);
		// Init game
		initializeGame(players, k, seed, &G);
		// Randomize handsize
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize +1);
		
		G.deckCount[0] = deckSize - handSize;
		G.handCount[0] = handSize;
		
		// Randomize players decks
		for(j = 0; j < players; j++)
		{
			// To loop through the players deck to set_new_handler
			for(y = 0; y < G.deckCount[j]; y++)
			{
				// Gen random number to represent num aassoicated with card
				randomCard = rand() % (51);
				// Used to represent random card from k array
				randNum = rand() % (10);
				switch (randomCard)
				{
					case 1:
						G.deck[j][y] = copper;
					case 2:
						G.deck[j][y] = silver;
					case 3:
						G.deck[j][y] = gold;
					default:
						G.deck[j][y] = k[randNum];
				}
			}
		}
		
		// Count coins (copper/silver/gold) for current player
		for(z = 0; z < G.handCount[curPlayer]; z++)
		{
			if(G.hand[curPlayer][z] == copper || G.hand[curPlayer][z] == silver || G.hand[curPlayer][z] == gold)
				coinCountBefore++;
		}
		// Call adventurer card effect
		adventurerEffect(&G);
		// Count coins after effect
		for(z = 0; z < G.handCount[curPlayer]; z++)
		{
			if(G.hand[curPlayer][z] == copper || G.hand[curPlayer][z] == silver || G.hand[curPlayer][z] == gold)
				coinCountCur++;
		}
		
		// Counts the copper, silver, gold discarded
		for(x = 0; x < G.discardCount[curPlayer]; x++)
		{
			switch(G.discard[curPlayer][x])
			{
				case copper:
					copperTest++;
				case silver:
					silverTest++;
				case gold:
					goldTest++;
			}
		}
		// Tests for too many cards
		if(coinCountCur > (coinCountBefore + 2))
		{
			result = 0;
			failed++;
			printf("Too many cards drawn.\n");
		}
		// Tests for too few cards
		if(coinCountCur < coinCountBefore)
		{
			result = 0;
			failed++;
			printf("Too many cards discarded.\n");
		}
		// Tests for copper/silver/gold discard
		if(copperTest > 0)
		{
			result = 0;
			failed++;
			printf("Copper was discarded.\n");
		}
		if(silverTest > 0)
		{
			result = 0;
			failed++;
			printf("Silver was discarded.\n");
		}
		if(goldTest > 0)
		{
			result = 0;
			failed++;
			printf("Gold was discarded.\n");
		}
		// If this was reached, then all tests passed
		if(result)
		{
			passed++;
			printf("All tests have passed.\n");
		}
	}
	
	// Display results
	printf("\n\n# of Tests Passed: %d\n", passed);
	printf("# of Tests Failed: %d\n", failed);
	
	if(passed > failed)
	{
		printf("A majority of the tests passed.\n");
		return 1;
	}
	else
	{
		printf("A majority of the tests failed.\n");
		return 0;
	}
}