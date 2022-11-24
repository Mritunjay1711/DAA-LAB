//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item item1, Item item2)
    {
        return (double)item1.value/item1.weight > (double)item2.value/item2.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double val = 0;
        sort(arr, arr+n, compare);
        int i = 0;
        while(W && i<n)
        {
            if(arr[i].weight < W)
            {
                val += arr[i].value;
                W -= arr[i].weight;
                i++;
            }
            else
            {
                // cout << W << "*" << endl;
                val += (((double)arr[i].value/arr[i].weight)*W);
                W = 0;
                i++;
            }
        }
        return val;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends