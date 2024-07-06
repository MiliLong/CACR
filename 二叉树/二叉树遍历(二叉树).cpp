#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
typedef struct tnode{
	char data;
	tnode *l,*r;
}*tree;
/*
typedef struct tagPoint
{
    double x;
    double y;
    double z;
} Point;
在上面的代码中，实际上完成了两个操作：
1、定义了一个新的结构类型
struct tagPoint
{
    double x;
    double y;
    double z;
} ;
2、使用 typedef 为这个新的结构起了一个别名，叫 Point，即：
typedef struct tagPoint Point
因此，现在你就可以像 int 和 double 那样直接使用 Point 定义变量，如下面的代码所示：
Point oPoint1={100，100，0};
Point oPoint2;
*/
char i;
/*
引用引入了对象的一个同义词。定义引用的表示方法与定义指针相似，只是用&代替了*。
int a=1;
int &b=a;
a=1,b=1
a=2;
a=2,b=2
b=3;
a=3,b=3
*/
void build(tree &t){
	cin>>i;
	if(i=='#'){
		t=NULL;
		return;
	}
	t=new tnode;
	t->data=i;
	build(t->l);
	build(t->r);
}
//前序建树
//顺序：：读节点，建左树，建右树
//遇到NULL return；
void inorder(tree &t){
	if(t==NULL)return;
	inorder(t->l);
	cout<<t->data<<' ';
	inorder(t->r);
}
//中序遍历树
//顺序：：读左树，读节点，读右面树
//遇到NULL return；
void solve() {
	tree t;//此时tree是一个类型，一个tnode的指针，其内容是地址，t就是地址
	//递归中传递的就是tnode定义的指针
	//tree就相当于tnode定义的指针
	build(t);
	inorder(t);
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
