#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义棋盘的大小
char chess_board[5][5];



//棋盘初始化
void start()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            chess_board[row][col] = ' ';
        }
    }

    srand((unsigned int)time(0));
}

//打印棋盘
void display()
{
    int row = 0;

    while(row != 5)
    {
        printf("| %c | %c | %c | %c | %c |\n",
               chess_board[row][0],
               chess_board[row][1], chess_board[row][2],
               chess_board[row][3], chess_board[row][4]);
        printf(" --- --- --- --- --- \n");
        row++;

    }

}
//我方玩家_1出棋
void People()
{
    printf("|玩家_1出棋|\n");
    while (1)
    {
        printf("请输入出棋位置的坐标(row,col):");
        int row = 0;
        int col = 0;
        scanf("%d,%d", &row, &col);

        //检查输入是否有误
        if (row < 0 || row >= 5 || col < 0 || col >= 5)
        {
            printf("坐标超出棋盘范围,请重新输入...\n");
            continue;
        }
        if (chess_board[row][col] != ' ')
        {
            printf("该位置已有棋子!\n");
            continue;
        }
        chess_board[row][col] = 'x';
        break;
    }
    printf("出棋成功!\n");
}
//对方玩家_2出棋
void People_2()
{
    printf("|玩家_2出棋|\n");
    while (1)
    {
        printf("请输入出棋位置的坐标(row,col):");
        int row = 0;
        int col = 0;
        scanf("%d,%d", &row, &col);

        //检查输入是否有误
        if (row < 0 || row >= 5 || col < 0 || col >= 5)
        {
            printf("坐标超出棋盘范围,请重新输入...\n");
            continue;
        }
        if (chess_board[row][col] != ' ')
        {
            printf("该位置已有棋子!\n");
            continue;
        }
        chess_board[row][col] = 'o';
        break;
    }
    printf("出棋成功!\n");
}
//电脑出棋
void Computer()
{
    printf("|玩家_2(电脑)出棋|\n");
    while (1)
    {
        int row = rand() % 5;
        int col = rand() % 5;
        if (chess_board[row][col] != ' ')
        {
            continue;
        }
        chess_board[row][col] = 'o';
        break;
    }
    printf("电脑出棋完毕!\n");
}
//返回值为胜利者代号-x表示玩家胜利-o表示电脑胜利-no无获胜者即和棋

char  CheckWinner()
{
    {
        //检查所有行是否连城一条线
        for (int row = 0; row < 5; ++row)
        {
            if (chess_board[row][0] == chess_board[row][1]
                    && chess_board[row][0] == chess_board[row][2]
                    && chess_board[row][0] == chess_board[row][3]
                    && chess_board[row][0] == chess_board[row][4])
                return chess_board[row][0];
        }
    }
    //检查所有列是否连城一条线
    for (int col = 0; col < 5; ++col)
    {
        if ( chess_board[0][col] == chess_board[1][col]
                && chess_board[0][col] == chess_board[2][col]
                && chess_board[0][col] == chess_board[3][col]
                && chess_board[0][col] == chess_board[4][col])
        {
            return chess_board[0][col];
        }
    }
    //检查所有对角线是否连城一条线
    if (    chess_board[0][0] == chess_board[1][1] &&
            chess_board[0][0] == chess_board[2][2] &&
            chess_board[0][0] == chess_board[3][3] &&
            chess_board[0][0] == chess_board[4][4]      )
    {
        return chess_board[0][0];
    }
    if (    chess_board[0][4] == chess_board[1][3] &&
            chess_board[0][4] == chess_board[2][2] &&
            chess_board[0][4] == chess_board[3][1] &&
            chess_board[0][4] == chess_board[4][0]     )
    {
        return chess_board[0][4];
    }
    //棋盘是否已满
    else
    {

        for (int row = 0; row < 5; ++row)
        {
            for (int col = 0; col < 5; col++)
            {
                if (chess_board[row][col] == ' ')
                {
                    return ' ';
                }
            }
        }
        //如果棋盘已满
        return 'no';

    }

}

//人机大战
void pc_game()
{

    start();//棋盘坐标初始赋值
    char winner = ' ';
    while (1)
    {

        display();//打印棋盘

        People();//我方落子

        winner = CheckWinner();//判断胜负

        if (winner != ' ')//是否有人胜出
        {
            break;
        }

        system("cls");

        Computer(); //电脑落子

        winner = CheckWinner();//判断胜负

        if (winner != ' ')//是否有人胜出
        {
            break;
        }
    }

    if (winner == 'x')
    {
        printf("【游戏结束】\n");
        printf("恭喜你获得胜利!\n");
        system("pause");
        system("cls");
    }
    else if (winner == 'o')
    {
        printf("【游戏结束】\n");
        printf("很遗憾，你输了请多加练习!\n");
        system("pause");
        system("cls");
    }
    else if (winner == 'no')
    {
        printf("【游戏结束】\n");
        printf("旗鼓相当，本局不分胜负!\n");
        system("pause");
        system("cls");
    }
}
//双人大战
void pp_game()
{

    start();//棋盘坐标初始赋值
    char winner = ' ';
    while (1)
    {

        display();//打印棋盘

        People();//玩家1落子
        system("cls");
        display();
        winner = CheckWinner();//判断胜负

        if (winner != ' ')//是否有人胜出
        {
            break;
        }



        People_2(); //玩家2落子
        system("cls");
        winner = CheckWinner();//判断胜负


        if (winner != ' ')//是否有人胜出
        {
            break;
        }
    }

 //   display();//打印游戏结果

    if (winner == 'x')
    {
        printf("【游戏结束】\n");
        printf("恭喜[玩家_1]获得胜利!\n");
        system("pause");
        system("cls");
    }
    else if (winner == 'o')
    {
        printf("【游戏结束】\n");
        printf("恭喜[玩家_2]方获得胜利!\n");
        system("pause");
        system("cls");
    }
    else if (winner == 'no')
    {
        printf("【游戏结束】\n");
        printf("平分秋色，本局不分胜负!\n");
        system("pause");
        system("cls");
    }
}
int main()
{
    printf("+---------------------------------------------------------+\n");
    printf("|                                                         |\n");
    printf("|             欢迎进入欢乐五子棋游戏，祝您游戏愉快！      |\n");
    printf("|                                                         |\n");
    printf("+---------------------------------------------------------+\n");
    system("pause");
    system("cls");



    while(1)
    {
        printf("+----------------------------------+\n");
        printf("|             【模式选择】         |\n");
        printf("|                                  |\n");
        printf("|           1.人机大战             |\n");
        printf("|           2.双人大战             |\n");
        printf("|           0.退出                 |\n");
        printf("|                                  |\n");
        printf("+----------------------------------+\n");
        printf("请输入您的选择:");
        int n = 0;
        scanf("%d", &n);
        system("cls");

        switch(n)
        {
        case 1:

            pc_game();
            break;
        case 2:

            pp_game();
            break;

        case 0:
            printf("再见，欢迎下次再来！\n");
            return 0;

        default:

            printf("输入有误! \n");
            break;



        }
    }

}





