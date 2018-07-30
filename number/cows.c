int CalCowsNum(int Year)
{
	int year = 0;
	long cowsNum = 1;//奶牛总数
	for (year = 1; year <=Year; year++)
	{
		if (year >= 4)//4年以后奶牛数量开始增多
		{
			if ((Year - year)>3)//第二个4年开始后产的奶牛也开始产奶牛
			{
				cowsNum += CalCowsNum(Year - year);
			}
			else
			{
				cowsNum++;
			}
		}
	}
	return cowsNum;
}
