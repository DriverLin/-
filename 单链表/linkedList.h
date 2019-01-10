#ifndef linkedList
#define linkedList
struct node
    {
        int num;
        struct node *next;
    };
/*
typ(struct node *head)//打印链表   传入头指针
DestroyList(struct node *head)//销毁链表  传入头指针
getlen(struct node *head)//获取长度  传入头指针  
Find(struct node *head,int s)//查找链表中第i个元素  传入头指针,i 
insrt(struct node *head,int s,int x)  //在第i个结点前插入值为x的结点 传入头指针,i,x
Findx(struct node *head)  //链表中查找元素值为x的结点，成功返回结点指针，失败报错 
Del_i(struct node *head,int n)//删除单链表中第i个元素结点 传入头指针,i  
Del(struct node *s)//传入需要删除的单元的前一个指针
OrderedIns(struct node *head,int n) //递增有序链表有序插入值   传入头指针，x
BreakDown(struct node *head)//按照奇偶拆分链表 传入头指针  
append(struct node *p,int n)//在尾部节点之后附加单元  传入p，x 
comb(struct node *l1,struct node *l2)//两个递增有序单链表求交集 传入连个地址 返回l3
Deduplication(struct node *head)//删除递增有序链表重复元素  传入头指针 
*/


int typ(struct node *head)//打印链表   传入头指针
{
    struct node *p;
    p = head;
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
    return 0;
}

int _1()
{   
    struct node *head;
    head = NULL;
    struct node *p1,*p2;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");     
    Endinsrttyp(head);  
    return 0;
} 

int _2()
{   
    struct node *head,*p1,*p2;
    p1 = p2 = head = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p2->num);
    p2->next = NULL;
    while(p1->num != 0)
        {
            p1 = ( struct node *) malloc( sizeof (struct node) );
            p1->next = p2;
            p2 = p1;
            scanf("%d",&p1->num);
        }
    head=p1;
    printf("End\n");    
    Headinserttyp(head);    
    return 0;
} 

int _3()
{   
    struct node *head;
    head = NULL;
    struct node *p1,*p2;
    int i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;
            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");    
    typ(head);
    DestroyList(head);
    return 0;
}

int _4()
{   
    struct node *head;
    head = NULL;
    struct node *p1,*p2;
    int i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");      
    typ(head);
    printf("Length=%d\n",getlen(head));
    return 0;
}


int _5()
{   
    struct node *head;
    head = NULL;
    struct node *p1,*p2;
    int u,i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");     
    typ(head);
    if(head==NULL)//区分第一组第二组实验要求
    {
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        return 0;
    }
    else{
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        scanf("%d",&u);
        printf("i=%2d ",u);
        Find(head,u);
        return 0;
    }



    
    return 0;
}

int _6()
{   
    struct node *head;
    head = NULL;
    struct node *p1,*p2;
    int u,v,i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");     
    typ(head); 
    u=100;
    printf("输入i:");
    scanf("%d",&v);
    insrt(head,v,u);
    typ(head);
    return 0;
}

int _7()
{   
    struct node *head , *temp;
    head = NULL;
    struct node *p1,*p2;
    int u,i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;        
    p2->next = NULL;    
    printf("End\n");       
    typ(head);
    printf("查找1  ");
    if(Findx(head,1)) printf("Successful!\n");
    printf("查找17 ");
    if(Findx(head,17)) printf("Successful!\n");
    printf("查找20 ");
    if(Findx(head,20)) printf("Successful!\n");
    printf("查找88 ");
    if(Findx(head,88)) printf("Successful!\n");
    return 0;
}

int _8()
{   
    struct node *head ;
    head = NULL;
    struct node *p1,*p2;
    int u,i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");          
    typ(head);
    printf("输入i:");
    scanf("%d",&u);
    Del_i(head,u);
    typ(head);
    return 0;
}

int _9()
{   
    struct node *head ;
    head = NULL;
    struct node *p1,*p2;
    int u,i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");     
    typ(head);
    printf("输入X:");
    scanf("%d",&u);
    OrderedIns(head,u);
    typ(head);
    return 0;
}

int _10()
{   
    struct node *head ;
    head = NULL;
    struct node *p1,*p2;
    int i = 1,x;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");     
    typ(head);
    BreakDown(head);
    return 0;
}

int _11()
{   
    struct node *head1;
    head1 = NULL;
    struct node *p1,*p2;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head1 == NULL)
                head1 = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");    
    struct node *head2;
    head2 = NULL;
    struct node *q1,*q2;
    q1 = q2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&q1->num);
    q1->next = NULL;
    while(q1->num != 0)
        {
            if(head2 == NULL)
                head2 = q1;
            else
                q2->next = q1;
            q2 = q1;

            q1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&q1->num);
        }
    free(q1);
    q1 = NULL;
    q2->next = NULL;
    printf("End\n");     
    printf("L1:");
    typ(head1);
    printf("L2:");
    typ(head2);
    comb(head1,head2);
    return 0;
}

int _12()
{   
    struct node *head , *temp;
    head = NULL;
    struct node *p1,*p2;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
    free(p1);
    p1 = NULL;
    p2->next = NULL;
    printf("End\n");    
    printf("Before:");
    typ(head);
    Deduplication(head);
    printf("After :");
    typ(head);
    return 0;
}

int _13()
{   
    struct node *head1;
    head1 = NULL;
    struct node *p1,*p2;
    p1 = p2 = (struct node *) malloc ( sizeof ( struct node ) );
    printf("输入0结束\n输入值:");
    scanf("%d",&p1->num);
    p1->next = NULL;
    while(p1->num != 0)
        {
            if(head1 == NULL)
                head1 = p1;
            else
                p2->next = p1;
            p2 = p1;

            p1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&p1->num);
        }
        free(p1);
        p1 = NULL;
        p2->next = NULL;
        printf("End\n");    
        struct node *head2;
        head2 = NULL;
        struct node *q1,*q2;
        q1 = q2 = (struct node *) malloc ( sizeof ( struct node ) );
        printf("输入0结束\n输入值:");
        scanf("%d",&q1->num);
        q1->next = NULL;
        while(q1->num != 0)
        {
            if(head2 == NULL)
                head2 = q1;
            else
                q2->next = q1;
            q2 = q1;
            q1 = ( struct node *) malloc ( sizeof ( struct node ) );
            scanf("%d",&q1->num);
        }
        free(q1);
        q1 = NULL;
        q2->next = NULL;
        printf("End\n");     
        printf("L1:");
        typ(head1);
        printf("L2:");
        typ(head2);
        if(struc(head1,head2))//特殊情况 head1为空
        {
            head1 = (struct node *) malloc ( sizeof ( struct node ) );
            head1->next = head2->next;
            head1->num = head2->num;
        } 
        free(head2);
        printf("\nL1:");
        typ(head1);
    return 0;
}

int DestroyList(struct node *head)//销毁链表  传入头指针
{  
    struct node *p;  
    if(head==NULL){
        printf("Failed to destroy\n");;  
        return 0;  
    }
    while(head)  
    {  
        p=head->next;  
        free(head);  
        head=p;  
    } 
    printf("Successfully destroyed\n");
    return 1;  
}

int getlen(struct node *head)//获取长度  传入头指针  
{  
    struct node *p;
    if(head==NULL){
    printf("Error!\n");
    return 0;
}
    int i=1;
    for(p = head;p->next != NULL; p=p->next,i++);
    return i;  
}  


int Find(struct node *head,int s)//查找链表中第i个元素  传入头指针,i 
{  
    struct node *p;
    if(head==NULL){
    printf("Error!\n");
    return 0;
}
    int i=1;
    for(p = head;p != NULL; p=p->next,i++){
        if(i==s){
            printf("%d\n",p->num);
            return 1;
        }
    }
    printf("Error!\n");
    return 0;  
}  
int insrt(struct node *head,int s,int x)  //在第i个结点前插入值为x的结点 传入头指针,i,x
{  
    struct node *p,*insrt;
    int i=1;
    if(head==NULL){
    printf("Error!\n");
    return 0;
    }
    p=head;
    insrt = ( struct node *) malloc ( sizeof ( struct node ) );
    if(s==1){
        insrt->next=p->next;
        p->next=insrt;
        insrt->num=p->num;
        p->num=x;
        return 0;
    }
    for(p = head;p->next != NULL; p=p->next,i++){
        if(i==s-1){
            insrt->next=p->next;
            p->next=insrt;
            insrt->num=x;
            return 1;
        }
    }
    printf("Error!\n");
    return 0;  
}  
int Findx(struct node *head,int x)  //链表中查找元素值为x的结点，成功返回结点指针，失败报错   

{  
    struct node *p ;
    if(head==NULL){
    printf("Error!\n");
    return 0;
}
    for(p = head;p != NULL; p=p->next){
        if(p->num == x)
            return 1;
    }
    printf("Error!\n");
    return 0;  
} 
int Del_i(struct node *head,int n)//删除单链表中第i个元素结点 传入头指针,i  
{  
    struct node *p,*temp;
    int i=0;
    if(head==NULL){
    printf("Error!\n");
    return 0;
}
    for(p = head;p->next != NULL; p=p->next,i++){
        if(i==n-2){
            temp=p->next;
            p->next = ((p->next)->next);
            free(temp);
            return 0;
        }
    }
    printf("Error!\n");
    return 0;  
}  
int Del(struct node *s)//传入需要删除的单元的前一个指针
{  
    struct node *p,*temp;
    if(s==NULL){
    printf("Error!\n");
    return 0;
}
    p=s;
    temp=p->next;
    p->next = temp->next;
    free(temp);
    return 0;  
}   
int OrderedIns(struct node *head,int n) //递增有序链表有序插入值   传入头指针，x
 
{  
    struct node *p,*q,*insrt;
    if(head==NULL){
        printf("Error!\n");
        return 0;
    }
    insrt = ( struct node *) malloc ( sizeof ( struct node ) );     
    for(p = head,q = head->next ;p->next != NULL;p = p->next , q=q->next){
        if(q->num>n){ 
            insrt->next=p->next;
            p->next=insrt;
            insrt->num=n;           
            return 0;
        }
    }
    insrt->next=p->next;
    p->next=insrt;
    insrt->num=n;
    return 0;  
}
int BreakDown(struct node *head)//按照奇偶拆分链表 传入头指针  
{  
    struct node *p,*odd,*oddp,*eve,*evep;
    int n;
    if(head==NULL){
        printf("Error!\n");
        return 0;
    }
    odd = ( struct node *) malloc ( sizeof ( struct node ) );
    odd->next=NULL;
    eve = ( struct node *) malloc ( sizeof ( struct node ) );
    eve->next=NULL;
    oddp=odd;
    evep=eve;
    for(p = head;p != NULL;p = p->next){
        if((p->num)%2){
            append(oddp,p->num);
            oddp = oddp->next;
        }
        else{
            append(evep,p->num);
            evep = evep->next;  
        }
    }
    odd=odd->next;
    eve=eve->next;
    typ(odd);
    typ(eve);
    return 0;  
} 

int append(struct node *p,int n)//在尾部节点之后附加单元  传入p，x 
{
    struct node *ins;
    ins = ( struct node *) malloc ( sizeof ( struct node ) );
    ins->num = n;
    ins->next = NULL;
    p->next = ins;
    return 0;
}

int comb(struct node *l1,struct node *l2)//两个递增有序单链表求交集 传入连个地址 返回l3
{  
    struct node *l3,*pointer,*p,*q;
    if(l1==NULL){
        printf("L3:\n");
        return 0;
    }
    if(l2==NULL){
        printf("L3:\n");
        return 0;
    }
    l3 = (struct node *) malloc ( sizeof( struct node ) );
    l3->next=NULL;
    pointer=l3;
    p=l1;
    q=l2;
    while(p != NULL && q != NULL){
            if(p->num > q->num){
                q=q->next;
            }
            else if(p->num < q->num){
                p=p->next;
            }
            else{
                append(pointer,p->num);
                pointer=pointer->next;
                p=p->next;
                q=q->next;
            }
    }
    l3=l3->next;
    printf("L3:");
    typ(l3);
    return l3;  
}

int Deduplication(struct node *head)//删除递增有序链表重复元素  传入头指针 
{  
    struct node *p;
    p=head;
    for(p = head;p->next != NULL; p=p->next){
        while(p->num == (p->next)->num){
            if(p->next->next==NULL){
                Del(p);
                return 0;
            }
            Del(p);
        }   
    }
    return 1;  
}

int struc(struct node *head1,struct node *head2)
{
    struct node *a,*b,*u;
    if(head1 == NULL){
        head1 = head2;
        return 1;
    }
    else if(head2==NULL){
        return 0;
    }
    else ;
    a = head1;
    b = head2;
    while(a->next != NULL && b->next != NULL){
        if(a->next->num < b->next->num){
            a = a->next;
        }
        else if(a->next->num == b->next->num ){
            a=a->next;
            b=b->next;
        }
        else{
            u = b->next;
            b->next = b->next->next;
            u->next = a->next;
            a->next = u;
        }
    }
    if(b->next != NULL){
        a->next = b->next;
    }
    return 0;
}
int Endinsrttyp(struct node *head)//尾插打印
{
    struct node *p;
    if(head==NULL){
        printf("Error!\n");
        return 0;
    }
    p = head;
    while (p->next != NULL) {
        
        printf("%d ", p->num);
        p = p->next;
    }
    printf("%d \n", p->num);
    return 0;
}

int Headinserttyp(struct node *head)//头插打印
{
    struct node *p;
    if(head->next==NULL){
        printf("Error!\n");
        return 0;
    }
    p = head;
    p = p->next;
    while (p->next != NULL) {
        
        printf("%d ", p->num);
        p = p->next;
    }
    printf("%d \n", p->num);
    return 0;
}

#endif