#include<iostream>
using namespace std;

int main(){
    int arr[]={10, 5, 40, 20, 30};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    for(int i=0; i<n-1; i++){
        bool s=true;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1], arr[j]);
                s=false;
            }
            if(s){
                break;
            }
        }
    }

    cout<<"After sorting: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}