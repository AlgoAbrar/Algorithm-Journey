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
    cout << src << " ";
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
    
    // Perform DFS starting from node 0
    dfs(0);
    
    return 0;
}
/*
Algorithm:
1. The program performs **Depth-First Search (DFS)** to traverse all the nodes in an undirected graph starting from node 0.
2. The graph is represented using an **adjacency list** `adj_list[1005]`, where each index represents a node, and each element at that index is a list of neighboring nodes.
3. The DFS function is implemented recursively:
   - Mark the current node `src` as visited and print it.
   - For each unvisited neighboring node of `src`, recursively call DFS.
4. The program reads the graph's number of nodes `n` and edges `e` from the user input, and then constructs the graph by reading pairs of edges.
5. The DFS traversal starts from node 0, and the program prints the nodes in the order they are visited.

Time Complexity:
- **O(N + E)**, where `N` is the number of nodes and `E` is the number of edges. Each node and edge is visited exactly once during the DFS traversal.

Space Complexity:
- **O(N + E)**, for the adjacency list representation of the graph and the `vis[]` array for storing whether a node has been visited.

*/