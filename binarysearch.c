#include<stdio.h>

int binarysearch(int a[],int low, int high,int key){
    if(low<=high){
        int mid = (low+high)/2;
        if(key == a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            return binarysearch(a,low,mid-1,key);
        }
        else{
            return binarysearch(a,mid+1,high,key);
        }
    }
    return -1;
}

int main(){
    int a[]={2,4,6,8,10};
    int n = 5;
    int key = 8;
    int index = binarysearch(a,0,n-1,key);
    if (index !=-1){
        printf("Element %d found at index %d\n",key,index);
    }
    else{
        printf("Element %d not found",key);
    }
}
