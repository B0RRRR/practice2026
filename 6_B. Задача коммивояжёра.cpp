#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    int MAXX = 1000000000;
    vector<vector<int>> dp(1 << n, vector<int>(n, MAXX));

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0 || dp[mask][i] == MAXX) continue;

            for (int j = 0; j <= n - 1; j++) {
                if ((mask & (1 << j)) == 0) {
                    int new_mask = mask | (1 << j);
                    dp[new_mask][j] = min(dp[new_mask][j], dp[mask][i] + c[i][j]);
                } 
            }
            
        }
    }

    int ans = MAXX;
    int full = (1 << n) - 1;
    
    for (int i = 0; i < n; i++) {
        
        dp[full][i] += c[i][0];
        ans = min(ans, dp[full][i]);

    }

    cout << ans << endl;  
    return 0;
}