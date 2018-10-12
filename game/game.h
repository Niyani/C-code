#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define ROW 9//雷盘行数
#define COL 9//雷盘列数
#define ROWS ROW+2//数组（实际）行数
#define COLS COL+2//数组（实际）列数
#define EASY_COUNT 10//初级难度的雷数

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化雷盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);//打印雷盘
void SetBoard(char board[ROWS][COLS], int row, int col, int count);//布雷
int GetCount(char board[ROWS][COLS], int x, int y);//统计雷数
void expend(char board1[ROWS][COLS], char board[ROWS][COLS], int x, int y, int *num);//扩展式排雷
void sign(char board[ROWS][COLS], int x, int y);//标记猴头（雷）
void unsign(char board[ROWS][COLS], int x, int y);//取消标记

#endif//__GAME_H__
