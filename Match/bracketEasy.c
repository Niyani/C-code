int main()
{
    int ch = 0;
    int count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '{')
            count++;
        else if (ch == '}'&&count == 0)
        {
            count = 1;
            break;
        }
        else if (ch == '}')
            count--;
    }
    if (count == 0)
    {
        printf("匹配\n");
    }
    else
    {
        printf("不匹配\n");
    }
    system("pause");
    return 0;
}
