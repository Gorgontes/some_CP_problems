#include <bits/stdc++.h>

using namespace std;

struct Movs {
	bool recur;
	int dirs[9][2];
};
int main ()
{
	char d[68];
	char t[8][8];
	bool touched[8][8];
	int stack[65][2];
	int tpStack;
	int dirP[3][2] = {
		{-1, -1}, {-1, 1}, {0, 0}
	};
	int dirp[3][2] = {
		{1, 1}, {1, -1}, {0, 0}
	};
	int dirn[9][2] = {
		{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {0, 0}
	};
	int dirk[9][2] = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}, {0, 0}
	};
	int dirq[9][2] = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}, {0, 0}
	};
	int dirb[5][2] = {
		{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0}
	};
	int dirr[5][2] = {
		{1, 0}, {0, -1}, {-1, 0}, {0, 1}, {0, 0}
	};
	char piece;
	freopen("test.input", "r", stdin);
	freopen("test.output", "w", stdout);

	Movs movs[127];
	movs['p'].recur = false;
	memcpy(movs['p'].dirs, dirp,sizeof(dirp));
	movs['P'].recur = false;
	memcpy(movs['P'].dirs, dirP,sizeof(dirP));
	movs['n'].recur = false;
	memcpy(movs['n'].dirs, dirn,sizeof(dirn));
	movs['k'].recur = false;
	memcpy(movs['k'].dirs, dirk,sizeof(dirk));
	movs['r'].recur = true;
	memcpy(movs['r'].dirs, dirr,sizeof(dirr));
	movs['q'].recur = true;
	memcpy(movs['q'].dirs, dirq,sizeof(dirq));
	movs['b'].recur = true;
	memcpy(movs['b'].dirs, dirb,sizeof(dirb));
	while (scanf("%s", d) != EOF){
		for(int i = 0 ; i < 8 ; i++)
			for(int j = 0 ; j < 8 ; j++){
				t[i][j] = ' ';
				touched[i][j] = false;
			}
		int i = 0, j = 0, k = -1;
		tpStack = 0;
		while(d[++k] != '\0'){
			if(d[k] == '/'){
				j++; i=0;
			}
			else
				if(isdigit(d[k])) i += d[k] - '0';
				else {
					t[j][i] = d[k];
					stack[tpStack][0] = j;
					stack[tpStack++][1] = i++;
				}
		}
		int xr,yr;
		Movs *crr;
		for(int i = 0 ; i < tpStack; i++ ){
			xr = stack[i][0];
			yr = stack[i][1];
			piece = t[xr][yr];
			piece = (piece == 'P') ? 'P' : tolower(piece);
			touched[xr][yr] = true;
			crr = &movs[piece];
			if(crr->recur){
				for(int it = 0 ; crr->dirs[it][0] || crr->dirs[it][1] ; it++){
					int cx=xr, cy=yr;
					while(true){
						cx += crr->dirs[it][0];
						cy += crr->dirs[it][1];
						if(cx >= 0 && cx < 8 && cy >= 0 && cy < 8){
							if(t[cx][cy] != ' ') break;
							else touched[cx][cy] = true;
						} else break;
					}
				}
			} else {
				for(int it = 0 ; crr->dirs[it][0] || crr->dirs[it][1] ; it++){
					int cx=xr + crr->dirs[it][0], cy=yr + crr->dirs[it][1];
					if(cx >= 0 && cx < 8 && cy >= 0 && cy < 8)
						touched[cx][cy] = true;
				}
			}
		}
		int cont = 0;
		for(int a = 0 ; a < 8 ; a++){
			for(int b = 0 ; b < 8 ; b++){
				cont += !touched[a][b];
			}
		}
		printf("%d\n", cont);
	}
}
