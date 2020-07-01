/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    queue<TreeNode*> childs;
    
    
    bfs(TreeNode* root)
    {
        childs.push(root);
        int maks;
        while (!childs.empty())
        {
            TreeNode* temp = childs.front();
            if (temp->left == nullptr) 
            {
                maks = temp->right;
            }
            else if (temp->right == nullptr) maks = temp->left;
            else if (temp->left != nullptr && temp->right != nullptr)
            {
                
            }
             
        }
    }
    
    vector<int> largestValues(TreeNode* root) 
    {
            
    }
};