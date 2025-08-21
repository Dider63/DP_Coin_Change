#include <iostream>
using namespace std;

int countWays(int coins[], int n, int total)
{
    int dp[n + 1][total + 1];

    // Initialize base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;  // 1 way to make sum = 0 (choose nothing)

    for (int j = 1; j <= total; j++)
        dp[0][j] = 0;  // 0 ways to make positive sum with 0 coins

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][total];
}

int main()
{
    int n, total;

    cout << "Enter number of coin types: ";
    cin >> n;

    int coins[n];

    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter the total amount: ";
    cin >> total;

    int ways = countWays(coins, n, total);
    cout << "Number of ways to make " << total << " is: " << ways << endl;

    return 0;
}


