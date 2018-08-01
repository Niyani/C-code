int GetListLenth(ListNode *pHead)
{
    int len = 0;
    ListNode *pNode = pHead;
    while (pNode != NULL)
    {
        ++len;
        pNode = pNode->next;
    }
    return len;
}
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
    //得到两个链表的长度
    int len1 = GetListLenth(pHead1);
    int len2 = GetListLenth(pHead2);
    int lenth= len1 - len2;

    ListNode *pListLong = pHead1;
    ListNode *pListShort = pHead2;

    if (len2 > len1)
    {
        pListLong = pHead2;
        pListShort = pHead1;
        lenth = len2 - len1;

    }
    //先在长链表上走几步，再同时遍历
    for (int i = 0; i < lenth; ++i)
    {
        pListLong = pListLong->next;
    }
    while ((pListLong != NULL) && (pListShort != NULL) && (pListLong != pListShort))
    {
        pListLong = pListLong->next;
        pListShort = pListShort->next;
    }
    ListNode *pFirstCommon = pListLong;
    return pFirstCommon;
}
