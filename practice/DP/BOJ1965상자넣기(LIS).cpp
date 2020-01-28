#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int MAX = 1010;
int arr[MAX];
vector <int> res;
//int dis[MAX];
//vector <int> dap;
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	int index = 0;
	res.push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		
		if (res[index] < arr[i]) {
			index++;
			res.push_back(arr[i]);
			//dis[i] = index;
		}
		else {
			int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			res[pos] = arr[i];
			//dis[i] = pos;

		}
	}
	cout << res.size();
	
	/*
	for (int i = n; i >= 1 && index >= 0; i--) {
		if (dis[i] == index) {
			dap.push_back(arr[i]);
			index--;
		}
	}
	for (int i = dap.size()-1; i >= 0; i--) cout << dap[i]<<" ";
	*/
	return 0;
}