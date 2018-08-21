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
int g[25][25];
ll dp[210][24];
int m,c;
ll solve(int money, int atual){
	if(money > m)
		return -INF;
	if(atual == c){
		return money;
	}
	if(dp[money][atual] != -1)
		return dp[money][atual];
	ll ans = -1;
	REP(i,1,g[atual][0]+1){
		ans = max(ans, solve(money + g[atual][i],atual+1));
	}
	return dp[money][atual] = ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){

		cin >> m >> c;
		memset(dp,-1,sizeof dp);
		REP(i,0,c){
			cin >> g[i][0];
			REP(j,1,g[i][0]+1){
				cin >> g[i][j];
			}
		}
		ll ans = solve(0,0);
		if(ans != -1){
			cout << ans << endl;
		}else{
			cout << "no solution" << endl;
		}

	}
	return 0;
}

