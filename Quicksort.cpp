#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int st, int end){
    int idx = st-1, piv = arr[end];

    for(int j=st;j<end;j++){
        if(arr[j]<=piv){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;

}
 void quicksort(vector<int> &arr, int st, int end){
    if(st < end){
        int piv = partition(arr, st, end);
        quicksort(arr,st,piv-1);
        quicksort(arr,piv+1,end);
    }
}



int main(){
    vector<int> arr = {12,10,3,6,4,67};
    quicksort(arr,0,5);
    for(int num : arr){
        cout<< num<< " ";
    }
}