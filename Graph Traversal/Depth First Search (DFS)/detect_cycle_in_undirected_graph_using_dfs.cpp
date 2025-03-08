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
int parent[105];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
    {
        // If the child is already visited and is not the parent, cycle detected
        if(vis[child] && parent[src] != child)
            cycle = true;
        if(!vis[child])
        {
            parent[child] = src;  // Mark the parent of the current node
            dfs(child);  // Recursively call DFS for unvisited child
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
        adj_list[a].push_back(b);  // Add edge from a to b
        adj_list[b].push_back(a);  // Add edge from b to a (undirected graph)
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));  // Initialize parent array
    cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);  // Perform DFS from each unvisited node
    }
    if(cycle)
        cout << "Cycle Detected\n";  // Print "Cycle Detected" if a cycle is found
    else
        cout << "No Cycle\n";  // Print "No Cycle" if no cycle is found
    return 0;
}
/*
Algorithm:
1. The program uses **Depth-First Search (DFS)** to detect cycles in an undirected graph.
2. The graph is represented using an adjacency list, where each node stores a list of its adjacent nodes.
3. The DFS traversal is performed using:
   - `vis[]`: Keeps track of whether a node has been visited.
   - `parent[]`: Stores the parent of each node to ensure we don't mistakenly count the parent-child edge as a cycle.
4. During DFS, if we encounter a node that has already been visited and is not the parent of the current node, it indicates the presence of a cycle.
5. The program explores all nodes and edges. If a cycle is detected during any DFS call, it sets the `cycle` flag to true.
6. If the cycle flag is set to true after all DFS calls, a cycle is detected. Otherwise, no cycle exists in the graph.

Time Complexity:
- The time complexity is **O(N + E)**, where N is the number of nodes and E is the number of edges. This is because each node and edge is processed once during DFS.

Space Complexity:
- The space complexity is **O(N + E)** due to the adjacency list, visited (`vis[]`), and parent (`parent[]`) arrays used by DFS.

*/