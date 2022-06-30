#include <bits/stdc++.h>
using namespace std;

inline void solve(unsigned int days) {
    map<int, int> urn;
    unsigned long long ans = 0, bill, bills;
    while(days--) {
        scanf("%llu", &bills);
        while(bills--) {
            scanf("%llu", &bill);
            urn[bill]++;
        }
        auto itr = urn.rbegin();
        auto itl = urn.begin();
        ans += itr -> first - itl -> first;
        itr -> second--;
        itl -> second--;
        if(itr -> second == 0)
            urn.erase(itr -> first);
        if(itl -> second == 0)
            urn.erase(itl -> first);
    }
    printf("%llu\n", ans);
} 

int main () {
    freopen("err.input", "r", stdin);
    /* freopen("err.output", "w", stdout); */
    unsigned int days;
    while(scanf("%u", &days), days) {
        solve(days);
    }
    return 0;
}
