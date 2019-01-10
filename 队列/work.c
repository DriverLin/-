#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"queueproject.h"

int main()
{	
  int a,i=0;
  start:
  system("cls");
  printf("循环顺序队列实验:\n");
  printf("      11.初始化队列\n");
  printf("      12.判断是否队空\n");
  printf("      13.判断是否队满\n");
  printf("      14.入队\n");
  printf("        出队\n");
  printf("        取队头元素\n");
  printf("        求当前队列中元素个数\n");
  printf("      15.奇数偶数相关\n");
  printf("链队列实验:\n");
  printf("      21.初始化队列\n");
  printf("      22.判断是否队空\n");
  printf("      23.判断是否队满\n");
  printf("      24.入队\n");
  printf("        出队\n");
  printf("        取队头元素\n");
  printf("        求当前队列中元素个数\n");
  printf("      25.奇数偶数相关\n");
  printf("0.退出\n");
  printf("      输入选择:");
  scanf("%d",&a);
  
  system("cls");
    switch(a)
    {
    case 11 :
      printf("1.初始化队列\n" );
      seq_1();
      system("pause");
      getchar();
      goto start;
    case 12 :
      printf("2.判断是否队空\n" );
      seq_2();
      system("pause");
      goto start;
    case 13 :
      printf("3.判断是否队满\n" );
      seq_3();
      system("pause");
      goto start;
    case 14 :
      printf("4.多项目\n" );
      seq_4();
      system("pause");
      goto start;
    case 15 :
      printf("5.奇数偶数相关\n" );
      seq_5();
      system("pause");
      goto start;


    case 21 :
      printf("1.初始化队列\n" );
      link_1();
      system("pause");
      getchar();
      goto start;
    case 22 :
      printf("2.判断是否队空\n" );
      link_2();
      system("pause");
      goto start;
    case 23 :
      printf("3.判断是否队满\n" );
      link_3();
      system("pause");
      goto start;
    case 24 :
      printf("4.多项目\n" );
      link_4();
      system("pause");
      goto start;
    case 25 :
      printf("5.奇数偶数相关\n" );
      link_5();
      system("pause");
      goto start;



    case 0 :
      return 0;
    default :
      printf("无效的选择\n" );
      system("pause");
      getchar();
      goto start;
    }
  system("pause");
  return 0;
}
  
