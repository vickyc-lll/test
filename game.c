//
//  game.c
//  比特
//
//  Created by Vickyc on 2021/2/5.
//
#include<stdio.h>
#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j]=' ';
        }
    }
}
//打印棋盘,显示棋盘中均为空格


void DisplayBoard(char board[ROW][COL],int row,int col)
{
    int i=0;
    for(i=0;i<row;i++)
    {
        //1.打印一行的数据
        int j=0;
        for(j=0;j<col;j++)
        {
            //1.打印一行数据
            printf(" %c ",board[i][j]);
            if(j<col-1)//最后一列不存在|
            printf("|");
        }
        printf("\n");//换行
        //2.打印分割行
        if(i<row-1)
        {
            for(j=0;j<col;j++)
            {
                printf("---");
                if(j<col-1)
                printf("|");
            }
            printf("\n");
        }
    }
}

void playmove(char board[ROW][COL],int row,int col)
{
    int x=0;
    int y=0;
    printf("玩家走\n");
    printf("请输入要下的坐标\n");
    scanf("%d%d",&x,&y);
    //判断x y坐标的合法性
    //用户认为的坐标从1开始所以所有行列全部-1为正常坐标
    while(1)
    {
    if(x>=1&&x<=ROW&&y>=1&&y<=COL)
    {
        if(board[x-1][y-1]==' ')//棋盘内未落子
        {
            board[x-1][y-1]='*';
            break;
        }
        else
        {
            printf("该坐标被占用！\n");
        }
    }
    else
    {
        printf("坐标非法，请重新输入\n");
    }
    }
}

void computermove(char board[ROW][COL],int row,int col)
{
    int x=0;
    int y=0;
    printf("电脑走\n");
    while(1)
    {
    x=rand() % row;//生成随机坐标
    y=rand() % col;
    if(board[x][y]==' ')
    {
        board[x][y]='#';
    break;
    }
    }
    
}

//返回1表示棋盘满了
//返回0表示棋盘没满

int isfull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;//未满
            }
        }
    }
    return 1;//满了
}


char lswin(char board[ROW][COL],int row,int col)
{
    int i=0;
    //横三行
    for(i=0;i<row;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1]!=' ')
        {
            return board[i][1];
        }
    }
    //薯三列
    for(i=0;i<col;i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] !=' ')
        {
            return board[1][i];
        }
    }
    //两个对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] !=' ')
        return board[1][1];
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] !=' ')
        return board[1][1];
    //判断是否平局
    if(1 == isfull(board,ROW,COL))
    {
        return 'q';
    }
    return 'c';
}
