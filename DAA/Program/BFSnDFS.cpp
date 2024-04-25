#include<iostream>
#include<queue>
using namespace std;

	int graph[10][10];
	int size;
	
	void set(){
			cout<<"\nEnter vertex:";
			cin>>size;
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<"\nEnter weight of "<<i+1<<" to "<<j+1<<" :";
					cin>>graph[i][j];
				}
			}
	}

class BFS{
	bool visited[10];
	public:
		void get(){
			cout<<"\nGraph is:\n";
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++){
					cout<<graph[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		
		void bfs(){
			cout<<endl;
			for(int i=0;i<size;i++)
				visited[i]=false;
			queue<int> q;
			q.push(0);
			visited[0]=true;
			while(!q.empty()){
				int i= q.front();
				q.pop();
				cout<<i<<"\t";
				for(int j=0;j<size;j++){
					if(graph[i][j]!=0 && !visited[j]){
						q.push(j);
						visited[j]=true;
					}
				}
			}
		}
};

class DFS{
	public:
		bool visited[10];
		void setFalse(){
			for(int i=0;i<size;i++)
				visited[i]=false;
		}
		void dfs(int node){
			visited[node]=true;
			cout<<node<<"\t";
			
			for(int i=0;i<size;i++){
				if(graph[node][i]!=0 && !visited[i])
					dfs(i);
			}
		}
};

int main(){
	BFS b;
	set();
	b.get();
	cout<<"\nBFS IS\n";
	b.bfs();
	DFS d;
	d.setFalse();
	cout<<"\nDFS IS\n";
	d.dfs(0);
}
