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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >>k;
	map<int,int> conj;
	REP(i,0,n){
		int x;
		cin >> x;
		if(conj.find(x) == conj.end()){
			conj[x] = i+1;
		}
	}
	if(conj.size()>= k){
		cout << "YES" << endl;
		for(auto atual : conj){
			if(k == 0)
				break;
			k--;
			cout << atual.second << " ";
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
		return 0;
	}
}

