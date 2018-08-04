void DeleteStr(char first[], char second[])
{
	int i=0;
	int flag = 0;
	int count = 0;
	for (; first[i] != '\0';i++)
	{
		flag = 0;
		int j = 0;
		for (; second[j]!='\0'; j++)
		{
			if (first[i]==second[j])
			{
				flag = 1;
				count++;
				break;
				

			}
		}
		if (flag == 0)
		{
			first[i - count] = first[i];
		}
	}
	first[i -count] = '\0';
}
