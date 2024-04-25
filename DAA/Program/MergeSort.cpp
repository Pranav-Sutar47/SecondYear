#include<iostream>
using namespace std;

class MergeSort{
		int a[10];
		int b[10];
	public:
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
		
		void mergeSort(int lb,int ub){
			if(lb<ub){
				int mid = (lb+ub)/2;
				mergeSort(lb,mid);
				mergeSort(mid+1,ub);
				merge(a,lb,mid,ub);
			}
		}
		
		void merge(int a[],int lb,int mid,int ub){
			int i = lb;
			int j = mid+1;
			int k = lb;
			while(i<=mid && j<=ub){
				if(a[i]<=a[j]){
					b[k] = a[i];
					i++;
				}else{
					b[k] = a[j];
					j++;
				}
				k++;
			}
			if(i>mid){
				while(j<=ub){
					b[k] = a[j];
					k++;
					j++;
				}
			}else{
				while(i<=mid){
					b[k] = a[i];
					k++;
					i++;
				}
			}
			for(k=lb;k<=ub;k++)
				a[k]=b[k];
		}

};

int main(){
	MergeSort m;
	m.set();
	m.get();
	m.mergeSort(0,m.size-1);
	m.get();
}
