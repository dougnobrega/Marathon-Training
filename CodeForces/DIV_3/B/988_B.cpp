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

							// Define's end //
bool comp(pair<string,int> a, pair<string,int> b){
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair<string,int> > p(n);
	REP(i,0,n){
		cin >> p[i].F;
		p[i].S = 0;
	}
	REP(i,0,n){
		REP(j,0,n){
			if(p[j].F.find(p[i].F) >= 0 && p[j].F.find(p[i].F) <= p[j].F.size() ){
				p[i].second++;
			}
		}
	}
	sort(all(p),comp);
	bool vdc = false;
	int cont = 0;
	REP(i,0,n){
		REP(j,i+1,n){
			if(p[j].F.find(p[i].F) < 0 || p[j].F.find(p[i].F) >= p[j].F.size() ){
				vdc = true;
				break;
			}
		}
	}
	if(vdc == true){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	REP(i,0,n){
		cout << p[i].F  << endl;
	}
	return 0;
}

