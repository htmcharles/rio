#include <iostream>

using namespace std;

void bubbleSort(int arr[],int n){
	int temp;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(arr[i]<arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	
	int array[5]={1,2,3,5,6};
	int n = sizeof(array)/sizeof(array[0]);
    bubbleSort(array,n);
    
    for (int i=0;i<n;i++){
		cout << array[i];
	}
	
	
	return 0;
}
