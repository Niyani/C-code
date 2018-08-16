typedef struct QStack
{
    Queue queue;
}QStack;

void Init(QStack *pQS)
{
    QueueInit(&(pQS->queue));
}

void Push(QStack *pQS, QDataType data)
{
    QueuePush(&(pQS->queue), data);
}

void Pop(QStack *pQS)
{
    int i;
    QDataType data;
    Queue *pQ = &(pQS->queue);
    for (i = 1; i < QueueSize(pQ); i++)
    {
        data = QueueFront(pQ);
        QueuePop(pQ);
        QueuePush(pQ, data);
    }
    QueuePop(pQ);
}
//查看队列顶端元素
QDataType Top(QStack *pQS)
{
    int i;
    QDataType data;
    Queue *pQ = &(pQS->queue);
    for (i = 1; i < QueueSize(pQ); i++)
    {
        data = QueueFront(pQ);
        QueuePop(pQ);
        QueuePush(pQ, data);
    }
    data = QueueFront(pQ);
    QueuePop(pQ);
    QueuePush(pQ, data);
    return data;
}
