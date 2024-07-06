#include<iostream>
#include<queue>
using namespace std;
struct stu {
	char name[12];
	int h;
} mid;
class cmp {
	public:
		bool operator()(const stu&a, const stu&b) {
			return a.h > b.h;
		}
};
int main () {
	int n;
	cin >> n;
	priority_queue<stu, vector<stu>, cmp> p;
	for (int x = 0; x < n; x++) {
		char i[12];
		cin >> i;
		if (i[0] == 'G') {
			if (p.empty() == false) {
				cout << p.top().name << endl;
				p.pop();
			} else cout << "EMPTY QUEUE!" << endl;
		} else if (i[0] == 'P') {
			cin >> mid.name >> mid.h;
			p.push(mid);
		}
	}
	return 0;
}
