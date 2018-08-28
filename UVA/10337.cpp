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
int m[10][1010];
int dp[10][1010];
int c = 10,l;
int solve(int i,int j){
	if(i < 0 || i > 9 || j > l)
		return 1e9;
	if(j == l){
		if(i == 0)
			return 0;
		else
			return 1e9;
	}
	if(dp[i][j] != -1)
		return dp[i][j];


	return dp[i][j] = min(min(20 - m[i][j] + solve(i-1,j+1),
							  30 - m[i][j] + solve(i,j+1)),
			  	  	  	  	  60 - m[i][j] + solve(i+1,j+1)) ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		l = x/100 ;
		for(int i = 9; i >= 0;i--){
			REP(j,0,l){
				cin >> m[i][j];
			}
		}
		memset(dp,-1,sizeof dp);
		cout << solve(0,0) << endl << endl;
	}
	return 0;
}

