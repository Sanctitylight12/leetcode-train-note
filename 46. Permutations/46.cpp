
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//未來最好再看一次

//遞歸解法，不太確定的點在於swap，CareerCup書
class Solution {
public:
    void backtrack(int i,vector<int>& n,vector<vector<int>>& ans){

        if(i==n.size()){//確認vector大小為與傳進來一致時，輸出結果
            ans.push_back(n);
            return;
        }

        for(int j=i;j<n.size();j++){
            swap(n[i],n[j]);
            backtrack(i+1,n,ans);
            swap(n[i],n[j]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;//存答案
        backtrack(0,nums,ans);//遞歸
        return ans;
    }
};

// DFS，深度優先
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level == num.size()) {res.push_back(out); return;}
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};

// 利用STL內建的函式庫，該方法對應到這題，可直接用全排列解
class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num.begin(), num.end())) {
            res.push_back(num);
        }
        return res;
    }
};