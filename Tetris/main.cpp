#include "Block.h"
#include <time.h>

int storeFunc(Block store, Block present)
{
	Block temp;

	temp = present;

	present = store;

	store = temp;

}

int main(void)
{
	srand((unsigned int)time(NULL)); //난수 시드

	int i = 0, j = 0;

	Block arBlock[7];

	Block store, next, present;

	int isStored = 0;

	std::cout << "▨▤▤▤▤▤▤▤▤▤▤▤▧" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		std::cout << "▥			▥" << std::endl;
	}

	std::cout << "▧▤▤▤▤▤▤▤▤▤▤▤▨" << std::endl;


	for (i = 0; i < 4; i++)		//I shape
	{
		arBlock[0].changeValue(4, i);
	}

	for (i = 0; i < 3; i++)		//T shape
	{
		arBlock[1].changeValue(4, i);
	}
	arBlock[1].changeValue(3, 1);

	for (i = 0; i < 3; i++)		//L shape
	{
		arBlock[2].changeValue(4, i);
	}
	arBlock[2].changeValue(3, 0);

	for (i = 0; i < 3; i++)		//J shape
	{
		arBlock[3].changeValue(4, i);
	}
	arBlock[3].changeValue(3, 2);

	for (i = 0; i < 2; i++)		//S shape
	{
		arBlock[4].changeValue(4, i);
	}
	arBlock[4].changeValue(3, 1);
	arBlock[4].changeValue(3, 2);

	for (i = 1; i < 3; i++)		//Z shape
	{
		arBlock[5].changeValue(4, i);
	}
	arBlock[5].changeValue(3, 0);
	arBlock[5].changeValue(3, 1);

	for (i = 0; i < 2; i++)		//O shape
	{
		arBlock[6].changeValue(4, i);
	}
	arBlock[6].changeValue(3, 0);
	arBlock[6].changeValue(3, 1);
	

	

	
}