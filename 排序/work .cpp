#include<stdio.h>
#include<malloc.h>
#include"sort.h"
#include<math.h>
#include<time.h>
int main()
{
  int a;
	start:
	system("cls");
	printf("1.快排演示\n\n");
	printf("2.数组调整\n\n");
	printf("3.shell排序算法\n\n");
	printf("4.演示快排\n\n");
	printf("5.堆排序动态演示\n\n");
	printf("6.二路归并排序\n\n");
	printf("0.退出\n\n");
  printf("输入选择:");
	scanf("%d",&a);
  //a=4;
   	system("cls");
   	//a=1;
   	switch(a)
   	{
   	case 1 :
    	printf("1.快排演示\n");
     	_1();
      system("pause");
     	//getchar();
   		goto start;
   	case 2 :
    	printf("2.数组调整\n");
    	_2(1);
      _2(2);
      _2(3);	
   		system("pause");
   		goto start;
   	case 3 :
    	printf("3.shell排序算法\n");
   		_3();
   		system("pause");
   		//getchar();
   		goto start;
   	case 4 :
    	printf("4.演示快排\n");
   		_4();
   		system("pause");
   		//getchar();
   		goto start;
   	case 5 :
    	printf("5.堆排序动态演示\n");
   		_5();
   		system("pause");
   		//getchar();
   		goto start;
    case 6 :
      printf("6.二路归并排序\n");
      _6();
      system("pause");
      //getchar();
      goto start;
  system("pause");
      //getchar();
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


