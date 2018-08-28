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
int n = 0, m = 0, k = 0;
ll dp[55][55][55];
ll solve(int i,int c,int w){
	if(i == n && c == k)
		return 1;
	if(i > n)
		return 0;
	if(c > k)
		return 0;
	if(dp[i][c][w] != -1)
		return dp[i][c][w];
	if(w == m){
		return dp[i][c][w] = solve(i+1,c + 1,1);
	}
	return dp[i][c][w] = solve(i+1,c,w+1) + solve(i+1,c + 1,1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> k >> m){
		memset(dp,-1,sizeof dp);
		cout << solve(1,1,1) << endl;
	}
	return 0;
}

