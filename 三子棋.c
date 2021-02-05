//
//  三子棋.c
//  比特
//三子棋游戏
//  Created by Vickyc on 2021/2/5.
#include <stdio.h>
#include"game.h"
//菜单栏
void menu()
{
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("^^^1,play^^^0.exit^^^^^^^^\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("九宫格--三子相连即赢！！！！！！\n");
}

//游戏的算法实现
void game()
{
    char ret=0;
    //初始化输赢状态参数
    //数组-存放走出的棋盘的信息
    char board[ROW][COL]={0};
    //初始化棋盘
    InitBoard(board,ROW,COL);
    //打印棋盘--显示棋盘
    DisplayBoard(board,ROW,COL);
    //下棋
    while(1)
    {
        //玩家下棋
        playmove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        //显示棋盘
        //判断玩家是否赢
        ret=lswin(board,ROW,COL);
        if(ret !='c')//如果不是 游戏继续
        {
            break;
        }
        //电脑下棋
        computermove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        //判断电脑是否赢
        ret=lswin(board,ROW,COL);
        if(ret !='c')
        {
            break;
        }
    }
    if(ret=='*')
    {
        printf("玩家赢！\n");
    }
    else if(ret=='#')
    {
        printf("电脑赢！\n");
    }
    else
    {
        printf("平局。\n");
    }
}
void test()
{
    int input=0;
    srand((unsigned int)time(NULL));//随机值
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                printf("三子棋\n");
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误请重新选择!\n");
                break;
        }
    }while(input);
}
int main()
{
    test();
    return 0;
}
