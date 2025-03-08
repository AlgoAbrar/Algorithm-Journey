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

int find(int node)   // O(N)
{
    if(par[node] == -1) 
        return node;
    int leader = find(par[node]);
    return leader;
}

int main()
{
    memset(par,-1,sizeof(par));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    cout << find(4) << endl;

    return 0;
}
/*
Algorithm:
1. The program simulates the union-find (disjoint-set) structure with path compression.
2. The `par[]` array represents the parent of each node, initially set to -1, indicating that each node is its own leader.
3. The `find()` function recursively finds the root leader of the given node using path compression. If the node's parent is -1, it returns the node itself as its leader. Otherwise, it recursively calls `find()` on the parent of the node.
4. In the `main()` function, an array `par[]` is initialized to represent some parent-child relationships. Then, the `find()` function is used to find the leader of node 4.

Time Complexity:
- The time complexity of the `find()` function is O(N) in the worst case due to the recursive calls, where N is the number of nodes in the set. However, with path compression, the time complexity can be improved to nearly O(α(N)), where α is the inverse Ackermann function, which grows very slowly, making it almost constant time for practical inputs.

Space Complexity:
- The space complexity is O(N) due to the storage required for the `par[]` array, where N is the number of nodes.

*/