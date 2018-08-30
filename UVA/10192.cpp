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
#define MAXN 110
int dp[MAXN][MAXN];
string a , b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cont = 1;
	while(getline(cin,a)){
		if(a == "#")
			break;
		getline(cin,b);
		memset(dp,0,sizeof dp);
		REP(i,1,a.size()+1){
			REP(j,1,b.size()+1){
				int aux = 1;
				if(a[i-1] != b[j-1]) aux = -INF;
				dp[i][j] = max(dp[i-1][j],  //Remove
						   max(dp[i][j-1],	//Insert
							   dp[i-1][j-1] + aux)); //Replace
			}
		}
		cout << "Case #"<< cont++<<": you can visit at most " << dp[a.size()][b.size()] <<" cities."  << endl;
	}
	return 0;
}

