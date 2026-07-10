#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        vector<long long> prochnost(n);
        long long sum_prochnost = 0;
        for (int i = 0; i < n; i++) {
            cin >> prochnost[i];
            sum_prochnost += prochnost[i];
        }

        if (sum_prochnost <= k) {
            cout << n << "\n";
            continue; 
        }

        long long k_first = (k + 1) / 2;
        long long k_last = k / 2;
        
        int damaged = 0;

        for (int i = 0; i < n; i++) {
            if (prochnost[i] <= k_first) {
                k_first -= prochnost[i];
                damaged++;
            } else {
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (prochnost[i] <= k_last) {
                k_last -= prochnost[i];
                damaged++;
            } else {
                break;
            }
        }

        cout << damaged << "\n";
    }
    return 0;
}
