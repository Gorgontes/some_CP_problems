#include <bits/stdc++.h>

using namespace std;
int value[128];
int main ()
{
	bool cards[54];
	for (int i = 0 ; i < 54; i++)
		cards[i] = false;
	int g[3], b[2],j;
	freopen("test.input", "r", stdin);
	freopen("test.output", "w", stdout);
	while (scanf("%d", &g[0]), g[0]){
		scanf("%d %d %d %d", &g[1], &g[2], &b[0], &b[1]);
		for (int k = 0 ; k < 3 ; k++) cards[g[k]] = true;
		for (int k = 0 ; k < 2 ; k++) cards[b[k]] = true;
		// sort
		if(g[0] > g[1]) swap(g[0], g[1]);
		if(b[0] > b[1]) swap(b[0], b[1]);
		if(g[2] < g[1]){
			swap(g[2], g[1]);
			if(g[1] < g[0]) swap(g[1], g[0]);
		}
		//logic
		if (b[0] > g[2]) j = 1;
		else
			if (b[0] > g[1]) j = g[1] + 1;
			else
				if (b[1] > g[2]) j = g[2] + 1;
				else j = 53;

		while(cards[j]) j++;
		printf("%d\n",(j == 53) ? -1 : j);
		for (int k = 0 ; k < 3 ; k++) cards[g[k]] = false;
		for (int k = 0 ; k < 2 ; k++) cards[b[k]] = false;
	}
}
