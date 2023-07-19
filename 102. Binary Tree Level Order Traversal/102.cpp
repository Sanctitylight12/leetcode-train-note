#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

/*

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []



*/

//BFS


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);//先塞root進去
        while(!q.empty()){//每次進去開啟一次新的層級
            int qlen=q.size();//表當前這層多少元素
            vector<int> v;
            while(qlen--){
                //找到上一層的節點，上層節點的子節點，為這層要找的數組
                TreeNode *f=q.front();
                v.push_back(q.front()->val);
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
           ans.push_back(v);
        }
    return ans;

        
    }
};


// dfs

//先往最深層走


// class Solution2 {
// public:
//     void dfs(TreeNode * root ,vector<vector<int>>&ans,int d=0){
//       if(!root)return;
//       if(d>=ans.size())ans.push_back({});
//       ans[d].push_back(root->val);
//       dfs(root->left,ans,d+1);
//       dfs(root->right,ans,d+1);
//   }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         if(!root)return ans;
//          if(!root)return ans;
//          dfs(root,ans);
//         return ans;
//     }
// };