#include <bits/stdc++.h>
using namespace std;
// overall TC: O(log(range)*n + n)=> O(log(range)*n)
bool isValid(vector<int>& arr,int m,int n,int mid){//O(n)
    int stud=1; int pgs=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        if(pgs+arr[i]<=mid){
            pgs+=arr[i];
        }else{
            stud++;
            pgs=arr[i];
        }
    }
    return stud>m? false:true;
}

int bookAllocate(vector<int>& arr,int n,int m){
    if(m>n) return -1;
    int sum=0; int ans=-1;
    for(int i=0;i<n;i++){//O(n)
        sum+=arr[i];
    }
    int st=0;
    int end=sum;

    while(st<=end){//O(log(range)* n); range->0 to sum
        int mid=st+(end-st)/2;
        if(isValid(arr,m,n,mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={2,1,3,4};
    int n=arr.size();
    int m=2;
    cout<<bookAllocate(arr,n,m)<<endl;
    return 0;
}