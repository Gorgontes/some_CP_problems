#include <bits/stdc++.h>
#include <math.h>
#define REP(i, a, b) for (int i = int(a); i < b ;i++)

using namespace std;

int N;
char is_even[10], first[20], second[20];
bool inversed;
int imbalanced_coins[4],top_imbalanced_coins;

bitset<13> input[3][2],ans_coins;
string res;

int main () {
	bitset<13> auth_coins;
	bitset<13> lighter_coins;
	bitset<13> heavier_coins;
	/* freopen("simple.input", "r", stdin); */
	/* freopen("simple.output", "w", stdout); */
	scanf("%d", &N);
	while(N--){
		top_imbalanced_coins = 0;
		auth_coins.reset();
		lighter_coins.set();
		heavier_coins.set();
		REP(i,0,3)
			REP(j,0,2) 
				input[i][j].reset();

		REP(i,0,3){
			scanf("%s %s %s", first, second, is_even);
			inversed = is_even[0] == 'u';
			for(int j = 0 ; first[j]!= '\0'; j++)
				input[i][inversed].set(first[j] - 'A',1);
			for(int j = 0 ; second[j] != '\0'; j++)
				input[i][!inversed].set(second[j] - 'A',1);
			if(is_even[0] == 'e')
				auth_coins |= input[i][0] | input[i][1];
			else {
				auth_coins |= ~(input[i][0] | input[i][1]);
				imbalanced_coins[top_imbalanced_coins++] = i;
			}
		}
		bitset<13> *p;
		REP(j,0,top_imbalanced_coins){
			p = input[imbalanced_coins[j]];
			lighter_coins &= p[0];
			heavier_coins &= p[1];
		}
		lighter_coins &= ~auth_coins;
		heavier_coins &= ~auth_coins;

		if (lighter_coins.count() == 1){
	 		res = "light";
			ans_coins = lighter_coins;
		} else {
			res = "heavy";
			ans_coins = heavier_coins;
		}
		for(int k = 0 ; k < 13 ; k++){
			if(ans_coins[k]){
				printf("%c is the counterfeit coin and it is %s.\n", k + 'A', res.c_str());
				break;
			}
		}
	}
}
