class Solution {
public:

    void inorder(TreeNode* root, vector<int>& arr){
        if(root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* buildBalancedTree(vector<int>& arr, int start, int end){
        if(start > end) return NULL;

        int mid = start + (end - start)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildBalancedTree(arr, start, mid-1);
        root->right = buildBalancedTree(arr, mid+1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;

        inorder(root, arr);

        return buildBalancedTree(arr, 0, arr.size()-1);
    }
};