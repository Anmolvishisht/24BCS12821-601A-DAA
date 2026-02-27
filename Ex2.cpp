#include <bits/stdc++.h>
using namespace std;

static bool canFinish(const vector<long long>& w, long long cap, int D) {
    long long curr = 0;
    int days = 1;

    for (long long x : w) {
        if (x > cap) return false; 
        if (curr + x <= cap) {
            curr += x;
        } else {
            days++;
            curr = x;
            if (days > D) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<long long> w(N);
    long long low = 0, high = 0;

    for (int i = 0; i < N; i++) {
        cin >> w[i];
        low = max(low, w[i]); 
        high += w[i];         
    }

    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canFinish(w, mid, D)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}