#include<bits/stdc++.h>
using namespace std;
int ind{-1},n;
void Binary_Search(int beg,int End,int arr[],int target)
{
    int mid=(beg+End)/2;
    if(beg>End)
    {
        //ind=-1;
        return;
    }
    else if(arr[mid]==target)
    {
        ind=mid;
        //cout<<ind<<endl;
        Binary_Search(mid+1,End,arr,target);
        return;
        //return mid;
    }
    else if(arr[mid]>target)
        return Binary_Search(beg,mid-1,arr,target);
    else
        return Binary_Search(mid+1,End,arr,target);
}
int main()
{
    //int n;
    cout<<"Enter number of element : ";
    cin>>n;
    cout<<"Enter target : ";
    int target;
    cin>>target;
    cout<<"Enter array : ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    Binary_Search(0,n-1,arr,target);
    if(ind==-1)
        cout<<"not found"<<endl;
    else
        cout<<n-ind-1<<" elements"<<endl;
//    int index=Binary_Search(0,n-1,arr,target);
//
//    if(index==-1)
//        cout<<target<<" not found in array"<<endl;
//    else
//    {
//        for(index=index+1;index<n;index++)
//        {
//            if(arr[index]!=target)
//                break;
//        }
//        cout<<n-index<<" elements are greater than "<<target<<endl;
//    }
}
