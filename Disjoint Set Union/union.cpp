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
int par[1005];
int group_size[1005];

int find(int node)   // O(logN)
{
    if(par[node] == -1) 
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2) 
{
    int leader1 = find(node1); 
    int leader2 = find(node2);   
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    memset(par,-1,sizeof(par));
    memset(group_size,1,sizeof(group_size));
    dsu_union(1,2);
    dsu_union(2,0);
    dsu_union(3,1);

    for(int i=0;i<6;i++)
        cout << i << " -> " << par[i] << endl;
    return 0;
}
/*
Algorithm:
1. The program implements the Disjoint Set Union (DSU) or Union-Find data structure with path compression and union by size.
2. The `par[]` array is used to store the parent of each node, initially set to -1, indicating that each node is its own leader.
3. The `group_size[]` array is used to store the size of the group (or set) for each leader node.
4. The `find()` function recursively finds the leader of the given node. It applies path compression by setting the parent of the node directly to its leader, optimizing future queries.
5. The `dsu_union()` function performs a union operation between two sets. It first finds the leaders of both nodes. Then, it attaches the smaller set to the larger set (union by size), keeping the tree shallow and improving the efficiency of future operations.
6. In the `main()` function, a few union operations are performed, and the parent of each node is printed.

Time Complexity:
- The time complexity of the `find()` operation with path compression is nearly O(α(N)), where α is the inverse Ackermann function, which grows extremely slowly, and N is the number of nodes.
- The `dsu_union()` operation involves two calls to `find()`, and then a constant-time operation to attach the smaller group to the larger one. Thus, the time complexity of `dsu_union()` is O(α(N)).

Space Complexity:
- The space complexity is O(N), where N is the number of nodes. This is due to the storage required for the `par[]` and `group_size[]` arrays.

*/