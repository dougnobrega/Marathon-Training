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
	ll p[100010];
	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		int n;
		ll best = -INF, sum = 0;
		while(cin >> n && n){
			best = -INF, sum = 0;
			REP(i,0,n){
				cin >> p[i];
				sum = max(sum + p[i],p[i]);
				best = max(best,sum);
			}
			if(best > 0){
				cout << "The maximum winning streak is " << best << "." << endl;
			}else{
				cout << "Losing streak." << endl;
			}
		}
		return 0;
	}

