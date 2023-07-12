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
Given an array of intervals where intervals[i] = [starti, endi], 

merge all overlapping intervals, and return an array of the non-overlapping intervals

that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].


Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){//簡單來說，這裡區間不會重疊，直接塞進去
                //back 從後面取出元素
                ans.push_back(intervals[i]);
            }
            else{//這裡主要判斷區間，如：[1,3],[2,6]。3>2 => [1,6]
               ans.back()[1]=max(intervals[i][1],ans.back()[1]);//合併
            }
        }
        return ans;       
    }
};