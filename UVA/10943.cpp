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
int n,k;
int dp[120][120];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> k){
		if(n == 0 && k == 0)
			return 0;

		REP(i,0,n+1)
			dp[1][i] = 1;
		REP(i,2,k+1){
			REP(j,0,n+1){
				dp[i][j] = 0;
				REP(z,0,j+1){
					dp[i][j] = (dp[i][j] + dp[i-1][j-z])%1000000;
				}
			}
		}
		cout << dp[k][n] << endl;

	}
	return 0;
}

