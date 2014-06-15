#include <iostream>

class Block
{
public:
	Block(){}
	~Block(){}

	void print()
	{
		for (int i = 0; i < 16; i++)
		{
			if (this->Blockshape[i / 4][i % 4] == 1)
			{
				std::cout << "" << std::endl;
			}
		}
	}

private:
	int** Blockshape[4][4];
};