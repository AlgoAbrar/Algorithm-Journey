/*
Name: Saiyedul Abrar
ID: 0812320205101022
Dept. of Computer Science and Engineering,
Bangladesh Army University of Engineering & Technology,
Qadirabad Cantonment, Natore, Bangladesh
Contact: saiyedul.abrar1430@gmail.com, +8801533713957
*/

#include<bits/stdc++.h>
using namespace std;    // O(2^N)


// Function to calculate the nth Fibonacci number using Recursion
int fibo(int n)
{
    // Base case: Fibonacci of 0 or 1
    if(n < 2)
        return n;

    // Recursive case: Fibonacci of n is the sum of (n-1)th and (n-2)th Fibonacci numbers
    return fibo(n-1) + fibo(n-2); 
}

int main()
{
    int n;
    cin >> n;
    
    // Output the nth Fibonacci number
    cout << fibo(n);
    
    return 0;
}

/*
Algorithm:
1. The function `fibo(n)` calculates the nth Fibonacci number recursively.
2. The base case checks if n is less than 2 (Fibonacci of 0 is 0, and Fibonacci of 1 is 1).
3. For other values of n, the function recursively computes Fibonacci(n-1) and Fibonacci(n-2), and adds them together.

Time Complexity:
- The time complexity of this approach is **O(2^N)**, where `N` is the input value `n`. This is because each Fibonacci number calculation makes two recursive calls, leading to an exponential number of calls.

Space Complexity:
- The space complexity is **O(N)** due to the recursive call stack, as the recursion depth can be as large as `n`.

Note:
- This approach is inefficient for larger values of `n` because it recalculates the same Fibonacci numbers multiple times, leading to exponential time complexity.
*/
