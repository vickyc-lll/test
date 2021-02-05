//
//  game.h
//  比特
//
//  Created by Vickyc on 2021/2/5.
//
//存放一系列声明
#ifndef game_h
#define game_h
#define ROW 3
#define COL 3
#include <stdio.h>
#include"game.h"
#endif /* game_h */
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL],int row,int col);//大写即为宏定义值
void DisplayBoard(char board[ROW][COL],int row,int col);
void playmove(char board[ROW][COL],int row,int col);
void computermove(char board[ROW][COL],int row,int col);
//告诉我们四种游戏的状态
//玩家赢'*'
//电脑赢"#'
//平局  'q'
//游戏继续'c'
char lswin(char board[ROW][COL],int row,int col);
