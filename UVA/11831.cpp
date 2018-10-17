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
char mat[110][110];
int dx[] = {-1,0,1,0}; 
int dy[] = {0,1,0,-1};
bool ok(int i, int j){
	return mat[i][j] != '#';
}
struct robot{
	int x;
	int y;
	int direction;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,s;
	while(1){
		cin >> n >> m >> s;
		if(n == 0 && m == 0 && s == 0){
			return 0;
		}
		memset(mat,'#',sizeof mat);
		vector<robot> robos;
		REP(i,1,n+1){
			REP(j,1,m+1){
				cin >> mat[i][j];
				if(mat[i][j] == 'N'){
					robot aux;
					aux.direction = 0;
					aux.x = i;
					aux.y = j;
					robos.PB(aux);
				}else if(mat[i][j] == 'L'){
					robot aux;
					aux.direction = 1;
					aux.x = i;
					aux.y = j;
					robos.PB(aux);
				}else if(mat[i][j] == 'S'){
					robot aux;
					aux.direction = 2;
					aux.x = i;
					aux.y = j;
					robos.PB(aux);
				}else if(mat[i][j] == 'O'){
					robot aux;
					aux.direction = 3;
					aux.x = i;
					aux.y = j;
					robos.PB(aux);
				}
			}
		}
		string cmd;
		cin >> cmd;
		int pont = 0;
		REP(i,0,cmd.size()){
			REP(j,0,robos.size()){
				if(cmd[i] == 'D'){
					robos[j].direction++;
					if(robos[j].direction == 4){
						robos[j].direction = 0;
					}
				}else if(cmd[i] == 'E'){
					robos[j].direction--;
					if(robos[j].direction == -1){
						robos[j].direction = 3;
					}
				}else if(cmd[i] == 'F'){
					int x_ = robos[j].x + dx[robos[j].direction];
					int y_ = robos[j].y + dy[robos[j].direction];
					if(ok(x_,y_)){
						robos[j].x = x_;
						robos[j].y = y_;
						if(mat[robos[j].x][robos[j].y] == '*'){
							pont++;
							mat[robos[j].x][robos[j].y] = '.';
						}
					}
				}
			}
		}
		cout << pont << endl;
	}
	return 0;
}

