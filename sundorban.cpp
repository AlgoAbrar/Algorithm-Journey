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

char grid[35][35];
bool vis[35][35];
int level[35][35];
vector<pair<int, int>> d;
int n;

bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    
    while(!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    d.push_back({-1, 0}); // Up
    d.push_back({1, 0});  // Down
    d.push_back({0, -1}); // Left
    d.push_back({0, 1});  // Right
    
    int si, sj, di, dj;

    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == 'S') // Starting point
                {
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 'E') // Ending point
                {
                    di = i;
                    dj = j;
                }
            }
        }

        memset(vis, false, sizeof(vis)); // Reset visited array
        memset(level, -1, sizeof(level)); // Reset level array
        bfs(si, sj); // Perform BFS starting from (si, sj)
        cout << level[di][dj] << endl; // Output the shortest distance to the end point
    }
    return 0;
}
/*
Algorithm:
This program implements a breadth-first search (BFS) to find the shortest path in a grid from a starting point ('S') to an ending point ('E').
- The BFS algorithm explores the grid level by level starting from the source, marking visited cells to avoid revisiting.
- The grid can have obstacles ('T'), and BFS ensures the path does not pass through these obstacles.
- The program calculates the shortest distance from the start point to the end point.

Time Complexity:
- The time complexity of the BFS algorithm is O(n^2), where n is the dimension of the grid. This is because we may have to visit every cell in the grid in the worst case, and each cell is processed once.
  
Space Complexity:
- The space complexity is O(n^2), as we are storing a 2D grid (`grid`), a visited array (`vis`), and a level array (`level`), all of size n x n.

*/