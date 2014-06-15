#include <iostream>
#include <string.h>

class Block
{
public:
	Block()
	{
		for (int i = 0; i < 4; i++)
		{
			memset(this->blockShape[i], 0, sizeof(int)*4);
		}
	}
	~Block(){}

	void changeValue(int i, int j)
	{
		this->blockShape[i][j] = 1;

		return;
	}
	
	int print()			//화면 출력
	{
		for (int i = 0; i < 16; i++)
		{
			if (this->blockShape[i / 4][i % 4] == 1)
			{
				std::cout << "■" << std::endl;
			}
			else
			{
				std::cout << "□" << std::endl;
			}
		}

		return 1;
	}

	int turnRight()		//오른쪽 방향 클릭 회전
	{
		int blockShapeTemp[4][4];

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				blockShapeTemp[i][j] = this->blockShape[i][j];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->blockShape[i][j] = blockShape[j][3 - i];
			}
		}

		return 1;
	}

	int turnLeft()		//왼쪽 방향 클릭 회전
	{
		int blockShapeTemp[4][4];

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				blockShapeTemp[i][j] = this->blockShape[i][j];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->blockShape[i][j] = blockShape[3-j][i];
			}
		}

		return 1;
	}

	int removeVoid()		//최하단 공백 제거 함수
	{
		bool checkZero = true;

		int i = 0, j = 0; //루프 변수

		int blockShapeTemp[4][4];

		while (true)
		{

			for (j = 0; j < 4; j++)
			{
				checkZero = checkZero && (this->blockShape[i][j] = 0);
			}


			if (!checkZero)
			{
				break;
			}

			for (i = 0; i < 4; i++)		//임시변수 초기화
			{
				for (j = 0; j < 4; j++)
				{
					blockShapeTemp[i][j] = this->blockShape[i][j];
				}
			}

			for (i = 0; i < 4; i++)			//마지막 줄을 제일 위로 올림
			{
				this->blockShape[0][i] = blockShapeTemp[3][i];
			}

			for (i = 0; i < 3; i++)		//남은 세줄을 한줄씩 내림
			{
				for (j = 0; j < 4; j++)
				{
					this->blockShape[i + 1][j] = blockShapeTemp[i][j];
				}
			}
		}

		return 1;

	}

private:
	int blockShape[4][4];
};