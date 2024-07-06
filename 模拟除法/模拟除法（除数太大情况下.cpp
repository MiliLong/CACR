#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int s = 1, num = 1;
	while (s < n) {
		s = s * 10 + 1;
		num++;
	}
	while (1) {
		cout << s / n;
		if (s % n == 0) {
			break;
		} else {
			s = s % n * 10 + 1;
			num++;
		}

	}
	cout << ' ' << num;
	return 0;
}

