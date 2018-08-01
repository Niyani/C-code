void ConvertNode(TreeNode *pNode, TreeNode **pLastNode)
{
	if (pNode == NULL)
		return;
	TreeNode *pCur = pNode;
	if (pCur->left != NULL)
	{
		ConvertNode(pCur->left, pLastNode);
	}
	pCur->left = *pLastNode;
	if (*pLastNode != NULL)
		(*pLastNode)->right = pCur;
	*pLastNode = pCur;
	if (pCur->right != NULL)
	{
		ConvertNode(pCur->right, pLastNode);
	}
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode *pLastNode = NULL;//指向双向链表的尾结点
	ConvertNode(pRootOfTree, &pLastNode);

	//返回头结点
	TreeNode *pHead = pLastNode;
	while (pHead != NULL&&pHead->left != NULL)
	{
		pHead = pHead->left;
	}
	return pHead;
}
