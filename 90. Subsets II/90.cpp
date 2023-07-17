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
//跟78 那題差在有重複數字
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

*/

// dfs
class Solution {
public:

    void subSol(int idx,vector<int> & nums, int n,vector<int> &temp, vector<vector<int>>& ans)
    {

        ans.push_back(temp);
         for (int i = idx; i < n; i++) {
            if(i!=idx && nums[i]==nums[i-1]){ //發現有重複的，進入到下一個循環，如：[1,2,2]這樣子
                continue;//後面不做，返回進入到下一輪
             }
            temp.push_back(nums[i]);
            subSol(i+1, nums, n, temp, ans);
            temp.pop_back();
         }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subSol(0, nums, n, temp, ans);
        return ans;
    }
};