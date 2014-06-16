#include "Block.h"
#include <time.h>
#include <windows.h>
#include <conio.h>

void storeFunc(Block store, Block present)
{
	Block temp;

	temp = present;

	present = store;

	store = temp;
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

int main(void)
{
	srand((unsigned int)time(NULL)); //난수 시드

	int i = 0, j = 0;

	Block store, next, present;

	int isStored = 0;

	int key = 0;
	
	setcolor(11, 0);

	std::cout << "TETRIS!!" << std::endl;
	std::cout << std::endl;

	setcolor(15, 0);

	std::cout << "▨▤▤▤▤▤▤▤▤▤▤▤▧" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		std::cout << "▥			▥" << std::endl;
	}

	std::cout << "▧▤▤▤▤▤▤▤▤▤▤▤▨" << std::endl;

	gotoxy(30, 0);

	setcolor(11, 0);
	
	std::cout << "Stored Block";

	gotoxy(30, 2);

	setcolor(15, 0);

	std::cout << "▨▤▤▤▤▧";

	for (int i = 3; i < 7; i++)
	{
		gotoxy(30, i);
		std::cout << "▥        ▥";
	}

	gotoxy(30, 7);

	std::cout << "▧▤▤▤▤▨";

	gotoxy(30, 9);

	setcolor(11, 0);

	std::cout << "Next Block";

	setcolor(15, 0);

	gotoxy(30, 11);

	std::cout << "▨▤▤▤▤▧";

	for (int i = 12; i < 16; i++)
	{
		gotoxy(30, i);
		std::cout << "▥        ▥";
	}

	gotoxy(30, 16);

	std::cout << "▧▤▤▤▤▨";

	while (1)	//키 입력
	{

		if (kbhit())
		{
			key = _getch();
			switch (key)
			{
			case 75:
				present.turnLeft();
				break;

			case 77:
				present.turnRight();
				break;
			}
		}
	}

	
}