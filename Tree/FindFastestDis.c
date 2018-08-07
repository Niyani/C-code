
//求二叉树的高度
int TreeHeightR(BTreeNode *pRoot)
{
	if (pRoot == NULL)
		return 0;
	int leftH = TreeHeightR(pRoot->pLeft);
	int rightH = TreeHeightR(pRoot->pRight);
	return leftH > rightH ? (leftH + 1) : (rightH + 1);
}
int Max(int a, int b, int c)
{
	if (a > b&&a > c)
		return a;
	if (b > a&&b > c)
		return b;
	return c;
}
int FarDistance2(BTreeNode *pRoot, int *pHeight)
{
	if (pRoot == NULL)
	{
		*pHeight = 0;
		return 0;
	}
	int leftHeight, rightHeight;
	int leftPath = FarDistance2(pRoot->pLeft, &leftHeight);
	int rightPath = FarDistance2(pRoot->pRight, &rightHeight);
	int rootPath = leftHeight + rightHeight;
	*pHeight = leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
	return Max(rootPath, leftPath, rightPath);
}
