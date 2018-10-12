#define _CRT_SECURE_NO_WARNINGS 1 

#include "game.h"
void menu()
{
	printf("***********************\n");
	printf("***1 play       0 exit***\n");
	printf("***********************\n");
}
void game()
{
	int x = 0;
	int y = 0;
	int win = 0;//判定输赢的排雷次数
	int select = 0;//决定游戏功能的变量
	char mine[ROWS][COLS] = { 0 };//存雷的数组（雷盘）
	char show[ROWS][COLS] = { 0 };//展示的数组（雷盘）

	InitBoard(show, ROWS, COLS, '*');//展示的数组（雷盘）初始化为'*'
	InitBoard(mine, ROWS, COLS, '0');//存雷的数字（雷盘）初始化为'0'
	DisplayBoard(show, ROW, COL);//打印雷盘
	SetBoard(mine, ROW, COL, EASY_COUNT);//布雷
	DisplayBoard(mine , ROW, COL); 
	while (win<(ROW*COL - EASY_COUNT))//当排雷的次数不少于无雷格数（雷盘格数 减 雷数）时，停止排雷
	{
		printf("请选择功能：\n1 for 排雷；2 for 标记 3 for 取消标记 4 for 结束游戏  \n");
		scanf("%d", &select);
		fflush(stdin);//清空输入缓冲区，避免多输造成的影响
		if (select == 1)//1 for 排雷
		{
			printf("请输入坐标：\n");
			scanf("%d%d", &x, &y);
			fflush(stdin);//清空输入缓冲区，避免多输造成的影响
			if (x >= 1 && x <= ROW&&y >= 1 && y <= COL)//检验坐标是否合法
			{
				if (mine[x][y] == '1')//如果所选位置有雷，判断是否为第一次排雷
				{
					if (win != 0)//如果不是第一次排雷，宣布游戏结束
					{
						DisplayBoard(mine, ROW, COL);//排雷失败后打印一下雷的分布
						printf("你被炸死了！\n");
						return;
					}
					else//如果是第一次排雷，将这颗雷转移到其他位置，保证第一次不会排到雷
					{
						mine[x][y] = '0';
						SetBoard(mine, ROW, COL, 1);
						expend(mine, show, x, y, &win);
					}
				}
				else//如果所选位置没有雷，进行扩展式排雷
				{
					expend(mine, show, x, y, &win);
				}
				DisplayBoard(show, ROW, COL);//打印排雷后的雷盘
			}
			else
			{
				printf("输入错误坐标：\n");
			}
		}
		else if (select == 2)//2 for 标记
		{
			printf("请输入坐标：\n");
			scanf("%d%d", &x, &y);
			fflush(stdin);//清空输入缓冲区，避免多输造成的影响
			sign(show, x, y);
			DisplayBoard(show, ROW, COL);
		}
		else if (select == 3)//3 for 取消标记
		{
			printf("请输入坐标：\n");
			scanf("%d%d", &x, &y);
			fflush(stdin);//清空输入缓冲区，避免多输造成的影响
			unsign(show, x, y);
			DisplayBoard(show, ROW, COL);
		}
		else if (select == 4)//4 for 结束游戏
		{
			return;
		}

	}
	printf("排雷成功！\n");
}

void test()
{
	int num = 0;
	srand((unsigned int)time(NULL));//产生随机种子，用于随机布雷
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (num);

}


int main()
{
	test();
	return 0;
}
