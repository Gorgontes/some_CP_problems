#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = int(a); i < b ;i++)

using namespace std;

int main ()
{
	freopen("test.input", "r", stdin);
	freopen("test.output", "w", stdout);
	int N;
	int bc[5][5];
	bool marks[5][5];
	int pc[76][2];
	int nc,temp;
	bool nf;
	REP(i,0,76){
		pc[i][1] = -1;
		pc[i][0] = -1;
	}
	scanf("%d", &N);
	while(N--){
		nf = true;
		nc = 75;
		REP(i,0,5)
			REP(j,0,5){
				if(i!=2 || j !=2){
					marks[i][j] = false;
					scanf("%d", &bc[i][j]);
					pc[bc[i][j]][0] = i;
					pc[bc[i][j]][1] = j;
				}
			}
		marks[2][2] = true;
		while(nc--){
			scanf("%d", &temp);
			if (nf) {
				if(pc[temp][0] != -1) {
					int tx = pc[temp][0], ty = pc[temp][1];
					bool acabo = true;

					marks[tx][ty] = true;
					REP(k,0,5) acabo = acabo && marks[k][ty];

					if (acabo) nf = false;
					else {
						acabo = true;
						REP(k,0,5) acabo = acabo && marks[tx][k];
						if (acabo) nf = false;
						else{
							if(tx == ty){
								acabo = true;
								REP(k,0,5) acabo = acabo && marks[k][k];
								if (acabo) nf = false;
							} else if (tx + ty == 4){
								acabo = true;
								REP(k,0,5) acabo = acabo && marks[4-k][k];
								if (acabo) nf = false;
							}
						}
					}
					if(!nf)
						printf("BINGO after %d numbers announced\n", 75 - nc);
				}
			}
		}
		REP(i,0,5)
			REP(j,0,5){
				pc[bc[i][j]][0] = -1;
				pc[bc[i][j]][1] = -1;
			}
	}
}
