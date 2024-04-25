#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class QuickSort{
	public:
		int a[10];
		int size;
		void set(){
			cout<<"\nEnter size of array:";
			cin>>size;
			for(int i=0;i<size;i++){
				cout<<"\nEnter "<<i+1<<" element:";
				cin>>a[i];
			}
		}
		
		void get(){
			cout<<"\nArray is:\n";
			for(int i=0;i<size;i++)
				cout<<a[i]<<"\t";
		}
		
		void quickSort(int a[],int lb,int ub){
			if(lb<ub){
				int pivot = partation(a,lb,ub);
				quickSort(a,lb,pivot-1);
				quickSort(a,pivot+1,ub);
			}
		}
		
		int partation(int a[],int lb,int ub){
			int start = lb;
			int end = ub;
			int pivot = a[lb];
			while(start<end){
				while(a[start]<=pivot)
					start++;
				while(a[end]>pivot)
					end--;
				if(start<end)
					swap(a[start],a[end]);
			}
			swap(a[lb],a[end]);
			return end;
		}
};

int main(){
	QuickSort q;
	q.set();
	q.get();
	q.quickSort(q.a,0,q.size-1);
	q.get();
}
