class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
       TreeNode *pCur=root;
        TreeNode *pTop=NULL;
        stack<TreeNode*> stack;
        while(pCur!=NULL||!stack.empty())
        {
            while(pCur!=NULL)
           {
                stack.push(pCur);
                res.push_back(pCur->val);
                pCur=pCur->left;
           }
            
            pTop=stack.top();
            stack.pop();
            pCur=pTop->right;
        }
       return res;
    }
};
