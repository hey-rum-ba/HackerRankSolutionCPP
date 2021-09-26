#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> q;
    for (auto i = 0; i < n; ++i) {
        while (!q.empty() && arr[i] > q.back()) { 
            q.pop_back();          
        }

        q.emplace_back(arr[i]);
        if (i+1 >= k) {
            cout << q.front() << ' ';   
            if (arr[i+1-k] >= q.front()) {
                q.pop_front();
            }
        }
    }
    cout << '\n';
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}