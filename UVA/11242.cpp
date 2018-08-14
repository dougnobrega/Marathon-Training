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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int f, r;
	while(cin >> f && f){
		cin >> r;
		vi front(f), rear(r);
		REP(i,0,f){
			cin >> front[i];
		}
		REP(i,0,r){
			cin >> rear[i];
		}
		vector<double> diff;
		REP(i,0,f){
			REP(j,0,r){
				diff.PB((double)rear[j]/(double)front[i]);
			}
		}
		double best = 0;
		sort(all(diff));
		REP(i,1,diff.size()){
			best = max(best, diff[i]/diff[i-1]);
		}
		cout << setprecision(2) << fixed << best << endl;

	}
		return 0;
}

