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
iven two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

*/

class Solution {
public:

    // n=共要幾種數字，n=4，即1~4 k=幾個數字所構成組合  
    void solve(int n,int k,vector<int>&tmp,vector<vector<int>>&ans,int s){
        //s為從哪個數字開始找組合
        
        if(k==0){
            ans.push_back(tmp);
            return;
        }

        if(s>n){//超過上限肯定不用在找了，直接return
            return;
        }

        for(int i=s;i<=n;i++){//開始遞迴循環比較
            tmp.push_back(i);//舉例：假設初始起點是1
            solve(n,k-1,tmp,ans,i+1);//舉例：這裡就是由遞迴的樹狀結構往下找，組合，如：[1,2]、[1,3]
            tmp.pop_back();//把新生成的組合最後一位數去掉，如生成：[1,2]，把2去掉，要不然接下來找[1,3]會變成[1,2,3]
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(n,k,tmp,ans,1);
        return ans;

    }
};