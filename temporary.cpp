#include <bits/stdc++.h>
using namespace std;


#define ll                                        	long long
#define endl                                        '\n'
#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)
#define readInt(x)                                  int x; cin >> x; // reads int
#define readll(x)                                   ll x; cin >> x; // reads long long
#define readStr(x)                                  string x; cin >> x; // reads string(word)
#define readLine(x)                                 string x; getline(cin, x); // reads string(sentence)
#define print(x)                                    cout<<(x)<<" "
#define println(x)                                  cout<<(x)<<endl

void solve(){
	// start
	
	readInt(n)readInt(m);
  	readInt(x)readInt(y);
  	
  	int left = (y>1?(y-1)*n : 0);
  	int right = (y < m?(m-y)*n : 0);
  	int top = (x>1?(x-1)*m : 0);
  	int down = (x < n?(n-x)*m : 0);
  	
  	// cout << left << " " << right << " " << top << " " << down << endl;
  	cout << max(left, max(right, max(top, down))) << endl;

}

int main(){
	int testcases = 1;
	cin >> testcases;
	
	while(testcases--){
		solve();
	}
	
	return 0;
}