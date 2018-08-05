int Partion(int array[], int begin, int end)
{
	int left = begin;
	int right = end-1;
	int tmp = array[end - 1];//基准值
	while (left < right)
	{
		while (left < right&&array[left] <= tmp)//让left从左往右找第一个大于基准值的数
		{
			++left;//没找到，left往后+1;
		}
		while (left < right&&array[right] >= tmp)//让right从右往左找第一个小于基准值的数
		{
			--right;//没找到，right-1；
		}
		//这两个循环结束后，表示left 就指向了第一个大于 基准值 的元素，right 就指向了第一个小于 基准值 的元素
		if (left < right)
		{
			Swap(&array[left], &array[right]);
		}
	}
	//当left和right重合时，将其与基准值交换
	Swap(&array[left], &array[end - 1]);
	return left;
}
void _QuickSort(int array[], int begin, int end)
{
	if ((end - begin) <= 1)
		return;
	int mid = Partion(array, begin, end);//Partion完成基准值选择 和交换，返回基准值的位置
	_QuickSort(array, begin, mid);
	_QuickSort(array, mid + 1, end);
}
void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size);
}
