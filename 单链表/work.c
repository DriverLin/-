#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"linkedList.h"

int main()
{	
	int a;
	start:
	system("cls");
	printf("1.尾插法创建单链表，打印创建结果\n\n");
	printf("2.头插法创建单链表，打印创建结果\n\n");
	printf("3.销毁单链表\n\n");
	printf("4.求链表长度\n\n");
	printf("5.求单链表中第i个元素（函数），若不存在，报错\n\n");
	printf("6.在第i个结点前插入值为x的结点\n\n");
	printf("7.链表中查找元素值为x的结点，成功返回结点指针，失败报错\n\n");
	printf("8.删除单链表中第i个元素结点\n\n");
	printf("9.在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性\n\n");
	printf("10.将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），\n   分别放入新的单链表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果\n\n");
	printf("11.求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中\n\n");
	printf("12.删除递增有序单链表中的重复元素，要求时间性能最好\n\n");
	printf("13.递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，\n   并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点，\n   要求时间性能最好\n\n");
	printf("0.退出\n\n");
	printf("输入选择:");
	scanf("%d",&a);
   	system("cls");
   	switch(a)
   	{
   	case 1 :
    	printf("1.尾插法创建单链表，打印创建结果\n\n" );
     	_1();
     	system("pause");
     	getchar();
   		goto start;
   	case 2 :
    	printf("2.头插法创建单链表，打印创建结果\n\n" );
    	_2();	
   		system("pause");
   		getchar();
   		goto start;
   	case 3 :
    	printf("3.销毁单链表\n\n" );
   		_3();
   		system("pause");
   		getchar();
   		goto start;
   	case 4 :
    	printf("4.求链表长度\n\n" );
   		_4();
   		system("pause");
   		getchar();
   		goto start;
   	case 5 :
    	printf("5.求单链表中第i个元素（函数），若不存在，报错\n\n" );
   		_5();
   		system("pause");
   		getchar();
   		goto start;
   	case 6 :
    	printf("6.在第i个结点前插入值为x的结点\n\n" );
   		_6();
      printf("=========================\n");
      _6();
      printf("=========================\n");
      _6();
      printf("=========================\n");
      _6();
      printf("=========================\n");
      _6();
      printf("=========================\n");
      _6();
      printf("=========================\n");
       _6();
      printf("=========================\n");
   		system("pause");
   		getchar();
   		goto start;
   	case 7 :
    	printf("7.链表中查找元素值为x的结点，成功返回结点指针，失败报错\n\n" );
   		_7();
   		system("pause");
   		getchar();
   		goto start;
   	case 8 :
    	printf("8.删除单链表中第i个元素结点\n\n" );
   	  _8();
      printf("=========================\n");
      _8();
      printf("=========================\n");
      _8();
      printf("=========================\n");
      _8();
      printf("=========================\n");
      _8();
      printf("=========================\n");
       _8();
      printf("=========================\n");
   		system("pause");
   		getchar();
   		goto start;
   	case 9 :
    	printf("9.在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性\n\n" );
   		_9();
      printf("=========================\n");
      _9();
      printf("=========================\n");
      _9();
      printf("=========================\n");
      _9();
      printf("=========================\n");
   		system("pause");
   		getchar();
   		goto start;
   	case 10 :
    	printf("10.将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），\n   分别放入新的单链表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果\n\n" );
   		_10();
      printf("=========================\n");
      _10();
      printf("=========================\n");
   		system("pause");
   		getchar();
   		goto start;
   	case 11 :
    	printf("11.求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中\n\n" );
   		_11();
      printf("=========================\n");
      _11();
      printf("=========================\n");
      _11();
      printf("=========================\n");
   		system("pause");
   		getchar();
   		goto start;
   	case 12 :
    	printf("12.删除递增有序单链表中的重复元素，要求时间性能最好\n\n" );
   		_12();
      printf("=========================\n");
      _12();
      printf("=========================\n");
      _12();
      printf("=========================\n");
   		system("pause");
   		getchar();
   		goto start;
   	case 13 :
    	printf("13.递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，\n   并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点，\n   要求时间性能最好\n\n" );
   		_13();
      printf("=========================\n");
      _13();
      printf("=========================\n");
      _13();
      printf("=========================\n");
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
  


