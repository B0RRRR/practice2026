#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool valid(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void solve() {
    cin >> n >> m;
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    dp[1][1] = a[1][1];
    
    for (int sum = 2; sum <= n + m; ++sum) {
        for (int i = 1; i <= n; ++i) {
            int j = sum - i;
            
            if (j >= 1 && j <= m) {
                
                if (i == 1 && j == 1) continue;
                
                int prev_max = 0; 
                
                if (valid(i - 2, j + 1)) {
                    prev_max = max(prev_max, dp[i - 2][j + 1]);
                }
                
                if (valid(i - 2, j - 1)) {
                    prev_max = max(prev_max, dp[i - 2][j - 1]);
                }
                
                if (valid(i - 1, j - 2)) {
                    prev_max = max(prev_max, dp[i - 1][j - 2]);
                }
                
                if (valid(i + 1, j - 2)) {
                    prev_max = max(prev_max, dp[i + 1][j - 2]);
                }
                
                if (prev_max > 0) {
                    dp[i][j] = prev_max + a[i][j];
                }
            }
        }
    }
    
    int maxx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] > maxx) {
                maxx = dp[i][j];
            }
        }
    }
    
    cout << maxx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
