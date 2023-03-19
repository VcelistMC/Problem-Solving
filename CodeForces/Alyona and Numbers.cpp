#include <iostream> 
using namespace std;

uint64_t solve(int n, int m, int k = 5)
{
    long long d = max(n, m);
    long long nfreq[] = { 0, 0, 0, 0, 0 };
    long long mfreq[] = { 0, 0, 0, 0, 0 };

    for(long long i = 1; i <= d; i++){
        if(i <= n) ++nfreq[i % 5]; 
        if(i <= m) ++mfreq[i % 5]; 
    }

    return nfreq[0] * mfreq[0] + nfreq[1] * mfreq[4] + nfreq[2] * mfreq[3] + nfreq[3] * mfreq[2] + nfreq[4] * mfreq[1];

}


int main()
{
    long long n, m, k = 5;
    // cout << solve(6, 12) << endl; // 14
    // cout << solve(11, 14) << endl; // 31
    // cout << solve(1, 5) << endl; // 1
    // cout << solve(3, 8) << endl; //5
    // cout << solve(5, 7) << endl; // 7
    // cout << solve(21, 21) << endl; //88
    cin >> n >> m;
    cout << solve(n, m);
}