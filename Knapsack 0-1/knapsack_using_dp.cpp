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

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    if(i < 0 || mx_weight <= 0)
        return 0;
    
    // If the subproblem has already been solved, return the stored value
    if(dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    if(weight[i] <= mx_weight)
    {
        // Option 1: Include the item, and reduce the remaining weight
        int op1 = knapsack(i-1, mx_weight - weight[i]) + val[i];
        // Option 2: Exclude the item and keep the same remaining weight
        int op2 = knapsack(i-1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else
    {
        // If the item cannot be included, exclude it
        dp[i][mx_weight] = knapsack(i-1, mx_weight);
        return dp[i][mx_weight];
    }
}

int main()
{
    int n, mx_weight;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> val[i];  // Read values of the items
    for(int i = 0; i < n; i++)
        cin >> weight[i];  // Read weights of the items
    cin >> mx_weight;  // Read the maximum weight capacity

    // Initialize the dp array to -1 (indicating uncomputed states)
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;

    // Compute the maximum value that can be obtained with the given weight capacity
    cout << knapsack(n-1, mx_weight) << endl;

    return 0;
}
/*
Algorithm:
1. **0/1 Knapsack Problem** is a dynamic programming problem where we are given a set of items, each with a value and weight. We need to determine the maximum value that can be obtained by selecting a subset of the items such that their total weight is less than or equal to a given capacity `mx_weight`.
   
2. The solution uses dynamic programming to build a `dp` table where `dp[i][j]` represents the maximum value achievable by considering the first `i` items with a weight capacity `j`.
   
3. The recurrence relation is as follows:
   - If the weight of the current item `weight[i]` is less than or equal to the remaining weight capacity `mx_weight`, then we have two choices:
     - Include the current item: `dp[i][mx_weight] = max(dp[i-1][mx_weight], dp[i-1][mx_weight - weight[i]] + val[i])`
     - Exclude the current item: `dp[i][mx_weight] = dp[i-1][mx_weight]`
   
   - If the current item cannot be included because its weight exceeds the remaining capacity, we only consider excluding it: `dp[i][mx_weight] = dp[i-1][mx_weight]`
   
4. The final answer is stored in `dp[n-1][mx_weight]` where `n` is the number of items.

Time Complexity:
- **O(n * mx_weight)** where `n` is the number of items and `mx_weight` is the maximum weight capacity. We iterate over all items and weights, and for each combination, we compute the optimal value.

Space Complexity:
- **O(n * mx_weight)** for storing the dynamic programming table `dp` of size `n x mx_weight`.

*/