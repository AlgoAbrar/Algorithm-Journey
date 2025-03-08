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
        // ber kore ana
        int par = q.front();
        q.pop();

        // oi node ke niye kaj
        cout << par << " ";

        // children gulo push kora
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
    bfs(0);  // Start BFS from node 0
    return 0;
}
/*
Algorithm:
1. The program implements the **Breadth-First Search (BFS)** algorithm for traversing an undirected graph.
2. The graph is represented using an adjacency list, where each node points to its adjacent nodes.
3. BFS starts from the source node (node `0` in this case). It explores all the neighboring nodes at the present depth level before moving on to nodes at the next depth level.
4. The `vis[]` array is used to track visited nodes to avoid processing the same node multiple times.
5. The algorithm uses a queue to store nodes to be processed. As nodes are processed, they are dequeued from the front, and their unvisited neighbors are added to the queue.
6. The program outputs the nodes in the order they are visited by BFS.

Time Complexity:
- The time complexity is **O(N + E)**, where N is the number of nodes and E is the number of edges in the graph. Each node and each edge is processed once during BFS.

Space Complexity:
- The space complexity is **O(N + E)** due to the adjacency list representation of the graph and the visited array. The queue also uses space proportional to the number of nodes in the graph.

*/