#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
//#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
bool iscount(char a[]){
    for(int x=0;;x++){
        if(a[x]=='\0')break;
        if(!(a[x]<='9'&&a[x]>='0'))return false;
    }
    return true;
}
void solve() {
    bool isa=true,isb=true;
    char ar[100],br[100],c[200];
    int a,b,sum;
    //特殊的字符处理，非常好用
    scanf("%s%*1[^\n]%[^\n]",ar,br);//两种方法等效
    //scanf("%[^\n]",c);
    //sscanf(c,"%s",ar);
    //int la=strlen(ar);
    //sscanf(c+la+1,"%[^\n]",br);
    if(!iscount(ar))isa=false;
    else {
        sscanf(ar,"%d",&a);
        if(!(a<=1000&&a>=1))isa=false;
    }
    if(!iscount(br))isb=false;
    else {
        sscanf(br,"%d",&b);
        if(!(b<=1000&&b>=1))isb=false;
    }
    if(isa&&isb)sum=a+b;
    if(isa)cout<<a;
    else cout<<'?';
    cout<<" + ";
    if(isb)cout<<b;
    else cout<<'?';
    cout<<" = ";
    if(isa&&isb)cout<<sum;
    else cout<<'?';  
}
signed main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
