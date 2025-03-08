/*
Name: Saiyedul Abrar
ID: 0812320205101022
Dept. of Computer Science and Engineering,
Bangladesh Army University of Engineering & Technology,
Qadirabad Cantonment, Natore, Bangladesh
Contact: saiyedul.abrar1430@gmail.com, +8801533713957
*/

#include<bits/stdc++.h>
using namespace std;      // O(N)

long long int dp[1005];

// Function to calculate the nth Fibonacci number using Memoization (Top-down DP)
int fibo(long long int n)
{
    // Base case: Fibonacci of 0 or 1
    if(n < 2)
        return n;

    // If the Fibonacci number has already been calculated, return the stored result
    if(dp[n] != -1)
        return dp[n];

    // Recursively calculate the Fibonacci number and store it in dp array
    dp[n] = fibo(n-1) + fibo(n-2); 
    
    return dp[n];
}

int main()
{
    // Initialize dp array with -1 (indicating that no Fibonacci number has been calculated yet)
    memset(dp, -1, sizeof(dp));
    
    long long int n;
    cin >> n;
    
    // Output the nth Fibonacci number
    cout << fibo(n);
    
    return 0;
}

/*
Algorithm:
1. The function `fibo(n)` calculates the nth Fibonacci number using recursion and memoization.
2. If the result for `n` has already been computed (i.e., `dp[n]` is not -1), it returns the cached value.
3. If the result has not been computed, it computes the Fibonacci number recursively and stores the result in `dp[n]` to avoid redundant calculations in future calls.
4. The base case is when `n` is less than 2 (Fibonacci of 0 is 0, and Fibonacci of 1 is 1).

Time Complexity:
- The time complexity of this approach is **O(N)**, where `N` is the input value `n`. This is because each Fibonacci number is computed at most once and stored in the `dp` array.

Space Complexity:
- The space complexity is **O(N)** due to the storage required for the `dp` array, which holds Fibonacci values for all integers from `0` to `n`.

Note:
- This approach uses memoization, which improves performance by avoiding the recalculation of Fibonacci numbers that have already been computed.
*/
