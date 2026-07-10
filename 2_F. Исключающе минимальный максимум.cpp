#include <iostream>
#include <vector>

using namespace std;

const int MAX_BITS = 31;

struct Node {
    int next[2];
    int count;
    Node() {
        next[0] = next[1] = -1;
        count = 0;
    }
};

vector<Node> trie;

void insert(long long x) {
    int u = 0;
    trie[u].count++;
    for (int i = MAX_BITS - 1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        if (trie[u].next[bit] == -1) {
            trie[u].next[bit] = trie.size();
            trie.push_back(Node());
        }
        u = trie[u].next[bit];
        trie[u].count++;
    }
}

void remove_val(long long x) {
    int u = 0;
    trie[u].count--;
    for (int i = MAX_BITS - 1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        u = trie[u].next[bit];
        trie[u].count--;
    }
}

long long get_min(long long x) {
    int u = 0;
    long long ans = 0;
    for (int i = MAX_BITS - 1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        if (trie[u].next[bit] != -1 && trie[trie[u].next[bit]].count > 0) {
            u = trie[u].next[bit];
        } else {
            ans |= (1LL << i);
            u = trie[u].next[bit ^ 1];
        }
    }
    return ans;
}

long long get_max(long long x) {
    int u = 0;
    long long ans = 0;
    for (int i = MAX_BITS - 1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        int opp_bit = bit ^ 1;
        if (trie[u].next[opp_bit] != -1 && trie[trie[u].next[opp_bit]].count > 0) {
            ans |= (1LL << i);
            u = trie[u].next[opp_bit];
        } else {
            u = trie[u].next[bit];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    trie.push_back(Node());
    trie.reserve(n * MAX_BITS + 10);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        remove_val(a[i]);
        long long min_xor = get_min(a[i]);
        long long max_xor = get_max(a[i]);
        cout << min_xor << " " << max_xor << "\n";
        insert(a[i]);
    }

    return 0;
}
