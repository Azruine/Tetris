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
	
	int print()			//ȭ�� ���
	{
		for (int i = 0; i < 16; i++)
		{
			if (this->blockShape[i / 4][i % 4] == 1)
			{
				std::cout << "��" << std::endl;
			}
			else
			{
				std::cout << "��" << std::endl;
			}
		}

		return 1;
	}

	int turnRight()		//������ ���� Ŭ�� ȸ��
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

	int turnLeft()		//���� ���� Ŭ�� ȸ��
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

	int removeVoid()		//���ϴ� ���� ���� �Լ�
	{
		bool checkZero = true;

		int i = 0, j = 0; //���� ����

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

			for (i = 0; i < 4; i++)		//�ӽú��� �ʱ�ȭ
			{
				for (j = 0; j < 4; j++)
				{
					blockShapeTemp[i][j] = this->blockShape[i][j];
				}
			}

			for (i = 0; i < 4; i++)			//������ ���� ���� ���� �ø�
			{
				this->blockShape[0][i] = blockShapeTemp[3][i];
			}

			for (i = 0; i < 3; i++)		//���� ������ ���پ� ����
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