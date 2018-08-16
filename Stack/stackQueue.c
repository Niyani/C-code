typedef struct SQueue
{
    Stack stack1;//入数据栈
    Stack stack2;//出数据栈
}SQueue;

void Init(SQueue *pSQ)
{
    Stack *p1, *p2;
    p1 = &(pSQ->stack1);
    p2 = &(pSQ->stack2);
    StackInit(p1);
    StackInit(p2);
}

void Push(SQueue *pSQ, SDataType data)
{
    Stack *p1, *p2;
    p1 = &(pSQ->stack1);
    p2 = &(pSQ->stack2);
    StackPush(p1,data);//只入第一个栈
}

void Pop(SQueue *pSQ)
{
    SDataType data;
    Stack *p1, *p2;
    p1 = &(pSQ->stack1);
    p2 = &(pSQ->stack2);
    if (StackIsEmpty(p2))
    {
        //当p2为空但p1不为空时，将p1中的数据弹出并压入到栈p2中
        while (!StackIsEmpty(p1))
        {
            data = StackTop(p1);
            StackPop(p1);
            StackPush(p2, data);
        }
    }
    StackPop(p2);//将p2中数据弹出栈
}
