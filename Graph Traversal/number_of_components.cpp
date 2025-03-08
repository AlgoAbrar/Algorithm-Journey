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

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,e;
    cin >> n >> e;
    
    // Input edges and build the adjacency list
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    
    // Count connected components
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i);  // Start DFS if the node is unvisited
            cnt++;   // Increment the count of connected components
        }
    }

    cout << cnt << endl;  // Print the number of connected components
    return 0;
}
/*
Algorithm:
1. The program finds the number of connected components in an undirected graph using **Depth-First Search (DFS)**.
2. The graph is represented using an **adjacency list** `adj_list[1005]`, where each index represents a node, and each element at that index is a list of neighboring nodes.
3. The DFS function is implemented recursively:
   - Mark the current node `src` as visited.
   - For each unvisited neighboring node of `src`, recursively call DFS.
4. The program reads the graph's number of nodes `n` and edges `e` from the user input, and then constructs the graph by reading pairs of edges.
5. The DFS traversal is initiated for each unvisited node, and the number of times DFS is initiated represents the number of connected components in the graph.

Time Complexity:
- **O(N + E)**, where `N` is the number of nodes and `E` is the number of edges. Each node and edge is visited exactly once during the DFS traversal.

Space Complexity:
- **O(N + E)**, for the adjacency list representation of the graph and the `vis[]` array for storing whether a node has been visited.

*/