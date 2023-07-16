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

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
 

*/

// DFS
class Solution {
public:
    int n;
    vector<vector<int>> resultSet;//結果集合
    void dfs(int idx,vector<int>subset,vector<int>& nums){

        resultSet.push_back(subset);//每一次進到這裡，就弄一份塞進resultSet中

        for(int i=idx;i<n;i++){
            subset.push_back( nums[i]);
            dfs(i+1,subset,nums);//進到下一層
            subset.pop_back();
            // 因為還要遞迴，假設一條路走到[1,2.3]走到底了
            // 還要往回遞下一條路徑時，如：要的答案是[1,3]，但變成[1,2,3,3]，因為沒把上一輪的 2,3 pop掉，會造成結果錯誤

        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {        
        n=nums.size();
        dfs(0,  {}, nums);
            
        return resultSet;
    
    }
};