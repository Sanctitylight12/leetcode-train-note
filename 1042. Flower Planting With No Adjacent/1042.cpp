#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


/*1042
You have n gardens, labeled from 1 to n, 

and an array paths where paths[i] = [xi, yi] 

describes a bidirectional path between garden xi to garden yi. 

In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that,

for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, 

where answer[i] is the type of flower planted in the (i+1)th garden. 

The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].



Example 2:
說明：第一個set 和 第二個set皆為一個連通圖
故1、2互聯標type 1 2。
  3、4互聯標type 1 2。
得type [1,2,1,2]
Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]



Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

*/

/*
要求:這道題相當與給我們N個點, 每個點最多與圖中另外三個點相連,
要求我們用4種顏色給圖染色,同時任意一條 邊上的2個點不能是相同的顏色。

思路:
因為題目保證了一定存在解, 所以我們只要搜索出一種染色方法就可以了。

對於一個圖,它一定是由若幹個最大 連通子圖組成的。

任意兩個不同的連通 圖,它們之間的染色互相不影響。

而我們 對每個連通圖,分別做一次dfs就可以把這個連通圖中所有的點做一次滿足要求的染色,

並把結果保存到我們返回的染色數 組中即可。

時間複雜度: O(paths) = O(1.5N)// 空間複雜度:O(N)

*/



class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);//節點資訊，如是否染色
        vector<vector<int>> G(N);//圖
        for (vector<int>& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);//push_back() 都是在陣列的尾端加入一個元素
            G[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < N; ++i) {
            int colors[5] = {};
            for (int j : G[i])
                colors[res[j]] = 1;
            for (int c = 4; c > 0; --c)//花色只有四種
                if (!colors[c])
                    res[i] = c;
        }
        return res;
    }

};

int main(void)
{
    
    //mock
    //Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
    //Output: [1,2,3,4]


    Solution testObj;
    
    // vector<int> vect{2,7,11,15};
    vector<vector<int>> p ={{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
    vector<int> store;
    int n=4;
    store=testObj.gardenNoAdj(n,p);

    for (int i : store)
        cout << i << " ";

}
