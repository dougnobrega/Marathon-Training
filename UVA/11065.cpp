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

ll g[65];
int n;
int best = 0;
int cont = 0;
ll ok = 0;

void backtracking(int i, ll used, int qtd){
	if(used == ok){
		cont++;
		best = max(best,qtd);
	}else{
		REP(j,i,n){
			if(!(used & (1LL << j))){
				backtracking(j+1,(used | g[j]),qtd+1);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cont = 0;
		best = 0;
		cin >> n;
		ok = (1LL << n) - 1;
		REP(i,0,n){
			g[i] =  (1LL << i);
		}
		int e;
		cin >> e;
		REP(i,0,e){
			int x,y;
			cin >> x >> y;
			g[x] |= (1LL << y);
			g[y] |= (1LL << x);
		}

		backtracking(0,0,0);
		cout << cont << endl;
		cout << best << endl;
	}
	return 0;
}

