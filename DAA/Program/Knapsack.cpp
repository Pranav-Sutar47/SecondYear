#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Knapsack{
	public:
		float weight,profit,pw;
		
		void set(){
			cout<<"\nEnter Weight:";
			cin>>weight;
			cout<<"\nEnter Profit:";
			cin>>profit;
			pw = profit/weight;
		} 
		
		void get(){
			cout<<"\nWeight is:"<<weight;
			cout<<"\nProfit is:"<<profit;
			cout<<"\nProfit \ Weight is:"<<pw;
		}
		
		void weightSort(Knapsack obj[],int item){
			for(int i=0;i<item;i++){
				for(int j=i+1;j<item;j++){
					if(obj[i].weight>obj[j].weight)
						swap(obj[i],obj[j]);
				}
			}
		}
		
		void profitSort(Knapsack obj[],int item){
			for(int i=0;i<item;i++){
				for(int j=i+1;j<item;j++){
					if(obj[i].profit<obj[j].profit)
						swap(obj[i],obj[j]);
				}
			}
		}
		
		void pwSort(Knapsack obj[],int item){
			for(int i=0;i<item;i++){
				for(int j=i+1;j<item;j++){
					if(obj[i].pw<obj[j].pw)
						swap(obj[i],obj[j]);
				}
			}
		}
		
		float knapsack(Knapsack obj[],int capacity,int item){
			int i=0;
			float p=0;
			while(capacity>0){
				if(capacity>=obj[i].weight){
					capacity-=obj[i].weight;
					p+=obj[i].profit;
					i++;
				}else{
					p= p + (capacity/obj[i].weight*obj[i].profit);
					capacity -= obj[i].weight;
				}
			}
			return p;
		}
		
//		float profitKnapsack(Knapsack obj[],int capacity,int item){
//			profitSort(obj,item);
//			float p =0;
//			int i = 0;
//			while(capacity>0){
//				if(capacity>=obj[i].weight){
//					p +=obj[i].profit;
//					capacity-=obj[i].weight;
//					i++;
//				}else{
//					p = p +(capacity/obj[i].weight*obj[i].profit);
//					capacity -= obj[i].weight;
//				}
//			}
//			return p;
//		}
		
//		float pwKnapsack(Knapsack obj[],int capacity,int item){
//			pwSort(obj,item);
//			float p = 0;
//			int i = 0;
//			while(capacity>0){
//				if(capacity>obj[i].weight){
//					p += obj[i].profit;
//					capacity-=obj[i].weight;
//					i++;
//				}else{
//					p = p+(capacity/obj[i].weight*obj[i].profit);
//					capacity-=obj[i].weight;
//				}
//			}
//			return p;
//		}
		
};


int main(){
	int capacity,item;
	cout<<"\nEnter capacity:";
	cin>>capacity;
	cout<<"\nEnter total items:";
	cin>>item;
	Knapsack obj[item];
	for(int i=0;i<item;i++){
		obj[i].set();
	}
	cout<<"\nItems are\n";
	for(int i=0;i<item;i++)
		obj[i].get();
	obj[0].weightSort(obj,item);
	cout<<"\n\nGreedy on Weight is:"<<obj[0].knapsack(obj,capacity,item);
	obj[0].profitSort(obj,item);
	cout<<"\n\nGreedy on Profit is:"<<obj[0].knapsack(obj,capacity,item);
	obj[0].pwSort(obj,item);
	cout<<"\n\nGreedy on Profit/Weight is:"<<obj[0].knapsack(obj,capacity,item);
//	obj[0].pwSort(obj,item);
//	for(int i=0;i<item;i++)
//		obj[i].get();

	
}
