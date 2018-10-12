#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//初始化雷盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
	//memset(board, set, row*col*sizeof(board[0][0]));//利用memset初始化
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)//打印雷盘
{
	int i = 0;
	int j = 0;
	printf("  ");//为了打印列坐标时对齐
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);//打印列坐标1 2 3 4 5 6 7 8 9 10
		if (i == col)
		{
			printf("\n");
		}
	}

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行坐标1 2 3 4 5 6 7 8 9 10
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetBoard(char board[ROWS][COLS], int row, int col, int count)//布雷
{
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;//保证行坐标在1到10之间
		y = rand() % col + 1;//保证列坐标在1到10之间
		if (board[x][y] == '0')//判断该位置是否布过雷
		{
			board[x][y] = '1';//‘1’代表有雷
			count--;//布一次雷，雷数减一
		}
	}

}

int GetCount(char board[ROWS][COLS], int x, int y)//统计雷数
{
	return board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0';//将该位置周围八个位置的情况（是否有雷）计数
}

void expend(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y, int *num)//扩展式排雷（递归）
{
	int i = 0;
	int j = 0;
	if (board2[x][y] == '*')//如果该位置字符为'*'，则该位置是未排过的，进行排雷
	{
		(*num)++;//排雷次数加一
		int count = GetCount(board1, x, y);//统计该位置周围的雷数
		if (count != 0)//如果该位置周围的雷数不为0
		{
			board2[x][y] = count + '0';//显示雷数,则该位置的字符不为'*'，可避免下次排雷重复排到该位置
		}
		else//如果该位置的雷数为0，则向它周围八个位置扩展排雷
		{
			board2[x][y] = '0';//该位置的字符显示为‘0’
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)
					{
						if (i != 0 || j != 0)//避免重复排到自己
							expend(board1, board2, x + i, y + j, num);
					}
				}
			}
		}
	}
}

void sign(char board[ROWS][COLS], int x, int y)//用‘@’标记雷
{
	if (board[x][y] == '*')
	{
		board[x][y] = '@';
	}
}

void unsign(char board[ROWS][COLS], int x, int y)//取消标记
{
	if (board[x][y] == '@')
	{
		board[x][y] = '*';
	}
}
