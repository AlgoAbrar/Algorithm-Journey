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
    if(i < 0 || mx_weight <= 0) // Base case: No items left or knapsack is full
        return 0;
    
    if(dp[i][mx_weight] != -1) // If the result is already computed, return it
        return dp[i][mx_weight];

    if(weight[i] <= mx_weight) // If the current item can be included
    {
        int op1 = knapsack(i-1, mx_weight - weight[i]) + val[i]; // Include the item
        int op2 = knapsack(i-1, mx_weight); // Exclude the item
        dp[i][mx_weight] = max(op1, op2); // Store the maximum of both options
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i-1, mx_weight); // Exclude the item
        return dp[i][mx_weight];
    }
}

int main()
{
    int n, mx_weight;
    cin >> n >> mx_weight; // Input number of items and the maximum weight capacity

    // Input the weight and value of each item
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }

    // Initialize the DP table with -1 (indicating uncomputed values)
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;

    // Output the result of the knapsack function, which is the maximum value that can be obtained
    cout << knapsack(n-1, mx_weight) << endl;

    return 0;
}
/*
Algorithm:
This is the dynamic programming (DP) implementation of the 0/1 Knapsack problem. 
We use a DP table `dp[i][mx_weight]` where `i` represents the number of items considered 
and `mx_weight` represents the weight capacity of the knapsack. The idea is to store the 
result of subproblems in the DP table to avoid redundant calculations.
- If the item can be included in the knapsack, we calculate the maximum value by either 
  including or excluding the item.
- If the item cannot be included, we exclude it.
The solution is built from smaller subproblems and stored for future use.

Time Complexity:
The time complexity of this dynamic programming solution is O(n * W), 
where n is the number of items and W is the maximum weight capacity of the knapsack. 
This is because we fill a DP table of size `n * W`.

Space Complexity:
The space complexity is O(n * W) due to the DP table `dp` used to store the results of subproblems.

*/