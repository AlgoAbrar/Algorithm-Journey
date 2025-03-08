/*
Name: Saiyedul Abrar
ID: 0812320205101022
Dept. of Computer Science and Engineering,
Bangladesh Army University of Engineering & Technology,
Qadirabad Cantonment, Natore, Bangladesh
Contact: saiyedul.abrar1430@gmail.com, +8801533713957
*/
#include<bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    // Print current position
    cout << si << " " << sj << endl;
    
    // Mark the current cell as visited
    vis[si][sj] = true;

    // Explore all 4 neighboring directions
    for(int i=0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        
        // If the cell is valid and not yet visited, recursively call DFS
        if(valid(ci,cj) && !vis[ci][cj])
            dfs(ci,cj);
    }
}

int main()
{
    cin >> n >> m;
    
    // Input the grid
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    // Input the start position for DFS
    int si,sj;
    cin >> si >> sj;
    
    memset(vis,false,sizeof(vis));
    
    // Start DFS from the given position
    dfs(si,sj);
    return 0;
}
/*
Algorithm:
1. The program uses **Depth-First Search (DFS)** to explore all reachable cells in a 2D grid starting from a given source cell (si, sj).
2. The grid is represented using a 2D array `grid[105][105]`, where each cell can either be traversable or not. The grid elements are input by the user.
3. The DFS traversal is performed using:
   - `vis[105][105]`: Keeps track of whether a cell has been visited.
   - `d`: A vector containing the 4 possible directions for movement (up, down, left, right).
4. The DFS function prints the current position `(si, sj)` as it explores the grid. It recursively visits all valid neighboring cells.
5. The program starts DFS from the given start cell `(si, sj)` and explores all connected cells in the grid that are not already visited.

Time Complexity:
- The time complexity is **O(N * M)**, where N is the number of rows and M is the number of columns. Each cell is visited once during DFS traversal.

Space Complexity:
- The space complexity is **O(N * M)** for the `vis[105][105]` array, which stores whether a cell has been visited or not.

*/