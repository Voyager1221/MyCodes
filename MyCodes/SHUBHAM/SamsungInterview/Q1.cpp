// C++ program for the above approach

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countDistinct(vector<int>&arr, int K, int N)
{
	// Creates an empty hashmap hm
	unordered_map<int, int> hm;
    int ans=0;

	// initialize distinct element count for current window
	int dist_count = 0;

	// Traverse the first window and store count
	// of every element in hash map
	for (int i = 0; i < K; i++) {
		if (hm[arr[i]] == 0) {
			dist_count++;
		}
		hm[arr[i]] += 1;
	}
    for(auto itr:hm){
        if(itr.second>1)dist_count--;
    }

	// Print count of first window
	// cout << dist_count << endl;
    
    ans += dist_count;

	// Traverse through the remaining array
	for (int i = K; i < N; i++) {

		if (dist_count<K){
            dist_count++;
		    if (hm[arr[i - K]] == 1) {
			    dist_count--;
		    }
		    hm[arr[i - K]] -= 1;
            hm[arr[i]] += 1;
            if(hm[arr[i]] > 1){
                dist_count--;
            }
            ans += dist_count;
        }else{
            if (hm[arr[i - K]] == 1) {
			    dist_count--;
		    }
		    hm[arr[i - K]] -= 1;
            if(hm[arr[i]]==0)dist_count++;
            hm[arr[i]] += 1;
            if(hm[arr[i]] > 1){
                dist_count--;
            }
            ans += dist_count;
        }
	}
    return ans;
}

// Driver's code
int main()
{
	// int arr[] = {1, 2, 1, 3, 4, 2, 3};
	// int N = sizeof(arr) / sizeof(arr[0]);
	// int K = 4;
    int K,N;
    cin>>K>>N;
    vector<int>vec(N, 0);
    for(int i=0; i<N; i++){
        cin>>vec[i];
    }
	// Function call
	cout<<countDistinct(vec, K, N)<<endl;

	return 0;
}
