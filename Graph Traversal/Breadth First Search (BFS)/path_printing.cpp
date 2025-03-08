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

vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    // Reconstruct the path from dst to src using parent array
    vector<int> path;
    int node = dst;
    while(node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());  // Reverse the path to show from src to dst

    // Print the path
    for(int x : path)
    {
        cout << x << " ";
    }

    return 0;
}
/*
Algorithm:
1. **BFS (Breadth-First Search)** is used to find the shortest path from the source node `src` to the destination node `dst` in an undirected graph.
2. The graph is represented using an adjacency list `adj_list[1005]`, where each node is connected to other nodes via edges.
3. BFS is performed to explore all reachable nodes level by level from the source node:
   - Start from `src`, mark it as visited, and initialize its level to 0.
   - For every node, explore its neighbors. If the neighbor hasn't been visited, mark it as visited, update its level, and record its parent.
4. After BFS completes, the parent array is used to backtrack from the destination node `dst` to the source node `src`, constructing the path.
5. The path is printed in reverse order (from `src` to `dst`).

Time Complexity:
- **O(N + E)** where `N` is the number of nodes and `E` is the number of edges. BFS visits each node and edge once.

Space Complexity:
- **O(N + E)** for storing the adjacency list and the arrays `vis[]`, `level[]`, and `parent[]`.

*/