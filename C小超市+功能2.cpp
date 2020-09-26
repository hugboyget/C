/*退出时请按0正常退出程序，否则数据将不会被保存*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//颜色
#include<conio.h>//清屏

void Edi_goods();          /*修改*/
void Sell_goods();         /*售货*/
void Return_goods();       /*退货*/
void Add_goods();          /*录入*/
void Del_goods();          /*删除*/
void GongNeng();           /*功能选择*/
void Find_goods();         /*查询*/
int  number = 0;            //商品种类计数
/******************商品结构体*****************/
typedef struct goods
{
    char name[20] ;      /*名称*/

    int id;              /*商品编号*/
    int price;           /*价格*/
    int discount,gcount;        //折扣、总数目

} typel;
typel g[100];
/********************主函数*****************/
int main()
{
    //从文件读入数据
    read_txt();
    while(1)
    {


        printf("+----------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                    |\n");
        printf("|                                           [商品管理系统]                                           |\n");
        printf("|                                                                                                    |\n");
        printf("|                   1. 增加商品                                5. 售货                               |\n");
        printf("|                   2. 查询商品                                6. 退货                               |\n");
        printf("|                   3. 修改商品信息                            7. 修改系统颜色                       |\n");
        printf("|                   4. 删除下架过期商品                        8. 浏览商品信息                       |\n");
        printf("|                                                                                                    |\n");
        printf("|                                                                                                    |\n");
        printf("|                                                                                        [0. 退出]   |\n");
        printf("+----------------------------------------------------------------------------------------------------+\n");

        int a;
        printf("请选择服务，并输入对应数字:\n");
        scanf("%d",&a);
        if(a>8 || a< 0)
        {
            printf("输入有误！请重新输入...\n");//当输入不在0~7范围时。
            scanf("%d",&a);
        }

        switch(a)
        {
        case 1:

            printf("【增加功能】\n");
            Add_goods();
            break;
        case 2:

            printf("【查询功能】\n");
            Find_goods();
            break;

        case 3:

            printf("【修改功能】\n");
            Edi_goods();
            break;
        case 4:

            printf("【删除功能】\n");
            Del_goods();
            break;
        case 5:

            printf("【售货功能】\n");
            Sell_goods();
            break;
        case 6:

            printf("【退货功能】\n");
            Return_goods();
            break;

        case 7:

            printf("【颜色设置】 \n\n");
            set_color();
            break;

       case 8:

            printf("【浏览所有商品信息】 \n\n");
            all_data();
            break;
        case 0:
            //在文件中保存数据
            write_txt();
            printf("[本次操作数据已保存]\n");
            printf("谢谢惠顾，O(∩_∩)O拜拜~\n");
            return 0;

        }
    }

    return 0;

}
/******************从文件读取数据*****************/
void read_txt()
{
     FILE *fp;
     if((fp=fopen("goods_data.txt","rb"))==NULL)

	 {
		 printf("|系统提示：文件中暂无信息！|\n");
	     return;
     }
     int n = 0;
     fscanf(fp,"|>>数据总计 %d 条<<|\n",&n);
	 while(number < n)
      {
      number++;
      fscanf(fp,"商品编号: %d 商品名称: %s 商品价格: %d 商品折扣: %d 商品数目: %d\n"
     ,&g[number].id,&g[number].name,&g[number].price,&g[number].discount,&g[number].gcount);

      }
    fclose(fp);
    return;
}

/******************把数据写入文件*****************/
void write_txt()
{
    FILE*fp;
    if(!(fp=fopen("goods_data.txt","w")))
    {
        printf("打开文件失败！");
        return;
    }
    fprintf(fp,"|>>数据总计 %d 条<<|\n",number);
    int i = 0;
    for(i ; i < number;)
    {
        i++;
        //将对数据的操作（增、删、改）保存
        fprintf(fp,"商品编号: %d 商品名称: %s 商品价格: %d 商品折扣: %d 商品数目: %d\n"
     ,g[i].id,g[i].name,g[i].price,g[i].discount,g[i].gcount);
    }
    fclose(fp);
    return;
}
/****************************修改系统颜色**************************/
void set_color()
{
    int key;
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
/***************************浏览所有商品信息****************************/
void all_data()
{
printf("商品编号         商品名称         商品价格         商品折扣         剩余数目         \n\n");
int a = 0;
for(a; a<=number ;a++)
{

    printf("%d         %s         %d         %d         %d\n\n",g[a].id,g[a].name,g[a].price,g[a].discount,g[a].gcount);

}
printf("共计——[%d]——条信息\n",number);
return 0;
}

/***************************1.【增加功能】****************************/
void Add_goods()
{

    number++;
    int aid;
    printf("请输入商品编号:" );
    scanf("%d",&aid);
    /*验证录入是否重复*/
    int k;
    for( k = 1; k < number ; k++)
    {

        if(aid == g[k].id)
        {
            printf("输入商品重复！\n");
            getchar();
            number--;
            break;
        }
    }

    g[number].id = aid;

    printf("请输入商品名称:");
    scanf("%s",g[number].name);
    printf("请输入商品价格:");
    scanf("%d",&g[number].price);
    printf("请输入商品折扣:");
    scanf("%d",&g[number].discount);
    printf("请输入商品数量:");
    scanf("%d",&g[number].gcount);
    printf("[New_Data]:\n");
    printf("商品编号         商品名称         商品价格         商品折扣         剩余数目         \n\n");
    printf("%d         %s         %d         %d         %d\n\n",g[number].id,g[number].name,g[number].price,g[number].discount,g[number].gcount);
    printf("恭喜，录入商品信息成功！\n");
    system("pause");
    system("cls");
    return;

}
/******************2.商品查询*****************/
void Find_goods()
{
    int iid;
    int p;
    printf("请输入要查询商品编号:");
    scanf("%d",&iid);
    for(p=1; p <= number; p++)
    {
        if(iid == g[p].id)
        {
            break;
        }
        if(p == number)
        {
            printf("【%s】商品不存在\n",iid);

            return;
        }
    }

    printf(">>查询成功!\n");
    printf("商品编号         商品名称         商品价格         商品折扣         剩余数目         \n\n");
    printf("%d         %s         %d         %d         %d\n\n",g[p].id,g[p].name,g[p].price,g[p].discount,g[p].gcount);
    system("pause");
    system("cls");
    return;
}
/*******************3.商品信息修改******************/
void Edi_goods()
{
    int iid;
    int q;
    printf("请输入要修改的商品编号:");
    scanf("%d",&iid);
    for(q = 1; q <= number; q++)
    {
        if(iid == g[q].id)
        {
            break;
        }
        if(q == number)
        {
            printf("未找到该商品【%d】信息\n",iid);
            return;
        }
    }
    printf("新商品编号:");
    scanf("%d",&g[q].id);
    printf("新商品名称:");
    scanf("%s",&g[q].name);
    printf("新商品价格:");
    scanf("%d",&g[q].price);
    printf("新商品折扣:");
    scanf("%d",&g[q].discount);
    printf("新商品数量:");
    scanf("%d",&g[q].gcount);
    printf("修改成功！\n");
    system("pause");
    system("cls");




}

/******************4.商品的删除*****************/
void Del_goods()
{
    int id;
    int i;
    printf("请输入要删除的商品编号:");
    scanf("%d",&id);
    for(i=1; i <= number; i++)                            /*检索商品编号*/
    {
        if(id == g[i].id)
        {
            break;
        }
        if(i == number)                                 /*检索结束未找到信息*/
        {
            printf("未找到该商品【%d】成绩\n",id);
            return;
        }
    }
    int j;
    for(j=i; j <= number; j++)
    {
        g[j]=g[j+1];//把该商品后的数据向前移动1位
    }
    printf("[Old_Data]:\n");
    printf("商品编号         商品名称         商品价格         商品折扣         剩余数目         \n\n");
    printf("%d         %s         %d         %d         %d\n\n",g[i].id,g[i].name,g[i].price,g[i].discount,g[i].gcount);
    number--;//数据组总数减一
    printf("该商品已被删除！\n");
    system("pause");
    system("cls");

    return;
}
/******************5.售货*****************/

void Sell_goods()
{
    printf("[>>>所有商品信息<<<] \n");
    printf("商品编号         商品名称         商品价格         商品折扣         剩余数目         \n\n");
    int k;
    for(k=1; k <= number; k++)
    {
        printf("%d         %s         %d         %d         %d\n\n",g[k].id,g[k].name,g[k].price,g[k].discount,g[k].gcount);
    }
    printf("请输入出售商品名称：");
    char selname[20];
    scanf("%s",selname);
    int i;
    for(i=1; i <= number; i++)                            /*检索商品编号*/
    {
        if(strcmp(selname,g[i].name)==0)
        {

            break;
        }
        if(i == number)                                 /*检索结束未找到信息*/
        {
            printf("未找到该商品【%s】信息\n",selname);
            return;
        }
    }
    printf("请输入出售商品数量：");
    int selcount;
    scanf("%d",&selcount);
    printf("应付款【￥：%d】",g[i].price * selcount);
    g[i].gcount = g[i].gcount -selcount;
    printf("出售完成！");
    system("pause");
    system("cls");
}
/******************6.退货*****************/

void Return_goods()
{
    printf("[>>>所有商品信息<<<] \n");
    printf("商品编号         商品名称         商品价格         商品折扣         剩余数目         \n\n");
    int k;
    for(k=1; k <= number; k++)
    {
        printf("%d         %s         %d         %d         %d\n\n",g[k].id,g[k].name,g[k].price,g[k].discount,g[k].gcount);
    }
    printf("请输入退货商品名称：");
    char returname[20];
    scanf("%s",returname);
    int i;
    for(i=1; i <= number; i++)                            /*检索商品编号*/
    {
        if(strcmp(returname,g[i].name)==0)
        {

            break;
        }
        if(i == number)                                 /*检索结束未找到信息*/
        {
            printf("未找到该商品【%s】信息\n",returname);
            return;
        }
    }
    printf("请输入退货商品数量：");
    int selcount;
    scanf("%d",&selcount);
    printf("应退款【￥：%d】",g[i].price * selcount);
    g[i].gcount = g[i].gcount + selcount;
    printf("退货完成！");
    system("pause");
    system("cls");
}
