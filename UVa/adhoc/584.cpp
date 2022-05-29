#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = int(a); i < b ;i++)

using namespace std;

int main ()
{
	/* freopen("test.input", "r", stdin); */
	/* freopen("test.output", "w", stdout); */
	char s[200], s2[200];
	int mul[3];
	int cont, val;
	int veces;
	while(scanf("%s", s), s[0]!='G'){
		REP(i,0,3) mul[i] = 1;
		veces = cont = 0;
		while (true) {
			veces++;
			if(s[0] == 'X') {
				cont += 10 * mul[0];
				mul[0] = mul[1] + 1;
				mul[1] = mul[2] + 1;
				mul[2] = 1;
			}
			else {
				val = s[0] - '0';
				cont += val * mul[0];
				scanf("%s", s2);
				if (s2[0] == '/') {
					val = 10 - val;
					cont += val * mul[1];
					mul[2]++;
				} else
					cont += (s2[0] - '0') * mul[1];
				mul[0] = mul[2];
				mul[1] = 1;
				mul[2] = 1;
			}
			/* printf(" %d\n", cont); */
			if(veces < 10){
				scanf("%s", s);
			}
			else {
				if(s[0] == 'X'){
					scanf("%s %s", s, s2);
					cont += ((s[0] == 'X') ? 10 : s[0] - '0') * (mul[0] - 1);
					if(s2[0] == 'X')
						cont += 10;
					else
						if(s2[0] == '/')
							cont += 10 - s[0] + '0';
						else
							cont += s2[0] - '0';
				} else if(s2[0] == '/') {
					scanf("%s", s);
					cont += (s[0] == 'X' ? 10 : s[0] - '0') * (mul[0] - 1);
				}
				break;
			}
		}
		printf("%d\n", cont);
	}
}
