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

#define MAXN 1000
int dp[MAXN][MAXN];
string a, b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool n = false;
	while(getline(cin,a) && getline(cin,b)){

		if(n == true)
			cout << endl;
		else
			n = true;

		int tama = a.size(),tamb = b.size();
		REP(i,0,max(tama,tamb) + 1){
			dp[i][0] = i; //delete
			dp[0][i] = i; //insert
		}
		REP(i,1,tama+1){
			REP(j,1,tamb+1){
				int aux = 0;
				if(a[i-1] != b[j-1]){
					aux = 1;
				}
				dp[i][j] = min(dp[i-1][j] + 1, // delete
						   min(dp[i][j-1] + 1,  // insert
							   dp[i-1][j-1] + aux)); //replace
			}
		}
		cout << dp[tama][tamb] << endl;
		vector<pair<int,pair<int,char > > > aux;
		int i = tama, j = tamb;
		while(dp[i][j] != 0){
			if(i == 0){
				aux.PB({1,{i,b[j-1]}}); //insert
				j--;
			}else if(j == 0){
				aux.PB({0,{i,b[j-1]}}); //delete
				i--;
			}else if(dp[i][j] == dp[i-1][j-1] + (a[i-1]!= b[j-1])){
				if(i > 0 && j >0 &&a[i-1] != b[j-1])
				aux.PB({2,{i,b[j-1]}}); //insert
				i--;
				j--;
			}else if(dp[i][j] == dp[i-1][j] + 1){
				aux.PB({0,{i,b[j-1]}}); //delete
				i--;
			}else if(dp[i][j] == dp[i][j-1] + 1){
				aux.PB({1,{i,b[j-1]}}); //insert
				j--;
			}
		}
		reverse(all(aux));
		int helpme = 0;
		REP(i,0,(int)aux.size()){
			cout << i+1  << " ";
			if(aux[i].F == 0){
				cout << "Delete " << aux[i].S.F - helpme << endl;
				helpme++;
			}else if(aux[i].F == 1){
				helpme--;
				cout << "Insert " << aux[i].S.F - helpme << ',' << aux[i].S.S << endl;
			}else{
				cout << "Replace " << aux[i].S.F - helpme << ',' << aux[i].S.S << endl;
			}
		}

	}
	return 0;
}

