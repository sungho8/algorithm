#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	// 이동하려는 번호
	int N; cin >> N;

	// 리모콘 넘버
	vector<int> limocon;
	for (int i = 0; i < 10; i++) {
		limocon.push_back(i);
	}

	// 부서진 버튼 처리
	int count; cin >> count;
	for (int i = 0; i < count; i++) {
		int num; cin >> num;
		limocon[num] = -1;
	}

	// 100 에서 갈때
	int min_num = abs(100 - N);
	if (min_num > to_string(N).length()) {
		for (int i = 0; i <= 999999; i++) {
			int click = abs(N - i);

			string s = to_string(i);

			bool broken = false;

			for (int j = 0; j < s.length(); j++) {
				if (limocon[s[j] - '0'] == -1) {
					broken = true;
				}
			}

			if (!broken && min_num > click + to_string(i).length()) {
				min_num = click + to_string(i).length();
				//cout <<i<<" : "<< abs(N - i) + to_string(i).length() << endl;
			}
		}
	}
	cout << min_num;
}