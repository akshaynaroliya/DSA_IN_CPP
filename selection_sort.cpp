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
        int min=arr[i];
        int loc=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<min){
                min=arr[j];
                loc=j;
            }
        }
        if(loc!=i){
            swap(arr[i], arr[loc]);
        }
    }

    cout<<"After sorting: "<<endl;
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}