#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cute.input", "r", stdin);
    unsigned int n;
    while(scanf("%u", &n), n) {
        unsigned int res[2] = {0}, p = 0;
        for(int i = 0 ; i < 32 ; ++i) {
            if((1 << i) & n) {
                res[p] |= 1 << i;
                p = !p;
            }
        }
        printf("%u %u\n", res[0], res[1]);
    }
}
