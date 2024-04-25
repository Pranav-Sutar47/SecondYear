#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Multistage{
	int graph[10][10];	
	public:
	int size;
	int distance[10];
		void set(){
			cout<<"\nEnter vertex:";
			cin>>size;
			for(int i =0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<"\nEnter "<<i+1<<" weight with "<<j+1<<" :";
					cin>>graph[i][j];
			
			}
		}
		
		void get(){
			cout<<endl;
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++)
					cout<<graph[i][j]<<"\t";
				cout<<endl;
			}
		}
		
		int shortestPath(){
			distance[size-1]=0;
			for(int i=size-2;i>=0;i--){
				distance[i]=INT_MAX;
				for(int j=i;j<size;j++){
					if(graph[i][j]==0)
						continue;
					distance[i]=min(distance[i],graph[i][j]+distance[j]);
				}
			}
			return distance[0];
		}
};

int main(){
	Multistage m;
	m.set();
	m.get();
	cout<<"\nShortest Path is:"<<m.shortestPath()<<endl;
	for(int i=0;i<m.size;i++)
		cout<<m.distance[i]<<"\t";
}
