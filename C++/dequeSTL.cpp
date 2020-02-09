#include <iostream>
#include <deque> 
using namespace std;

int findMax(deque<int> const &list)
{
    int max = list[0];
    for(int i=1;i<list.size();i++)
    {
        if(list[i]>max){
            max = list[i];
        }
    }
    //cout<<"findMax "<<max<<endl;
    return max;    
}

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> subarray;
    int i = 0;
    while(i<k){
        subarray.push_back(arr[i]);
        i++;
    }
    int max_elem_in_subarr = findMax(subarray);
    cout<<max_elem_in_subarr<<" ";
    for(;i<n;i++){
        int popped_elem_in_subarr = subarray.front();
        subarray.pop_front();
        subarray.push_back(arr[i]);
        if(popped_elem_in_subarr != max_elem_in_subarr){
            /*max element is still present in the deque.
            So just compare the max elem with the newly added value */
            if(subarray.back() > max_elem_in_subarr){
                //new max elem
                max_elem_in_subarr = subarray.back();
            }
        }
        else{
            //max elem was popped out. need to find new max elem
            max_elem_in_subarr = findMax(subarray);
        }
        cout<<max_elem_in_subarr<<" ";
    }
    cout<<endl;
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

