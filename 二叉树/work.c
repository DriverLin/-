#include<stdio.h>
#include<malloc.h>
#include"BitTree.h"
//static Funnnnn=0;




int main()
{
  int a;
	start:
	system("cls");
	printf("1.打印出二叉树的三种遍历序\n\n");
	printf("2.设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数\n\n");
	printf("3.求二叉树的高度\n\n");
	printf("4.求二叉树的结点数\n\n");
	printf("5.求二叉树的叶子结点数\n\n");
	printf("6.求二叉树的度为2的结点数\n\n");
	printf("7.键盘输入一个元素x，求其父节点、兄弟结点、子结点的值\n\n");
	printf("8.键盘输入一个元素x，求其在树中的层次\n\n");
	printf("9.将按顺序方式存储在数组中的二叉树转换为二叉链表形式\n\n");
	printf("10.交换二叉树中每个结点的左右孩子指针的值\n\n");
	printf("0.退出\n\n");
	printf("输入选择:");
	scanf("%d",&a);
   	system("cls");
   	switch(a)
   	{
   	case 1 :
    	printf("1.打印出二叉树的三种遍历序\n\n");
     	_1();
     	//system("pause");
     	getchar();
   		goto start;
   	case 2 :
    	printf("2.设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数\n\n");
    	_2();	
   		//system("pause");
   		getchar();
   		goto start;
   	case 3 :
    	printf("3.求二叉树的高度\n\n");
   		_3();
   		//system("pause");
   		getchar();
   		goto start;
   	case 4 :
    	printf("4.求二叉树的结点数\n\n");
   		_4();
   		//system("pause");
   		getchar();
   		goto start;
   	case 5 :
    	printf("5.求二叉树的叶子结点数\n\n");
   		_5();
   		//system("pause");
   		getchar();
   		goto start;
   	case 6 :
    	printf("6.求二叉树的度为2的结点数\n\n");
   		_6();
   		//system("pause");
   		getchar();
   		goto start;
   	case 7 :
    	printf("7.键盘输入一个元素x，求其父节点、兄弟结点、子结点的值\n\n");
   		_7();
   		//system("pause");
   		getchar();
   		goto start;

	case 8 :
    	printf("8.键盘输入一个元素x，求其在树中的层次\n\n");
   		_8();
   		//system("pause");
   		getchar();
   		goto start;
   	case 9 :
    	printf("9.将按顺序方式存储在数组中的二叉树转换为二叉链表形式\n\n");
   		_9();
   		//system("pause");
   		getchar();
   		goto start;
    case 10 :
    	printf("10.交换二叉树中每个结点的左右孩子指针的值\n\n");
   		_10();
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



int _1()//打印
{
	printMarkAndTree();
	
	int mark;
	char A[10000]={'^'};
	star_1:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();

	printf("  先序遍历:");
  	PreTravle(T,T);
  	printf("\n");
  	printf("  中序遍历:");
  	InTravle(T);
  	printf("\n");
  	printf("  后序遍历:");
  	PostTravle(T);
  	printf("\n    交换:");
  	PreTravleFun(T,A,1);
  	puts(A);
  	printf("\n===========\n");
  	goto star_1; 
}

int _2()//中序 节点层数
{
	printMarkAndTree();
	
	int mark;
	star_2:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();
	InTravleAndPutHeight(T);
	printf("\n===========\n");
	goto star_2;
}

int _3()//高度
{
	printMarkAndTree();
	
	int mark;
	star_3:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();
  	printf("先序为:");
  	PreTravle(T);
	printf("  高度=%d",getMaxHeight(T));
	printf("\n===========\n");
	goto star_3;
}

int _4()//节点数
{
	printMarkAndTree();
	
	int mark;
	star_4:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();

	printf("  先序遍历:");
  	PreTravle(T);
  	NodeNumber = 0;
  	NodeCount(T);
  	printf("  节点数=%d\n",NodeNumber);
  	printf("\n===========\n");
  	goto star_4; 
}

int _5()//叶子节点数
{
	printMarkAndTree();
	
	int mark;
	star_5:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();

	printf("  先序遍历:");
  	PreTravle(T);
  	leafnode = 0;
  	LeafNodeCount(T);
  	printf("  叶子节点数=%d\n",leafnode);
  	printf("\n===========\n");
  	goto star_5; 
}

int _6()//2度节点数
{
	printMarkAndTree();
	
	int mark;
	star_6:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();

	printf("  先序遍历:");
  	PreTravle(T);
  	twonode = 0;
  	twoNodeCount(T);
  	printf("  2度节点数=%d\n",twonode);
  	printf("\n===========\n");
  	goto star_6; 
}

int getMaxHeight(BitTree *T){
	int left ,right ;
	if(T == NULL) return 0;
	left = getMaxHeight(T->lChild);
	right = getMaxHeight(T->rChild);
	if(left>right)
		return left+1;
	else 
		return right+1;
}

int _7()//求他全家
{
	printMarkAndTree();
	
	int mark;
	char x;
	choosetree:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();
	printf("  先序遍历:");
  	PreTravle(T);
 	getchar();
  	star_7:
  	printf("\n输入X,回车重新选择树:");
  	scanf("%c",&x);
  	if(x == '\n'){ 
  		printf("\n重新选择树");	
  		goto choosetree;
  	}
  	iFlag = 0;
  	if(FamilyList(T,x) != 1)
  		printf("Not Exist\n");
	printf("\n===========\n");
	getchar();
	goto star_7;
}

int _8()//求层次
{
	printMarkAndTree();
	int mark;
	char x;
	choosetree:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();
	printf("  先序遍历:");
  	PreTravle(T);
  	star_8:
  	getchar();
  	printf("\n输入X,回车重新选择树:");
  	FindFlag = 0;
  	scanf("%c",&x);
  	if(x == '\n'){ 
  		printf("\n重新选择树");	
  		goto choosetree;
  	}
  	FindXAndPutLevel(T,x);
  	if(FindFlag == 0)
  		printf("NotFound!\n");  	
  	printf("===========\n");
  	goto star_8; 
}

int _9(){
	char a[80],temp;
	int i,j,level,count;
	extern char strLine[1000][3];
	star_9:
	system("cls");
	i=1;
	j=0;
	level=0;
	count=1;
	nArrLen = 0,iCount = 0,level = 0,NodeNumber = 0,leafnode = 0,twonode= 0,iFlag = 0,FindFlag = 0;
	ExM = 0;
	printf("输入顺序存储二叉树,^补齐:");
	for(i=1;a[i-1]!='\n';i++){
		a[i] = getchar();
	}
	while(count<=i-2){
		count*=2;
		level++;
	}
 	ExchangeSeqroAnother(1,a,i);
 	/*printf("下面是strlin\n");
 	while(j<10){
 		printf("strLine[%d][0]=%c\n",j,strLine[j][0]);
 		j++;
 	}*/
 	BitTree *T = PreCreateBitreeFromRAM();
 	delNullNode(T);
	printf("  先序遍历:");
  	PreTravle(T);
  	printf("\n输入0返回 其他任意键退出");
  	if(getchar() == '0'){
  	  		getchar();
  	 		goto star_9;}
 	else
		return 0;
}

int _10()//交换值
{
	printMarkAndTree();
	int mark;
	star_3:
	printf("\n输入序号,输入-1返回:");
	reEnter:
	scanf("%d",&mark);
	if(mark == -1) return 0;
	if(mark > 11 || mark <-1){
		printf("输入错误！重新输入:");
		goto reEnter;
	}
	ReadFileToRAM(mark);
  	BitTree *T = PreCreateBitreeFromRAM();
  	printf("先序为:");
  	PreTravle(T);
  	ExchangeChild(T);
  	printf("\n交换完成\n交换后");
	printf("先序为:");
  	PreTravle(T);
	printf("\n===========\n");
	goto star_3;
}

int InTravleAndPutHeight(BitTree *T)//中序遍历同时返回层数  
{
	if(T == NULL) return ;
	level++;
	InTravleAndPutHeight(T->lChild);
	putchar(T->data);
	printf("---%d\n", level);
	InTravleAndPutHeight(T->rChild);
	level--;
	return ;
}

int NodeCount(BitTree *T)//节点数是全局变量NodeNumber
{
	if(T == NULL) return 0;
	NodeNumber++;
	NodeCount(T->lChild);
	NodeCount(T->rChild);
	return 0;
}


int LeafNodeCount(BitTree *T)//叶子节点数是全局变量leafnode
{
	if(T == NULL) return 0;
	if(T->lChild == NULL && T->rChild ==NULL)
		leafnode++;
	LeafNodeCount(T->lChild);
	LeafNodeCount(T->rChild);
	return 0;
}

int twoNodeCount(BitTree *T)//初始传入0
{
	if(T == NULL) return 0;
	if(T->lChild != NULL && T->rChild !=NULL)
		twonode++;
	twoNodeCount(T->lChild);
	twoNodeCount(T->rChild);
	return 0;
}

int FamilyList(BitTree *T,char x)//先序遍历
{
	int f,b;
	if(T == NULL) return iFlag;
	if(T->data == x)//ROOT就是X  需要单独处理
	{
		f = 0;//f赋值0 代表FatherNode不存在 
		b = -1;
		goto notFun;
	}
	if(T->lChild != NULL){
		if(T->lChild->data == x){
			f = 1;// FatherNode存在
			b = 0;//b=0 代表值为X的节点是T的lChild 兄弟节点就是rChild
			goto notFun;
		}
	}

	if(T->rChild != NULL){
		if(T->rChild->data == x){
			f = 1;
			b = 1;//b=1 代表值为X的节点是T的rChild 兄弟节点就是lChild
			goto notFun;
		}
	}

	goto fun;//递归中跳过
	//====================================
	notFun:
	iFlag = 1;
	if(f==0){
		printf("  FatherNodeNotExist!\n");
		printf("  BrotherNodeNotExist!\n");
		if(T->lChild->data != NULL)
			printf("  lChildNode=%c \n",T->lChild->data);
		else
			printf("  lChildNodeNotExist!\n");	
		if(T->rChild->data != NULL)
			printf("  rChildNode=%c \n",T->rChild->data);
		else
			printf("  rChildNode\n");
		return iFlag;
	}
	
	else//F=1有FatherNode  执行下面 
	{
		printf("  FatherNode=%c\n",T->data);
		if(b==0){
			if(T->rChild!=NULL)
				printf("  RightBrotherNode=%c\n",T->rChild->data);
			else
				printf("  RightBrotherNodeNotExist!\n");



			if(T->lChild->lChild != NULL)
				printf("  lChildNode=%c \n",T->lChild->lChild->data);
			else
				printf("  lChildNodeNotExist!\n");
			if(T->lChild->rChild != NULL)
				printf("  rChildNode=%c \n",T->lChild->rChild->data);
			else
				printf("  rChildNodeNotExist!\n");

		}
		else{
			if(T->lChild!=NULL)
				printf("  LeftBrotherNode=%c\n",T->lChild->data);
			else
				printf("  LeftBrotherNodeNotExist!\n");



			if(T->rChild->lChild != NULL)
				printf("  lChildNode=%c \n",T->rChild->lChild->data);
			
			else
				printf("  lChildNodeNotExist!\n");


			if(T->rChild->rChild != NULL)
				printf("  rChildNode=%c \n",T->rChild->rChild->data);
			else
				printf("  rChildNodeNotExist!\n");
		}
	}
	return iFlag;
	//=====================================

	fun:
	FamilyList(T->lChild,x);
	FamilyList(T->rChild,x);
	return iFlag;
}




int FindXAndPutLevel(BitTree *T,char x)//中序遍历同时返回层数  
{
	if(T == NULL) return ;
	level++;
	if(T->data == x){
		printf("%c---%d\n", x,level);
		FindFlag = 1;
	}
	FindXAndPutLevel(T->lChild,x);
	
	FindXAndPutLevel(T->rChild,x);
	level--;
	return ;
}


int ExchangeSeqroAnother(int i,char a[],int max){
	if(i >= max-1){
		strLine[ExM][0] = '^';
		strLine[ExM][1] = 0;
		strLine[ExM][2] = 0;
		ExM++;
		//printf("此时 ExM=%d，a[%d]=^ 返回\n",ExM,i);
		return 0;
	}
	strLine[ExM][0] = a[i];
	strLine[ExM][1] = 1;
	strLine[ExM][2] = 1;
	ExM++;
	//printf("此时 ExM=%d，a[%d]=%c \n",ExM,i,strLine[ExM][0]);
	ExchangeSeqroAnother(2*i,a,max);
	ExchangeSeqroAnother(2*i+1,a,max);
	return 0;
}

int delNullNode(BitTree *T)//删除^节点
{
	if(T == NULL) return 0;
	delNullNode(T->lChild);
	delNullNode(T->rChild);
	if(return10(T->lChild)) T->lChild = NULL;
	if(return10(T->rChild)) T->rChild = NULL;
	return 0;
}

int return10(BitTree *T)
{
	if(T == NULL) return 0;
	if(T->data == '^') 
		return 1;
	else 
		return 0;
}

int ExchangeChild(BitTree *T)//交换
{
	if(T == NULL) return;
	ExchangeChild(T->lChild);
	ExchangeChild(T->rChild);
	BitTree *temp;
	temp = T->lChild;
	T->lChild = T->rChild;
	T->rChild = temp;
	return ;
}

S.node[parent].parent

pTree


int TransForm(BitTree *T,pTree *S,int i,int p){
	if(T==NULL) return 0;
	S.node[i].data = T->data;
	if( i==0 ) S.node[i].parent = -1;
	else S.node[i].parent = p; 
	TransForm(T->lChild,S,***,i);
	TransForm(T->lChild,S,***,S.node[i].parent);
}