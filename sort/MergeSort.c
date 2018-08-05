void MergeArray(int array[], int begin, int mid, int end, int *tmp)//实现归并的功能
{
    int cur1 = begin;
    int cur2 = mid;
    int output = begin;
    while (cur1 < mid&&cur2 < end)
    {
        if (array[cur1] <array[cur2])
        {
            tmp[output++] = array[cur1++];
        }
        else
        {
            tmp[output++] = array[cur2++];
        }
    }
    //有的数组没有走完，把该数组剩下的元素加到tmp后边
    while (cur1 < mid)
    {
        tmp[output++] = array[cur1++];
    }
    while (cur2 < end)
    {
        tmp[output++] = array[cur2++];
    }
    //把缓存区的数拷贝到array中
    memcpy(array+begin, tmp+begin, sizeof(int)*(end - begin));
}
//非递归实现
void MergeSortLoop(int array[], int size)
{
    if (size <= 1)
        return;
    int *tmp = (int *)malloc(sizeof(int)*size);
    int gap = 1;
    for (; gap <= size / 2; gap *= 2)
    {
        int i = 0;
        for (; i < size; i += 2 * gap)
        {
            int begin = i;
            int mid = i+gap;
            if (mid >= size)
                mid=size;
            int end = i+2 * gap;
            if (end >= size)
                end=size;
            MergeArray(array, begin, mid, end, tmp);
        }
    }
    free(tmp);
}


//递归实现
void _MergeSort(int array[], int begin, int end, int *tmp)//该函数完成递归
{
    if ((end - begin) <= 1)
        return;
    int mid = begin + (end -begin) / 2;
    _MergeSort(array, begin, mid, tmp);
    _MergeSort(array, mid, end, tmp);
    MergeArray(array, begin, mid, end, tmp);
}
void MergeSort(int array[], int size)
{
    int *tmp = (int *)malloc(sizeof(int)*size);//申请一个缓冲区
    _MergeSort(array, 0, size, tmp);
    free(tmp);
    return;
}
