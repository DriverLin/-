#ifndef stackproject
#define stackproject

typedef struct
{
    char elem[1000];
    int top;
} Oseqstack;

typedef struct node {
    char data;
    struct node *next;
} LinkstackNode;

typedef struct {
    LinkstackNode *top;
    int length;
} Linkstack; 

int _1()
{
    Oseqstack s;
    char hex[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int n,value;
    printf("输入10进制数:");
    OrderInitstack(&s);//初始化
    getchar();//等待输入
    scanf("%d",&n);
    while( n ){
        value = n%16;
        OrderPush(&s,value);
        n=n/16;
    }//输入值转化16进制不同数位入栈
    printf("\n转换16进制:");
    while (OrderPop(&s, &value) == 1) {
        printf("%c", hex[value]);
    }//出栈输出16进制数组相应的字符
    printf("\n\n");
    return 0;
}

int _2()
{
    Oseqstack s;
    char a='0';
    int iflag=0;
    printf("输入表达式:");
    getchar();
    OrderInitstack(&s);
    while(a !='\n'){
        a=getchar();
        if( a == '{' || a == '[' || a == '('){
            OrderPush(&s,a);
        }//a是左括号，则入栈
        else if( a == '}' || a == ']' || a == ')'){
            if(OrderIsEmpty(s) == 1)//当a是右括号且栈空，说明右括号多于左括号 直接返回
            {
                iflag=1;
                
            }
            OrderPop(&s,&a);
        }//a是右括号，出栈
        else ;
    }
    if(iflag == 1){
        printf("NO\n");
        return 0;

    }
    if(OrderIsEmpty(&s)) 
        printf("YES\n");//左括号等于右括号时，栈为空，若站不为空则说明不匹配
    else 
        printf("NO\n");
    return 0;
}

int _3()
{
    Linkstack s;
    char hex[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int n,value;
    LinkInitstack(&s);
    printf("输入10进制数:");
    getchar();
    scanf("%d",&n);
    while( n ){
        value = n%16;
        LinkPush(&s,value);
        n=n/16;
    }
    printf("\n转换16进制:");
    while (LinkPop(&s, &value) == 1) {
        printf("%c", hex[value]);
    }
    printf("\n\n");
    return 0;
}

int _4()
{
    Linkstack s;
    char a='0';
    int i=0,iflag=0; 
    printf("输入表达式:");
    getchar();
    LinkInitstack(&s);
    while(a !='\n'){
        a=getchar();
        if( a == '{' || a == '[' || a == '('){
            LinkPush(&s,a);
        }
        else if( a == '}' || a == ']' || a == ')'){
            if(LinkIsEmpty(&s) == 1){
                 iflag=1;
            }
            LinkPop(&s,&a);
        }
        else ;
    }
    if(iflag == 1){
        printf("NO\n");
        return 0;
    }

    if(LinkIsEmpty(&s) == 1) 
        printf("YES\n");
    else 
        printf("NO\n");
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

int OrderPush(Oseqstack *s,int n)//入栈 传入栈顶指针和入栈的值 成功返回1 失败返回0
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

int LinkInitstack(Linkstack *s)//初始化栈
{
     s->length = 0;//长度为0代表空
     s->top = NULL;//空时top定义为NULL
     return 1;
}


int LinkIsEmpty(Linkstack *s)//判断栈空
{
    if (s->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

int LinkPush(Linkstack *s, char value)//入栈
{
    LinkstackNode *temp = (LinkstackNode *)malloc(sizeof(LinkstackNode));
    if (temp == NULL)
        return 0;
    if(s->top != NULL){
        temp->next = s->top;
    }
    else{
        temp->next = NULL;
    }
    temp->data = value;
    s->top = temp;
    s->length++;
    return 1;
}

int LinkPop(Linkstack *s, char *value)//出栈
{
    if (LinkIsEmpty(s) == 1) 
    	return 0;
	LinkstackNode *temp;
	temp = s->top;
	s->top = s->top->next;
	if(s->top == NULL){
        s->length--;
        *value = temp->data;
        free(temp);
        return 1;    
    }
    s->length--;
	*value = temp->data;
	free(temp);
    return 1;
}

#endif