void AdjustDown(int array[], int size, int pRoot)
{
    while (1)
    {
        int left = 2 * pRoot + 1;
        int right = 2 * pRoot + 2;
        int max;
        if (left >= size)
            return;
        max = left;
        if (right<size&&array[right]>array[left])
        {
            max = right;
        }
        if (array[pRoot] < array[max])
        {
            Swap(&array[pRoot], &array[max]);
        }
        pRoot = max;
    }
    return;
}
void HeapCreate(int array[], int size)
{
    int i = (size-1-1)/2;
    for (; i >=0; i--)
    {
        AdjustDown(array, size, i);
    }
}
void HeapSort(int array[], int size)
{
    if (size <= 1)
        return;
    HeapCreate(array, size);//建堆
    int i = 0;
    for (; i < size; i++)
    {

        Swap(&(array[0]), &(array[size - 1 - i]));//每次都把最后一个结点的树与根节点交换，即把最大的数都放在了最后
        AdjustDown(array, size - 1 - i, 0);

    }
    Print(array, size);
    return;
}
