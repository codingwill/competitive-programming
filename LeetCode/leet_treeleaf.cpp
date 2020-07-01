#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/04
*/
using namespace std;
using ll = long long int;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> leaves1, leaves2;

public:
    void traverse(vector<int> &leaves, TreeNode* node)
    {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr)
            leaves.push_back(node->val);
        traverse(leaves, node->left);
        traverse(leaves, node->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(leaves1, root1);
        traverse(leaves2, root2);
        if (leaves1.size() != leaves2.size()) return false;
        for (int i = 0; i < leaves1.size(); ++i)
        {
            if (leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};
/*
class Solution 
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        stack<TreeNode*> s;
        //tree A
        vector<bool> visited(201, false);
        s.push(root1);
        vector<int> leaves1, leaves2;
        while (!s.empty())
        {
            TreeNode* node = s.top();
            if (!visited[node->val])
            {
                visited[node->val] = true;
                TreeNode* l = node->left;
                if (l != nullptr) s.push(l);
                TreeNode* r = node->right;
                if (r != nullptr) s.push(r);
                if (l == nullptr && r == nullptr) 
                    leaves1.push_back(node->val);
            }
            else
            {
                s.pop();
            }
        }

        s.push(root2);
        fill(visited.begin(), visited.end(), false);
        while (!s.empty())
        {
            TreeNode* node = s.top();
            if (!visited[node->val])
            {
                visited[node->val] = true;
                TreeNode* l = node->left;
                if (l != nullptr) s.push(l);
                TreeNode* r = node->right;
                if (r != nullptr) s.push(r);
                if (l == nullptr && r == nullptr) 
                    leaves2.push_back(node->val);
            }
            else
            {
                s.pop();
            }
        }
        sort(leaves1.begin(), leaves1.end());
        sort(leaves2.begin(), leaves2.end());
        if (leaves1.size() != leaves2.size()) return false;
        for (int i = 0; i < leaves1.size(); ++i)
        {
            if (leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};

*/