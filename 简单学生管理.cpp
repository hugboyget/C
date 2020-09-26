#include<stdio.h>
#include<string.h>


void XiuGai();          /*修改*/
void XianShi();         /*显示*/
void LuRu();            /*录入*/
void ShanChu();         /*删除*/
void GongNeng();        /*功能选择*/
void read_txt();        /*读入数据*/
void ChaXun();          /*查询*/
int number = 0;//计数
/******************学生结构体*****************/
typedef struct student
{
    char name[20] ;      /*姓名*/

    int id;             /*学号*/

    int score;           /*成绩*/

} typel;
typel stu[10];
/********************主函数*****************/
int main()
{
    while(1)
    {


        printf("+--------------+\n");
        printf("|  1. 增加功能 |\n");
        printf("|  2. 查询功能 |\n");
        printf("|  3. 修改功能 |\n");
        printf("|  4. 删除功能 |\n");
        printf("|  5. 输出功能 |\n");
        printf("|  0. 退出     |\n");
        printf("+--------------+\n");

        int a;
        printf("请选择服务，并输入对应数字:\n");
        scanf("%d",&a);
        if(a>5 || a< 0)
        {
            printf("输入有误！请重新输入...\n");//当输入不在0~5范围时。
            scanf("%d",&a);
        }

        switch(a)
        {
        case 1:

            printf("【增加功能】\n");
            LuRu();
            break;
        case 2:

            printf("【查询功能】\n");
            ChaXun();
            break;

        case 3:

            printf("【修改功能】\n");
            XiuGai();
            break;
        case 4:

            printf("【删除功能】\n");
            ShanChu();
            break;
        case 5:

            printf("【输出功能】\n");
            XianShi();
            break;

        case 0:

            printf("谢谢惠顾，O(∩_∩)O拜拜~\n");
            return 0;

        }
    }

    return 0;

}
/***************************从文件读入数据****************************/
void read_txt()
{
    /*从文件中读入数据*/

    FILE *file;                 //定义文件指针
    //file = fopen("step1/data.txt","r");//以只读的方式打开文件
    file = fopen("data.txt","r");
    int i = 0;
    while(1)
    {
        i++;
        fscanf(file,"%d %s %d",&stu[i].id,&stu[i].name,&stu[i].score);
        //printf("%d \n",i);
        if(i == 5 )
        {

            fclose(file);
            number = 5;
            break;
        }

    }
    return;
}
/***************************录入-【增加功能】****************************/
void LuRu()
{


    read_txt();

    printf("请输入录入学生的数量:");
    int n;
    //printf("001\n");
    scanf("%d",&n);

    if (n <= 0 || n > 10 - number)
    {
        printf("输入错误，或储存空间不足！\n");
    }
    else
    {


        while(number <= 10 && number-5 < n)/*录入学生信息*/
        {

            number++;

            int iid;
            printf("请输入第%d个学生的学号:", number-5 );
            scanf("%d",&iid);
            /*验证录入是否重复*/
            for(int k = 1; k < number ; k++)
            {
                //printf("- %d -",number);
                //printf("- %d -",k);
                if(iid == stu[k].id)
                {
                    printf("输入学号重复！重新输入！\n");
                    number--;
                    break;
                }
                else if(k == number-1)  //说明已经遍历所有数据，未重复
                {
                    stu[number].id = iid;

                    printf("请输入第%d个学生的姓名:", number-5 );
                    scanf("%s",stu[number].name);

                    printf("请输入第%d个学生的成绩:", number-5 );
                    scanf("%d",&stu[number].score);
                    //printf("001");
                    break;

                }


            }




        }
    }

    printf("恭喜，录入学生成绩成功！\n");
    XianShi();


}
/******************成绩的删除*****************/
void ShanChu()
{
    int id;
    int i=1;
    printf("请输入要删除学生的学号:");
    scanf("%d",&id);
    for(i; i <= number; i++)                      /*检索学号*/
    {
        if(id == stu[i].id)
        {
            break;
        }
        if(i == number)                                 /*检索结束未找到信息*/
    {
        printf("未找到该学生【%s】成绩\n",id);
        return;
    }
    }

    for(int j=i; j <= number; j++)
    {
        stu[j]=stu[j+1];//把该学生后的数据向前移动1位
    }
    number--;//数据组总数减一
    XianShi();
    printf("删除成功！\n");


    return;
}
/******************显示成绩*****************/

void XianShi()
{
    printf("[>>>目前已有 %d 位学生的信息<<<] \n",number);
    printf("%10s  %16s  %12s\n", "学号", "姓名", "成绩");

    for(int k=1; k <= number; k++)
    {
        printf("%10d%20s%10d\n", stu[k].id, stu[k].name, stu[k].score);
    }
}
/******************成绩查询*****************/
void ChaXun()
{
    int iid;
    int p;
    printf("请输入要查询学生的学号:");
    scanf("%d",&iid);
    for(p=1; p <= number; p++)
    {
        if(iid == stu[p].id)
        {
            break;
        }
        if(p == number)
        {
            printf("【%s】成绩不存在\n",iid);

            return;
        }
    }

    printf(">>查询成功!\n");
    printf("%10s  %16s  %12s\n", "学号", "姓名", "成绩");
    printf("%10d  %20s  %10d\n", stu[p].id, stu[p].name, stu[p].score);
    return;
}
/*******************成绩修改******************/
void XiuGai()
{
    XianShi();
    int iid;
    int q;
    printf("请输入要修改学生的学号:");
    scanf("%d",&iid);
    for(q = 1; q <= number; q++)
    {
        if(iid == stu[q].id)
        {
            break;
        }
        if(q == number)
    {
        printf("未找到该学生【%d】成绩\n",iid);
        return;
    }
    }
    printf("请输入学号:");
    scanf("%d",&stu[q].id);
    printf("请输入姓名:");
    scanf("%s",&stu[q].name);
    printf("请输入成绩:");
    scanf("%d",&stu[q].score);
    XianShi();
    printf("修改成功！\n");




}
