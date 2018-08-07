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
int p,s,t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	REP(i,0,a.size()){
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
			p++;
		}
	}
	if(p != 5){
			cout << "NO" << endl;
			return 0;
		}
	REP(i,0,b.size()){
		if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u'){
			s++;
		}
	}
	if(s != 7){
			cout << "NO" << endl;
			return 0;
		}
	REP(i,0,c.size()){
		if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'){
			t++;
		}
	}
	if(t != 5){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}

