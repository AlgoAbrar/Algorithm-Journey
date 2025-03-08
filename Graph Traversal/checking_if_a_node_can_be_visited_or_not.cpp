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

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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
        adj_list[b].push_back(a);  // Undirected graph
    }
    memset(vis,false,sizeof(vis));
    int src,dst;
    cin >> src >> dst;
    bfs(src);

    if(vis[dst])
        cout << "YES\n";  // Path exists between src and dst
    else
        cout << "NO\n";  // No path exists between src and dst

    return 0;
}
/*
Algorithm:
1. The program uses **Breadth-First Search (BFS)** to determine if there is a path between two nodes in an undirected graph.
2. The graph is represented using an adjacency list, where each node stores its neighbors.
3. BFS starts from the source node (`src`). It explores all neighboring nodes at the current depth level before moving on to the next level.
4. The `vis[]` array keeps track of the nodes that have been visited to prevent revisiting nodes.
5. The program performs BFS from the source node and checks if the destination node (`dst`) is reachable. If it is, the program outputs "YES", otherwise "NO".

Time Complexity:
- The time complexity is **O(N + E)**, where N is the number of nodes and E is the number of edges in the graph. This is because each node and edge is processed once during BFS.

Space Complexity:
- The space complexity is **O(N + E)** due to the adjacency list representation and the visited array. The queue also uses space proportional to the number of nodes in the graph.

*/