void SelectSort(int array[], int size)
{
    if (size <= 1)
        return;
    int bound = 0;
    for (; bound < size; ++bound)
    {
        int i = bound;
        for (; i < size; i++)
        {
            if (array[i] < array[bound])
            {
                Swap(&array[i], &array[bound]);
            }
        }
    }
    Print(array, size);
    return;
}
