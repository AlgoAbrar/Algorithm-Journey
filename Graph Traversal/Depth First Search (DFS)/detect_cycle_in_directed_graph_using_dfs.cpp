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

bool vis[105];
vector<int> adj_list[105];
bool pathvis[105];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for(int child : adj_list[src])
    {
        if(vis[child] && pathvis[child])
            cycle = true;  // A cycle is detected
        if(!vis[child])
        {
            dfs(child);  // Recur for unvisited child
        }
    }
    pathvis[src] = false;  // Unmark the current node after finishing DFS for that node
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);  // Directed graph edge from a to b
    }
    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);  // Start DFS from unvisited node
    }
    if(cycle)
        cout << "Cycle Detected\n";  // If a cycle is detected, print "Cycle Detected"
    else
        cout << "No Cycle\n";  // Otherwise, print "No Cycle"
    return 0;
}
/*
Algorithm:
1. The program uses **Depth-First Search (DFS)** to detect cycles in a directed graph.
2. The graph is represented using an adjacency list, where each node stores a list of its adjacent nodes (children).
3. The DFS is performed using two auxiliary arrays:
   - `vis[]`: Keeps track of whether a node has been fully visited.
   - `pathvis[]`: Keeps track of the nodes currently in the recursion stack (part of the current DFS path).
4. During DFS, if we encounter a node that is already visited and is also part of the current DFS path (`pathvis[src]`), it indicates the presence of a cycle in the graph.
5. The algorithm explores all nodes, and if a cycle is detected during any DFS call, it sets the `cycle` flag to true.

Time Complexity:
- The time complexity is **O(N + E)**, where N is the number of nodes and E is the number of edges. This is because we visit each node and edge once during the DFS.

Space Complexity:
- The space complexity is **O(N + E)** due to the adjacency list, the visited (`vis[]`) and path visit (`pathvis[]`) arrays, and the recursion stack used during DFS.

*/