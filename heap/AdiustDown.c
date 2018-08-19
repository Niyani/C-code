//向下调整（递归）
void AdiustDownRecursion(Heap *pH, int parent)
{
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int maxChild;
    if (leftChild >= pH->size)
    {
        return;//叶子结点
    }
     maxChild = leftChild;
     if (rightChild < pH->size&&pH->array[leftChild] < pH->array[rightChild])
    {
        maxChild = rightChild;
    }
    if (pH->array[parent] < pH->array[maxChild])
    {
        Swap(&(pH->array[parent]), &(pH->array[maxChild]));
    }
    AdiustDownRecursion(pH ,maxChild);
}
//向下调整非递归实现
void AdiustDown(Heap *pH, int parent)
{
    while (1)
    {
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;
        int maxChild;
        if (leftChild >= pH->size)
        {
            return;//叶子结点
        }
        maxChild = leftChild;
        if (rightChild < pH->size&&pH->array[leftChild] < pH->array[rightChild])
        {
            maxChild = rightChild;
        }
        if (pH->array[parent] < pH->array[maxChild])
        {
            Swap(&(pH->array[parent]), &(pH->array[maxChild]));
        }
        parent = maxChild;
    }
}
