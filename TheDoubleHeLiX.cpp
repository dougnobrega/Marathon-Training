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
	ll first[10010], nf;
	ll second[10010], ns;
	ll dp[10010][2];
	ll solve(int i,bool op){
		if(op == 0){
			if(i == nf){
				return 0LL;
			}
			if(dp[i][op] != -1){
				return dp[i][op];
			}
			int pos = lower_bound(second,second+ns,first[i]) - second;
			if(pos < ns && second[pos] == first[i]){
				return dp[i][op] = max(first[i] + solve(i+1,op), second[pos] + solve(pos+1,!op));
			}
			return dp[i][op] = first[i] + solve(i+1,op);
		}else{
			if(i == ns){
				return 0;
			}
			if(dp[i][op] != -1){
				return dp[i][op];
			}
			int pos = lower_bound(first,first+nf,second[i]) - first;
			if(pos < nf && first[pos] == second[i]){
				return dp[i][op] = max(second[i] + solve(i+1,op), first[pos] + solve(pos+1,!op));
			}
			return dp[i][op] = second[i] + solve(i+1,op);
		}
	}
	int main(){
		ios::sync_with_stdio(0);
		cin.tie(0);
		while(cin >> nf){
			if(nf == 0)
				break;
			REP(i,0,nf){
				cin >> first[i];
			}
			cin >> ns;
			REP(i,0,ns){
				cin >> second[i];
			}
			memset(dp,-1,sizeof dp);
			cout << (ll)max(solve(0,0),solve(0,1)) << endl;
		}
		return 0;
	}

