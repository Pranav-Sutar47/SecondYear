#include<iostream>
#include<limits.h>
using namespace std;


class Dijkstra{
	int graph[10][10];
	int distance[10];
	bool visited[10];
	public:
		int size;
		
		void set(){
			cout<<"\nEnter vertex:";
			cin>>size;
			for(int i =0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<"\nEnter "<<i+1<<" weight with "<<j+1<<" :";
					cin>>graph[i][j];
				}
			}
		}
		
		void dijkstra(){
        	cout<<"\nU\tV\tDistance\t";
        	for(int i=0;i<size;i++){
            	cout<<"\n1\t"<<i+1<<"\t"<<distance[i];
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
		
		void algo(){
			for(int i=0;i<size;i++){
				visited[i]=false;
				distance[i]=INT_MAX;
			}
			distance[0]=0;
			int b=1;
			while(b==1){
				int i = min();
				
				for(int j=0;j<size;j++){
					if(graph[i][j]!=0){
						if(distance[j]>(graph[i][j]+distance[i]))
							distance[j]=(graph[i][j]+distance[i]);
					}
					if(j==size-1)
						visited[i]=true;
				}
				if(i==10)
					b=0;
			}
		}
		
		int min(){
			int m = INT_MAX;
			int pos;
			short b=0;
			for(int i=0;i<size;i++){
				if(distance[i]<m && visited[i]==false){
					m = distance[i];
					pos = i;
				}else 
					b++;
			}
			if(b>size-1)
				return 10;
			else 
				return pos;
		}
		
};

int main(){
	Dijkstra d;
	d.set();
	d.get();
	d.algo();
	d.dijkstra();
}
