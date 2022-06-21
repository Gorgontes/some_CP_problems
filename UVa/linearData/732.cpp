#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define TAB(a) for(int m = 0 ; m < a ; ++m) printf("    ");
using namespace std;
char inpw[200], outw[200];
char inpc[200], outc[200];
char pila[201][201];
int sinp, sout;

// topi should be more than 1
void solve(int inpt, int outt, int topi, int mask, int pile) {
    if(inpt != sinp) {
        memcpy(pila[pile + 1], pila[pile], topi);
        pila[pile + 1][topi] = inpw[inpt];
        solve(inpt + 1, outt, topi + 1, (mask << 1) | 1,pile + 1);
    } else {
        while(topi--) {
            if(pila[pile][topi] != outw[outt++])
                return;
            mask = mask << 1;
        }
        int i = sinp * 2;
        printf("%c", (mask & (1 << --i)) ? 'i' : 'o');
        while(i--) {
            printf(" %c", (mask & (1 << i)) ? 'i' : 'o');
        }
        printf("\n");
        return;
    }

    if(topi && pila[pile][--topi] == outw[outt]) {
        solve(inpt, outt + 1, topi, mask << 1, pile);
    }

}


int main () {
    freopen("anagram.input", "r", stdin);
    freopen("anagram.output", "w", stdout);
    while(scanf("%s", inpw) != EOF) {
        printf("[\n");
        scanf("%s", outw);
        for(sinp = 0; inpw[sinp] != '\0'; ++sinp);
        for(sout = 0; outw[sout] != '\0'; ++sout);
        if(sinp == sout) {
            strcpy(inpc, inpw);
            strcpy(outc, outw);
            sort(inpc, inpc + sinp);
            sort(outc, outc + sinp);
            if (strcmp(inpc, outc) == 0) {
                solve(0,0,0,0,0);
            }
        }
        printf("]\n");
    }
    return 0;
}
