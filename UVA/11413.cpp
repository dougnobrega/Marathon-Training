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
vi p(1001);
int m,n;
int cont = 0;
bool check(int x){
	cont = 1;
	int acc = 0;

	REP(i,0,n){
		if(acc + p[i] > x){
			acc = 0;
			if(cont == m)
				return 0;
			cont++;
		}
		if(p[i] >  x){
			return 0;
		}
		acc += p[i];
	}
	return 1 ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m){
		REP(i,0,n){
			cin >> p[i];
		}

		int lo = 0, hi = 1e9, mid = 0, best = 0;
		while(lo <= hi){
			mid = (lo+hi)/2;
			if(check(mid)){
				hi = mid-1;
				best = mid;
			}else{
				lo = mid+1;
			}
		}
		cout << best << endl;
	}
	return 0;
}

