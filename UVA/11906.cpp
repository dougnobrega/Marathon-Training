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
int mat[110][110];
int odd;
int even;
int r,c;
int m, n;
int ok(int x,int y){
	return (x >= 0 && x < r && y>=0 && y < c && mat[x][y] >= 0);
} 
int ok2(int x,int y){
	return (x >= 0 && x < r && y>=0 && y < c && mat[x][y] == 0);
} 
vpi directions;
void dfs(int x,int y){
	if(mat[x][y] != 0)
		return;
	int qtd = 0;
	vpi teste;
	REP(i,0,directions.size()){
		int x_, y_;
		x_ = x + directions[i].F;
		y_ = y + directions[i].S;
		teste.PB({x_,y_});
	}
	sort(all(teste));
	teste.erase(unique(all(teste)),teste.end());
	REP(i,0,teste.size()){
		if(ok(teste[i].F,teste[i].S)){
			qtd++;
		}
	}
	if(qtd & 1){
		mat[x][y] = 1;
		odd++;
	}else{
		mat[x][y] = 1;
		even++;
	}
	REP(i,0,teste.size()){
		if(ok2(teste[i].F,teste[i].S)){
			dfs(teste[i].F,teste[i].S);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	REP(caso,1,t+1){
		directions.clear();
		even = 0;
		odd = 0;
		cin >> r >> c >> m >> n;
		memset(mat,0,sizeof mat);
		int w;
		cin >> w;
		REP(i,0,w){
			int x, y;
			cin >> x >> y;
			mat[x][y] = -1;
		}
		directions.PB({m,n});
		directions.PB({m,-n});
		directions.PB({n,m});
		directions.PB({n,-m});
		directions.PB({-m,n});
		directions.PB({-m,-n});
		directions.PB({-n,m});
		directions.PB({-n,-m});
		dfs(0,0);
		cout << "Case " << caso << ": " << even << " "  << odd << endl; 
	}
	return 0;
}

