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
vector<int> g[50050];
int vis[50005];
int sum[50005];
int dfs(int x){
	vis[x] = 1;
	int ans = 0;
	REP(i,0,g[x].size()){
		if(!vis[g[x][i]])
			ans = ans + 1 + dfs(g[x][i]);
	}
	vis[x] = 0;
	return sum[x] = ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int caso = 1;
	while(t--){
		int n;
		cin >> n;
		vis[0] = 0;
		memset(sum,-1,sizeof sum);
		REP(i,1,n+1){
			g[i].clear();
			vis[i] = 0;
		}
		REP(i,0,n){
			int x, y;
			cin >> x >> y;
			g[x].PB(y);
		}
		int ans = 0;
		REP(i,1,n+1){
			if(sum[i] == -1){
				dfs(i);
			}
			if(sum[ans] < sum[i]){
				ans = i;
			}
		}
		cout << "Case " << caso++ << ": " <<  ans << endl;
	}
	return 0;
}

