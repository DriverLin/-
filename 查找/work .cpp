#include<stdio.h>
#include<malloc.h>
#include"Find.h"
#include<math.h>
int main()
{
  int a;
	start:
	system("cls");
	printf("1.二分查找算法实现查找\n\n");
	printf("2.在二叉排序树中插入结点并实现构建二叉排序树\n\n");
	printf("3.设计算法在二叉排序树中查找指定值的结点\n\n");
	printf("4.求森林叶子结点数\n\n");
	printf("5.设计算法以构造一棵平衡的二叉排序树来存放该数组中的所有元素\n\n");
	printf("0.退出\n\n");
	printf("输入选择:");
	scanf("%d",&a);

   	system("cls");
   	//a=1;
   	switch(a)
   	{
   	case 1 :
    	printf("1.二分查找算法实现查找\n");
     	_1();
     	//system("pause");
     	getchar();
   		goto start;
   	case 2 :
    	printf("2.在二叉排序树中插入结点并实现构建二叉排序树\n");
    	_2();	
   		//system("pause");
   		getchar();
   		goto start;
   	case 3 :
    	printf("3.设计算法在二叉排序树中查找指定值的结点\n");
   		_3();
   		//system("pause");
   		getchar();
   		goto start;
   	case 4 :
    	printf("4.设计算法在二叉排序树中删除特定值的结点\n");
   		_4();
   		//system("pause");
   		getchar();
   		goto start;
   	case 5 :
    	printf("5.设计算法以构造一棵平衡的二叉排序树来存放该数组中的所有元素\n");
   		_5();
   		//system("pause");
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


