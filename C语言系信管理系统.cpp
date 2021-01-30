#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>//颜色
#include<conio.h>//清屏
#include<string.h>
#define LEN sizeof(struct student)
#define SDJ stu[k].ID,stu[k].name,stu[k].sex,stu[k].age,stu[k].address,stu[k].score_1,stu[k].score_2
#define DJ stu[p].ID,stu[p].name,stu[p].sex,stu[p].age,stu[p].address,stu[p].score_1,stu[p].score_2
#define dj stu[m].ID,stu[m].name,stu[m].sex,stu[m].age,stu[m].address,stu[m].score_1,stu[m].score_2
using namespace std;

int m = 0;               /*数据条数*/
void PaiXu(int key);    /*排序key = 1按单科成绩排序，key = 2 按平均分成绩排序*/
void XianShi();         /*显示*/
void LuRu();            /*录入*/

void read_txt();//从文件读入数据
void write_txt();//把数据写入文件中去

void ChaXun();          /*查询*/
void color();   /*颜色选择*/

/******************学生结构体*****************/
typedef struct student
{
    char name[20];      /*姓名*/
    char sex[20];        /*性别*/
    char age[20];        /*年龄*/
    char ID[20];         /*学号*/
    char address[20];    /*住址*/
    int score_1, score_2;/*数学，英语*/

} typel;
typel stu[100];


/********************功能选择******************/
int main()
{
    read_txt();
    //getchar();
    while (1)
    {


        printf("+----------------------------------------------------------------------------+\n");
        printf("|                                                                            |\n");
        printf("|                          [欢迎使用信息管理系统]                            |\n");
        printf("|                                                                            |\n");
        printf("|                  1.录入学生成绩                                            |\n");
        printf("|                  2.输出文件中数据                                          |\n");
        printf("|                  3.查询学生成绩                                            |\n");
        printf("|                  4.按照单科成绩排名                                        |\n");
        printf("|                  5.修改系统风格                                            |\n");
        printf("|                  6.按学生平均分排序                                        |\n");
        printf("|                                                            0.[退出系统]    |\n");
        printf("+----------------------------------------------------------------------------+\n");
        int b;
        printf("请选择服务，并输入对应数字:\n");



        scanf_s("%d", &b);
        getchar();
        switch (b)              /*选择功能*/
        {
        case 1:
            system("cls");
            LuRu();
            break;
        case 2:
            system("cls");
            XianShi();
            break;
        case 3:
            system("cls");
            ChaXun();
            break;
        case 4:
            system("cls");
            PaiXu(1);
            break;
        case 5:
            system("cls");
            color();
            break;
        case 6:
            system("cls");
            PaiXu(2);
            break;
        case 0:
            system("cls");
            printf("本次操作数据已保存！");
            write_txt();
            return 0;
            break;

        }
    }

}
/******************颜色选择*****************/
void color()
{
    int key;
    printf("【颜色设置】 \n\n");
    printf("[背景颜色]");
    printf("0.黑底白字____1.红色______2.粉色_______3.黄色_____\n\n");
    printf("[字体颜色]");
    printf("0.黑底白字____4.红色______5.粉色_______6.黄色_____\n\n");
    scanf_s("%d", &key);
    if (key == 0)
    {
        system("color 0F");   //原色
    }
    //背景色
    if (key == 1)
    {
        system("color 04");   //红
    }
    if (key == 2)
    {
        system("color 05");   //粉
    }
    if (key == 3)
    {
        system("color 06");   //黄
    }
    //字体色
    if (key == 4)
    {
        system("color 4F");   //红
    }
    if (key == 5)
    {
        system("color 5F");   //粉
    }
    if (key == 6)
    {
        system("color 6F");   //黄
    }

    return;
}
/******************从文件读取数据*****************/

void read_txt()
{
    m = 1;

    FILE* fp;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("|系统提示：文件student.txt中暂无数据|\n\n");
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        fscanf_s(fp, "%s", &stu[i].ID);
        //fscanf(fp,"%s",&stu[i].name);
        //fscanf(fp,"%s",&stu[i].sex);
        //fscanf(fp,"%s",&stu[i].age);
        //fscanf(fp,"%s",&stu[i].address);

        //fscanf(fp,"%d",&stu[i].score_1);
        //fscanf(fp,"%d",&stu[i].score_2);
    }
    fclose(fp);        /*关闭文件防止信息丢失*/
    return;
}
/******************把数据写入文件*****************/
void write_txt()
{
    FILE* fp;
    if (!(fp = fopen("student.txt", "w")))
    {
        printf("打开文件失败！");
        exit(1);
    }

    for (int i = 1; i <= m; i++)
    {
        /*将新录入的信息写入指定的磁盘文件*/
        fprintf(fp, "%s", stu[i].ID);
        fprintf(fp, "%s", stu[i].name);
        fprintf(fp, "%s", stu[i].sex);
        fprintf(fp, "%s", stu[i].age);
        fprintf(fp, "%s", stu[i].address);
        fprintf(fp, "%d", stu[i].score_1);
        fprintf(fp, "%d", stu[i].score_2);
    }
    fclose(fp);
    return;
}
/***************************成绩录入****************************/
void LuRu()
{
    m++;

    printf("请输入学号:");
    scanf_s("%s", stu[m].ID);
    printf("请输入姓名:");
    scanf_s("%s", stu[m].name);
    printf("请输入性别:");
    scanf_s("%s", stu[m].sex);
    printf("请输入年龄:");
    scanf_s("%s", stu[m].age);
    printf("请输入地址:");
    scanf_s("%s", stu[m].address);
    printf("请输入文化课成绩:");
    scanf_s("%d", &stu[m].score_1);
    printf("请输入英专业课成绩:");
    scanf_s("%d", &stu[m].score_2);


    return;

}

/******************显示成绩*****************/
void XianShi()
{
    printf("学号/姓名/性别/年龄/地址/score—1/score-2 \n\n");

    for (int k = 1; k <= m; k++)
    {
        printf("\n");
        printf("%s %s %s %s %s %d %d \n", SDJ);

    }
    getchar();
}
/******************成绩查询*****************/
void ChaXun()
{

    int p;
    char iid[20];
    printf(">>成绩查询<<\n");
    if (m == 0)
    {
        printf("没有成绩可查，请先录入成绩！\n");
        _getch();
        return;
    }
    printf("请输入要查询学生的学号:\n");
    scanf_s("%s", &iid);
    int flag = 0;
    for (p = 1; p <= m; p++)
    {
        if (strcmp(iid, stu[p].ID) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("【%s】成绩不存在\n", iid);
        _getch();
        return;
    }
    printf(">>查询成功!\n");
    printf("学号/姓名/性别/年龄/地址/score—1/score-2\n");
    printf("%s %s %s %s %s %d %d\n", DJ);
    return;
}
/********************成绩排序******************/
void PaiXu(int key)
{

    printf(">>成绩排序<<\n");

    if (m == 0)
    {
        printf("没有成绩可排序，请先录入成绩！");
        _getch();
    }
    typel t;

    if (key == 1)//按照单科成绩排序
    {
        for (int w = 0; w < m; w++)        /*FOR循环排序*/
        {
            for (int c = w; c < m; c++)
            {
                if (stu[w].score_1 < stu[c].score_1)
                {
                    t = stu[w];
                    stu[w] = stu[c];
                    stu[c] = t;
                }
            }
        }
    }
    if (key == 2)//按平均分成绩排序
    {
        int p = 0, q = 0;
        for (int w = 0; w < m; w++)        /*FOR循环排序*/
        {
            for (int c = w; c < m; c++)
            {
                //计算平均分
                p = (stu[w].score_1 + stu[w].score_2) / 2;
                q = (stu[c].score_1 + stu[c].score_2) / 2;

                if (p < q)
                {
                    t = stu[w];
                    stu[w] = stu[c];
                    stu[c] = t;
                }
            }
        }
    }

    printf("学号/姓名/性别/年龄/地址/score—1/score-2\n");
    printf("%s%s%s%s%s%d%d\n", dj);
    for (int s = 1; s < m; s++)
    {
        printf("%s%s%s%s%s%d%d\n", dj);
    }

    _getch();
    return;
}
