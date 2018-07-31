typedef struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
}RandomListNode;
	

RandomListNode* Clone(RandomListNode* pHead)
{
	RandomListNode* pNode;
	RandomListNode* pOldRandom;
	RandomListNode* pNewNode;
	RandomListNode* pNewRandom;
	//复制结点
	for (pNode = pHead; pNode; pNode = pNode->next->next)
	{
		pNewNode = (RandomListNode *)malloc(sizeof(RandomListNode));
		pNewNode->label = pNode->label;
		pNewNode->next = pNode->next;
		pNewNode->random = NULL;
		pNode->next = pNewNode;
	}
	//复制结点random
	for (pNode = pHead; pNode; pNode = pNode->next->next)
	{
		pNewNode = pNode->next;
		pOldRandom = pNode->random;
		if (pOldRandom != NULL)
		{
			pNewRandom = pOldRandom->next;
			pNewNode->random = pNewRandom;
		}
	}
	//拆链表
	RandomListNode *pNewFirst = pHead->next;
	for (pNode = pHead; pNode; pNode = pNode->next)
	{
		pNewNode = pNode->next;
		pNode->next = pNewNode->next;
		if (pNode->next != NULL)
		{
			pNewNode->next= pNode->next->next;
		}
		else
		{
			pNewNode->next = NULL;
		}
	}
	return pNewFirst;

}
