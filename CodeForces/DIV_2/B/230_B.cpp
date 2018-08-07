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
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'

							// Define's end //

bitset <1000001> vis;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<ll > conj;
	REP(i,2,sqrt(1000001) + 1){
		if(!vis[i]){
			int j = 2;
			while(i*j <= 1000000){
				vis[i*j] = 1;
				j++;
			}
		}
	}
	REP(i,2,1000001){
		if(!vis[i])
			conj.insert((ll)i*i);
	}
	int n;
	cin >> n;
	REP(i,0,n){
		ll x;
		cin >> x;
		if(conj.find(x) != conj.end()){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}

