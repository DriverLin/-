#ifndef BitTree

typedef struct node{
	char data;
	struct node *lChild,*rChild;
}BitTree;

static char strLine[1000][3];
static int COUNTBOOK = 0,nArrLen = 0,iCount = 0,level = 0,NodeNumber = 0,leafnode = 0,twonode= 0,iFlag = 0,FindFlag = 0,Funnnnn=0;//全局变量这里要记得初始化下在用
static int ExM = 0;
BitTree * generateNode(){
	BitTree * node = (BitTree *)malloc(sizeof(BitTree));
	node->rChild = NULL; 
	node->lChild = NULL;
	return node;
}

typedef struct
{
    char elem[1000];
    int top;
} Oseqstack;

//============三种遍历=============
void PreTravle(BitTree *T)//先序遍历
{
	if(T == NULL) return;
	putchar(T->data);
	PreTravle(T->lChild);
	PreTravle(T->rChild);
	return ;
}

void InTravle(BitTree *T)//中序遍历
{
	if(T == NULL) return ;
	InTravle(T->lChild);
	putchar(T->data);
	InTravle(T->rChild);
	return ;
}

void PostTravle(BitTree *T)//后序遍历
{
	if(T == NULL) return ;
	PostTravle(T->lChild);
	PostTravle(T->rChild);
	putchar(T->data);
	return ;
}

//=============分割线==============

BitTree * PreCreateBitree()//返回根节点  用法 BitTree *root = PreCreateBitree();
{
	BitTree *node = generateNode();
	char value;
	int l = 0,r = 0;
	scanf("%c %d %d",&value, &l, &r);
	getchar();
	printf("========\n");
	node->data = value;
	if (l) node->lChild = PreCreateBitree();
	if (r) node->rChild = PreCreateBitree();
	return node;
}

int ReadFileToRAM(int Mark)//这是读取文件到全局变量里面
{
	FILE *pFile;
	char str[1000];
	char fileMark[12][80];
    sprintf(fileMark[0],"W:\\BTdata\\bt4.btr",80);
    sprintf(fileMark[1],"W:\\BTdata\\bt8.btr",80);
    sprintf(fileMark[2],"W:\\BTdata\\bt9.btr",80);
    sprintf(fileMark[3],"W:\\BTdata\\bt10.btr",80);
    sprintf(fileMark[4],"W:\\BTdata\\bt12.btr",80);
    sprintf(fileMark[5],"W:\\BTdata\\bt14.btr",80);
    sprintf(fileMark[6],"W:\\BTdata\\bt15.btr",80);
    sprintf(fileMark[7],"W:\\BTdata\\bt21.btr",80);
    sprintf(fileMark[8],"W:\\BTdata\\bt261.btr",80);
    sprintf(fileMark[9],"W:\\BTdata\\bt262.btr",80);
    sprintf(fileMark[10],"W:\\BTdata\\full4.btr",80);
    sprintf(fileMark[11],"W:\\BTdata\\full5.btr",80);
	pFile = fopen(fileMark[Mark],"r");
	if(!pFile){
		printf("Open Failed!\n");
		return 0;
	}
	if(fgets(str,1000,pFile) != NULL){
		if(strcmp(str,"BinaryTree\n") != 0){
			printf("File Error!\n");
			fclose(pFile);
			return 0;
		}
	}
	while(fscanf(pFile,"%c %d %d\n",&strLine[nArrLen][0],&strLine[nArrLen][1],&strLine[nArrLen][2]) != EOF){
		//printf("nArrLen=%2d,char=%c\n",nArrLen,strLine[nArrLen][0]);
		nArrLen++;
	}
	fclose(pFile);
	//printf("Success!");	
	return 0;
}

BitTree * PreCreateBitreeFromRAM()//从全局变量创建
{
	BitTree *node = generateNode();
	char value;
	int l = 0,r = 0;
	value = strLine[iCount][0];
	l = strLine[iCount][1];
	r = strLine[iCount][2];
	iCount++;
	//printf("========\n");
	node->data = value;
	if (l == 1) node->lChild = PreCreateBitreeFromRAM();
	if (r == 1) node->rChild = PreCreateBitreeFromRAM();
	return node;
}

int printMarkAndTree(){
    printf(" 0   bt4.btr\n 1   bt8.btr \n 2   bt9.btr \n 3   bt10.btr \n 4   bt12.btr \n 5   bt14.btr \n 6   bt15.btr \n 7   bt21.btr \n 8   bt261.btr \n 9   bt262.btr \n10   full4.btr \n11   full5.btr \n ");
    return 0;
}

int OrderInitstack(Oseqstack *s)//初始化栈
{
    s->top = -1;//s->top为-1表示空栈
}

int OrderIsEmpty(Oseqstack *s)//判断是否栈空   是返回1 否返回0
{
    if (s->top == -1) return 1;
    else return 0;
}

int OrderIsFull(Oseqstack *s)//判断是否栈满   是返回1 否返回0
{
    if(s->top == 999 ) return 1;
    else return 0;
}

int OrderPush(Oseqstack *s,char n)//入栈 传入栈顶指针和入栈的值 成功返回1 失败返回0
{
    if(OrderIsFull(s)) return 0;
    s->top++;
    s->elem[s->top] = n;
    return 1;
}

int OrderPop(Oseqstack *s,char *n)//出栈 传入栈顶指针和出栈的指针 成功返回1 失败返回0
{
    if(OrderIsEmpty(s)) return 0;
    *n = s->elem[s->top];
    s->top--;
    return 1;
}


int LorR(BitTree *T,BitTree *Root)//有返回1 没返回0
{
	if(Root == NULL) return COUNTBOOK;
	LorR(T,Root->lChild);
	LorR(T,Root->rChild);
	if(T->data == Root->data) COUNTBOOK=1;
	return COUNTBOOK;
}

void PrintPatch(BitTree *T,BitTree *Root,Oseqstack *s){
	printf("\n%c:",T->data);
	if(T->data==Root->data){
		printf("%c",Root->data);
		return ;
	}
	printf("%c ",Root->data);
	while(T->data!=Root->data){
		COUNTBOOK=0;
		if(LorR(T,Root->lChild)){
			Root=Root->lChild;
			printf("%c ",Root->data);
		}
		else{
			Root=Root->rChild;
			printf("%c ",Root->data);
		}
	}
	return;
}


int PreTravleFun(BitTree *T,char A[],int i)//
{
	if(T == NULL) return 0;
	PreTravleFun(T->lChild,A,i*2);
	//Funnnnn++;
	PreTravleFun(T->rChild,A,i*2+1);
	A[i]=T->data;
	return 0 ;
}

//int h = Getheight(T);



#endif