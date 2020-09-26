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
    while(1)
    {


        printf("+--------------------------------------------------------------+\n");
        printf("|                          [超市管理系统]                      |\n");
        printf("|                                                              |\n");
        printf("|                   1. 增加商品                                |\n");
        printf("|                   2. 查询商品                                |\n");
        printf("|                   3. 修改商品信息                            |\n");
        printf("|                   4. 删除下架过期商品                        |\n");
        printf("|                   5. 售货                                    |\n");
        printf("|                   6. 退货                                    |\n");
        printf("|                                                  [0. 退出]   |\n");
        printf("+--------------------------------------------------------------+\n");

        int a;
        printf("请选择服务，并输入对应数字:\n");
        scanf("%d",&a);
        if(a>6 || a< 0)
        {
            printf("输入有误！请重新输入...\n");//当输入不在0~5范围时。
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


        case 0:

            printf("谢谢惠顾，O(∩_∩)O拜拜~\n");
            return 0;

        }
    }

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
