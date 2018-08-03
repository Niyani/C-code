void reorderList(ListNode *head) 
{
	if (head == NULL||head->next == NULL)
		return;
	ListNode *pFast = head->next;
	ListNode *pSlow = head;
	//找到中间节点
	while (pFast&&pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	//以中间节点为界，将链表断开，分成前后两部分  ,断开的目的是方便链表翻转操作
	ListNode* pCur = pSlow->next;
	pSlow->next = NULL;
	//单链表逆置
	while (pCur)
	{
		ListNode *tmp = pCur;
		pCur = pCur->next;
		tmp->next = pSlow->next;
		pSlow->next = tmp;
	}
	//再次断开成两个链表，合并
	ListNode *pSecond = pSlow->next;
	pSlow->next = NULL;
	ListNode *pPre = head;
	while (pSecond)
	{
		ListNode *tmp = pSecond;
		pSecond = pSecond->next;
		tmp->next = pPre->next;
		pPre->next = tmp;
		pPre = tmp->next;
	}
}
