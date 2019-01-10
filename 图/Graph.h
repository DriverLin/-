#include <iostream>
#define INF 65535          //定义无穷大
#define MaxVerNum  100     //定义最大顶点个数
#define MAXLEN 800   //树最大个数
//typedef int elementType;  //定义图中顶点的数据类型

#define true 1
#define false 0 
using namespace std;
typedef char elementType;  //定义图中顶点的数据类型
typedef int cellType;      //定义邻接矩阵中元素的数据类型
						   //对无权图，1-相邻（有边），0-不相邻（无边）
						   //对有权图，为边的权值，特别是无穷大。
						   //枚举图的类型--无向图(UDG)，无向网(UDN)，有向图(DG)，有向网(DN)
typedef enum { UDG, UDN, DG, DN } GraphKind;

bool visited[MaxVerNum + 1];  //全局数组，标记顶点是否已经访问，visited[0]单元不用

							  //****************************************************//
							  //*  定义邻接矩阵表示的图结构。5个分量组成：         *//
							  //*      data[]数组保存图中顶点数据元素              *//
							  //*      AdjMatrix[][]邻接矩阵                       *//
							  //*      VerNum顶点个数                              *//
							  //*      ArcNum边（弧）条数                          *//
							  //*      gKind枚举图的类型                           *//
							  //*  考虑到名称的统一性，图类型名称定义为Graph       *//
							  //****************************************************//
typedef struct GraphAdjMatrix
{
	elementType Data[MaxVerNum + 1];                 //顶点数组，存放顶点元素的值，Data[0]单元不用
	cellType AdjMatrix[MaxVerNum + 1][MaxVerNum + 1];  //邻接矩阵，数组下标为0单元不用，从AdjMatrix[1][1]单元开始
	int VerNum;       //顶点数
	int ArcNum;       //弧（边）数
	GraphKind gKind;  //图的类型:0-无向图；1-无向网；2-有向图；3-有向网
} Graph;  //图的类型名
		  //==========================================================================
		  //=============栈======================================================
typedef struct
{
	char elem[1000];
	int top;
}stack;

void Initstack(stack &s)//初始化栈
{
	s.top = -1;//s.top为-1表示空栈

}

int IsEmpty(stack &s)//判断是否栈空   是返回1 否返回0
{
	if (s.top == -1) return true;
	else return false;
}

int IsFull(stack &s)//判断是否栈满   是返回1 否返回0
{
	if (s.top == 999) return true;
	else return false;
}

int Push(stack &s, int n)//入栈 传入栈顶指针和入栈的值 成功返回1 失败返回0
{
	if (IsFull(s)) return false;
	s.top++;
	s.elem[s.top] = n;
	return true;
}

char Pop(stack &s)//出栈 传入栈顶指针和出栈的指针 成功返回1 失败返回0
{
	if (IsEmpty(s)) return 0;
	s.top--;
	return s.elem[s.top + 1];
}

//========================树====================================

typedef struct pNode
{
	elementType data;   //结点数据域
	int parent;         //父结点下标

}PTNode;

//双亲表示的树（森林）结构
typedef struct pTree
{
	PTNode node[MAXLEN];   //结点数组
	int n;              //结点总数
}pTree;


//初始化树
void initialTree(pTree &T)
{
	T.n = 0;   //结点数初始化为0
}

//求祖先结点
bool getAncestor(pTree &T, elementType x)
{
	int w = 0;
	elementType y;
	y = x;

	for (w = 0; w<T.n; w++)
	{
		if (T.node[w].data == y)
		{
			w = T.node[w].parent;     //取得x的父结点
			y = T.node[w].data;
			cout << y << "\t";
			break;
		}
	}
	if (w >= T.n)    //x不在树上，返回0
		return 0;

	//搜索x父结点之外的其它祖先结点
	while (w != -1)
	{
		if (T.node[w].data == y)
		{
			w = T.node[w].parent;     //取得w的双亲结点下标
			y = T.node[w].data;
			cout << y << "\t";
		}
		else
			w = (w + 1) % T.n;
	}
	return 1;
}

//求孩子结点
void getChildren(pTree &T, elementType x)
{
	int i, w;
	for (w = 0; w<T.n; w++)     //获取x在结点数组中的下标
	{
		if (T.node[w].data == x)
			break;
	}
	if (w >= T.n)  //x不在表中
		return;
	for (i = 0; i<T.n; i++)
	{
		if (T.node[i].parent == w)   //找到子结点，打印
			cout << T.node[i].data << "\t";
	}
	cout << endl;
}

//先序遍历
int firstChild(pTree &T, int v)    //搜索下标为v的结点的第一个孩子结点下标
{
	int w;
	if (v == -1)
		return -1;

	for (w = 0; w<T.n; w++)
	{
		if (T.node[w].parent == v)
			return w;
	}
	return -1;
}
int nextSibling(pTree &T, int v, int w)  //搜索v的下标位于w之后的下一个孩子结点下标
{
	int i;
	for (i = w + 1; i<T.n; i++)
		if (T.node[i].parent == v)
			return i;
	return -1;
}
void preOrder(pTree &T, int v)
{
	int w;
	cout << T.node[v].data << " ";

	w = firstChild(T, v);
	while (w != -1)
	{

		preOrder(T, w);
		w = nextSibling(T, v, w);
	}
}

void preTraverse(pTree &T)
{
	int i;
	int visited[MAXLEN];
	for (i = 0; i<T.n; i++)
	{
		visited[i] = 0;
	}
	//搜索根结点，可能是森林，有多个根结点
	for (i = 0; i<T.n; i++)
	{
		if (T.node[i].parent == -1)
			preOrder(T, i);
	}
}

void postOrder(pTree &T, int v)
{
	int w;
	w = firstChild(T, v);
	while (w != -1)
	{
		postOrder(T, w);
		w = nextSibling(T, v, w);
	}
	cout << T.node[v].data << " ";   //访问根结点
}

void postTraverse(pTree &T)
{
	int i;
	int visited[MAXLEN];
	for (i = 0; i<T.n; i++)
	{
		visited[i] = 0;
	}
	//搜索根结点，可能是森林，有多个根结点
	for (i = 0; i<T.n; i++)
	{
		if (T.node[i].parent == -1)
			postOrder(T, i);
	}
}

//打印树
void printTree(pTree &T)
{
	int i;
	cout << "下标\t结点\t双亲" << endl;
	for (i = 0; i<T.n; i++)
		cout << i << "\t" << T.node[i].data << "\t" << T.node[i].parent << endl;
}

//===============================================================
//=================队列==============================
typedef struct
{
	int data[MaxVerNum];
	int head, end;
} Queue;

void initalQueue(Queue &Q) {
	Q.head = 0;
	Q.end = 0;
}

void EnQueue(Queue &Q, int data) {
	if (Q.end == MaxVerNum)
		return;
	Q.data[Q.end] = data;
	Q.end++;
	return;
}
int outQueue(Queue &Q) {
	if (Q.head >= Q.end)
		return -1;
	Q.head++;
	return Q.data[Q.head - 1];
}

int QueueEmpty(Queue &Q) {
	if (Q.head == Q.end)
		return true;
	else
		return false;
}
//==================队列算法结束
//=============================================================





//******************* 访问图中顶点的函数*********************//
//* 函数功能：打印图中顶点元素，并标记为已经访问            *//
//* 入口参数  Graph G，待访问的图；int verID 目标顶点编号   *//
//* 出口参数：无                                            *//
//* 返 回 值：空                                            *//
//* 函 数 名：visit(Graph &G, int verID)                    *//
//***********************************************************//

void strLTrim(char* str)//删除字符串、字符数组左边空格
{
	int i, j;
	int n = 0;
	n = strlen(str) + 1;
	for (i = 0; i<n; i++)
	{
		if (str[i] != ' ')  //找到左起第一个非空格位置
			break;
	}
	//以第一个非空格字符为手字符移动字符串
	for (j = 0; j<n; j++)
	{
		str[j] = str[i];
		i++;
	}
}
//*************************从数据文件创建图**************************//
//* 函数功能：从文本文件创建邻接矩阵表示的图                        *//
//* 入口参数  char fileName[]，文件名                               *//
//* 出口参数：                                                      *//
//* 返 回 值：bool，true创建成功；false创建失败                     *//
//* 函 数 名：CreateGrpFromFile(char fileName[])                  *//
//*******************************************************************//
bool CreateGrpFromFile(char fileName[], Graph &G)
{
	FILE* pFile;      //定义顺序表的文件指针
	char str[1000];   //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行

	cellType  eWeight;    //边的信息，常为边的权值
	GraphKind GrpType;  //图类型枚举变量

	pFile = fopen(fileName, "r");
	if (!pFile)
	{

		printf("错误：文件%s打开失败。\n", fileName);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //跳过注释行
			continue;
		else  //非注释行、非空行，跳出循环
			break;
	}

	//循环结束，str中应该已经是文件标识，判断文件格式
	if (strstr(str, "Graph") == NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取图的类型，跳过空行
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;
		else  //非空行，也非注释行，即图的类型标识
			break;
	}

	//设置图的类型
	if (strstr(str, "UDG"))
		GrpType = UDG;  //无向图
	else if (strstr(str, "UDN"))
		GrpType = UDN;  //无向网
	else if (strstr(str, "DG"))
		GrpType = DG;   //有向图
	else if (strstr(str, "DN"))
		GrpType = DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取顶点元素，到str。跳过空行
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;
		else  //非空行，也非注释行，即图的顶点元素行
			break;
	}

	//顶点数据放入图的顶点数组	
	char* token = strtok(str, " ");
	int nNum = 1;
	while (token != NULL)
	{
		G.Data[nNum] = *token; // atoi(token);	//顶点数据转换为整数，若为字符则不需转换		
		token = strtok(NULL, " ");
		nNum++;
	}
	nNum--;   //顶点数

			  //图的邻接矩阵初始化
	int nRow = 1;  //矩阵行下标，从1开始
	int nCol = 1;  //矩阵列下标，从1开始
	if (GrpType == UDG || GrpType == DG)
	{
		for (nRow = 1; nRow <= nNum; nRow++)
			for (nCol = 1; nCol <= nNum; nCol++)
				G.AdjMatrix[nRow][nCol] = 0;
	}
	else
	{
		for (nRow = 1; nRow <= nNum; nRow++)
			for (nCol = 1; nCol <= nNum; nCol++)
				G.AdjMatrix[nRow][nCol] = INF;  //INF表示无穷大
	}

	//循环读取边的数据到邻接矩阵

	int edgeNum = 0;  //边的数量
	elementType Nf, Ns; //边或弧的2个相邻顶点
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;

		char* token = strtok(str, " ");  //以空格为分隔符，分割一行数据，写入邻接矩阵

		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf = *token;  //获取边的第一个顶点

		token = strtok(NULL, " ");  //读取下一个子串，即第二个顶点
		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}

		Ns = *token;  //获取边的第二个顶点
					  //从第一个顶点获取行号		
		for (nRow = 1; nRow <= nNum; nRow++)
		{
			if (G.Data[nRow] == Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
		//从第二个顶点获取列号		
		for (nCol = 1; nCol <= nNum; nCol++)
		{
			if (G.Data[nCol] == Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		//如果为网，读取权值
		if (GrpType == UDN || GrpType == DN)
		{
			token = strtok(NULL, " ");  //读取下一个子串，即边的附加信息，常为边的权重
			if (token == NULL)  //分割为空串，失败退出
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile); //关闭文件
				return false;
			}
			eWeight = atoi(token);  //取得边的附加信息
		}
		if (GrpType == UDN || GrpType == DN)  //如果为网，邻接矩阵中对应的边设置权值，否则置为1
			G.AdjMatrix[nRow][nCol] = eWeight;
		else
			G.AdjMatrix[nRow][nCol] = 1;  //atoi(token);	//字符串转为整数

		edgeNum++;   //边数加1
	}

	G.VerNum = nNum;  //图的顶点数
	if (GrpType == UDG || GrpType == UDN)
		G.ArcNum = edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum = edgeNum;

	G.gKind = GrpType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}

void printGraph(Graph &G)
{
	int i = 0, j = 0;
	//打印图的类型
	switch (G.gKind)
	{
	case UDG:
		cout << "图类型：无向图" << endl;
		break;
	case UDN:
		cout << "图类型：无向网" << endl;
		break;
	case DG:
		cout << "图类型：有向图" << endl;
		break;
	case DN:
		cout << "图类型：有向网" << endl;
		break;
	default:
		cout << "图类型错误。" << endl;
		break;
	}
	//打印图的顶点数
	cout << "顶点数：" << G.VerNum << endl;
	//打印图的边数
	cout << "边  数：" << G.ArcNum << endl;
	//打印顶点及其编号
	cout << "编  号：";
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "顶  点：";
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << G.Data[i] << "\t";
	}
	cout << endl;

	//打印邻接矩阵
	cout << "图的邻接矩阵：" << endl;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << "\t";
		for (j = 1; j <= G.VerNum; j++)
		{
			if ((G.gKind == UDN || G.gKind == DN) && G.AdjMatrix[i][j] == INF)
				cout << "INF" << "\t";  //网，无穷大时，打印“INF”表示
			else
				cout << G.AdjMatrix[i][j] << "\t";
		}
		cout << endl;
	}

}

void visit(Graph &G, int verID)
{        //顶点编号从1开始，数组0单元不用
	cout << G.Data[verID] << " ";
	visited[verID] = true;
}

int firstAdj(Graph &G, int v)
{
	int w;
	for (w = 1; w <= G.VerNum; w++)
	{
		if ((G.AdjMatrix[v][w] >= 1) &&
			(G.AdjMatrix[v][w])<INF)
			return w;    //返回第一个邻接点编号
	}
	return 0;          //未找到邻接点，返回0
}

int nextAdj(Graph &G, int v, int w)
{
	int k;
	for (k = w + 1; k <= G.VerNum; k++)
	{
		if ((G.AdjMatrix[v][k] >= 1) && (G.AdjMatrix[v][k]) < INF)
			return k;    //返回v的位于w之后的下一个邻接点k
	}
	return 0;           //不存在下一个邻接点，返回0
}

void DFS(Graph &G, int Ver) {
	int w;
	visit(G, Ver);
	w = firstAdj(G, Ver);
	while (w != false) {
		if (visited[w] != true)
			DFS(G, w);
		w = nextAdj(G, Ver, w);
	}
	return;
}

void DFStravel(Graph &G) {
	int i;
	for (i = 0; i <= MaxVerNum; i++) {
		visited[i] = false;
	}
	printf("DFS:");
	DFS(G, 1);
	printf("\n");
}

void BFS(Graph &G, int Ver) {
	Queue Q;
	int v, w;
	initalQueue(Q);
	visit(G, Ver);
	EnQueue(Q, Ver);
	while (!QueueEmpty(Q)) {
		v = outQueue(Q);
		w = firstAdj(G, v);

		while (w != false) {
			if (!visited[w]) {
				visit(G, w);
				EnQueue(Q, w);
			}
			w = nextAdj(G, v, w);
		}
	}
}

void BFStravel(Graph &G) {
	int i;
	for (i = 0; i <= MaxVerNum; i++) {
		visited[i] = false;
	}
	printf("BFS:");
	BFS(G, 1);
	printf("\n");
}

void ArcNumber(Graph &G) {
	if (G.gKind == UDG || G.gKind == UDN)//无向 边
		printf("边数为:");
	else//有向 弧
		printf("弧数为:");
	printf("%d\n", G.ArcNum);
}

void _1() {
	Graph udg8, udg115, dg6, f14;
	char File_udg8[80], File_udg115[80], File_dg6[80], File_f14[80];
	sprintf(File_udg8, "D:\\grpData\\udg8.grp", 80);
	sprintf(File_udg115, "D:\\grpData\\udg115.grp", 80);
	sprintf(File_dg6, "D:\\grpData\\dg6.grp", 80);
	sprintf(File_f14, "D:\\grpData\\f14.grp", 80);
	CreateGrpFromFile(File_udg8, udg8);
	CreateGrpFromFile(File_udg115, udg115);
	CreateGrpFromFile(File_dg6, dg6);
	CreateGrpFromFile(File_f14, f14);
	printf("\n");
	puts(File_udg8);
	DFStravel(udg8);
	BFStravel(udg8);
	printf("\n");
	puts(File_udg115);
	DFStravel(udg115);
	BFStravel(udg115);
	printf("\n");
	puts(File_dg6);
	DFStravel(dg6);
	BFStravel(dg6);
	printf("\n");
	puts(File_f14);
	DFStravel(f14);
	BFStravel(f14);
	printf("\n");
}

void _2() {
	Graph udg8, udg115, dg6, f14;
	char File_udg8[80], File_udg115[80], File_dg6[80], File_f14[80];
	sprintf(File_udg8, "D:\\grpData\\udg8.grp", 80);
	sprintf(File_udg115, "D:\\grpData\\udg115.grp", 80);
	sprintf(File_dg6, "D:\\grpData\\dg6.grp", 80);
	sprintf(File_f14, "D:\\grpData\\f14.grp", 80);
	CreateGrpFromFile(File_udg8, udg8);
	CreateGrpFromFile(File_udg115, udg115);
	CreateGrpFromFile(File_dg6, dg6);
	CreateGrpFromFile(File_f14, f14);
	printf("\n");
	puts(File_udg8);
	ArcNumber(udg8);
	printf("\n");
	puts(File_udg115);
	ArcNumber(udg115);
	printf("\n");
	puts(File_dg6);
	ArcNumber(dg6);
	printf("\n");
	puts(File_f14);
	ArcNumber(f14);
	printf("\n");
}

void DFStree_visit(Graph &G, int verID, pTree &T, int parentID)
{        //顶点编号从1开始，数组0单元不用
	T.node[verID].data = G.Data[verID];
	T.n++;
	T.node[verID].parent = parentID;
	visited[verID] = true;
}

void tree_DFS(Graph &G, int Ver, pTree &T, int parentID) {
	int w, temp;
	DFStree_visit(G, Ver, T, parentID);
	w = firstAdj(G, Ver);
	temp = Ver;
	while (w != false) {
		if (visited[w] != true)
			tree_DFS(G, w, T, temp);
		temp = w;
		w = nextAdj(G, Ver, w);
	}
	return;
}

void DFSCreatTree(Graph &G, pTree &T) {
	int i;
	for (i = 0; i <= MaxVerNum; i++) {
		visited[i] = false;
	}
	initialTree(T);
	tree_DFS(G, 1, T, -1);
	T.n++;
	printf("先序遍历:");
	preTraverse(T);
	printf("\n后序遍历:");
	postTraverse(T);
	printf("\n\n");
}

void _3() {
	Graph udg8, dg6, un8, dn10;
	pTree  Tree_udg8, Tree_dg6, Tree_un8, Tree_dn10;
	char File_udg8[80], File_dg6[80], File_un8[80], File_dn10[80];
	sprintf(File_udg8, "D:\\grpData\\udg8.grp", 80);
	sprintf(File_dg6, "D:\\grpData\\dg6.grp", 80);
	sprintf(File_un8, "D:\\grpData\\un8.grp", 80);
	sprintf(File_dn10, "D:\\grpData\\dn10.grp", 80);
	CreateGrpFromFile(File_udg8, udg8);
	CreateGrpFromFile(File_dg6, dg6);
	CreateGrpFromFile(File_un8, un8);
	CreateGrpFromFile(File_dn10, dn10);
	printf("\n");
	puts(File_udg8);
	DFSCreatTree(udg8, Tree_udg8);
	puts(File_dg6);
	DFSCreatTree(dg6, Tree_dg6);
	puts(File_un8);
	DFSCreatTree(un8, Tree_un8);
	puts(File_udg8);
	DFSCreatTree(dn10, Tree_dn10);

}



void BFStree_visit(Graph &G, int verID, pTree &T, int parentID)//图 节点编号 树 父节点编号
{        //顶点编号从1开始，数组0单元不用
	T.node[verID].data = G.Data[verID];
	T.n++;
	T.node[verID].parent = parentID;
	visited[verID] = true;
}

void tree_BFS(Graph &G, int Ver, pTree &T, int parentID) {
	Queue Q;
	int v, w;
	initalQueue(Q);
	BFStree_visit(G, Ver, T, parentID);
	EnQueue(Q, Ver);
	while (!QueueEmpty(Q)) {
		v = outQueue(Q);
		w = firstAdj(G, v);
		while (w != false) {
			if (!visited[w]) {
				BFStree_visit(G, w, T, v);
				EnQueue(Q, w);
			}
			w = nextAdj(G, v, w);
		}
	}
}

void BFSCreatTree(Graph &G, pTree &T) {
	int i;
	for (i = 0; i <= MaxVerNum; i++) {
		visited[i] = false;
	}
	initialTree(T);
	tree_BFS(G, 1, T, -1);
	T.n++;
	printf("先序遍历:");
	preTraverse(T);
	printf("\n后序遍历:");
	postTraverse(T);
	printf("\n\n");
}

void _4() {
	Graph udg8, dg6, un8, dn10;
	pTree  Tree_udg8, Tree_dg6, Tree_un8, Tree_dn10;
	char File_udg8[80], File_dg6[80], File_un8[80], File_dn10[80];
	sprintf(File_udg8, "D:\\grpData\\udg8.grp", 80);
	sprintf(File_dg6, "D:\\grpData\\dg6.grp", 80);
	sprintf(File_un8, "D:\\grpData\\un8.grp", 80);
	sprintf(File_dn10, "D:\\grpData\\dn10.grp", 80);
	CreateGrpFromFile(File_udg8, udg8);
	CreateGrpFromFile(File_dg6, dg6);
	CreateGrpFromFile(File_un8, un8);
	CreateGrpFromFile(File_dn10, dn10);
	printf("\n");
	puts(File_udg8);
	BFSCreatTree(udg8, Tree_udg8);
	puts(File_dg6);
	BFSCreatTree(dg6, Tree_dg6);
	puts(File_un8);
	BFSCreatTree(un8, Tree_un8);
	puts(File_udg8);
	BFSCreatTree(dn10, Tree_dn10);

}


//========prim算法=====================
typedef struct Prim_MinEdgeType {
	cellType AdjMatrix[MaxVerNum + 1][MaxVerNum + 1];
	int VerNum;
}Prim_MinEdgeType;//边集结构 

typedef struct Prim_MinVertexType {
	int Node[MaxVerNum];
	int VerNum;
}Prim_MinVertexType;//顶点集结构  Vernum表示顶点个数 Node[i]表示编号i的顶点是否在集合里

void Prim_EdgeCopy(Graph &G, Prim_MinEdgeType &Edge) {//复制边集 从图到集合  （图，集合）
	int i, j;
	Edge.VerNum = G.VerNum;
	for (i = 1; i <= MaxVerNum; i++) {
		for (j = 1; j <= MaxVerNum; j++)
			Edge.AdjMatrix[i][j] = G.AdjMatrix[i][j];
	}
	return;
}

void Prim_initalEdge(Prim_MinEdgeType &Edge, int Kind, Graph &G) {//初始化边集  (边集合，标识，图) 标识为0/1   0则初始化为空，1则复制图中全部边集
	int i, j;
	Edge.VerNum = G.VerNum;
	if (Kind == 0) {//参数为0 初始化为空 全部值为0
		for (i = 1; i <= MaxVerNum; i++) {
			for (j = 1; j <= MaxVerNum; j++)
				Edge.AdjMatrix[i][j] = 0;
		}
	}
	else//非0，初始化为U=V 边集全部复制
		for (i = 1; i <= MaxVerNum; i++) {
			for (j = 1; j <= MaxVerNum; j++) {
				if (G.AdjMatrix[i][j] == INF)
					Edge.AdjMatrix[i][j] = 0;
				else
					Edge.AdjMatrix[i][j] = 1;
			}
		}
	return;
}

void Prime_initalVertex(Prim_MinVertexType &Vertex, int Kind, Graph &G) {//初始化点集  (点集合，标识，图) 标识为0/1   表示i图中I节点是否在点集合里
	int i;												   //只能初始化为空或者全
	Vertex.VerNum = G.VerNum;
	for (i = 1; i <= G.VerNum; i++) {
		Vertex.Node[i] = Kind;
	}
}

void Prim_MoveNode(Prim_MinVertexType &U, Prim_MinVertexType &S, int i) {
	U.Node[i] = 0;
	S.Node[i] = 1;
	return;
}

int Prim_VertexEmpty(Prim_MinVertexType &Vertex) {//判断点集是否为空  空返回0 非空返回1
	int i;
	for (i = 1; i <= Vertex.VerNum; i++) {
		if (Vertex.Node[i] == 1)
			return 1;
	}
	return 0;
}

void Prim_UpdateWE(Prim_MinEdgeType &WE, Prim_MinEdgeType &TE, int Ver, Graph &G) {//跟新候选边 每次更新一个节点Ver   (WE,TE,节点，图)
	int i;
	for (i = 1; i <= G.VerNum; i++) {
		if (G.AdjMatrix[Ver][i] != 65535) {//寻找有关的边    条件可能要修改
			WE.AdjMatrix[Ver][i] = 1;//有边则更新 置为1
			if (TE.AdjMatrix[Ver][i] == 1)
				WE.AdjMatrix[Ver][i] = 0;//如果边在已选边(TE)里 则删除(置0)
		}
	}
	return;
}

int Prim_SelectMinEdge(Prim_MinEdgeType &WE, Prim_MinEdgeType &TE, Graph &G, Prim_MinVertexType &S, Prim_MinVertexType &U) {
	int i, j, Flag, E, H;
	int minmum = 999;

	for (i = 1; i <= G.VerNum; i++) {
		for (j = 1; j <= G.VerNum; j++) {
			if (WE.AdjMatrix[i][j] == 1) {//在候选边里 
				if (G.AdjMatrix[i][j] <= minmum) {//寻找最小边
					E = i;
					H = j;
					minmum = G.AdjMatrix[i][j];
					//printf("min=%d\n",minmum);
				}
			}
		}
	}

	TE.AdjMatrix[E][H] = 1;//更新已选边
	if (S.Node[H] == 1)
		Flag = E;
	else
		Flag = H;
	//Flag此时是未选边
	//printf("E=%d H=%d \n",E,H );
	Prim_MoveNode(U, S, Flag);//移动顶点到已选顶点
	Prim_UpdateWE(WE, TE, Flag, G);
	return Flag;
}

void prim(Graph &G, pTree &T) {
	int i = 1, j = 1;
	Prim_MinEdgeType WE, TE;//WE候选边 TE已经选边
	Prim_MinVertexType S, U;//S已选点 U候选点
	Prime_initalVertex(S, 0, G);//S为空
	Prime_initalVertex(U, 1, G);//U为V
	Prim_initalEdge(WE, 0, G);//WE为空
	Prim_initalEdge(TE, 0, G);//TE为空  初始化完成
	Prim_MoveNode(U, S, i);
	Prim_UpdateWE(WE, TE, i, G);

	while (Prim_VertexEmpty(U)) {
		i = Prim_SelectMinEdge(WE, TE, G, S, U);

		//printf("Flag=%d\n",i);
		printf("S:");
		for (i = 1; i <= G.VerNum; i++) {
			//printf("%d ",S.Node[i]);
			if (S.Node[i] == 1)
				printf("%d ", i);
		}
		printf("\t");
		printf("U:");
		for (i = 1; i <= G.VerNum; i++) {
			//printf("%d ",U.Node[i]);
			if (U.Node[i] == 1)
				printf("%d ", i);
		}
		printf("\n候选:");
		for (i = 1; i <= G.VerNum; i++) {
			for (j = 1; j <= G.VerNum; j++) {
				//printf("%-3d",WE.AdjMatrix[i][j]);
				if (WE.AdjMatrix[i][j] == 1)
					printf("%d-%d ", i, j);
			}
			//printf("\n");
		}
		printf("\n已选:");
		for (i = 1; i <= G.VerNum; i++) {
			for (j = 1; j <= G.VerNum; j++) {
				//printf("%-3d",TE.AdjMatrix[i][j]);
				if (TE.AdjMatrix[i][j] == 1)
					printf("%d-%d ", i, j);
			}
			//printf("\n");
		}
		printf("\n\n");

	}
}


void _5() {
	int i, j;
	Graph udn6, un8;
	pTree  Tree_udn6, Tree_un8;
	char File_udn6[80], File_un8[80];
	sprintf(File_udn6, "D:\\grpData\\udn6.grp", 80);
	sprintf(File_un8, "D:\\grpData\\un8.grp", 80);
	CreateGrpFromFile(File_udn6, udn6);
	CreateGrpFromFile(File_un8, un8);
	puts(File_udn6);
	printGraph(udn6);
	DFStravel(udn6);
	prim(udn6, Tree_udn6);
	printf("============================分割线==========================\n");
	puts(File_un8);
	printGraph(un8);
	DFStravel(un8);
	prim(un8, Tree_un8);
	return;
}

//========================Kruskal算法=======================
typedef struct
{
	int vBegin;//边的始点下标
	int vEnd;//边的终点下标
	int eWeight;//边的权值
}EdgeType;



int getEdges(Graph &G, EdgeType edges[]) {//获取边数组 返回边数
	int i, j, k = 1;
	for (i = 1; i <= G.VerNum; i++) {
		for (j = 1; j <= G.VerNum; j++) {
			if (G.AdjMatrix[i][j] != INF) {
				edges[k].vBegin = i;
				edges[k].vEnd = j;
				edges[k].eWeight = G.AdjMatrix[i][j];
				k++;
			}
		}
	}
	return k - 1;
}

int GetMinEdge(EdgeType edges[], int length) {//（边数组，长度）返回最小边下标 无修改任何数值
	int i, minEdge = INF, mark;
	for (i = 1; i <= length; i++) {
		if (edges[i].eWeight <= minEdge) {
			minEdge = edges[i].eWeight;
			mark = i;
		}
	}
	return mark;
}

void updateTreeEdges(EdgeType edges[], EdgeType Treeedges[], int minEdgeMark, int UsedMark) {//(边，树边，最小边下标，树边下标)
	Treeedges[UsedMark].vBegin = edges[minEdgeMark].vBegin;
	Treeedges[UsedMark].vEnd = edges[minEdgeMark].vEnd;
	Treeedges[UsedMark].eWeight = edges[minEdgeMark].eWeight;
	edges[minEdgeMark].eWeight = INF;//保存过边信息之后 把原最小边置为INF 从而达到删除的效果
}

void Kruskal(Graph &G, pTree &T) {
	int i, j, edgeNum, conVerID[MaxVerNum], minEdge = 1, Flag;
	EdgeType edges[MaxVerNum*MaxVerNum],//边数组 从1开始
		Treeedges[MaxVerNum*MaxVerNum];//树边数组
	int edgesUsed[MaxVerNum*MaxVerNum] = { 0 };//存放使用的边信息 初始化为0 代表空 1则使用过
	int VerNum;
	edgeNum = getEdges(G, edges);

	//	if(G.gKind==UDG||G.gKind==UDN)//无向图 执行两倍次数
	//	VerNum=(G.VerNum-1);
	//else
	VerNum = (G.VerNum - 1);

	for (i = 1; i <= G.VerNum; i++) {
		conVerID[i] = i;
	}

	for (i = 1; i <= VerNum; i++) {

		minEdge = GetMinEdge(edges, edgeNum);

		while (conVerID[edges[minEdge].vBegin] == conVerID[edges[minEdge].vEnd]) {//比较所选边的两个顶点的权值 相同则说明是环
			edges[minEdge].eWeight = INF;//此边改为不可用

			minEdge = GetMinEdge(edges, edgeNum);//重新获取最短边
												 //printf("conVerID[edges[minEdge].vBegin]= %d\nconVerID[edges[minEdge].vEnd]= %d\nminEdge= %d\n\n",conVerID[edges[minEdge].vBegin],conVerID[edges[minEdge].vEnd],minEdge);
												 //getchar();	
			if (conVerID[edges[minEdge].vBegin] == conVerID[edges[minEdge].vEnd])
				break;
		}

		conVerID[edges[minEdge].vBegin] = INF;
		conVerID[edges[minEdge].vEnd] = INF;//更新权值 选中的统一用INF表示 

		updateTreeEdges(edges, Treeedges, minEdge, i);
	}
	initialTree(T);
	for (i = 1; i <= VerNum; i++) {
		T.node[i].data = G.Data[Treeedges[i].vEnd];
		T.node[i].parent = G.Data[Treeedges[i].vBegin];
		T.n++;
		printf("%d: MineWeight=%-2d    %-2c->%-2c \n", i, Treeedges[i].eWeight, G.Data[Treeedges[i].vBegin], G.Data[Treeedges[i].vEnd]);
	}
}

void _6() {
	Graph udn6, un8;
	pTree  Tree_udn6, Tree_un8;
	char File_udn6[80], File_un8[80];
	sprintf(File_udn6, "D:\\grpData\\udn6.grp", 80);
	sprintf(File_un8, "D:\\grpData\\un8.grp", 80);
	CreateGrpFromFile(File_udn6, udn6);
	CreateGrpFromFile(File_un8, un8);
	printGraph(udn6);
	Kruskal(udn6, Tree_udn6);
	printf("\n\n");
	printGraph(un8);
	Kruskal(un8, Tree_un8);
}
//=============================Dijkstra算法==========================================


void printDijkstra(Graph &G, int path[], int dist[], int vID) {
	int sPath[MaxVerNum];
	int vPre;
	int top = -1;
	int i, j;
	//printf("6");
	for (i = 1; i <= G.VerNum; i++) {
		printf("%-c->%-c ", G.Data[vID], G.Data[i]);
		if (dist[i - 1] == INF)
			printf("NoPath\n");
		else {
			printf("最短距离:%-2d路径:", dist[i - 1]);
		}

		top++;
		sPath[top] = i;
		vPre = path[i - 1];
		while (vPre != -1) {
			top++;
			sPath[top] = vPre;
			vPre = path[vPre - 1];
			//printf("艹");
		}
		if (dist[i - 1] != INF) {
			if (G.Data[sPath[top]] != G.Data[vID])
				printf("%-2c ", G.Data[vID]);
			for (j = top; j >= 0; j--) {
				//cout<<G.Data[sPath[j]-1]<<" ";
				printf("%-2c ", G.Data[sPath[j]]);
			}
		}
		top = -1;
		printf("\n");
	}
}

void Dijkstra(Graph &G, int path[], int dist[], int vID) {
	//path[]保存最短路径信息 dist[]保存最短路径距离值  vID为指定起始顶点编号
	int solved[MaxVerNum];
	int i, j, v;
	cellType minDist;//初始化集合S和距离向量
	for (i = 1; i <= G.VerNum; i++) {
		solved[i - 1] = 0;//所有顶点未求解
		dist[i - 1] = G.AdjMatrix[vID][i];
		if (dist[i - 1] != INF)
			path[i - 1] = vID;//第i顶点前驱为vID
		else
			path[i - 1] = -1;//i无前驱
	}
	solved[vID - 1] = 1;//vID已求解
	dist[vID - 1] = 0;//vID到自身距离为0
	path[vID] = -1;//vID无前驱
				   //依次找出其他n-1个顶点加入已求解集合S
	for (i = 1; i <= G.VerNum; i++) {
		minDist = INF;
		for (j = 1; j <= G.VerNum; j++) {
			if (solved[j - 1] == 0 && dist[j - 1]<minDist) {
				v = j;
				minDist = dist[j - 1];
			}
		}
		if (minDist == INF)
			return;
		//printf("选择顶点:%c 距离为:%d \n",G.Data[v-1],minDist);
		solved[v - 1] = 1;
		for (j = 1; j <= G.VerNum; j++) {
			if (solved[j - 1] == 0 && (minDist + G.AdjMatrix[v][j])<dist[j - 1]) {
				dist[j - 1] = minDist + G.AdjMatrix[v][j];
				path[j - 1] = v;
			}
		}
	}
}


void _7() {
	Graph udn6, un8, dn8, dn10;
	char File_udn6[80], File_un8[80], File_dn8[80], File_dn10[80];
	sprintf(File_udn6, "D:\\grpData\\udn6.grp", 80);
	sprintf(File_un8, "D:\\grpData\\un8.grp", 80);
	sprintf(File_dn8, "D:\\grpData\\dn8.grp", 80);
	sprintf(File_dn10, "D:\\grpData\\dn10.grp", 80);
	CreateGrpFromFile(File_udn6, udn6);
	CreateGrpFromFile(File_un8, un8);
	CreateGrpFromFile(File_dn8, dn8);
	CreateGrpFromFile(File_dn10, dn10);
	int path[MaxVerNum], dist[MaxVerNum], vID;
	printGraph(udn6);
	Dijkstra(udn6, path, dist, 1);
	printDijkstra(udn6, path, dist, 1);
	printf("\n====================================================\n");
	printGraph(un8);
	Dijkstra(un8, path, dist, 1);
	printDijkstra(un8, path, dist, 1);
	printf("\n====================================================\n");
	printGraph(dn8);
	Dijkstra(dn8, path, dist, 1);
	printDijkstra(dn8, path, dist, 1);
	printf("\n====================================================\n");
	printGraph(dn10);
	Dijkstra(dn10, path, dist, 1);
	printDijkstra(dn10, path, dist, 1);
}
//==============Floyd算法===================================
void Floyd(Graph &G) {
	cellType dist[MaxVerNum][MaxVerNum];
	int path[MaxVerNum][MaxVerNum];
	int i, j, m, k;
	for (i = 1; i <= G.VerNum; i++) {//初始化
		for (j = 1; j <= G.VerNum; j++) {
			dist[i][j] = G.AdjMatrix[i][j];

			if (i != j && G.AdjMatrix[i][j] < INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}
	for (m = 1; m <= G.VerNum; m++) {
		for (i = 1; i <= G.VerNum; i++) {
			for (j = 1; j <= G.VerNum; j++) {
				if (i != j && dist[i][m] + dist[m][j] < dist[i][j]) {
					dist[i][j] = dist[i][m] + dist[m][j];//dist是i j 的距离
					path[i][j] = path[m][j];//path中保存的是j到i最短路径上 j的前驱
				}
			}
		}
	}/*
	 printf("Dist:\n");
	 for(i=1;i<=G.VerNum;i++){
	 for(j=1;j<=G.VerNum;j++){
	 if (dist[i][j]==INF){
	 printf("INF");
	 }
	 else
	 printf("%-2d ",dist[i][j]);
	 }
	 printf("\n");
	 }
	 printf("Path:\n");
	 for(i=1;i<=G.VerNum;i++){
	 for(j=1;j<=G.VerNum;j++){
	 if (path[i][j]==-1)
	 {
	 printf("%-2d ",0);
	 }
	 else
	 printf("%-2d ",path[i][j]);
	 }
	 printf("\n");
	 }
	 k=4;//1-7
	 while(k!=-1&&k!=1){
	 printf("%-2c ",G.Data[k]);
	 printf("K=%d  path[1][%d]=%d dist[1][%d]=%d\n",k,k,path[1][k],k,dist[1][k]);
	 k=path[1][k];
	 }
	 printf()
	 */
	for (i = 1; i<G.VerNum; i++) {
		for (j = 1; j<G.VerNum; j++) {
			k = j;
			if (j != i) {
				printf("%-c->%-2c: ", G.Data[i], G.Data[j]);
				while (k != -1) {
					printf("%-2c", G.Data[k]);
					//printf("K=%d  path[0][%d]=%d",k,k,path[0][k]);
					k = path[i][k];
				}
				//printf("%-2c",G.Data[i]);
				printf("\n");
			}
			else
				printf("%-c->%-2c: %-c \n", G.Data[i], G.Data[j], G.Data[i]);
		}
		printf("\n");
	}
}



void _8() {
	Graph udn6, un8, dn8, dn10;
	char File_udn6[80], File_un8[80], File_dn8[80], File_dn10[80];
	sprintf(File_udn6, "D:\\grpData\\udn6.grp", 80);
	sprintf(File_un8, "D:\\grpData\\un8.grp", 80);
	sprintf(File_dn8, "D:\\grpData\\dn8.grp", 80);
	sprintf(File_dn10, "D:\\grpData\\dn10.grp", 80);
	CreateGrpFromFile(File_udn6, udn6);
	CreateGrpFromFile(File_un8, un8);
	CreateGrpFromFile(File_dn8, dn8);
	CreateGrpFromFile(File_dn10, dn10);

	printGraph(udn6);
	Floyd(udn6);

	printGraph(un8);
	Floyd(un8);

	Floyd(dn8);

	printGraph(dn10);
	Floyd(dn10);
}

int Find_0_Arc(Graph &G, int list[]) {//寻找第一个入度为0的节点 输出 同时删除节点
	int i, j, iFlag;
	//printf("\n");
	for (i = 1; i <= G.VerNum; i++) {//从1开始
		iFlag = 1;
		while (list[i] == INF) {
			i++;
		}//以删除节点 跳过循环		
		for (j = 1; j <= G.VerNum; j++) {
			//printf("G.AdjMatrix[%d][%d]=%d \n",j,i,G.AdjMatrix[j][i]);
			if (G.AdjMatrix[j][i] != 0 && G.AdjMatrix[j][i] != INF)//iFlag=1  如果检测到入度 则iFlag=0  
				iFlag = 0;
		}
		//printf("555");
		if (iFlag == 1) {//入度为0 iFlag=1
						 //i是入度为0的节点
			for (j = 1; j <= G.VerNum; j++) {
				G.AdjMatrix[i][j] = 0;
			}//删除路径
			list[i] = INF;//删除节点
						  //printf("==========================\n");
			return i;//退出
		}
		//printf("==========================\n");
	}
	return INF;
}

int Topological(Graph &G) {
	int UsedARC[MaxVerNum], k = 0, count = 0;
	printf("拓补序列:");
	k = Find_0_Arc(G, UsedARC);
	while (k != INF) {
		printf("%d ", k);
		k = Find_0_Arc(G, UsedARC);
		count++;
	}
	if (count != G.VerNum) {
		printf("存在回路，拓补排序失败\n");
		return false;
	}
	else {
		printf("\n");
		return true;
	}
}

void _9() {
	Graph top6dg1, top7dg1, dn8, dn10;
	char File_top6dg1[80], File_top7dg1[80], File_dn8[80], File_dn10[80];
	sprintf(File_top6dg1, "D:\\grpData\\top6dg1.grp", 80);
	sprintf(File_top7dg1, "D:\\grpData\\top7dg1.grp", 80);
	sprintf(File_dn8, "D:\\grpData\\dn8.grp", 80);
	sprintf(File_dn10, "D:\\grpData\\dn10.grp", 80);
	CreateGrpFromFile(File_top6dg1, top6dg1);
	CreateGrpFromFile(File_top7dg1, top7dg1);
	CreateGrpFromFile(File_dn8, dn8);
	CreateGrpFromFile(File_dn10, dn10);

	printGraph(top6dg1);
	Topological(top6dg1);
	printf("==============================================================================\n");
	printGraph(top7dg1);
	Topological(top7dg1);
	printf("==============================================================================\n");
	printGraph(dn8);
	Topological(dn8);
	printf("==============================================================================\n");
	printGraph(dn10);
	Topological(dn10);
	printf("==============================================================================\n");
}

/*
int GetHead(Graph &G){//返回入度0节点
int i,j,iFlag;
for(i=1;i<=G.VerNum;i++){
iFlag=1;

for(j=1;j<=G.VerNum;j++){

if(G.AdjMatrix[j][i]!=INF)
iFlag=0;
}

if(iFlag==1)
return i;
}

return INF;
}
int GetEnd(Graph &G){//返回出度0节点
int i,j,iFlag;
for(i=1;i<=G.VerNum;i++){
iFlag=1;

for(j=1;j<=G.VerNum;j++){
if(G.AdjMatrix[i][j]!=INF)
iFlag=0;
}

if(iFlag==1)
return i;
}

return INF;
}
int TopologicalListAOE(Graph &G, int list[], int E[]) {
	int UsedARC[MaxVerNum], k = 0, count = 0, i = 1, c, miniPath;
	//printf("拓补序列:");
	for (c = 1, miniPath = INF - 1; c<G.VerNum; c++) {
		E[c] = 0;
	}
	k = Find_0_Arc(G, UsedARC);
	list[i++] = k;
	while (k != INF) {
		//printf("%d ",k);
		k = Find_0_Arc(G, UsedARC);
		list[i++] = k;
		count++;
		if (k != INF) {
			for (c = 1; c<G.VerNum; c++) {
				if (E[k] + G.AdjMatrix[k][c]>E[c]) {
					E[c] = E[k] + G.AdjMatrix[k][c];//E[]初始化为0
				}
			}
		}
	}
	if (count != G.VerNum) {
		//printf("存在回路，拓补排序失败\n");
		return false;
	}
	else {
			printf("\n");
		return true;
	}
}

void CriticalPath(Graph &G) {
	int head, end, list[MaxVerNum], i, E[MaxVerNum], c;
	//head=GetHead(G);
	//end=GetEnd(G);
	if (TopologicalListAOE(G, list, E) == false) {
		printf("存在环");
		return;
	}
	//for(i=1;i<=G.VerNum;i++){
	//	printf("%d ", list[i] );
	//}
	head = list[1];
	end = list[G.VerNum];
	//printf("%d %d", head,end );
	for (c = 1; c<G.VerNum; c++) {
		printf("%d ", E[c]);
	}
}//不要了不要了 自己想的 有时间再完善
*/
void FindInDegree(Graph G, int indegree[]){
	int i,j;
    for (i=1;i<=G.VerNum;i++){
        for (j=1;j<=G.VerNum;j++){
            if (G.AdjMatrix[i][j] != INF)
                indegree[j]++;//入度        
        }
    }
}//传入图  节点入度数组  返回时 图节点对应度保存在数组里

bool TopologicalSort(Graph &G,stack &S,int ve[],int vl[])
{
    int indegree[MaxVerNum] = {0};
    FindInDegree(G,indegree);
    Queue Q;
    initalQueue(Q);
    int i,j;
    for (i=1;i<=G.VerNum;i++)
    {
        if (indegree[i] == 0)
        {
            EnQueue(Q,i);
        }
    }
    int count = 0;
    while (!QueueEmpty(Q))
    {
        i = outQueue(Q);
        Push(S,i);
        //outQueue(Q);
        count++;
        for (j=1;j<=G.VerNum;j++){
            if (G.AdjMatrix[i][j] != INF)
            {
                if (!(--indegree[j])){
                    EnQueue(Q,j);
                }
                if (ve[i]+G.AdjMatrix[i][j]>ve[j]){
                    ve[j]=ve[i]+G.AdjMatrix[i][j];
                }
            }
        }
    }
    if (count < G.VerNum)
        return false;
    else
        return true;
}



int CriticalPath(Graph G)
{
    stack S;
    Initstack(S);
    int i,j;
    int temp;
    int ve[MaxVerNum] = {0};
	int vl[MaxVerNum] = {INF};
	
    if (TopologicalSort(G,S,ve,vl)!=true)
        return false;
    for (i=1;i<=G.VerNum;i++){
        vl[i] = INF;
    }
    temp=Pop(S);
    Push(S,temp);
    vl[temp]=ve[temp];
    printf("top=%d   \tve[top]=%d\tvl[top]=%d\n",temp,ve[temp],vl[temp]);
    while (!IsEmpty(S))
    {
        i = Pop(S);
        printf("Pop(S)=%d\t",i);
        for (j=1;j<=G.VerNum;j++){
            if (G.AdjMatrix[i][j] != INF){
      
                if (vl[j]-G.AdjMatrix[i][j]<vl[i]){
                    vl[i]=vl[j]-G.AdjMatrix[i][j];
                }
            }
        }
        //printf("Vl[%d]=%-2d\n",i,vl[i]);
        printf("Ve[%d]=%-2d\tVl[%d]=%-2d\t\n",i,ve[i],i,vl[i]);
                
    } 
    printf("\n");
    for (i=1;i<=G.VerNum;i++){
        for (j=1;j<=G.VerNum;j++){
            if (G.AdjMatrix[i][j] != INF){
            	if (ve[i] == vl[j]-G.AdjMatrix[i][j]){
                    printf("(%c->%c):%d\n",G.Data[i],G.Data[j],G.AdjMatrix[i][j]);
                }
            }
        
        }
        
    }
    printf("\n最长路径为%d\n\n",vl[temp]);
    return true;
}





void _10() {
	Graph top6dg1, top7dg1, dn8, dn10;
	char File_top6dg1[80], File_top7dg1[80], File_dn8[80], File_dn10[80];
	sprintf(File_top6dg1, "D:\\grpData\\top6dg1.grp", 80);
	sprintf(File_top7dg1, "D:\\grpData\\top7dg1.grp", 80);
	sprintf(File_dn8, "D:\\grpData\\dn8.grp", 80);
	sprintf(File_dn10, "D:\\grpData\\dn10.grp", 80);
	CreateGrpFromFile(File_top6dg1, top6dg1);
	CreateGrpFromFile(File_top7dg1, top7dg1);
	CreateGrpFromFile(File_dn8, dn8);
	CreateGrpFromFile(File_dn10, dn10);
	
	dn8.AdjMatrix[5][1] = INF;//给的图存在环 这个删了一个边能用 其他不改了  
	printGraph(dn8);
	CriticalPath(dn8);
}









/*
edgeNum=getEdges(G,edges);
printf("边数=%d\neWeight[%d]:",edgeNum,edgeNum);
for(i=1;i<=edgeNum;i++){
printf("%d ",edges[i].eWeight);
}
printf("\n");
printf("最小边 edges[%d].eWeight=%d\n",GetMinEdge(edges,edgeNum),edges[GetMinEdge(edges,edgeNum)].eWeight);
*/