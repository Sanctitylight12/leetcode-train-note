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

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.


Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1


Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/

// sliding window

// https://medium.com/%E6%8A%80%E8%A1%93%E7%AD%86%E8%A8%98/%E6%BC%94%E7%AE%97%E6%B3%95%E7%AD%86%E8%A8%98%E7%B3%BB%E5%88%97-two-pointer-%E8%88%87sliding-window-8742f45f3f55

// 最好花時間在看一次
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0;
        int ans = INT_MAX;
        int sum=0;

        for(int j=0;j<nums.size();j++){

             sum += nums[j];
             while(sum >= target && j<nums.size()){

                 ans = min(ans,j-i+1);
                 sum -= nums[i];
                 i++;
             }

        }
        return ans == INT_MAX ? 0 : ans;
    }
};