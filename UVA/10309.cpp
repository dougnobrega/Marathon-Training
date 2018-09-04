#include <bits/stdc++.h>

using namespace std;
							// Typedef's  start //
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

							//	Typedef's end //
							//	Define's start //
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

							// Define's end //
int matriz[11];
int ok = 1 << 10;
int best = INF;
void backtracking(int top,int now,int qtd,int i){
	if(i == 9){
		int cont = 0;
		while(top){
			int pos = top & -top;
			top ^= pos;
			if((pos << 1) == ok)
				now ^= (pos | (pos >> 1));
			else
				now ^= (pos | (pos << 1) | (pos >> 1));
			cont ++;
		}
		if(now)
			return;
		best = min(best,qtd+cont);
		return;
	}else{
		int bot = matriz[i+1];
		int cont = 0;
		while(top){
			int pos = top & -top;
			top ^= pos;
			if((pos << 1) == ok)
				now ^= (pos | (pos >> 1));
			else
				now ^= (pos | (pos << 1) | (pos >> 1));
			bot ^= pos;
			cont++;
		}
		backtracking(now,bot,qtd+cont,i+1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string t;
	ok = 1 << 10;
	while(cin >> t){
		if(t == "end")
			break;
		memset(matriz,0,sizeof matriz);
		REP(i,0,10){
			REP(j,0,10){
				char x;
				cin >> x;
				if(x == 'O'){
					matriz[i] |= (1 << j);
				}
			}
		}

		best = INF;
		REP(i,0,ok){
			int top = matriz[0];
			int atual = matriz[1];
			int mask = i;
			int cont = 0;

			while(mask){
				int pos = mask & -mask;
				mask ^= pos;
				if((pos << 1) == ok)
					top ^= (pos | (pos >> 1));
				else
					top ^= (pos | (pos << 1) | (pos >> 1));
				atual ^= pos;
				cont++;
			}
			backtracking(top,atual,cont,1);
		}
		cout << t << " " << best << endl;
	}
	return 0;
}

