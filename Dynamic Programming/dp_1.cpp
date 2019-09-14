#include<iostream>

int main()
{
    int maxN= 100; 
    int dp[maxN];

    // base case : Factorial of 0 is 1 
    dp[0]= 1;

    int n= 3; 
    for (int i= 1; i<=n; i++)
    {
        dp[i]= dp[i-1]*i;
    }

    std::cout << "Factorial for: "<< n << " is: "<< dp[n] << std::endl;  
}