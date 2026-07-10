#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;


    vector<vector<int>> gold(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> gold[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = gold[i][j] + max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    cout << dp[n][m] << "\n";

    return 0;
}
