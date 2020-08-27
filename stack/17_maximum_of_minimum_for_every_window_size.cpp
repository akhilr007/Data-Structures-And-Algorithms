// maximum of minimum for every window size
/*
Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
A[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10 
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1. Minimums of windows
of size 1 are {10}, {20}, {30}, {50},
{10}, {70} and {30}. Maximum of these
minimums is 70. 
Second element in output indicates
maximum of minimums of all windows of
size 2. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
Maximum of these minimums is 20. 
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
A[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
Your Task:
The task is to complete the function printMaxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 105
1 <= A[i] <= 106*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> nsl(int arr[], int n)
{
    stack<pair<int,int>> s;
    
    vector<int> v;
    
    int pseudo_index = -1;
    
    for(int i = 0; i < n; i++)
    {
        if(s.size() == 0)
            v.push_back(pseudo_index);
            
        else if(s.size() > 0 and s.top().first < arr[i])
            v.push_back(s.top().second);
            
        else if(s.size() > 0 and s.top().first >= arr[i])
        {
            while(s.size() > 0 and s.top().first >= arr[i])
                s.pop();
                
            if(s.size() == 0) v.push_back(pseudo_index);
            
            else v.push_back(s.top().second);
        }
        
        s.push({arr[i], i});
    }
    
    //reveres(v.begin(), v.end());
    return v;
}

vector<int> nsr(int arr[], int n)
{
    stack<pair<int,int>> s;
    
    vector<int> v;
    
    int pseudo_index = n;
    
    for(int i = n-1; i >= 0; i--)
    {
        if(s.size() == 0)
            v.push_back(pseudo_index);
            
        else if(s.size() > 0 and s.top().first < arr[i])
            v.push_back(s.top().second);
            
        else if(s.size() > 0 and s.top().first >= arr[i])
        {
            while(s.size() > 0 and s.top().first >= arr[i])
                s.pop();
                
            if(s.size() == 0) v.push_back(pseudo_index);
            
            else v.push_back(s.top().second);
        }
        
        s.push({arr[i], i});
    }
    
    reverse(v.begin(), v.end());
    return v;
}
 
vector<int> mah(int arr[], int n){
    
    // Your code here
    
    vector<int> right = nsr(arr, n);
    
    vector<int> left = nsl(arr, n);
    
    vector<int> ans(n+1, 0);
    
    for(int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] -1;
        
        ans[len] = max(ans[len], arr[i]);
    }
    
    for(int i = n-1; i >=1; i--)
    {
        ans[i] = max(ans[i], ans[i+1]);
    }
    
    vector<int> res(n);
    
    for(int i = 1; i <= n; i++)
    {
        res[i-1] = ans[i];
    }
    
    return res;
        
    
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
            
        vector<int> v = mah(arr, n);
        
        for(int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
    
    return 0;
}
