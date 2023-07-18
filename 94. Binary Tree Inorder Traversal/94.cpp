#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


// Morris Traversal方法

/*
 1. O(1)空間複雜度，即只能使用常數空間；

 2. 二叉樹的形狀不能被破壞（中間過程允許改變其形狀）。


一、中序遍歷
步驟：

1. 如果當前節點的左孩子為空，則輸出當前節點並將其右孩子作為當前節點。

2. 如果當前節點的左孩子不為空，在當前節點的左子樹中找到當前節點在中序遍歷下的前驅節點。

   a) 如果前驅節點的右孩子為空，將它的右孩子設定為當前節點。當前節點更新為當前節點的左孩子。

   b) 如果前驅節點的右孩子為當前節點，將它的右孩子重新設為空（恢復樹的形狀）。輸出當前節點。當前節點更新為當前節點的右孩子。

3. 重複以上1、2直到當前節點為空。
 
*/

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans; 
//         TreeNode* cur=root;
//         while(cur){
//             if(!cur->left){
//                 ans.push_back(cur->val);
//                 cur=cur->right;
//             }
//             else{
//                 TreeNode* prev=cur->left;
//                 while (prev->right != NULL && prev->right != cur)
//                     prev = prev->right;
    
//                     if (prev->right == NULL) 
//                     {
//                         prev->right = cur;
//                         cur = cur->left;
//                     }
//                     else                     
//                     {
//                         ans.push_back(cur->val);
//                         prev->right = NULL;
//                         cur = cur->right;
//                     }

//             }
      
//         }
//       return ans;
    
//     }
// };


//遞歸


// class Solution2 {
//     vector<int> ans;
// public:
//     void inorder(TreeNode* &root){
//     if(!root) return;
//         inorder(root->left);
//         ans.push_back(root->val);
//         inorder(root->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorder(root);
//         return ans;
//     }
// };




// stack

// class Solution3 {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode *> st;
//         while(true){
//             if(root!=NULL){
//                 st.push(root);
//                 root=root->left;
//             }
//             else{
//                 if(st.empty()){
//                     break;
//                 }
//                 root=st.top();
//                 res.push_back(root->val);
//                 st.pop();
//                 root=root->right;
//             }
//         }
//         return res;
//     }
// };












