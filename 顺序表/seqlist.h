#ifndef seqList
#define seqList

int _1()
{   
    int a[80]={0},b[80]={0},*p,*q,n;
    p=&a[0];
    printf("输入第一组数据 长度n>=10\n");
    crelist(p);
    printf("长度n=%d\n",getlength(p));
    findI(p,5);
    findI(p,getlength(p));
    findI(p,0);
    findI(p,getlength(p)+1);
    findI(p,getlength(p)+2);
    printf("\n第二组数据 长度n=0\n");
    a[0]=-1;
    findI(p,0);
    findI(p,2);
    return 0;
} 

int _2()
{   
    int a[80]={0},b[80]={0},*p,*q,n,x;
    p=&a[0];
    q=&b[0];
    printf("输入第一组数据 长度n>=10\n");
    crelist(p);
    printf("长度n=%d\n",getlength(p));

    coppppy(p,q);
    insrtIX(q,5,100);

    coppppy(p,q);
    insrtIX(q,getlength(q),100);
    
    coppppy(p,q);
    insrtIX(q,getlength(q)+1,100);

    coppppy(p,q);
    insrtIX(q,0,100);

    coppppy(p,q);
    insrtIX(q,1,100);

    coppppy(p,q);
    insrtIX(q,getlength(q)+2,100);
    
    printf("\n第二组数据 长度n=0\n");
    a[0]=-1;
    insrtIX(p,0,100);
    insrtIX(p,2,100);
    return 0;
} 

int _3()
{   
    int a[80]={0},b[80]={0},*p,*q,n,x;
    p=&a[0];
    q=&b[0];
    printf("输入第一组数据 长度n>=10\n");
    crelist(p);
    printf("长度n=%d\n",getlength(p));

    coppppy(p,q);
    del(q,5);

    coppppy(p,q);
    del(q,getlength(q));

    coppppy(p,q);
    del(q,1);
    
    coppppy(p,q);
    del(q,getlength(q)+1);

    coppppy(p,q);
    del(q,0);

    printf("\n第二组数据 长度n=0\n");
    a[0]=-1;

    del(p,5);

    return 0;
} 

int _4()
{   
    int a[80]={10,20,30,40,50,60,70,80,90,100,-1},b[80]={0},*p,*q,n,x;
    p=&a[0];
    q=&b[0];
    printf("L:");
    typlist(p);
    printf("\n");
    coppppy(p,q);
    printf("插入25\n");
    orderinsrt(q,25);
    printf("\n");
    coppppy(p,q);
    printf("插入85\n");
    orderinsrt(q,85);
    printf("\n");
    coppppy(p,q);
    printf("插入110\n");
    orderinsrt(q,110);
    printf("\n");
    coppppy(p,q);
    printf("插入8\n");
    orderinsrt(q,8);
    printf("\n");
    return 0;
} 

int _5()
{   
    int a[80]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,-1},b[80]={10,20,30,40,50,60,70,80,90,100,-1},*p,*q;
    p=&a[0];
    q=&b[0];
    typlist(p);
    OEseparation(p);
    printf("\n\n");
    typlist(q);
    OEseparation(q);

    return 0;
} 

int _6()
{   
	int a1[80]={1,3,6,10,15,16,17,18,19,20,-1},
		a2[80]={1,3,6,10,15,16,17,18,19,20,-1},
		a3[80]={-1},
		b1[80]={1,2,3,4,5,6,7,8,9,10,18,20,30,-1},
		b2[80]={2,4,5,7,8,9,12,22,-1},
		b3[80]={1,2,3,4,5,6,7,8,9,10,-1},
		*p,*q;
	p=&a1[0];
	q=&b1[0];
	printf("L1: ");
	typlist(p);
	printf("L2: ");
	typlist(q);
	printf("L3: ");
	comb(p,q);
    printf("\n");
	p=&a2[0];
	q=&b2[0];
	printf("L1: ");
	typlist(p);
	printf("L2: ");
	typlist(q);
	printf("L3: ");
	comb(p,q);
	printf("\n");
	p=&a3[0];
	q=&b3[0];
	printf("L1: ");
	typlist(p);
	printf("L2: ");
	typlist(q);
	printf("L3: ");
	comb(p,q);
	printf("\n");
    return 0;
} 

int _7()
{   
	int a1[80]={1,2,3,4,5,6,7,8,9,-1},
		a2[80]={1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9,-1},
		a3[80]={1,2,3,4,5,5,6,7,8,8,9,9,9,9,9,-1},
		*p1,*p2,*p3;
	p1=&a1[0];
	p2=&a2[0];
	p3=&a3[0];
	typlist(p1);
	printf("移动次数: %d \n",Deduplication(p1));
	typlist(p1);
	printf("\n");
	typlist(p2);
	printf("移动次数: %d \n",Deduplication(p2));
	typlist(p2);
	printf("\n");
	typlist(p3);
	printf("移动次数: %d \n",Deduplication(p3));
	typlist(p3);
	printf("\n");
    return 0;
} 


int crelist(int *p)//创建顺序表 传入表指针
{
    int i;
    printf("输入数据\n以-1结束\n\n");
    for(i = 0;(*(p+i-1)) != -1 ; i++){
        scanf("%d",&(*(p+i)));
    }
    printf("\n创建成功:");
    typlist(p);
    return 0;
}

int typlist(int *p)//打印顺序表 传入表指针
{
    int i;
    for(i = 0;(*(p+i)) != -1 ; i++){
        printf("%d ",(*(p+i)));
    }
    printf("\n");
    return 0;
}

int getlength(int *p)//求表长度 传入表指针
{
    int i,length=0;
    for(i = 0;(*(p+i)) != -1 ; i++){
        length++;
    }
    return length;
}

int findI(int *p,int n)//查找i,传入表指针,i值
{
    if( n > getlength(p) || n == 0){
        printf("第%2d个元素不存在 Error!\n",n);
        return 0;
    }
    printf("第%d个元素是%d\n",n,*(p+n-1));
    return 1;
}

int insrtIX(int *p,int n,int x)//插入,传入表指针,i，x
{
    int temp=0,i=0;

    if( n > getlength(p) || n == 0){
        printf("i=%2d,x=%3d 插入失败 Error!\n",n,x);
        return 0;
    }

    (*(p+getlength(p)+2)) = x;
    for(i = getlength(p)+2 ; i > n-1 ; i--){
        temp=(*(p+i));
        (*(p+i))=(*(p+i-1));
        (*(p+i-1))=temp;
    }
    printf("i=%2d,x=%3d 插入成功 ",n,x);
    typlist(p);
    return 1;
}

int coppppy(int *p,int *q)//复制p到q
{
    int i;
    for(i = 0;(*(p+i-1)) != -1 ; i++){
        (*(q+i))=(*(p+i));
    }
    return 0;
}

int del(int *p,int n){
    int temp,i;
    if( n > getlength(p) || n == 0){
        printf("删除第%2d个节点失败 Error!\n",n);
        return 0;
    }
    n;
    for(i = n ; i < getlength(p)+2 ; i++){
        temp=(*(p+i));
        (*(p+i))=(*(p+i-1));
        (*(p+i-1))=temp;
    }
    printf("删除第%2d个节点成功 ",n);
    typlist(p);
    return 0;
}

int orderinsrt(int *p,int x)
{
    int i;
    for(i = 0;(*(p+i)) != -1 ; i++){
        if( (*(p+i)) > x ) break;
    }

    insrtIXforOrderInsrt(p,++i,x);
    typlist(p);
    return 0;
}

int insrtIXforOrderInsrt(int *p,int n,int x)//插入,传入表指针,i，x
{
    int temp=0,i=0;

    if( n > getlength(p) || n == 0){
        //printf("i=%2d,x=%3d 插入失败 Error!\n",n,x);
        return 0;
    }

    (*(p+getlength(p)+2)) = x;
    for(i = getlength(p)+2 ; i > n-1 ; i--){
        temp=(*(p+i));
        (*(p+i))=(*(p+i-1));
        (*(p+i-1))=temp;
    }
    //printf("i=%2d,x=%3d 插入成功 ",n,x);
    //typlist(p);
    return 1;
}

int OEseparation(int *p)
{
    int i,odd[80],eve[80],m=0,n=0,*oddp,*evep;
    oddp=&odd[0];
    evep=&eve[0];
    for(i = 0;(*(p+i)) != -1 ; i++){
        if((*(p+i))%2)
            odd[m++]=(*(p+i));
        else
            eve[n++]=(*(p+i));
    }
    odd[m]=-1;
    eve[n]=-1;
    typlist(oddp);
    typlist(evep);
    return 0;
}

int comb(int *p,int *q)
{
	int a[80],*ptr,i=0,j=0,l=0;
	ptr = &a[0];
	while( *(p+i) != -1 && *(q+j) != -1){
            if( *(p+i) > *(q+j)){
                j++;
            }
            else if( *(p+i) < *(q+j) ){
                i++;
            }
            else{
               a[l++]=*(p+i);
               i++;
               j++;
            }
    }
    a[l]=-1;
    typlist(ptr);
}	

int Deduplication(int *p)
{
	int i = 0,count=0;
	while(*(p+i)!=-1){
        while(*(p+i) == *(p+i+1)){
            count += delForDeduplication(p,i+1);
            i--;
        }
        i++;
    }
    return count;
}

int delForDeduplication(int *p,int n){
    int temp,i,count=0;
    for(i = n ; i < getlength(p)+2 ; i++){
        temp=(*(p+i));
        (*(p+i))=(*(p+i-1));
        (*(p+i-1))=temp;
        count++;
    }
    return count;
}

#endif