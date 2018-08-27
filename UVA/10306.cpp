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
ll dp[310][310];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		vpi moedas;
		cin >> n >> m;
		REP(i,0,n){
			int x , y;
			cin >> x >> y;
			moedas.PB({x,y});
		}
		memset(dp,0x3f,sizeof dp);
		dp[0][0] = 0;
		ll ans = INF;

		for(auto atual : moedas){
			REP(i,atual.F,m+1){
				REP(j,atual.S,m+1){
					dp[i][j] = min(dp[i][j],1+dp[i-atual.F][j - atual.S]);
					if(i*i + j*j == m*m){
						ans = min(ans,dp[i][j]);
					}
				}
			}
		}
		if(ans == INF){
			cout << "not possible" << endl;
		}else{
			cout << ans << endl;
		}
	}

	return 0;
}

