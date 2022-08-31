#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n, int m){

    if(x<n && y<m && arr[x][y]==1){
        return true;
    }

    return false;
}

bool mazeSolver(int **arr, int x, int y, int n, int m, char **solArr){

    if(x==n-1 && y==m-1){
        solArr[x][y]='*';
        return true;
    }

    if(isSafe(arr,x,y,n,m)){
        solArr[x][y]='*';

        if(mazeSolver(arr,x+1,y,n,m,solArr)){
            return true;
        }

        if(mazeSolver(arr,x,y+1,n,m,solArr)){
            return true;
        }

        solArr[x][y]='0'; //backtracking
        return false;
    }

    return false;
}

int main(){

    int n,m;
    cout << "Enter the number of rows : " << endl ;
    cin >> n ;
    cout << "Enter the number of columns : " << endl ;
    cin >> m ;

    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }

    cout << "\nEnter the maze (in the form of 0's ans 1's) : " << endl ;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    char **solArr=new char*[n];
    for(int i=0; i<n;i++){
        solArr[i]=new char[n];

        for(int j=0 ; j<n ;j++){
            solArr[i][j]='0';    
        }
    }

    if(mazeSolver(arr,0,0,n,m,solArr)){

        cout <<"\n\nThe path is shown as follows : \n"<< endl;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << solArr[i][j] << " ";
            }
            cout << endl ;
        }
    }

    else{
        cout << "\n\nNo path found for the given maze." ;
    }

    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1 
// 0 1 0 1 0
// 1 0 0 1 1 
// 1 1 1 0 1