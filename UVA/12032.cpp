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

vi p(100050);
int n;
bool check(int x){
	if(p[0] == x){
		x--;
	}else if(p[0] > x ){
		return 0;
	}
	REP(i,1,n){
		if(p[i]-p[i-1] == x){
			x--;
		}else if(p[i]-p[i-1] > x ){
			return 0;
		}
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int cont = 1;
	while(t--){
		cin >> n;
		REP(i,0,n){
			cin >> p[i];
		}
		int lo = 0, hi = 1e7, mid, best = 0;
		while(lo<=hi){
			mid = (lo+hi)/2;
			if(check(mid)){
				hi = mid - 1;
				best = mid;
			}else{
				lo = mid + 1;
			}
		}
		cout << "Case " << cont++ << ": ";
		cout << best << endl;

	}
	return 0;
}

