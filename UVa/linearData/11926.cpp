#include <bits/stdc++.h>
#include <cstdint>
#include <cstdio>
#include <unistd.h>

using namespace std;

bitset<1000001> sc;
inline bool simple(int i, int j) {
    for(int k = i + 1; k <= j; ++k)
        if(sc.test(k))
            return false;
        else
            sc.set(k);
    return true;
}

inline bool comp(int i, int j, int l) {
    while(j < 1000001) {
        if(!simple(i,j)) return false;
        i += l;
        j += l;
    }
    if(i < 1000001)
        return simple(i, min(1000000, j));
    else
        return true;
}

int main () {
    freopen("temp.input", "r", stdin);
    freopen("temp.output", "w", stdout);
    unsigned int ssa,cca;
    while(scanf("%u %u", &ssa, &cca), ssa || cca) {
        bool res = true;
        unsigned int a, b, c;
        sc.reset();
        while(ssa--) {
            scanf("%u %u", &a, &b);
            if(res)
                res = res && simple(a,b);
        }
        while(cca--) {
            scanf("%u %u %u", &a, &b, &c);
            if(res)
                res = res && comp(a,b,c);
        }
        printf("%s\n", res ? "NO CONFLICT" : "CONFLICT");
    }
}
