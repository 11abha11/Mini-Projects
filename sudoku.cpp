#include <iostream>
using namespace std;
# define N 9

int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool inCol(int col , int num){     //check whether num is present in column
    for(int row=0 ; row<N ; row++){
        if (grid[row][col]==num)
            return true;
    }
    return false;
}

bool inRow(int row , int num){    //check whether num is present in row
    for(int col=0 ; col<N ; col++){
        if (grid[row][col]==num)
            return true;
    }
    return false;
}

bool inBox(int startRow, int startCol , int num){    //check whether num is present in 3x3 box
    for(int row=0 ; row<3 ; row++){
        for(int col=0 ; col<3 ; col++){
            if(grid[row+startRow][col+startCol]==num)
                return true;
        }
    }
    return false;
}

bool empty(int row, int col){
    for(row=0;row<N;row++){
        for(col=0 ; col<N ; col++){
            if (grid[row][col]==0)
                return true;
        }
    }
    return false;
}

void printGrid(){     //to print the grid
    for(int row=0 ; row < N ; row++){
        for(int col=0 ; col < N ; col++){
            if(col==3 || col==6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        
        if(row==2 || row==5){
            cout << endl << "-----------------------";
        }
        cout << endl;
    }
}

bool valid(int row, int col, int num){
    return !inRow(row,num) && !inCol(col,num) && inBox(row - row%3, col - col%3 , num);
}

bool solve(){
    int row, col;
    if(!empty(row, col))
        return true;
    for(int num=1; num<=9 ; num++){
        if(valid(row,col,num))
            grid[row][col]=num;

            if(solve())
                return true;
            grid[row][col]=0;
    }
    return false;
}

int main(){

    printGrid();

    if(solve()==true)
        printGrid();
    else    
        cout << "No solution exists." ;
    return 0;
}
