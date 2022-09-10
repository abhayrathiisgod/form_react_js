#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int s,int e){
    int mid= (s+e)/2;
    int len1= mid-s+1;
    int len2=e-mid;
    

    //creating two arrays for left and right part
     int *first= new int[len1];
     int *second= new int[len2];

     //copying the values from main array to first and second array
      int k=s;
      for(int i=0;i<len1;i++){
        first[i]=arr[k++];
      }

        k=mid+1;
      for(int i=0;i<len2;i++){
        second[i]=arr[k++];
      }
      // up to here, the main arrray is divided into two parts and both are sorted


      //now the task is to re combine ta array
      //concept of merge two sorted array

        int index1=0;
        int index2=0;
         k=s;

        while(index1< len1 && index2< len2){
            if(first[index1]<second[index2]){
                arr[k++]=arr[index1++];
            }
            else{
                arr[k++]=arr[index2++];
            }
        }
        while(index1<len1){
            arr[k++]=arr[index1++];
        }
        while(index2<len2){
            arr[k++]=arr[index2++];
        }
}





void mergeSort( int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    //sort left part
    mergeSort(arr,s,mid);
    //sort right part
    mergeSort(arr,mid+1,e);

    //merge two sorted array
    merge(arr,s,e);



}


int main(){
    int n=5;
    int arr[]={5,4,3,21,7};
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}