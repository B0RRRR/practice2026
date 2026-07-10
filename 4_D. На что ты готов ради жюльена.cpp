#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    string s;
    cin >> s;
    
    string a = "L" + s + "L";
    
    int pos = 0;
    while (pos < n + 1) {
        if (a[pos] == 'C') {
            cout << "NO\n";
            return;
        }
        

        if (a[pos] == 'W') {
            pos++;
            k--;

            if (k < 0) {
                cout << "NO\n";
                return;
            }
            continue;
        }
        
        int next_log = -1;
        for (int i = pos + 1; i <= min(pos + m, n + 1); ++i) {
            if (a[i] == 'L') {
                next_log = i;
            }
        }
        
        if (next_log != -1) {
            pos = next_log;
        } else {
            pos = pos + m;
        }
    }
    
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
