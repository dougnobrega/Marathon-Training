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
int dp[110][10230][2];
int m, n;
pii v[110];

int solve(int i, int resto,bool can){
	if(resto == m + can*200)
		return 0;
	if(i == n)
		return 0;
	if(dp[i][resto]!= -1)
		return dp[i][resto];
	bool vdc = 0;
	if(resto+v[i].F > 2000)
			vdc = 1;
	if(v[i].F + resto > m + (can||vdc)*200)
		return dp[i][resto] = solve(i+1,resto,can);

	return dp[i][resto] = max(solve(i+1,resto,can),solve(i+1,resto+v[i].F,can||vdc) + v[i].S);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> m >> n){

		REP(i,0,n){
			cin >> v[i].F >> v[i].S;
		}
		sort(v,v+n);
		memset(dp,-1,sizeof dp);
		cout << solve(0,0,0) << endl;
	}
	return 0;
}

