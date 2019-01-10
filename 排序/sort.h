#define MAXLEN 1000
#include <iostream>
#include <time.h>
using namespace std;
static int Count1_1=0,Count1_2=0;
typedef struct
{
	int data[MAXLEN];
	int length;
}List;

typedef struct node{
	int key,location;
	struct node *lchild,*rchild;
}Bnode;

typedef struct
{
	int length;
	int bijiao;
	int change;
	int time;
}Datavalue;




void ReadFile(List &l,int Mark)//读取预先存放的数据
{
	FILE *pFile;
	int i=1,j;
	char fileMark[8][80];
    sprintf(fileMark[1],"W:\\ListData\\test9\\1.List",80);
    sprintf(fileMark[2],"W:\\ListData\\test9\\2.List",80);
    sprintf(fileMark[3],"W:\\ListData\\test9\\3.List",80);
    sprintf(fileMark[4],"W:\\ListData\\test9\\4.List",80);
    sprintf(fileMark[5],"W:\\ListData\\test9\\5.List",80);
    sprintf(fileMark[6],"W:\\ListData\\test9\\6.List",80);
    pFile = fopen(fileMark[Mark],"r");
    if(!pFile){														
		printf("Radom\n");
		for(j=1;j<=Mark;j++){
			l.data[j]=rand()%999;
		}
		l.length=--j;
		return;	//不存在就随机生成  此时mark为长度
	}
	while(fscanf(pFile,"%d,",&l.data[i]) != EOF){
		i++;
	}
	l.length=--i;
	fclose(pFile);	
	return ;//完成
}

void QuickSortPrint(List &List,int l,int r){//快速排序  打印
	if(l<r){    //l<r为返回条件
		int i=l,j=r,temp,head;
//==========================================
		temp=List.data[l];//基准值为第一个值
		//printf("轮次排列中\n");
		while(i<j){//相遇时停止

			while(i<j &&    List.data[j]>=temp    && Count1_2++) 
				j--; //从后向前  直到找到比中间值大的 
			if(i<j){//如果此时还满足条件
				List.data[i]=List.data[j];//交换 i向前
				i++;//i向前   此时List.data[j]有两个，一个时原始位置，一个是基准值确定的位置
					//下面的List.data[i]就是替换了原始位置
				Count1_1++;//计数用
			}

			while(i<j &&    List.data[i]<=temp    && Count1_2++)
				i++;
			if(i<j){
				List.data[j]=List.data[i];//这里的就List.data[j]已复制到应该的位置 
										  //直接替换原始位置
				j--;//j向前
				Count1_1++;//计数用
			}
			/*
			for(head=l;head<=r;head++)
				printf("%-3d  ",List.data[head]);
			printf("\n");*/
			//过程中  每次都是利用List.data[l]即基准值为空间  排序过程中数组没有temp
		}

		List.data[i]=temp;//这里排序完成   也确定基准值的位置   替换掉重复的即可
//===========================================================
		//printf("轮次排列完成\n");
		for(head=l;head<=r;head++){
			if(List.data[head]==temp) printf("[");
			printf("%-3d",List.data[head]);
			if(List.data[head]==temp) printf("] ");
			else printf("  ");
		}
		putchar('\n');
		//putchar('\n');
		//下面只要遍历执行分割好的序列就行
		QuickSortPrint(List,l,i-1);
		QuickSortPrint(List,i+1,r);
	}
	return;
}

void QuickSort(List &List,int l,int r){
	if(l<r){
		int i=l,j=r,temp=List.data[l];
		while(i<j){
			while(i<j&&List.data[j]>=temp&&Count1_2++) 
				j--;
			if(i<j){
				List.data[i++]=List.data[j];
				Count1_1++;
			}
			while(i<j&&List.data[i]<=temp&&Count1_2++)
				i++;
			if(i<j){
				List.data[j--]=List.data[i];
				Count1_1++;
			}
		}
		List.data[i]=temp;
		QuickSort(List,l,i-1);
		QuickSort(List,i+1,r);
	}
	return;
}

void PrintList_2(List &l)//带显示%3的打印
{
	int i=1;
	printf("数值:");
	while(i!=l.length+1){
		printf("%-3d ",l.data[i]);
		i++;
	}
	i=1;
	printf("\n余数:");
	while(i!=l.length+1){
		printf("%-3d ",l.data[i]%3);
		i++;
	}
	printf("\n");
}

void PrintList(List &l)//打印数据
{
	int i=1;
	//printf("数值:");
	while(i!=l.length+1){
		printf("%-3d ",l.data[i]);
		i++;
	}
	printf("\n");
}

void SortBy3(List &l){//0左边   1中间   2右边
	int count,Flag,temp;
	count=1;//全局变量   计数用
	for(Flag=1;Flag<=l.length;Flag++){
		if((l.data[Flag])%3==0){//%3=0的数
			temp=l.data[Flag];
			l.data[Flag]=l.data[count];
			l.data[count]=temp;
			//交换到最前面，之后向前交换
			count++;
		}
	}//
	for(Flag=count;Flag<=l.length;Flag++){
		if((l.data[Flag])%3==1){
			temp=l.data[Flag];
			l.data[Flag]=l.data[count];
			l.data[count]=temp;
			//类似上面的   只是从已经交换完成的数组的位置开始
			count++;
		}
	}
}

void inTravel(Bnode *T){
	if(T==NULL) return;
	inTravel(T->lchild);
	printf("%d ",T->key);
	inTravel(T->rchild);
}

void shellSort(List &l,int mind) {
        int length = l.length;
        int inner, outer;
        int temp,x=0;
        int h = 0;
        while (h <= length / mind)
            h = h * mind + 1;
        while (h > 0) {
            
            for (outer = h; outer < length; outer++)
            {
                temp = l.data[outer];
                inner = outer;
                while (inner > h - 1 && l.data[inner-h] >= temp)//插入排序移动 
                {
                    l.data[inner] = l.data[inner-h];
                    inner-=h;
                    x++;
                }
                l.data[inner] = temp;
            }
            
            h = (h - 1) / mind;
            PrintList(l);
        }
        printf("步长%d\t移动次数%d\n",mind,x);

        return;
    }

void Buildheap(List &l,List &T){
	int i=1;
	while(i!=l.length+1){
		T.data[i]=l.data[i];
		i++;
	}
	T.length=l.length;
}
void heapPrint(List &l,int mark){
	int i=1;
	//printf("数值:");
	while(i!=l.length+1){
		printf("%-3d ",l.data[i]);
		if(i==mark) printf("    ");
		i++;
	}
	printf("\n");
}

void heapsort(List &l,List &T,int i){
	int j,temp;
	for(j=T.length;j>1;j--){
		if(T.data[j]>T.data[j/2]){
			temp=T.data[j];
			T.data[j]=T.data[j/2];
			T.data[j/2]=temp;
			
			temp=l.data[j];
			l.data[j]=l.data[j/2];
			l.data[j/2]=temp;
		}
	}

	T.data[1]=T.data[T.length];

	temp=l.data[1];
	l.data[1]=l.data[T.length];
	l.data[T.length]=temp;
	T.length--;
	heapPrint(l,T.length);
	//PrintList(T);
	if(T.length==0) return;
	heapsort(l,T,T.length);
}



void _1(){
	int i,j,temp,text=0;
	Count1_1=0;
	Count1_2=0;
	List A;
	A.length=0;
	i=rand()%100;
	i=i+100;
	//i=10;//这里观察用   之后注释掉
	printf("长度=%d",i);
	printf("\n==========================================================================================================================\n");
	printf("生成数组:\n");
	for(j=0;j<i;j++){
		A.data[j]=rand()%999;
	}
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		A.length++;
		text++;
		if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n");
	printf("排序完成:\n");
	text=0;
	//===============
	long t1,t2;
	t1=clock();
	//===============
	QuickSort(A,0,A.length-1);//这里  传入A。length-1   因为从0开始计数
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		text++;
		if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n");
	printf("交换次数%d\t",Count1_1);
	printf("比较次数%d\n\n",Count1_2);
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	//system("pause");
}

void _2(int mark){
	List A;
	ReadFile(A,mark);
	printf("数组:\n");
	PrintList_2(A);
	//printf("length= %d",A.length);
	//===============
	long t1,t2;
	t1=clock();
	//===============	
	SortBy3(A);
	printf("调整完成:\n");
	PrintList_2(A);
	printf("==========================================================================================================================\n");
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	return;
}

void _3(){
	List A;
	ReadFile(A,30);
	printf("数组:\n");
	PrintList(A);
	//printf("length= %d",A.length);
	printf("排序中:\n");
	//===============
	long t1,t2;
	t1=clock();
	//===============
	shellSort(A,3);
	printf("排序完成:\n");
	PrintList(A);
	printf("==========================================================================================================================\n");
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	return;
}

void _4(){
	int i,j,temp,text=0;

	Count1_1=0;
	Count1_2=0;
	List A;
	A.length=0;
	i=20;
	//i=8;
	printf("长度=%d",i);
	printf("\n==========================================================================================================================\n");
	printf("生成数组:\n");
	for(j=0;j<i;j++){
		A.data[j]=rand()%999;
	}
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		A.length++;
		text++;
		//if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n过程演示:\n\n");
	text=0;
	//===============
	long t1,t2;
	t1=clock();
	//===============
	QuickSortPrint(A,0,A.length-1);//这里  传入A。length-1   因为从0开始计数
	printf("==========================================================================================================================\n");
	printf("排序完成:\n");
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		text++;
		if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n");
	printf("交换次数%d\t",Count1_1);
	printf("比较次数%d\n\n",Count1_2);
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	//system("pause");
}

void _5(){
	List A,T;
	Bnode List;
	ReadFile(A,1);
	printf("数组:\n");
	PrintList(A);
	Buildheap(A,T);
	printf("排序中:\n");
	//===============
	long t1,t2;
	t1=clock();
	//===============
	heapsort(A,T,T.length);
	printf("排序完成:\n");
	PrintList(A);
	//======================
	t2=clock();
	printf("时间为%dms\n",(t2-t1));
	//=======================
}

void Merge(int data[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;   
    int *temp = new int[high - low + 1];//申请temp数组暂存合并的有序序列
    if(!temp){//内存分配失败 
        printf("Error!");
        return;
    }
    while(i <= mid && j <= high){//顺序选取两个有序区的较小元素，存储到temp中
        if(data[i] <= data[j])                 
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];
    }
    while(i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = data[i++];
    while(j <= high)
        temp[k++] = data[j++];

    for(i=low, k=0; i <= high; i++, k++)//将排好序的存回data中low到high这区间 
        data[i] = temp[k];
    delete [ ]temp;
    return;//删除指针
}

void MergeSort(int data[], int low, int high){
	if(low<high){
        int mid = (low + high) / 2;
        MergeSort(data, low, mid);
        MergeSort(data, mid + 1, high);
        Merge(data, low, mid, high);
    }
    return;
}

void DevideList(List &l){
	int list[MAXLEN];
	int	i=0,j;
	while(i!=l.length){
		list[i]=l.data[i+1];
		i++;
	}
	i--;
	//printf("===%d==a[]=%d",i,list[i]);
	MergeSort(list,0,i);
	for(int j = 0; j < i+1; j++)
       l.data[j+1]=list[j];
       // printf("%-3d ",list[j]);
}

void _6(){
	List A,T;
	Bnode List;
 	//===============
	long t1,t2;
	t1=clock();
	//===============
	ReadFile(A,150);
	printf("数组:\n");
	PrintList(A);
	DevideList(A);
	PrintList(A);
 	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
}

//===========================================================






void complex_1(Datavalue &datavalue){
	int i,j,temp,text=0;
	Count1_1=0;
	Count1_2=0;
	List A;
	A.length=0;
	//i=rand()%100;
	i=datavalue.length;
	//i=10;//这里观察用   之后注释掉
	printf("长度=%d",i);
	printf("\n==========================================================================================================================\n");
	printf("生成数组:\n");
	for(j=0;j<i;j++){
		A.data[j]=rand()%999;
	}
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		A.length++;
		text++;
		if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n");
	printf("排序完成:\n");
	text=0;
	//===============
	long t1,t2;
	t1=clock();
	//===============
	QuickSort(A,0,A.length-1);//这里  传入A。length-1   因为从0开始计数
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		text++;
		if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n");
	
	printf("交换次数%d\t",Count1_1);
	datavalue.change=Count1_1;
	printf("比较次数%d\n\n",Count1_2);
	datavalue.bijiao=Count1_2;
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	datavalue.time=t2-t1;
	//=======================
	//system("pause");
}


void complex_2(Datavalue &datavalue){
	List A;
	ReadFile(A,datavalue.length);
	printf("数组:\n");
	PrintList_2(A);
	//printf("length= %d",A.length);
	//===============
	long t1,t2;
	t1=clock();
	//===============	
	SortBy3(A);
	printf("调整完成:\n");
	PrintList_2(A);
	printf("==========================================================================================================================\n");
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	return;
}


void complex_3(Datavalue &datavalue){
	List A;
	ReadFile(A,datavalue.length);
	printf("数组:\n");
	PrintList(A);
	//printf("length= %d",A.length);
	printf("排序中:\n");
	//===============
	long t1,t2;
	t1=clock();
	//===============
	shellSort(A,3);
	printf("排序完成:\n");
	PrintList(A);
	printf("==========================================================================================================================\n");
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	return;
}

void complex_4(Datavalue &datavalue){
	int i,j,temp,text=0;

	Count1_1=0;
	Count1_2=0;
	List A;
	A.length=0;
	//i=20;
	i=datavalue.length;
	printf("长度=%d",i);
	printf("\n==========================================================================================================================\n");
	printf("生成数组:\n");
	for(j=0;j<i;j++){
		A.data[j]=rand()%999;
	}
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		A.length++;
		text++;
		//if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n过程演示:\n\n");
	text=0;
	//===============
	long t1,t2;
	t1=clock();
	//===============
	QuickSortPrint(A,0,A.length-1);//这里  传入A。length-1   因为从0开始计数
	printf("==========================================================================================================================\n");
	printf("排序完成:\n");
	for(j=0;j<i;j++){
		printf("%-3d  ",A.data[j]);
		text++;
		if(text%25==0) printf("\n");
	}
	printf("\n==========================================================================================================================\n");
	printf("交换次数%d\t",Count1_1);
	printf("比较次数%d\n\n",Count1_2);
	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
	//system("pause");
}


void complex_5(Datavalue &datavalue){
	List A,T;
	Bnode List;
	ReadFile(A,datavalue.length);
	printf("数组:\n");
	PrintList(A);
	Buildheap(A,T);
	printf("排序中:\n");
	//===============
	long t1,t2;
	t1=clock();
	//===============
	heapsort(A,T,T.length);
	printf("排序完成:\n");
	PrintList(A);
	//======================
	t2=clock();
	printf("时间为%dms\n",(t2-t1));
	//=======================
}



void complex_6(Datavalue &datavalue){
	List A,T;
	Bnode List;
 	//===============
	long t1,t2;
	t1=clock();
	//===============
	ReadFile(A,datavalue.length);
	printf("数组:\n");
	PrintList(A);
	DevideList(A);
	PrintList(A);
 	//======================
	t2=clock();
	printf("用时%dms\n",(t2-t1));
	//=======================
}






/*
void Buildheap(List &l,Bnode *T,int i){
	T->key=l.data[i];
	T->location=i;
	//printf("-%d-",T->key);
	if(i*2<=l.length){
		Bnode *newnodel;
		newnodel=(Bnode *)malloc(sizeof(Bnode));
		T->lchild=newnodel;
		Buildheap(l,T->lchild,i*2);
	}
	else{
		T->lchild=NULL;
	}
	if(i*2+1<=l.length){
		Bnode *newnoder;
		newnoder=(Bnode *)malloc(sizeof(Bnode));
		T->rchild=newnoder;
		Buildheap(l,T->rchild,i*2+1);
	}
	else{
		T->rchild=NULL;
	}
	return;
}

void heapsort(List &l,Bnode *P){
	int temp;
	Bnode *T;
	T=P;
	while(T!=NULL){
		if(T->key<T->lchild->key){
			temp=T->key;
			T->key=T->lchild->key;
			T->lchild->key=temp;
			//二叉树数值交换
			temp=T->location;
			T->location=T->lchild->location;
			T->lchild->location=temp;
			//二叉树标记交换
			temp = l.data[T->location];
			l.data[T->location]=l.data[T->lchild->location];
			l.data[T->lchild->location]=temp;
			//原表处理
		}
		T=T->lchild;
	}
	T=P;
	while(T->location!=l.length){
		T=T->lchild;
	}
}


void heapsort(List &l,List &T){
	int i,temp;
	sort:
	if(T.length==0) return;
	i=1;
	while(i<=T.length){
		if(T.data[i]<T.data[i*2]){
			temp=T.data[i];
			T.data[i]=T.data[i*2];
			T.data[i*2]=temp;
			
			temp=l.data[i];
			l.data[i]=l.data[i*2];
			l.data[i*2]=temp;
		}
		i=i*2;
	}
	i=1;
	while(i<=T.length){
		if(T.data[i]<T.data[i*2+1]){
			temp=T.data[i];
			T.data[i]=T.data[i*2+1];
			T.data[i*2+1]=temp;
			
			temp=l.data[i];
			l.data[i]=l.data[i*2+1];
			l.data[i*2+1]=temp;
		}
		i=i*2+1;
	}
	//temp=T.data[1];
	T.data[1]=T.data[T.length];
	//T.data[T.length]=temp;

	temp=l.data[1];
	l.data[1]=l.data[T.length];
	l.data[T.length]=temp;

	T.length--;
	PrintList(T);
	goto sort;
}


void hebing(int a[],int b[],int list[]){
	int i=1,j=1,k=1;
	while(a[i] != 0 || b[j] != 0){
		if(a[i]>b[j]){
			list[k++]=a[i];
			i++;
		}
		else{
			list[k++]=b[j];
			j++;
		}
	}
}



void fengli(int list[]){//把list拆分到ab 返回时已经有序
	
	int a[MAXLEN]={-1},b[MAXLEN]={-1},i=1,j=1,length=0;
	while(list[i]!=0){
		length++;
		i++;
	}//获取list长度
	if(length==2) return;//判断是否为1  是则退出
	for(i=1;i<length/2;i++){
		a[i]=list[i];
	}
	for(;i<=length;i++){
		b[j]=list[j];
		j++;
	}//拆分完成   现在在ab里
	//printf("666666666");
	//fengli(a);
	//fengli(b);
	//继续拆分ab  返回时ab已经合并

	hebing(a,b,list);//把ab有序合并到list
	for(i=1;i<=length;i++){
		printf("%-3d ",list[i]);

	}
}




void DevideList(List &l){

	int list[MAXLEN]={-1},a[MAXLEN]={-1},b[MAXLEN]={-1};
	int	i=1;
	while(i!=l.length+1){
		list[i]=l.data[i];
		i++;
		//printf("-");
	}
	i=1;
	fengli(list);
}




*/