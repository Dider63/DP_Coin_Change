#include <iostream>
#include <vector>
using namespace std;

int coinChangeWays(const vector<int>& coins, int target) {
    int n = coins.size();
    // Create dp table with (n+1) rows and (target+1) columns initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Initialize: 1 way to make amount 0 with any number of coins
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Fill dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            int coin = coins[i - 1];
            if (coin > j) {
                // Can't use this coin, copy value from above (exclude coin)
                dp[i][j] = dp[i - 1][j];
            } else {
                // Sum of excluding the coin and including the coin
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int target = 5;

    cout << "Number of ways to make " << target << " with coins {1, 2, 5}: "
         << coinChangeWays(coins, target) << endl;

    return 0;
}

