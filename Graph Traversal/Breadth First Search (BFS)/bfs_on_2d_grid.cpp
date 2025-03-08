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
int level[105][105];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0;i<4;i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(si,sj);
    cout << level[di][dj] << endl;
    return 0;
}
/*
Algorithm:
1. The program uses the **Breadth-First Search (BFS)** algorithm to find the shortest path between two points in a grid.
2. The grid is represented as a 2D matrix, where each cell can either be open ('.') or blocked ('#').
3. The BFS starts from the source node `(si, sj)` and explores all possible valid moves (up, down, left, right) while maintaining a queue to process nodes level by level.
4. The program tracks the visited cells to avoid revisiting them and updates the distance (level) from the source node for each cell.
5. If the destination `(di, dj)` is reached, the BFS terminates, and the shortest path length is output. If the destination is not reachable, the distance remains `-1`.

Time Complexity:
- The time complexity of the BFS algorithm is **O(N * M)**, where N is the number of rows and M is the number of columns in the grid. This is because each cell is processed at most once, and there are at most N * M cells in the grid.

Space Complexity:
- The space complexity is **O(N * M)**, due to the space required for the grid, visited array, and level array, where N and M are the number of rows and columns, respectively.

*/