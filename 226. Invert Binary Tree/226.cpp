#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


/*
Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []

*/


//Definition for a binary tree node.
struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

          if(root==NULL){
            return root;}

            TreeNode *a,*b,*c;

            a=invertTree(root->left);
            b=invertTree(root->right);
            c=a;
            a=b;
            b=c;

            root->left=a;
            root->right=b;

            return root;
        
    }
};


// TreeNode* invertTree(TreeNode* root) {
//        if (root) {
//            TreeNode* temp = root->left;
//            root->left = root->right;
//            root->right = temp;
//            invertTree(root->left);
//            invertTree(root->right);
//        }
//        return root;