#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define REP(i, a, b) for (int i = int(a); i < b ;i++)

using namespace std;
int dirs[4][2] = {{0,1}, {-1,0}, {0, -1}, {1,0}};
int pos[2];
int h,w;
char matrix[10000][10000];
int matrixAcum[10000][10000];
int res[5];
bool encontro;
void mostrar(){
	REP(i,0,h){
		REP(j,0,w){
			if(matrix[i][j])
				printf(ANSI_COLOR_RESET);
			else if (pos[0] == i && pos[1] == j)
				printf(ANSI_COLOR_RED);
			else
				printf(ANSI_COLOR_BLUE);

			printf("%c", matrix[i][j] ? '0': (pos[0] == i && pos[1] == j) ? '*' : '0');
			printf(ANSI_COLOR_RESET);
		}
		printf("\n");
	}
	printf("\n");
}
void mostrar_marcas(){
	REP(i,0,h){
		REP(j,0,w){
			printf("%*d",3, matrixAcum[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool estaEnRango(int a, int b)
{
	return a >= 0 && b >= 0 && a < h && b < w;
}

int main()
{
	freopen("amazin.input", "r", stdin);
	/* freopen("amazin.output", "W", stdout); */
	while(scanf("%d %d", &h, &w), h)
	{
		REP(i,0,h)
			scanf("%s", matrix[i]);
		encontro = false;
		REP(i,0,5)
			res[i] = 0;


		for(int i = h - 1; i >= 0 ; i--)
		{
			for(int j = 0 ; j < w ; j++)
			{
				matrixAcum[i][j] = 0;
				matrix[i][j] -= '0';
				if (!encontro && !matrix[i][j])
				{
					pos[0] = i;
					pos[1] = j;
					encontro = true;
				}
			}
		}
		int currDir = 0;
		int currPared = 3;
		int preViewX;
		int preViewY;
		int initx = pos[0],inity = pos[1];
		/* matrixAcum[pos[0]][pos[1]] = -1; */
		do {
			while(true)
			{
				preViewX = pos[0] + dirs[currPared][0];
				preViewY = pos[1] + dirs[currPared][1];
				if(!estaEnRango(preViewX, preViewY) || matrix[preViewX][preViewY])
				{
					while(true)
					{
						preViewX = pos[0] + dirs[currDir][0];
						preViewY = pos[1] + dirs[currDir][1];
						if(estaEnRango(preViewX, preViewY) && !matrix[preViewX][preViewY])
						{
							break;
						}
						currPared = (currPared + 1) % 4;
						currDir = (currPared + 1) % 4;
					}
				}
				else
				{
					currDir = currPared;
					currPared = (currPared + 3) % 4;
				}
				preViewX = pos[0] + dirs[currDir][0];
				preViewY = pos[1] + dirs[currDir][1];
				if(estaEnRango(preViewX, preViewY) && !matrix[preViewX][preViewY])
				{
					break;
				}
			}
			system("clear");
			matrixAcum[pos[0]][pos[1]]++;
			mostrar();
			usleep(200000);
			pos[0] = preViewX;
			pos[1] = preViewY;
		} while (pos[0] != initx || pos[1] != inity) ;

		int v;
		REP(i,0,h)
			REP(j,0,w)
			{
				v = matrixAcum[i][j];
				if(!matrix[i][j] && v < 5)
				{
					res[v]++;
				}
			}
		REP(i,0,5)
			printf("%*d",3, res[i]);
		printf("\n");
	}
}
