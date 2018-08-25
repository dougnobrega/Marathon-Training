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
vi aux(100000);
int recover[100010],pai[100010];
vi p;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	int k = 0;
	int i = 0;
	while(cin >> t){
		int pos = lower_bound(aux.begin(),aux.begin()+k,t) - aux.begin();
		p.PB(t);
		if(pos == k)
			k++;
		aux[pos] = p[i];
		recover[pos] = i;
		if(pos == 0)
			pai[i] = -1;
		else
			pai[i] = recover[pos-1];
		i++;
	}
	cout << k << endl;
	vi ans;
	int pos = recover[k - 1];
	while(pos >= 0){
		ans.PB(p[pos]);
		pos = recover[pos];
	}
	reverse(all(ans));
	cout << '-' << endl;
	REP(i,0,ans.size()){
		cout << ans[i] << endl;
	}


	return 0;
}

