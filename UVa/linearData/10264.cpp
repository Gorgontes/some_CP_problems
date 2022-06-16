#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main () {
    int n;
    while(scanf("%d", &n) != EOF) {
        int l = 1 << n;
        vector<int> lista(l,0);
        vector<int> sum(l,0);
        for(int i = 0 ; i < l ; ++i) scanf("%d", &lista[i]);
        for(int i = 0 ; i < l ; ++i)
            for(int j = 0 ; j < n ; ++j)
                sum[i] += lista[i ^ (1 << j)];
        int mx = 0;
        for(int i = 0 ; i < l ; ++i)
            for(int j = 0 ; j < n ; ++j)
                mx = max(mx, sum[i] + sum[i ^ (1 << j)]);
        printf("%d\n", mx);
    }
}
