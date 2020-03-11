#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue <long long, vector<long long>, greater<long long>> pq;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n*n; i++) {
		
		long long a;
		cin >> a;

		if (pq.size() < n) {
			pq.push(a);
		}
		else if(pq.size()==n){
			if (a > pq.top()) {
				pq.pop();
				pq.push(a);
			}
		}
		
		
	}
	

	cout << pq.top();
	


	return 0;

}