#define MAXLEN 100
#include <iostream>

using namespace std;
typedef struct
{
	int data[MAXLEN];
	int length;
}List;

typedef struct node{
	int key;
	struct node *lchild,*rchild;
}Bnode;



typedef int dataType;
 
#define EH 0       //左右子树一样高
#define LH 1       //左子树比右子树高
#define RH -1      //右子树比左子树高
 
 
//定义节点结构
typedef struct Node {
	dataType keyValue;             //数据
	int BalanceFactor;             //平衡因子
	struct Node *leftChild, *rightChild;
}*PNode;




//为新建一个节点
PNode createNode(dataType keyValue) {
	PNode newNode = (PNode)malloc(sizeof(Node));
	newNode->keyValue = keyValue;
	newNode->BalanceFactor = EH;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}
 

 
//右旋 顺时针旋转
void R_Rotate(PNode* node) {
	PNode tmp = (*node)->leftChild;
	(*node)->leftChild = tmp->rightChild;
	tmp->rightChild = (*node);
    (*node) = tmp;
}
 
//左旋，逆时针旋转
void L_Rotate(PNode* node) {
	PNode tmp = (*node)->rightChild;
	(*node)->rightChild = tmp->leftChild;
	tmp->leftChild = (*node);
	(*node) = tmp;
}
 
//左边失衡调整
void leftBalance(PNode* node) {
	PNode leftchild = (*node)->leftChild;
	PNode tmpRightChild = NULL;
	switch (leftchild->BalanceFactor) 
	{
	case LH:                                                                     //LL型失衡
		(*node)->BalanceFactor = leftchild->BalanceFactor = EH;
		 R_Rotate(node);
		 break;
	case RH:                                                                    //LR型失衡
		tmpRightChild = leftchild->rightChild;
		switch (tmpRightChild->BalanceFactor)
		{
		case LH:
			(*node)->BalanceFactor = RH;
			leftchild->BalanceFactor = EH;
			break;
		case EH:
			(*node)->BalanceFactor = leftchild->BalanceFactor = EH;
			break;
		case RH:
			(*node)->BalanceFactor = EH;
			leftchild->BalanceFactor = LH;
			break;
		}
		tmpRightChild->BalanceFactor = EH;
		L_Rotate(&(*node)->leftChild);
		R_Rotate(node);
		break;
	}
}
 
 
//右边失衡调整
void rightBalance(PNode* node) {
	PNode rightchild = (*node)->rightChild;
	PNode tmpChild = NULL;
	switch (rightchild->BalanceFactor)
	{
	case RH:                                                                          //RR型失衡
		(*node)->BalanceFactor = rightchild->BalanceFactor = EH;
		L_Rotate(node);
		break;
	case LH:                                                                         //RL型失衡
		tmpChild = rightchild->leftChild;
		switch (tmpChild->BalanceFactor)
		{
		case LH:
			(*node)->BalanceFactor = EH;
			rightchild->BalanceFactor = RH;
			break;
		case EH:
			(*node)->BalanceFactor = rightchild->BalanceFactor = EH;
			break;
		case RH:
			(*node)->BalanceFactor = EH;
			rightchild->BalanceFactor = LH;
			break;
		}
		tmpChild->BalanceFactor = EH;
		R_Rotate(&(*node)->rightChild);
		L_Rotate(node);
		break;
	}
}
 
 
//插入新值,higher用于判定是否需要调整平衡因子
int InsertKeyValue(PNode* node, dataType keyValue,bool* higher) {
	if ((*node) == NULL) {                                    //树中不包含此键值，则新建一个节点，
		(*node) = createNode(keyValue);
		*higher=true;
	}
	else if ((*node)->keyValue == keyValue) {                //树中已经包含此键值，则不需要插入
		*higher = false;
		return 0;
	}
	else if (keyValue < (*node)->keyValue) {                  //插入到左子树中
		if (!InsertKeyValue(&(*node)->leftChild, keyValue, higher))   //如果左子树中存在该节点
			return 0;
		if (*higher) {   
			switch ((*node)->BalanceFactor)
			{
			case LH:
				leftBalance(node);
				*higher = false;
				break;
			case RH:
				(*node)->BalanceFactor = EH;
				*higher = false;
				break;
			case EH:
				(*node)->BalanceFactor = LH;
				*higher = true;
				break;
			}
		}
	}
	else {
		if (!InsertKeyValue(&(*node)->rightChild, keyValue,higher))   //如果右子树中存在该节点
			return 0;
		if (*higher) {
			switch ((*node)->BalanceFactor)
			{
			case LH:                                                  
				(*node)->BalanceFactor = EH;
				*higher = false;
				break;
			case RH:
				rightBalance(node);
				*higher = false;
				break;
			case EH:
				(*node)->BalanceFactor = RH;
				*higher = true;
				break;
			}
		}
	}
	return 1;
}



void ReadFile(List &l,int Mark)//读取预先存放的数据
{
	FILE *pFile;
	int i=1;
	char fileMark[7][80];
    sprintf(fileMark[0],"W:\\ListData\\1.List",80);
    sprintf(fileMark[1],"W:\\ListData\\1.List",80);
    sprintf(fileMark[2],"W:\\ListData\\2.List",80);
    sprintf(fileMark[3],"W:\\ListData\\3.List",80);
    sprintf(fileMark[4],"W:\\ListData\\4.List",80);
    sprintf(fileMark[5],"W:\\ListData\\5.List",80);
    sprintf(fileMark[6],"W:\\ListData\\6.List",80);
    pFile = fopen(fileMark[Mark],"r");
    if(!pFile){
		printf("Open Failed!\n");
		return ;
	}
	while(fscanf(pFile,"%d,",&l.data[i]) != EOF){
		i++;
	}
	l.length=--i;
	fclose(pFile);	
	return ;
}

void PrintList(List &l)//打印数据
{
	int i=1;
	printf("序号: ");
	while(i!=l.length+1){
		printf("%3d ",i);
		i++;
	}
	printf("\n数值: ");
	i=1;
	while(i!=l.length+1){
		printf("%3d ",l.data[i]);
		i++;
	}
	printf("\n");
}

void BinarySearch(List &l,int num,int low,int high)//表指针 查找的数字 头 尾
{	
	int mid;
	mid=(low+high)/2;
	printf("(%d,%d)\t\t",low,high);
	if(num>l.data[high]){
		printf("NotFound!\n");
		return;
	}
	if(num == l.data[mid]){
		printf("Data[%d]=%d\n",mid,l.data[mid]);
		return;
	}
	if(low>high){
		printf("NotFound!\n");
		return;
	}
	if(num > l.data[mid])
		BinarySearch(l,num,mid+1,high);
	else
		BinarySearch(l,num,low,mid-1);
}

void InsrtNode(Bnode *T,int i){
	Bnode *newnode;
	newnode=(Bnode *)malloc(sizeof(Bnode));
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	newnode->key=i; 
	while(1){
		if(T->key > i){
			if(T->lchild != NULL)
				T = T->lchild;
			else{
				T->lchild = newnode;
				return;
			}
		}
		else{
			if(T->rchild != NULL)
				T = T->rchild;
			else{
				T->rchild = newnode;
				return;
			}
		}
	}
}

void inTravel(Bnode *T){
	if(T==NULL) return;
	inTravel(T->lchild);
	printf("%d ",T->key);
	inTravel(T->rchild);
}
void printfTree(PNode T){
	if(T==NULL) return ;
	printf("%3d ",T->keyValue);
	printfTree(T->leftChild);
	printfTree(T->rightChild);
}

void BinarySortTreeSearch(Bnode *T,int num){
	if(T==NULL){
		printf("NotFound");
		return;
	}
	if(T->key == num){
		printf("Found!");
		return;
	}
	if(T->key >num)
		BinarySortTreeSearch(T->lchild,num);
	else
		BinarySortTreeSearch(T->rchild,num);
}

int	DelData(Bnode *T,int num){
	int iFlag = -1;
	Bnode *headdle;
	if(T->key == num)
		goto headdle;
	while(1){

		if(T->key > num){
			T=T->lchild;
		}
		else
			T=T->rchild;
		if(T==NULL){
			return 0;
		}
		if(T->lchild!=NULL&&T->lchild->key == num){
			iFlag = 1;
			break;
		}

		if(T->rchild!=NULL&&T->rchild->key == num){
			iFlag = 0;
			break;
		}

		
	}

	goto pass;
	headdle:
		if(T->lchild == NULL)//头lch	ild左孩子空
		{
			T->key = T->rchild->key;
			T->lchild = T->rchild->lchild;
			T->rchild = T->rchild->rchild;
			return 1;
		}
		if(T->rchild == NULL)//头rchild右孩子空
		{
			T->key = T->rchild->key;
			T->lchild = T->lchild->lchild;
			T->rchild = T->lchild->rchild;
			return 1;
		}
		headdle=T->lchild;//向左，然后向右找到最低的节点，值替换head，然后删除最低节点
		if(headdle->lchild==NULL&&headdle->rchild==NULL)//左边去了 然后是叶子节点
		{
			T->key=headdle->key;
			T->lchild=NULL;
			return 1;
		}

		while(headdle->rchild->lchild!=NULL&&headdle->rchild->rchild!=NULL){
			headdle=headdle->rchild;
		}
		T->key=headdle->lchild->key;
		headdle->rchild=NULL;
		return 1;
	pass:
		if(iFlag==1)//删除T的左孩子 lchild
		{
			if(T->lchild->lchild==NULL&&T->lchild->rchild==NULL)//左孩子是叶子节点直接删除
			{
				T->lchild=NULL;
				return 1;
			}
			if(T->lchild->lchild==NULL)//左孩子（要删除节点）的左孩子空
			{
				T->lchild=T->lchild->rchild; //直接接上右孩子
				return 1;
			}
			if(T->lchild->lchild==NULL)//左孩子（要删除节点）的右孩子空
			{
				T->lchild=T->lchild->lchild; //直接接上左孩子
				return 1;
			}
			//到了这里应该左右的都不为空
			headdle=T->lchild->lchild;//向左，然后向右找到最低的节点，值替换，然后删除最低节点
			while(headdle->lchild->lchild!=NULL&&headdle->lchild->rchild!=NULL){
				headdle=headdle->rchild;
			}
			T->lchild->key=headdle->lchild->key;
			headdle->lchild=NULL;
			return 1;
		}
		else
		{
			if(T->rchild->lchild==NULL&&T->rchild->rchild==NULL)//左孩子是叶子节点直接删除
			{
				T->rchild=NULL;
				return 1;
			}
			if(T->rchild->lchild==NULL)//左孩子（要删除节点）的左孩子空
			{
				T->rchild=T->rchild->rchild; //直接接上右孩子
				return 1;
			}
			if(T->rchild->lchild==NULL)//左孩子（要删除节点）的右孩子空
			{
				T->rchild=T->rchild->lchild; //直接接上左孩子
				return 1;
			}
			//到了这里应该左右的都不为空
			headdle=T->rchild->lchild;//向左，然后向右找到最低的节点，值替换，然后删除最低节点
			while(headdle->rchild->lchild!=NULL&&headdle->rchild->rchild!=NULL){
				headdle=headdle->rchild;
			}
			T->rchild->key=headdle->lchild->key;
			headdle->lchild=NULL;
			return 1;
		}
}

void _1(){
	List A,B;
	int i,data1[9]={2,8,20,30,50,5,15,33,110},
		  data2[8]={22,8,80,3,100,1,13,120};
	printf("==========================================================================================================================\n");
	ReadFile(A,0);
	PrintList(A);
	printf("\n");
	for(i=0;i<9;i++){
		printf("查找值:%d\t",data1[i] );
		BinarySearch(A,data1[i],1,A.length);
	}
	printf("==========================================================================================================================\n");
	ReadFile(B,1);
	PrintList(B);
	printf("\n");
	for(i=0;i<8;i++){
		printf("查找值:%d\t",data2[i] );
		BinarySearch(B,data1[i],1,B.length);
	}
	printf("==========================================================================================================================\n");
	system("pause");
}

void _2(){
	int i;
	List A,B;
	Bnode ListA,ListB;
	printf("\n==================================================================\n");
	ReadFile(A,3);
	PrintList(A);
	i=2;
	ListA.key=A.data[1];
	ListA.lchild=NULL;
	ListA.rchild=NULL;
	printf("创建完毕\n");
	while(i!=A.length+1){
		InsrtNode(&ListA,A.data[i]);
		i++;
	}
	printf("中序遍历:");
	inTravel(&ListA);
	printf("\n==================================================================\n");
	ReadFile(B,4);
	PrintList(B);
	i=2;
	ListB.key=B.data[1];
	ListB.lchild=NULL;
	ListB.rchild=NULL;
	printf("创建完毕\n");
	while(i!=B.length+1){
		InsrtNode(&ListB,B.data[i]);
		i++;
	}
	printf("中序遍历:");
	inTravel(&ListB);
	printf("\n==================================================================\n");
	system("pause");
}

void _3(){
	int i,data[7]={150,70,160,190,10,55,175};
	List A,B;
	Bnode ListA,ListB;
	printf("\n==================================================================\n");
	ReadFile(A,3);
	PrintList(A);
	i=2;
	ListA.key=A.data[1];
	ListA.lchild=NULL;
	ListA.rchild=NULL;
	printf("创建完毕\n");
	while(i!=A.length+1){
		InsrtNode(&ListA,A.data[i]);
		i++;
	}
	printf("中序遍历:");
	inTravel(&ListA);
	printf("\n");
	for(i=0;i<7;i++){
		printf("查找%d\t",data[i]);
		BinarySortTreeSearch(&ListA,data[i]);
		printf("\n");
	}
	printf("==================================================================\n");
	ReadFile(B,4);
	PrintList(B);
	i=2;
	ListB.key=B.data[1];
	ListB.lchild=NULL;
	ListB.rchild=NULL;
	printf("创建完毕\n");
	while(i!=B.length+1){
		InsrtNode(&ListB,B.data[i]);
		i++;
	}
	printf("中序遍历:");
	inTravel(&ListB);
	printf("\n");
	for(i=0;i<7;i++){
		printf("查找%d\t",data[i]);
		BinarySortTreeSearch(&ListB,data[i]);
		printf("\n");
	}

	printf("==================================================================\n");
	system("pause");
}
void _4(){
	int i,j,data[3]={30,150,100};
	List A,B;
	Bnode ListA,ListB;
	printf("\n==================================================================\n");
	ReadFile(A,3);
	PrintList(A);
	i=2;
	ListA.key=A.data[1];
	ListA.lchild=NULL;
	ListA.rchild=NULL;
	printf("创建完毕\n");
	while(i!=A.length+1){
		InsrtNode(&ListA,A.data[i]);
		i++;
	}
	printf("中序遍历:");
	inTravel(&ListA);
	printf("\n");
	for(j=0;j<3;j++){
		i=2;
		ListA.key=A.data[1];
		ListA.lchild=NULL;
		ListA.rchild=NULL;
		//printf("创建完毕\n");
		while(i!=A.length+1){
			InsrtNode(&ListA,A.data[i]);
			i++;
		}
		printf("删除%d\t",data[j]);
		if(DelData(&ListA,data[j]))
			printf("删除成功\t");
		else
			printf("删除失败\t");
		printf("中序遍历:");
		inTravel(&ListA);
		printf("\n");
	}
	printf("==================================================================\n");
	ReadFile(B,4);
	PrintList(B);
	i=2;
	ListB.key=B.data[1];
	ListB.lchild=NULL;
	ListB.rchild=NULL;
	printf("创建完毕\n");
	while(i!=B.length+1){
		InsrtNode(&ListB,B.data[i]);
		i++;
	}
	printf("中序遍历:");
	inTravel(&ListB);
	printf("\n");
	for(j=0;j<3;j++){
		i=2;
		ListB.key=B.data[1];
		ListB.lchild=NULL;
		ListB.rchild=NULL;
		//printf("创建完毕\n");
		while(i!=B.length+1){
			InsrtNode(&ListB,B.data[i]);
			i++;
		}
		printf("删除%d\t",data[j]);
		if(DelData(&ListB,data[j]))
			printf("删除成功\t");
		else
			printf("删除失败\t");
		printf("中序遍历:");
		inTravel(&ListB);
		printf("\n");
	}

	printf("==================================================================\n");
	system("pause");
}
void _5(){
	int i;
	List A,B;
	Bnode ListA,ListB;
	PNode treeRootA = NULL,treeRootB = NULL;
	bool heigher;
	printf("\n==============================================================================================================\n");
	ReadFile(A,5);
	PrintList(A);
	for (i = 1; i < A.length+1; i++) {
		InsertKeyValue(&treeRootA,A.data[i],&heigher);
	}
	printf("创建完毕\n先序遍历:");
	printfTree(treeRootA);
	printf("\n===============================================================================================================\n");
	ReadFile(B,6);
	PrintList(B);
	for (i = 1; i < B.length+1; i++) {
		InsertKeyValue(&treeRootB,B.data[i],&heigher);
	}
	printf("创建完毕\n先序遍历:");
	printfTree(treeRootB);
	printf("\n===============================================================================================================\n");
	system("pause");
	return ;
}