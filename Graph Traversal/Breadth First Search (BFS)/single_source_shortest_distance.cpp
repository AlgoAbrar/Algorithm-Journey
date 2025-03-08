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
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    
    // Read the edges and populate the adjacency list
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));  // Mark all nodes as unvisited
    memset(level, -1, sizeof(level));  // Set initial distance (level) to -1 (unreachable)

    int src, dst;
    cin >> src >> dst;
    
    bfs(src);  // Perform BFS starting from the source node

    // Output the shortest distance from source to destination
    cout << level[dst] << endl;

    return 0;
}
/*
Algorithm:
1. **BFS (Breadth-First Search)** is used to find the shortest distance (in terms of edges) from a source node `src` to a destination node `dst` in an undirected graph.
2. The graph is represented using an adjacency list `adj_list[1005]`, where each node is connected to other nodes via edges.
3. BFS is performed starting from the source node `src`:
   - Start from `src`, mark it as visited, and initialize its distance (level) to 0.
   - For every node, explore its neighbors. If the neighbor hasn't been visited, mark it as visited and update its distance as `level[current node] + 1`.
4. After BFS completes, the level array stores the shortest distance from `src` to all other nodes.
5. The distance to the destination node `dst` is printed.

Time Complexity:
- **O(N + E)** where `N` is the number of nodes and `E` is the number of edges. BFS visits each node and edge once.

Space Complexity:
- **O(N + E)** for storing the adjacency list and arrays `vis[]` and `level[]`.

*/