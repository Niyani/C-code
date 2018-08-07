BTreeNode *CreatTreeByPreAndIn(char preOrder[], int preSize, char inOrder[], int inSize)
{
	if (preSize <= 0)
		return NULL;
	char root = preOrder[0];
	int i = 0;
	for (i = 0; i < inSize; i++)
	{
		if (inOrder[i] == preOrder[0])
		{
			break;
		}
	}
	if (i == inSize)
	{
		assert(0);
		
	}

	BTreeNode *pRoot = CreateNode(root);
	pRoot->pLeft = CreatTreeByPreAndIn(preOrder + 1, i, inOrder, i);
	pRoot->pRight = CreatTreeByPreAndIn(preOrder + 1 + i, preSize - 1 - i, inOrder + i + 1, inSize - 1 - i);
	return pRoot;
}
