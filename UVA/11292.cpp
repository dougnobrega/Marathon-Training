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
int dragons[20010],knight[20010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		if(n == 0 && m == 0)
			return 0;
		REP(i,0,n){
			cin >> dragons[i];
		}
		REP(i,0,m){
			cin >> knight[i];
		}
		sort(dragons,dragons+n);
		sort(knight,knight+m);
		int d = 0, k = 0;
		ll sum = 0;
		while(d < n && k < m){
			while(k < m && dragons[d] > knight[k]) k++;
			if(k == m)
				break;

			sum += knight[k];
			k++; d++;
		}
		if(d != n){
			cout << "Loowater is doomed!" << endl;
			continue;
		}else{
			cout << sum << endl;
		}
	}
	return 0;
}

