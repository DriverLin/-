#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"seqList.h"

int main()
{	
	int a;
	start:
	system("cls");
	printf("1.求顺序表中第i个元素,若不存在,报错 \n\n");
	printf("2.在第i个结点前插入值为x的结点\n\n");
	printf("3.删除顺序表中第i个元素结点\n\n");
	printf("4.在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性\n\n");
	printf("5.将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），\n  分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果\n\n");
	printf("6.求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中\n\n");
	printf("7.删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好\n\n");
	printf("0.退出\n\n");
	printf("输入选择:");
	scanf("%d",&a);
   	system("cls");
   	switch(a)
   	{
   	case 1 :
    	printf("1.求顺序表中第i个元素,若不存在,报错\n\n" );
     	_1();
     	system("pause");
     	getchar();
   		goto start;
   	case 2 :
    	printf("2.在第i个结点前插入值为x的结点\n\n" );
    	_2();	
   		system("pause");
   		getchar();
   		goto start;
   	case 3 :
    	printf("3.删除顺序表中第i个元素结点\n\n" );
   		_3();


   		system("pause");
   		getchar();
   		goto start;
   	case 4 :
    	printf("4.在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性\n\n" );
   		_4();


   		system("pause");
   		getchar();
   		goto start;
   	case 5 :
    	printf("5.将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），\n分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果\n\n" );
   		_5();


   		system("pause");
   		getchar();
   		goto start;
   	case 6 :
    	printf("6.求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中\n\n" );
   		_6();


   		system("pause");
   		getchar();
   		goto start;
   	case 7 :
    	printf("7.删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好\n\n" );
   		_7();


   		system("pause");
   		getchar();
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
  


