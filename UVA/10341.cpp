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
double p,q,r,s,t,u;
double check(double x){
	return p * exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> p >> q >> r >> s >> t >> u){
		double lo = 0.0, hi = 1.0, mid = 0,f;
		REP(i,0,30){
			mid = (lo + hi)/2;
			f = check(mid);
			if(f>0)
				lo = mid;
			else
				hi = mid;
		}
		if(check(lo) < -1e-6 || check(lo) > 1e-6 ){
			cout << "No solution\n";
			continue;
		}

		cout << setprecision(4) << fixed << lo << endl;
	}
	return 0;
}

