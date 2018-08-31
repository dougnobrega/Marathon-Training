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
int n = 0;
string v;
map<int,map<ll,ll> > dp;
ll solve(int i, ll num){
	if(num > 2147483647) return 0;
	if(i == n) return num;
	if(dp[i].count(num)){
		return dp[i][num];
	}
	if(num > 0){
		return dp[i][num] = max(num + solve(i+1,((int)v[i] - '0')),solve(i+1,num*10 + (ll)(v[i] - '0')));
	}
	return dp[i][num] = solve(i+1,(ll)(v[i] - '0'));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> v;
		n = v.size();
		dp.clear();
		cout << solve(0,0) << endl;
	}
	return 0;
}

