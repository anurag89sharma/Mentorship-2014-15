#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

void closest_pair(int arr1[], int arr2[], int m, int n, int x){
    int diff = INT_MAX;
    int cur_diff, l1,l2;
    int i=0,j=n-1;
    while(i < m && j >= 0){
        cur_diff = abs(arr1[i] + arr2[j] - x);
        if(cur_diff < diff){
            diff = cur_diff;
            l1 = i;
            l2 = j;
        }
        if(arr1[i]+arr2[j] > x)
            j--;
        else
            i++;
    }
    cout<<"Closent pairs are "<<arr1[l1]<<" and "<<arr2[l2]<<endl;
}

int main(){
    int x;
    int arr1[] = {1,4,5,7};
    int arr2[] = {10,20,30,40};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Enter a number: ";
    cin>>x;
    closest_pair(arr1,arr2,m,n,x);
    return 0;
}
