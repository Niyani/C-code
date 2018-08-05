void ShellSort(int array[], int size)
{
    Print(array, size);
    if (size <= 1)
        return;
    //用希尔序列n/2,n/4,n/8....1
    int gap = size / 2;
    for (; gap >= 1; gap /= 2)//生成希尔序列
    {
        //插入排序
        int bound = gap;
        for (; bound < size; bound++)
        {
            int bound_val = array[bound];
            int i = bound;
            for (; i >= gap; i -= gap)
            {
                if (array[i - gap]>bound_val)
                {
                    array[i] = array[i - gap];
                }
                else
                {
                    break;
                }
            }
            array[i] = bound_val;
        }

    }
    Print(array, size);
    return;
}
