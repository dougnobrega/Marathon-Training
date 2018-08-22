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
ll v[110][110];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(i,0,t){
		REP(j,0,t){
			cin >> v[i][j];
			if(i > 0)
				v[i][j] += v[i-1][j];
			if(j > 0)
				v[i][j] += v[i][j-1];
			if( i > 0 && j > 0)
				v[i][j] -= v[i-1][j-1];
		}
	}
	ll best = 0;
	REP(i,0,t){
		REP(j,0,t){
			REP(k,i,t){
				REP(z,j,t){
					ll ans = v[k][z];
					if(i > 0)
						ans -= v[i-1][z];
					if(j > 0)
						ans -= v[k][j-1];
					if( i > 0 && j > 0)
						ans += v[i-1][j-1];
					best = max(best,ans);
				}
			}
		}
	}
	cout << best << endl;
	return 0;
}

