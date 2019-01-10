#ifndef queueproject
#define queueproject
#define MAXLEN 100

typedef struct{
    char data[MAXLEN];
    int front;
    int rear;
} seqQueue;

typedef struct node{
	char data;
	struct node *next;
} Linknode;

typedef struct{
	Linknode *front;
	Linknode *rear;
	int length;
} LinkQueue;
//下面是程序

//这里是 循环队列 （划掉）  实验用不到  所以就固定长度了

int seq_1(){
	seqQueue s;
	if(initialQueue(&s))
  		printf("  初始化成功\n");
  	else
  		printf("  初始化失败\n");
	return 0;
}

int seq_2(){
	seqQueue s;
	char value='0';
  	initialQueue(&s);
  	printf("  输入 回车结束:");
  	getchar();
  	while(value != '\n'){
    	value = getchar();
    	if(value != '\n')//输入回车也会入队 
    	{
    		enQueue(&s,value);
  		}
  	}
  	//printf("Length=%d\n",queueLength(&s));
  	if(queueEmpty(&s))
    	printf("  Empty\n");
  	else
    printf("  NotEmpty\n");
	return 0;
}

int seq_3(){
	seqQueue s,s2;
	char value='0',fun='0';
  	int i=0;
  	initialQueue(&s);
  	printf("  第一组数据\n  输入n个数字 -1结束:");
  	getchar();
  	while(i != -1){
    	scanf("%d",&i);
    	if(i != -1)
    	{
    		enQueue(&s,i);
  		}
  	}
  	printf("  n=%d\n",queueLength(&s));
  	if(queueFull(&s))
    	printf("  Full\n");
  	else
    printf("  NotFull\n");
	initialQueue(&s2);
	printf("\n  第二组数据\n  1-99:");
	i=0;
	while(i != 99){
    	i++;
    	enQueue(&s2,i);
  	}
  	printf("\n  Length=%d\n",queueLength(&s2));
  	if(queueFull(&s2))
    	printf("  Full\n");
  	else
    printf("  NotFull\n");
	return 0;
}

int seq_4(){
	putchar('\n');
	seqQueue s,s2;
	char value='0',fun='0';
	int a,i;
  	initialQueue(&s);
  	printf("  第一组数据:4,7,8,12,20,50");
    enQueue(&s,4); 
    enQueue(&s,7); 
    enQueue(&s,8); 
    enQueue(&s,12); 
    enQueue(&s,20); 
    enQueue(&s,50);  		
  	a = queueFront(&s);
  	printf("\n  取队头元素:");
  	printf("%d",a);
  	printf("\n  元素个数为%d\n",queueLength(&s));
  	printf("  全元素出队");
  	while(!queueEmpty(&s)){	
  		a = outQueue(&s);
    	printf("%d ",a);
    }
    putchar('\n');
    initialQueue(&s2);
    printf("\n  第二组数据:a,b,c,d,f,g");
    enQueue(&s2,'a'); 
    enQueue(&s2,'b'); 
    enQueue(&s2,'c'); 
    enQueue(&s2,'d'); 
    enQueue(&s2,'f'); 
    enQueue(&s2,'g');
    value = queueFront(&s2);
  	printf("\n  取队头元素:");
  	putchar(value);
  	printf("\n  元素个数为%d\n",queueLength(&s2));  
  	printf("  全元素出队");
  	while(!queueEmpty(&s2)){	
  		value = outQueue(&s2);
    	putchar(value);
    	putchar(' ');
    }
    putchar('\n');
    putchar('\n');
	return 0;
}

int seq_5(){
	seqQueue s;
	int i=-1,a;
	initialQueue(&s);	
	printf("  ");
  	while(i != 0){
    	scanf("%d",&i);
    	if(i != 0){
    		if(i%2)
				enQueue(&s,i);  		
    		else
    			outQueue(&s);
  		}
  	}
	printf("  全元素出队:");
  	while(!queueEmpty(&s)){	
  		a = outQueue(&s);
    	printf("%d ",a);
    }
    putchar('\n');
	return 0;
}
//==================分割线==========================
//下面是链队列程序

int link_1(){
	LinkQueue s;
	if(initLinkQueue(&s))
  		printf("  初始化成功\n");
  	else
  		printf("  初始化失败\n");
	return 0;
}

int link_2(){
	LinkQueue s;
	char value='0';
  	initLinkQueue(&s);
  	printf("  输入 回车结束:");
  	getchar();
  	while(value != '\n'){
    	value = getchar();
    	if(value != '\n')//输入回车也会入队 
    	{
    		enLinkqueue(&s,value);
  		}
  	}
  	if(LinkQueueEmpty(&s))
    	printf("  Empty\n");
  	else
    printf("  NotEmpty\n");
	return 0;
}

int link_3(){
	LinkQueue s,s2;
	char value='0',fun='0';
  	int i=0;
  	initLinkQueue(&s);
  	printf("  第一组数据\n  输入n个数字 -1结束:");
  	getchar();
  	while(i != -1){
    	scanf("%d",&i);
    	if(i != -1)
    	{
    		enLinkqueue(&s,i);
  		}
  	}
  	printf("  n=%d\n",s.length);
  	if( 0 )
    	printf("  Full\n");
  	else
    printf("  NotFull\n");
	initLinkQueue(&s2);
	printf("\n  第二组数据\n  1-99:");
	i=0;
	while(i != 99){
    	i++;
    	enLinkqueue(&s2,i);
  	}
  	printf("\n  Length=%d\n",s2.length);
  	if( 0 )
    	printf("  Full\n");
  	else
    printf("  NotFull\n");
	return 0;
}

int link_4(){
  putchar('\n');
  LinkQueue s,s2;
  char value='0',fun='0';
  int a,i;
    initLinkQueue(&s);
    printf("  第一组数据:4,7,8,12,20,50");
    enLinkqueue(&s,4); 
    enLinkqueue(&s,7); 
    enLinkqueue(&s,8); 
    enLinkqueue(&s,12); 
    enLinkqueue(&s,20); 
    enLinkqueue(&s,50);     
    a = LinkqueueFront(&s);
    printf("\n  取队头元素:");
    printf("%d",a);
    printf("\n  元素个数为%d\n",s.length);
    printf("  全元素出队");
    while(!LinkQueueEmpty(&s)){ 
      a = outLinkQueue(&s);
      printf("%d ",a);
    }
    putchar('\n');
    initLinkQueue(&s2);
    printf("\n  第二组数据:a,b,c,d,f,g");
    enLinkqueue(&s2,'a'); 
    enLinkqueue(&s2,'b'); 
    enLinkqueue(&s2,'c'); 
    enLinkqueue(&s2,'d'); 
    enLinkqueue(&s2,'f'); 
    enLinkqueue(&s2,'g');
    value = LinkqueueFront(&s2);
    printf("\n  取队头元素:");
    putchar(value);
    printf("\n  元素个数为%d\n",s2.length);  
    printf("  全元素出队");
    while(!LinkQueueEmpty(&s2)){  
      value = outLinkQueue(&s2);
      putchar(value);
      putchar(' ');
    }
    putchar('\n');
    putchar('\n');
  return 0;
}

int link_5(){
	LinkQueue s;
	int i=-1,a;
	initLinkQueue(&s);	
	printf("  ");
  	while(i != 0){
    	scanf("%d",&i);
    	if(i != 0){
    		if(i%2)
				enLinkqueue(&s,i);  		
    		else
    			outLinkQueue(&s);
  		}
  	}
	printf("  全元素出队:");
  	while(!LinkQueueEmpty(&s)){	
  		a = outLinkQueue(&s);
    	printf("%d ",a);
    }
    putchar('\n');
	return 0;
}

//顺序队列函数
int initialQueue(seqQueue *s)//初始化
{
    s->front = 0;
    s->rear = 0;
    return 1;
}

int queueEmpty(seqQueue *s)//判断空 空返回1 非空返回0
{
    if( s->front == s->rear ) 
        return 1;
    else 
        return 0;
}

int queueFull(seqQueue *s)//判断满 满返回1 没满返回0
{
    if(s->rear >= MAXLEN) 
        return 1;
    else 
        return 0;
}

int queueLength(seqQueue *s)//返回长度
{
    return s->rear - s->front;
}

int queueFront(seqQueue *s)//获取队头   成功返回1 失败返回0
{
    char value;
    if( queueEmpty(s) )//判断队空
        return 0;
    else{
        value = s->data[s->front];
        return value;
    }
}

int enQueue(seqQueue *s,char value)//入队 成功返回1 失败返回0
{
    if(s->rear >= MAXLEN) 
        return 0;
    else{
        s->data[s->rear] = value; 
        s->rear++;
        return 1;
    }
}

int outQueue(seqQueue *s)//出队 成功返回值 失败返回0
{
    char value;
    if( queueEmpty(s) )//判断队空
        return 0;
    else{
        value = s->data[s->front];
        s->front++;
        return value;
    }
}
//链队列函数
int initLinkQueue(LinkQueue *Q)//初始化
{
	Linknode *newnode = (Linknode *)malloc(sizeof(Linknode));
	Q->length = 0;
	Q->front = newnode;
	Q->rear = Q->front;
	Q->front->next = NULL;
	return 0;
}

int LinkQueueEmpty(LinkQueue *Q)//空返回1 非空返回0
{
	if(Q->front == Q->rear)
		return 1;
	else 
		return 0;
} 

int LinkqueueFront(LinkQueue *Q)//返回值
{
	char value;
  if(LinkQueueEmpty(Q))
		return 0;
	else{
		value = Q->front->next->data;
		return value;
	}
}

int enLinkqueue(LinkQueue *Q ,char value)//成功返回0
{
	Linknode *newnode = (Linknode *)malloc(sizeof(Linknode));
	
	Q->length++;
	newnode->data = value;
	newnode->next = NULL;
	Q->rear->next = newnode;
	Q->rear =newnode;
	return 0;
}

int outLinkQueue(LinkQueue *Q)//成功返回值
{
	Linknode *temp;
	char value;
	if(LinkQueueEmpty(Q))
		printf("队空!\n");
	else{
		Q->length--;
		value = Q->front->next->data;
		temp = Q->front->next;
		Q->front->next = temp->next;
		
		free(temp);

		if(Q->front->next == NULL)
			Q->rear = Q->front;
	}
	return value;
}

#endif