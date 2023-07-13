#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
const ll INF = 1e18; // Define a big enough value for the binary search

int n, h;
int x1[MAXN], x2[MAXN];

// Define a function to calculate the total length of all air flow segments
// that intersect with the line segment [l, r]
ll calcLength(int l, int r) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        // Check if the current segment [x1[i], x2[i]] intersects with [l, r]
        if (max(l, x1[i]) <= min(r, x2[i])) {
            // If it does, add the length of the intersection to the total sum
            res += min(r, x2[i]) - max(l, x1[i]);
        }
    }
    return res;
}

int main() {
    cin >> n >> h;

    // Read input and shift the coordinates to start at x = 0
    for (int i = 1; i <= n; i++) {
        cin >> x1[i] >> x2[i];
        x1[i] -= x1[1];
        x2[i] -= x1[1];
    }

    // Perform binary search to find the optimal jumping point
    int lo = 0, hi = x2[n], ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // Calculate the height at the landing point if the glider jumps at mid
        ll height = h - mid + calcLength(mid, x2[n]);
        if (height <= 0) {
            // If the glider can't reach the ground, try jumping earlier
            hi = mid - 1;
        } else {
            // If the glider can reach the ground, try jumping later
            lo = mid + 1;
            ans = mid;
        }
    }

    // Output the result
    cout << ans + x1[1] + h << endl;
    return 0;
}
