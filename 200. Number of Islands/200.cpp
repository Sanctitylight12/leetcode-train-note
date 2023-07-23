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

/*

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

*/


// DFS ，把1周圍的全變成0，這樣找下一個島嶼時，只要再找到下一個1即可


// class Solution {
// public:
//      void DFS(vector<vector<char>>&grid, int m, int n, int i, int j){

//         if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')return;//界定邊界


//         if(grid[i][j]=='1'){
//             grid[i][j]='0';
//             DFS(grid,m,n,i-1,j);
//             DFS(grid,m,n,i+1,j);
//             DFS(grid,m,n,i,j+1);
//             DFS(grid,m,n,i,j-1);
//         }

//      }



//     int numIslands(vector<vector<char>>& grid) {
//         int result=0;//島嶼數

//         int m=grid.size();//row總數
//         int n=grid[0].size();//確定每一col

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     result++;
//                     DFS(grid,m,n,i,j);
//                 }
//             }
//         }

//         return result;
        
//     }
// };



// BFS，用queue存找到的座標，假設找到A點，將A點塞入queue，接著取出以A點為核心

// 接著將A點上下左右有島嶼的地方的座標一併塞入，重複這個過程，直到queue空了之後，將指針下移去走另一個座標


// class Solution2 {
// public:
//     int numIslands(vector<vector<char>>& grid) {

//         int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     islands++;
//                     grid[i][j] = '0';
//                     queue<pair<int, int>> todo;
//                     todo.push({i, j});
//                     while (!todo.empty()) {
//                         pair<int, int> p = todo.front();
//                         todo.pop();
//                         for (int k = 0; k < 4; k++) {
//                             int r = p.first + offsets[k], c = p.second + offsets[k + 1];
//                             if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
//                                 grid[r][c] = '0';
//                                 todo.push({r, c});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return islands;

//   }
// };



// Union Find ：找到共同的祖先 或 合併(x,y)為 同一個祖先

// https://www.bilibili.com/video/BV1xa411A76q?p=21&vd_source=5866b1e1e17eca98dfe4cd4221585e39

// 有用到再把影片看一次


// 將二維數組的概念，變成一維數組，然後用一維數組的概念同樣去找上下左右

// int findPar(int u, vector<int>& par){
//         return par[u] == u ? u : (par[u] = findPar(par[u], par));
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
//         int m = grid[0].size(), n = grid.size();
//         vector<int> par(n*m);
//         for(int i = 0; i < n*m; i++) par[i] = i;
        
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j] == '1'){
//                     int p1 = findPar(i *m + j, par);
//                     for(vector<int>& d : dir){
//                         int r = i + d[0], c = j + d[1];
//                         if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == '1'){
//                             int p2 = findPar(r*m + c, par);
//                             if(p1 != p2) {
//                                 par[p2] = p1;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         int ans = 0;
//         for(int idx = 0; idx < n*m; idx++){
//             int i = idx/ m, j = idx%m;
//             if(par[idx] == idx && grid[i][j] == '1') ans++; 
//         }
//         return ans;
//     }