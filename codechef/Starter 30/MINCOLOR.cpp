// #include <bits/stdc++.h>

// using namespace std;

// bool validBox(vector < vector < int >> & grid, int x, int y, int color) {
//     if (grid[x][y] != 0)
//       return false;
//     if (x >= 0 and grid[x][y] == color)
//         return false;
//     if (x < grid.size() and grid[x][y] == color)
//         return false;
//     if (y >= 0 and grid[x][y] == color)
//         return false;
//     if (y < grid[0].size() and grid[x][y] == color)
//         return false;
//     return true;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m;
//         cin >> n >> m;
//         int x1, x2, y1, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         vector < vector < int >> grid(n, vector < int > (m, 0));
//         // filling given positions
//         grid[x1 - 1][y1 - 1] = 1;
//         grid[x2 - 1][y2 - 1] = 2;
//         vector < vector < int >> copy_grid(n, vector < int > (m, 0));
//         copy_grid = grid;
//         set < int > st;
//         for (int i = 1; i <= 100; i++)
//             st.insert(i);
//         queue < pair < int, int >> q;
//         // Inserting pairs in queue
//         q.push({
//             x1 - 1,
//             y1 - 1
//         });
//         q.push({
//             x2 - 1,
//             y2 - 1
//         });
//         while (!q.empty()) {
//             pair < int, int > pr = q.front();
//             q.pop();
//             if (pr.first + 1 < n and grid[pr.first + 1][pr.second] == 0) {
//                 for (auto it = st.begin(); it != st.end(); it++) {
//                     if (validBox(grid, pr.first + 1, pr.second, * it)) {
//                         grid[pr.first + 1][pr.second] = * it;
//                         q.push({
//                             pr.first + 1,
//                             pr.second
//                         });
//                         break;
//                     }
//                 }
//             }
//             if (pr.first - 1 >= 0 and grid[pr.first - 1][pr.second] == 0) {
//                 for (auto it = st.begin(); it != st.end(); it++) {
//                     if (validBox(grid, pr.first - 1, pr.second, * it)) {
//                         grid[pr.first - 1][pr.second] = * it;
//                         q.push({
//                             pr.first - 1,
//                             pr.second
//                         });
//                         break;
//                     }
//                 }
//             }
//             if (pr.second + 1 < m and grid[pr.first][pr.second + 1] == 0) {
//                 for (auto it = st.begin(); it != st.end(); it++) {
//                     if (validBox(grid, pr.first, pr.second + 1, * it)) {
//                         grid[pr.first][pr.second + 1] = * it;
//                         q.push({
//                             pr.first,
//                             pr.second + 1
//                         });
//                         break;
//                     }
//                 }
//             }
//             if (pr.second - 1 >= 0 and grid[pr.first][pr.second - 1] == 0) {
//                 for (auto it = st.begin(); it != st.end(); it++) {
//                     if (validBox(grid, pr.first, pr.second - 1, * it)) {
//                         grid[pr.first][pr.second - 1] = * it;
//                         q.push({
//                             pr.first,
//                             pr.second - 1
//                         });
//                         break;
//                     }
//                 }
//             }

//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < m; j++) {
//                     if (copy_grid[i][j] != 0)
//                         continue;
//                     for (auto it = st.begin(); it != st.end(); it++) {
//                         if (validBox(copy_grid, i, j, * it)) {
//                             copy_grid[i][j] = * it;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//         set < int > pt1, pt2;
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < m; j++) {
//                     pt1.insert(grid[i][j]);
//                     pt2.insert(copy_grid[i][j]);
//                 }
//             }

//             if (pt1.size() < pt2.size()) {
//                 for (int i = 0; i < n; i++) {
//                     for (int j = 0; j < m; j++) {
//                         cout << grid[i][j] << " ";
//                     }
//                     cout << endl;
//                 }
//             } else {
//                 for (int i = 0; i < n; i++) {
//                     for (int j = 0; j < m; j++) {
//                         cout << copy_grid[i][j] << " ";
//                     }
//                     cout << endl;
//                 }
//             }
//     }
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin >> t;
   while (t--) {
      int n, m;
      cin >> n >> m;
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--;x2--;y1--;y2--;
      vector<vector<int>> arr(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if((i+j)%2==(x1+y1)%2)
               arr[i][j]=1;
            else
               arr[i][j]=2;
         }
      }

      if((x1+y1)%2 == (x2+y2)%2){
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(arr[i][j]==2)
                  arr[i][j] = 3;
            }
         }
         arr[x2][y2] = 2;
      }

      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
         }
         cout<<endl;
      }
   }
   return 0;
}