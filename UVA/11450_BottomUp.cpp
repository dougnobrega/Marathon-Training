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
bool dp[25][210];
int m,c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){

		cin >> m >> c;
		memset(dp,0,sizeof dp);
		REP(i,0,c){
			cin >> g[i][0];
			REP(j,1,g[i][0]+1){
				cin >> g[i][j];
			}
		}
		REP(i,1,g[0][0] + 1){
			if(m - g[0][i] >= 0){
				dp[0][m-g[0][i]] = 1;
			}
		}
		REP(i,1,c){
			REP(j,0,m){
				if(dp[i-1][j] == true){
					REP(k,1,g[i][0]+1){
						if(j - g[i][k] >= 0){
							dp[i][j-g[i][k]] = 1;
						}
					}
				}
			}
		}
		int money = 0;
		while(money <= m && !dp[c-1][money]){
			money++;
		}
		if(money != m+1){
			cout << m - money << endl;
		}else{
			cout << "no solution" << endl;
		}

	}
	return 0;
}

