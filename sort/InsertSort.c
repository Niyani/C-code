void InsertSort(int array[], int size)
{
    if (size <= 1)
        return;
    int bound = 1;//假设第一个元素就是一个有序的线性表
    for (; bound < size; ++bound)
    {
        int bound_val = array[bound];
        int i = bound;
        for (; i>0; --i)
        {
            if (array[i - 1]>bound_val)
            {
                array[i] = array[i - 1];
            }
            else
            {
                break;
            }
        }
        array[i] = bound_val;
    }
    Print(array, size);
    return;
}
