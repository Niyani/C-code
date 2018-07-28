TreeNode* getLCA(TreeNode *root, TreeNode *X, TreeNode *Y)
{
	TreeNode *left;
	TreeNode *right;
	if (root == NULL)
		return NULL;
	if (X == root || Y == root)
		return root;
	left = getLCA(root->pLeft, X, Y);
    right = getLCA(root->pRight, X, Y);
	if (left == NULL)
		return right;
	else if (right == NULL)
		return left;
	else
		return root;
}
