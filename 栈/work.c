#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Stackproject.h"

int main()
{	
  int a,i=0;
	start:
	system("cls");
  printf("顺序栈实验:\n\n");
	printf("      1.利用顺序栈实现将10进制数转换为16进制数\n\n");
	printf("      2.对一个合法的数学表达式来说，其中的各大小括号\n        “{”，“}”，“[”，“]”，“(”和“)”应是相互匹配的。\n        设计算法对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的\n\n");
  printf("链栈实验:\n\n");
	printf("      3.利用顺序栈实现将10进制数转换为16进制数\n\n");
	printf("      4.对一个合法的数学表达式来说，其中的各大小括号\n        “{”，“}”，“[”，“]”，“(”和“)”应是相互匹配的。\n        设计算法对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的\n\n");
  printf("0.退出\n\n");
	printf("      输入选择:");
	scanf("%d",&a);
  system("cls");
   	switch(a)
   	{
   	case 1 :
    	printf("1.利用顺序栈实现将10进制数转换为16进制数\n\n" );
     	_1();
     	system("pause");
     	getchar();
   		goto start;
   	case 2 :
    	printf("2.对一个合法的数学表达式来说，其中的各大小括号\n        “{”，“}”，“[”，“]”，“(”和“)”应是相互匹配的。\n        设计算法对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的\n\n" );
    	_2();
   		system("pause");
   		goto start;
   	case 3 :
    	printf("3.利用顺序栈实现将10进制数转换为16进制数\n\n" );
   		_3();
   		system("pause");
   		getchar();
   		goto start;
   	case 4 :
    	printf("4.对一个合法的数学表达式来说，其中的各大小括号\n        “{”，“}”，“[”，“]”，“(”和“)”应是相互匹配的。\n        设计算法对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的\n\n" );
      _4();
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
  
