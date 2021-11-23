# leetcode 124. Binary Tree Maximum Path Sum
[leetcode 124](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

## 题目描述
给定一个二叉树，返回最大路径和

## 思路
递归，返回以自身节点连接上左右任一branch或者单独自身，作为最大子路径返回。
同时，将自身看作是root，结合自己的左右branch，更新ans
如果节点为空，则无影响，返回0
若某一branch的子路径最大值<0，则不必考虑进来->max(0,return value)

## code
~~~cpp
class Solution {
public:
    int ans=-INT_MAX;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int left=max(helper(root->left),0);
        int right=max(helper(root->right),0);
        ans=max(ans,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};
~~~