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
	string t;
	cin >> t;
	REP(i,0,t.size()){
		if((t[i]-'0') % 8 == 0 ){
			cout << "YES" << endl;
			cout << t[i] << endl;
			return 0;
		}
		REP(j,i+1,t.size()){
			if(((t[i]-'0')*2 + (t[j]-'0')) % 8 == 0 ){
				cout << "YES" << endl;
				cout << t[i] << t[j] << endl;
				return 0;
			}
			REP(k,j+1,t.size()){
				if(((t[i]-'0')*4 + (t[j]-'0')*2 + t[k]-'0') % 8 == 0 ){
					cout << "YES" << endl;
					cout << t[i] << t[j] << t[k] << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}

