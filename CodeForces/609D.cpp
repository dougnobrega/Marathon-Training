#include <bits/stdc++.h>

using namespace std;

// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

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
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
vll a, b;
vector<pair<ll,int> > gadget[2];
ll n, m, k, s;
bool work(int mid, int print){

	if(mid < 0 || mid > n)
		return 0;
	pair<ll,int> doll = {a[0],1}, pound = {b[0],1};
	
	REP(i,0,mid){
		if(a[i] < doll.F)
			doll = {a[i], i+1};
		if(b[i] < pound.F)
			pound = {b[i], i+1};
	}
	
	vector<pair<ll, pii> > pack;
	
	REP(i,0,gadget[0].size()){
		pack.PB({gadget[0][i].F * doll.F,{gadget[0][i].S,0}});
	}
	REP(i,0,gadget[1].size()){
		pack.PB({gadget[1][i].F * pound.F,{gadget[1][i].S,1}});
	}
	sort(all(pack));
	
	ll accu = 0;
	REP(i,0,k){
		accu += pack[i].F;

		if(print){
			cout << pack[i].S.F << " " ;
			if(pack[i].S.S == 0){
				cout << doll.S << endl;
			}else{
				cout << pound.S << endl;
			}
		}
		if(accu > s){
			return 0;
		}
	}
	return 1;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> k >> s;
	a.resize(n);
	b.resize(n);
	REP(i,0,n){
		cin >> a[i];
	}
	
	REP(i,0,n){
		cin >> b[i];
	}
	REP(i,0,m){
		int op;
		cin >> op;
		int x;
		cin >> x;
		gadget[op-1].PB({x,i+1});
	}

	int lo = 0, hi = n, mid;
	while(lo <= hi){
		mid = (lo+hi) >> 1;
		if(!work(mid,0)){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	
	if(work(hi+1,0) == 0){
		cout << -1 << endl;
		return 0;
	}
	
	cout << max(1,hi+1) << endl;
	
	work(hi+1,1);
	
	return 0;
}

