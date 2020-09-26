#include<stdio.h>
#include<stdlib.h>//清屏
#include<conio.h>
#include<string.h>
#define i1 cou[i].ID,cou[i].name,cou[i].teacher,cou[i].time,cou[i].course_i,cou[i].count_now,cou[i].count_max
#define k1 cou[k].ID,cou[k].name,cou[k].teacher,cou[k].time,cou[k].course_i,cou[k].count_now,cou[k].count_max
#define p1 cou[p].count_now,cou[p].ID,cou[p].name,cou[p].teacher,cou[p].time,cou[p].course_i,cou[p].count_max
#define p2 cou[p].ID,cou[p].name,cou[p].teacher,cou[p].time,cou[p].course_i,cou[p].count_now,cou[p].count_max
#define m1 cou[m].ID,cou[m].name,cou[m].teacher,cou[m].time,cou[m].course_i,cou[m].count_now,cou[m].count_max
//using namespace std;

int m=0;                     //课程信息数

void get_course();           //选课
void order_course();         //按照选课人数排序
void display_course();       //浏览课程信息
void add_course();           //录入课程信息
void find_course(int key);   //查询课程信息/key=1按照课程名查找/key = 2按照教师名查找
void del_course();           //删除课程信息
void edi_course();           //修改课程信息

void read_txt();             //从那个文件中读取数据
void write_txt();            //把数据写入文件中去



/******************课程结构体*****************/
typedef struct cou
{
    char ID[20];           //课程编号
    char name[20] ;        //课程名称
    char teacher[20];      //授课教师
    char time[20];         //授课时间
    char course_i[20];     //课程备注

    int count_now=0,count_max=0;         //当前选课总总人数/最多可选人数

} typel;
typel cou[100];


/********************主函数******************/
int main()
{
    //从文件读取数据
    read_txt();

    while(1)
    {


        printf("____________________________________________________________________________\n");
        printf("                                                                            \n");
        printf("                          [选修课选课信息管理系统]                          \n");
        printf("                                                                            \n");
        printf("                  1.课程信息录入                  4.删除课程信息            \n");
        printf("                  2.浏览课程信息                  5.修改课程信息            \n");
        printf("                  3.按照教师查询课程信息          6.选课并保存              \n");
        printf("                  7.按照课程编号查询课程信息                                \n");
        printf("                                                         0.[退出系统]       \n");
        printf("____________________________________________________________________________\n");
        int b;
        printf("请选择服务，并输入对应数字:\n");



        scanf("%d",&b);
        getchar();
        switch(b)
        {
        case 1:
            system("cls");
            add_course();
            break;
        case 2:
            system("cls");
            display_course();
            getchar();
            break;
        case 3:
            system("cls");
            find_course(2);
            break;
        case 4:
            system("cls");
            del_course();
            break;
        case 5:
            system("cls");
            edi_course();
            break;
        case 6:
            system("cls");
            get_course();
            break;
        case 7:
            system("cls");
            find_course(1);
            break;
        case 0:
            system("cls");
            //保存操作数据
            write_txt();
            printf("感谢您的使用，本次操作数据已保存！Bye~");
            return 0;
            break;

        }
    }

}
/******************学生选课*****************/
void get_course()           //选课
{
    int i,j;
    int flag = 0;
    char id[20];
    printf("[选择课程]\n");


    display_course();
    if(m==0)
    {
        printf("没有课程可选，请先录入课程信息！");
        getch();
    }
    printf("\n\n请输入要选择的课程编号:");
    scanf("%s",&id);
    for(i=1; i<=m; i++)                      /*检索学号*/
    {
        if(strcmp(id,cou[i].ID)==0)
        {
            flag = 1;
            cou[i].count_now = cou[i].count_now + 1;
            printf("您选择的课程信息如下：\n");
            printf("课程编号          课程名称        授课教师        授课时间         课程备注        可选人数      已选总人数\n\n");
            printf("%s               %s              %s               %s             %s               %d            %d \n",i1);
            printf("选课成功！\n");
            return;

        }
    }
    if(flag == 0)                                 /*检索结束未找到信息*/
    {
        printf("未找到该课程【%s】信息\n",id);
        getch();
        return;
    }

    printf("选课失败！\n");
    return;

}

/******************删除课程信息*****************/
void del_course()
{

    int i,j;
    int flag = 0;
    char id[20];
    printf("[删除课程]\n");


    //display_course();
    if(m==0)
    {
        printf("没有信息可删，请先录入课程信息！");
        getch();
    }
    printf("请输入要删除课程的编号:");
    scanf("%s",&id);
    for(i=1; i<=m; i++)                      /*检索学号*/
    {
        if(strcmp(id,cou[i].ID)==0)
        {
            flag = 1;
            for(j=i; j<=m; j++)
            {
                cou[j]=cou[j+1];//把该学生后的数据向前移动1位
            }

            break;
        }
    }
    if(flag == 0)                                 /*检索结束未找到信息*/
    {
        printf("未找到该课程【%s】信息\n",id);
        getch();
        return;
    }



    m=m-1;//数据组总数减一
    printf("删除成功！\n");
    return;
}

/******************修改课程信息*****************/
void edi_course()
{
    int i,j;
    int flag = 0;
    char id[20];
    printf("[修改课程]\n");


    //display_course();
    if(m==0)
    {
        printf("没有信息可修改，请先录入课程信息！");
        getch();
    }
    printf("请输入要修改课程的编号:");
    scanf("%s",&id);
    for(i=1; i<=m; i++)                      /*检索学号*/
    {
        if(strcmp(id,cou[i].ID)==0)
        {
            flag = 1;
            printf("新课程编号:");
            scanf("%s",cou[i].ID);
            printf("新课程名称:");
            scanf("%s",cou[i].name);
            printf("新授课教师:");
            scanf("%s",cou[i].teacher);
            printf("新授课时间:");
            scanf("%s",cou[i].time);
            printf("新课程备注:");
            scanf("%s",cou[i].course_i);
            printf("新可选人数:");
            scanf("%d",&cou[i].count_max);

            break;

        }
    }
    if(flag == 0)                                 /*检索结束未找到信息*/
    {
        printf("未找到该课程【%s】信息\n",id);
        getch();
        return;
    }


    printf("修改成功！\n");
    return;
}
/******************从文件读取数据*****************/
void read_txt()
{
     FILE *fp;
     if((fp=fopen("course_data.txt","rb"))==NULL)

	 {
		 printf("|系统提示：文件中暂无信息！|\n");
	     return;
     }
     int n = 0;
     fscanf(fp,"|>>数据总计 %d 条<<|\n",&n);
	 while(m < n)
      {
      m++;
      fscanf(fp,"课程编号: %s 课程名称: %s 授课教师: %s 授课时间: %s 可选人数: %d 已选人数: %d 课程备注: %s \n"
     ,&cou[m].ID,&cou[m].name,&cou[m].teacher,&cou[m].time,&cou[m].count_max,&cou[m].count_now,&cou[m].course_i);

      }
    fclose(fp);
    return;
}

/******************把数据写入文件*****************/
void write_txt()
{
    FILE*fp;
    if(!(fp=fopen("course_data.txt","w")))
    {
        printf("打开文件失败！");
        return;
    }
    fprintf(fp,"|>>数据总计 %d 条<<|\n",m);
    for(int i = 0 ; i < m;)
    {
        i++;
        /*将新录入的信息写入指定的磁盘文件*/
        fprintf(fp,"课程编号: %s 课程名称: %s 授课教师: %s 授课时间: %s 可选人数: %d 已选人数: %d 课程备注: %s \n",
        cou[i].ID,cou[i].name,cou[i].teacher,cou[i].time,cou[i].count_max,cou[i].count_now,cou[i].course_i);
    }
    fclose(fp);
    return;
}
/***************************课程信息录入****************************/
void add_course()
{

    printf("|当前已有【%d】条课程信息| \n",m);

    if(m > 30)
    {
        printf(" 储存空间已满！");
        return;
    }
    else
    {
        m++;
    }
    printf("请输入课程编号:");
    scanf("%s",cou[m].ID);
    printf("请输入课程名称:");
    scanf("%s",cou[m].name);
    printf("请输入授课教师:");
    scanf("%s",cou[m].teacher);
    printf("请输入授课时间:");
    scanf("%s",cou[m].time);
    printf("请输入课程备注:");
    scanf("%s",cou[m].course_i);
    printf("请输入可选人数:");
    scanf("%d",&cou[m].count_max);



    return;

}

/******************浏览课程信息成绩*****************/
void display_course()
{
    printf("课程编号          课程名称        授课教师        授课时间         课程备注        可选人数      已选总人数\n\n");

    for(int k=1; k<=m; k++)
    {
        printf("\n");
        printf("%s               %s              %s               %s             %s               %d            %d \n",k1);


    }
    //getchar();
    return;
}
/******************查询课程信息*****************/
void find_course(int key)
{

    int p;
    int flag = 0;
    printf("[课程信息查询]\n");
    if(m==0)
    {

        printf("没有信息可查，请先录入课程！\n");
        getch();
        return;
    }
    if(key == 1)
    {
        char iid[20];
        printf("请输入要查询的课程编号:\n");
        scanf("%s",&iid);
        for(p=1; p<=m; p++)
        {
            if(strcmp(iid,cou[p].ID)==0)
            {
                flag = 1;
                break;
            }
        }
    }
    if(key == 2)
    {
        char teh[20];
        printf("请输入要查询课程的授课教师:\n");
        scanf("%s",&teh);
        for(p=1; p<=m; p++)
        {
            if(strcmp(teh,cou[p].teacher)==0)
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
    {
        printf("查询结果为空！\n");
        getch();
        return ;
    }
    printf(">>查询成功!\n");
    printf("已选总人数           课程编号          课程名称        授课教师        授课时间         课程备注        可选人数      \n\n");
    printf("%d                   %s                %s              %s              %s               %s               %d \n",p1);
    return ;
}
/********************按照选课人数排序******************/
void order_course()
{

    printf("[选课人数排序]\n");

    if(m==0)
    {
        printf("没有信息可排序，请先录入课程！");
        getch();
    }
    typel t;


        for(int w=0; w<m; w++)        /*FOR循环排序*/
        {
            for(int c=w; c<m; c++)
            {
                if(cou[w].count_now<cou[c].count_now)
                {
                    t=cou[w];
                    cou[w]=cou[c];
                    cou[c]=t;
                }
            }
        }



    printf("课程编号          课程名称        授课教师        授课时间         课程备注        可选人数      已选总人数\n\n");

    for (int p=1; p<m; p++)
    {
        printf("%d                %s              %s              %s               %s              %s             %d \n",p1);
    }

    getch();
    return;
}
