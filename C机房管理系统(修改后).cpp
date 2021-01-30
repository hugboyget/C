#include<stdio.h>
#include<stdlib.h>//颜色
#include<conio.h>//清屏
#include<string.h>//字符串操作
#define k1 stu[k].name,stu[k].hour_1,stu[k].minute_1,stu[k].hour_2,stu[k].minute_2,money
#define k2 stu[k].hour_1,stu[k].minute_1,stu[k].hour_2,stu[k].minute_2,hour_0,minute_0,stu[k].name
#define p1 stu[p].ID,stu[p].name,stu[p].clas,stu[p].hour_1,stu[p].minute_1,stu[p].hour_2,stu[p].minute_2

using namespace std;

int m = 0;               /*数据条数*/

void dis_play(int key);  /*显示*/
void add_stu();          /*录入学生信息*/
void find_stu();         /*查询*/


/******************学生结构体*****************/
typedef struct student
{
    char ID[20];           /*学号*/
    char name[20];         /*姓名*/
    char clas[20];         /*班级*/

    int hour_1, hour_2,minute_1,minute_2;  /*上机时-分，下机时-分*/

} typel;
typel stu[100];


/********************功能选择******************/
int main()
{
    while (1)
    {


        printf("+----------------------------------------------------------------------------+\n");
        printf("|                                                                            |\n");
        printf("|                          [机房管理系统]                                    |\n");
        printf("|                                                                            |\n");
        printf("|                  1.录入学生信息                                            |\n");
        printf("|                  2.查询学生上机时间                                        |\n");
        printf("|                  3.计算学生上机费用                                        |\n");
        printf("|                  4.机器使用情况记录                                        |\n");
        printf("|                                                            0.[退出系统]    |\n");
        printf("+----------------------------------------------------------------------------+\n");
        int n;
        printf("请选择服务，并输入对应数字:\n");
        scanf("%d", &n);

        getchar();//停顿

        switch (n)              /*选择功能*/
        {
        case 1:
            system("cls");
            add_stu();
            system("cls");
            break;
        case 2:
            system("cls");
            find_stu();
            system("cls");
            break;
        case 3:
            system("cls");
            dis_play(1);//key = 1代表显示上机费用
            system("cls");
            break;
        case 4:
            system("cls");
            dis_play(2);//key = 2代表显示记录
            system("cls");
            break;
        case 0:
            printf("Bye~");
            return 0;
            break;
        default:
            printf("输入错误！,重新输入...\n");
            break;
        }
    }

}

/***************************上机信息录入****************************/
void add_stu()
{
    m++;
    printf("________________________|>>信息录入<<|_________________________\n\n");
    printf("请输入学号:");
    scanf("%s", stu[m].ID);
    printf("请输入姓名:");
    scanf("%s", stu[m].name);
    printf("请输入班级:");
    scanf("%s", stu[m].clas);

    printf("[请输入上机时间]\n");
    printf("请输入上机时刻/时:");
    scanf("%d", &stu[m].hour_1);
    printf("请输入上机时刻/分::");
    scanf("%d", &stu[m].minute_1);

    printf("[请输入下机时间]\n");
    printf("请输入下机时刻/时:");
    scanf("%d", &stu[m].hour_2);
    printf("请输入下机时刻/分::");
    scanf("%d", &stu[m].minute_2);

    printf(">>录入完成!\n");
    system("pause");
    return;

}

/******************打印信息*****************/
void dis_play(int key)
{
    printf("________________________|>>数据信息如下<<|__________________________\n\n");
    if(key == 1)//打印上机费用数据
    {
        printf("姓名         上机时刻         下机时刻         上机费用/元   \n\n");
        for (int k = 1; k <= m; k++)
        {
            //计算上机费用
            int money;
            money = stu[k].hour_2 - stu[k].hour_1 + (stu[k].minute_2 - stu[k].minute_1)/60;
            if(money <= 1)//时间不够一小时按一小时计算
            {
                money = 1;
            }
            printf("\n");

            printf("%s           %d 时 %d 分            %d 时 %d 分         %d 元 \n",k1);

        }
        system("pause");
        return;
    }
    //默认打印机器使用情况
    printf("开机时刻   ---   关机时刻   ---   连续使用时间   ---   使用者姓名   \n\n");
    for (int k = 1; k <= m; k++)
    {
        //计算使用时长
        int hour_0,minute_0;
        hour_0 = stu[k].hour_2 - stu[k].hour_1;
        minute_0 = stu[k].minute_2 - stu[k].minute_1;
        printf("\n");

        printf("%d 时 %d 分   ---   %d 时 %d 分    ---   %d 时 %d 分   ---    %s \n",k2);

    }
    system("pause");
    return;
}
/******************信息查询*****************/
void find_stu()
{

    int p;
    char cond[20];//查询条件
    printf("\n");
    printf("+------------------------------|>>信息查询<<|-------------------------------------+\n");

    if (m == 0)
    {
        printf("没有信息可查，请先录入信息！\n");
        getch();
        return;
    }

    int flag = 0;
    while (1)
    {



        printf("|  1.按学号查询           2.按姓名查询           3.按班级查询                     |\n");
        printf("+--------------------------------------------------------------0.[返回] ----------+\n");
        int n;
        printf("请选择查询条件，并输入对应数字:\n");
        scanf("%d", &n);

        getchar();//停顿

        switch (n)              /*选择功能*/
        {
        case 1:
            system("cls");
            printf("请输入要查询学生的学号:\n");
            scanf("%s", &cond);

            for (p = 1; p <= m; p++)
            {
                if (strcmp(cond, stu[p].ID) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            system("cls");
            break;
        case 2:
            system("cls");
            printf("请输入要查询学生的姓名:\n");
            scanf("%s", &cond);

            for (p = 1; p <= m; p++)
            {
                if (strcmp(cond, stu[p].name) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            system("cls");
            break;
        case 3:
            system("cls");
            printf("请输入要查询学生的班级:\n");
            scanf("%s", &cond);
            printf(">>查询成功!\n");
             printf("学号             姓名             班级              上机记录\n\n");
            for (p = 1; p <= m; p++)
            {
                if (strcmp(cond, stu[p].clas) == 0)
                {


                    printf(" %s              %s                 %s               %d 时 %d 分~ %d 时 %d 分\n", p1);
                    //flag = 1;

                }
            }
            system("pause");
            system("cls");
            return;

        case 0:
            //return;
            break;
        default:
            printf("输入错误！,重新输入...\n");
            break;

        }
        break;
    }

    if (flag == 0)
    {
        printf("学生【%s】上机数据不存在！\n", cond);
        getch();
        return;
    }
    printf(">>查询成功!\n");
    printf("学号             姓名             班级              上机记录\n\n");
    printf(" %s              %s                 %s               %d 时 %d 分~ %d 时 %d 分\n", p1);
    system("pause");

    return;
}
