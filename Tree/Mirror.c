void Mirror(BTreeNode *pRoot)
{
	BTreeNode *pLeft;
	if (pRoot == NULL)
		return NULL;
	if (pRoot->pLeft == NULL&&pRoot->pRight == NULL)
		return NULL;
	pLeft = pRoot->pLeft;
	pRoot->pLeft = pRoot->pRight;
	pRoot->pRight = pLeft;

	Mirror(pRoot->pLeft);
	Mirror(pRoot->pRight);
}
