#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#include"Graph.h"
//#include"createGrpAdjMatrix.h"
//#include"grpAdjMatrix.h"
int main()
{
  int a;
	start:
	system("cls");
	printf("1.打印出图（网）的两种遍历序\n\n");
	printf("2.求给定图中的边（或弧）的数目\n\n");
	printf("3.DFS生成森树\n\n");
	printf("4.BFS生成树\n\n");
	printf("5.Prim算法\n\n");
	printf("6.Kruskal算法\n\n");
	printf("7.Dijkstra算法\n\n");
  printf("8.Floyd算法\n\n");
  printf("9.拓扑序列\n\n");
  printf("10.AOE网的关键路径\n\n");
  printf("0.退出\n\n");
  printf("输入选择:");
	scanf("%d",&a);
  //a=10;
   	system("cls");
   	//a=1;
   	switch(a)
   	{
   	case 1 :
    	printf("1.两种遍历序\n");
     	_1();
      system("pause");
     	//getchar();
   		goto start;
   	case 2 :
    	printf("2.求给定图中的边（或弧）的数目\n");
      _2();	
   		system("pause");
   		goto start;
   	case 3 :
    	printf("3.DFS生成树\n");
   		_3();
   		system("pause");
   		//getchar();
   		goto start;
   	case 4 :
    	printf("4.BFS生成树\n");
   		_4();
   		system("pause");
   		//getchar();
   		goto start;
   	case 5 :
    	printf("5.Prim算法\n");
   		_5();
   		system("pause");
   		//getchar();
   		goto start;
    case 6 :
      printf("6.Kruskal算法\n");
      _6();
      system("pause");
      //getchar();
      goto start;
    case 7 :
      printf("7.Dijkstra算法\n");
      _7();
      system("pause");
      //getchar();
      goto start;
    case 8 :
      printf("8.Floyd算法\n");
      _8();
      system("pause");
      //getchar();
      goto start;
    case 9 :
      printf("9.拓扑序列\n");
      _9();
      system("pause");
      //getchar();
      goto start;
     case 10 :
      printf("10.AOE网的关键路径\n");
      _10();
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


