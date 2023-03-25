#include<iostream>
using namespace std;

int main(){
    int arr[]={10, 5, 40, 20, 30};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    
    for(int i=1; i<n; i++){
        int k=arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j]>arr[i]){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=k;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}