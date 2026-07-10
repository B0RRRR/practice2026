#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
    }
    
    string s;
    cin >> s;
    
    vector<int> bal(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        bal[i] = (s[i - 1] == 'B' ? 1 : -1);
    }
    
    for (int i = n; i >= 2; --i) {
        bal[a[i]] += bal[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (bal[i] == 0) {
            ans++;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
