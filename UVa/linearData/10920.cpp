#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int posx, posy, size, pos;
    long long int dirs[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

    while(scanf("%lld %lld", &size, &pos), size) {
        bool mul = true;
        long long int curr_pos = 1, step_size = 0, curdir = 0;

        posx = size/2 + 1;
        posy = posx;

        while(curr_pos < pos) {
            if(mul) step_size++;
            
            posx += dirs[curdir][0] * step_size;
            posy += dirs[curdir][1] * step_size;
            curr_pos += step_size;

            mul = !mul;
            curdir = (curdir + 1) % 4;
        }

        curdir = (curdir + 3) % 4;
        
        posx -= (curr_pos - pos) * dirs[curdir][0];
        posy -= (curr_pos - pos) * dirs[curdir][1];

        printf("Line = %lld, column = %lld.\n", posx, posy);
    }
}
