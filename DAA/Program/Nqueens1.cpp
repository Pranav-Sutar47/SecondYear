#include<iostream>
#define N 4
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[N][N],int row,int col){
	int i,j;
	for(i=0;i<col;i++){
		if(board[row][i])
			return false;
	}
	for(i=row,j=col;i>=0 && j>=0;i--,j--){
		if(board[i][j])
			return false;
	}
	for(i=row,j=col;j>=0 && i<N;j--,i++){
		if(board[i][j])
			return false;
	}
	return true;
}

bool nQueen(int board[N][N],int col){
	if(col>=N)
		return true;
	for(int i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col]=1;
			if(nQueen(board,col+1))
				return true;
			board[i][col]=0;
		}
	}
	return false;
}

void printSolution(int board[N][N]){
	cout<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j])
				cout<<" Q ";
			else 
				cout<<" - ";
		}
		cout<<endl;
	}
}


bool solution(){
	int board[N][N]={
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0} };

	if(nQueen(board,0)==false){
		cout<<"Solution doesn't exist";
		return false;
	}
	
	printSolution(board);
	return true;
}


int main(){
	solution();
}
