#include <iostream>
using namespace std;

int cnt=0;

string name[20] , course[20], classSec[20] ;
int rollno[20] , contact[20];

void enter();
void display();
void search();
void update();
void del();

int main(){
    
    cout << "\n\nPress 1 to ENTER data." << endl ;
    cout << "Press 2 to DISPLAY data." << endl ;
    cout << "Press 3 to SEARCH data." << endl ;
    cout << "Press 4 to UPDATE data." << endl ;
    cout << "Press 5 to DELETE data." << endl ;
    cout << "Press 6 to EXIT." << endl ;

    int op;

    cout << "\nPlease enter your choice : " ;
    cin >> op ;
    switch(op){

        case 1:
            enter();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;
        
        case 4:
            update();
            break;

        case 5:
            del();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Invalid Input. Please try again!" << endl ;
            break;
    }

    return 0;
}


void enter(){

    int n=0;
    cout << "\n\nEnter the number of students : " ;
    cin >> n;

    if(cnt==0){

        cnt = n + cnt ;

        for(int i=0 ; i<n ; i++){
            cout << "\nEnter the following data of Student " << i+1 << " : " << endl ;
            cout << "Enter Name : " ;
            cin >> name[i] ;
            cout << "Enter Roll No : " ;
            cin >> rollno[i] ;
            cout << "Enter Course : " ;
            cin >> course[i] ;
            cout << "Enter Class : " ;
            cin >> classSec[i] ;
            cout << "Enter Contact : " ;
            cin >> contact[i] ; 

        }    
    }

    else{

        for(int i=cnt ; i<cnt+n ; i++){
            cout << "\nEnter the following data of Student " << i+1 << " : " << endl ;
            cout << "Enter Name : " ;
            cin >> name[i] ;
            cout << "Enter Roll No : " ;
            cin >> rollno[i] ;
            cout << "Enter Course : " ;
            cin >> course[i] ;
            cout << "Enter Class : " ;
            cin >> classSec[i] ;
            cout << "Enter Contact : " ;
            cin >> contact[i] ;  
        }

        cnt = n + cnt ;
    }

    main();

}


void display(){

    if(cnt==0){
        cout << "No data is entered." << endl ;
        main();
    }


    else{

        for(int i=0 ; i<cnt ; i++){
            cout << "\n\nData of Student " << i+1 << " : " << endl ;
            cout << "Name : " << name[i] ;
            cout << "\nRoll No : " << rollno[i] ;
            cout << "\nCourse : " << course[i] ;
            cout << "\nClass : " << classSec[i] ;
            cout << "\nContact : " << contact[i] ; 
        }
        main();
    }

}


void search(){

    if(cnt==0){
        cout << "No data is entered." << endl ;
        main();
    }

    else{
        int rollNo;
        cout << "\n\nEnter the Roll No of the Student whose data you want to search : " ;
        cin >> rollNo;

        for(int i=0 ; i<cnt ;i++){

            if(rollNo==rollno[i]){
                
                cout << "\n\nData of Student " << i+1 << " : " << endl ;
                cout << "Name : " << name[i] ;
                cout << "\nRoll No : " << rollno[i] ;
                cout << "\nCourse : " << course[i] ;
                cout << "\nClass : " << classSec[i] ;
                cout << "\nContact : " << contact[i] ;
            }

            else{
                cout << "Roll No not found!" << endl ;
            }
        }
        main();
    }
}

void update(){

    if(cnt==0){
        cout << "No data is entered." << endl ;
        main();
    }

    else{

        int rollNo;
        cout << "\n\nEnter the Roll No of the Student whose data you want to update : " ;
        cin >> rollNo;


        for(int i=0 ; i<cnt ;i++){

            if(rollNo==rollno[i]){
                
                cout << "\n\nPrevious data of Student " << i+1 << " : " << endl ;
                cout << "Name : " << name[i] ;
                cout << "\nRoll No : " << rollno[i] ;
                cout << "\nCourse : " << course[i] ;
                cout << "\nClass : "  << classSec[i] ;
                cout << "\nContact : " << contact[i] ;

                cout << "\n\nEnter the new data of Student " << i+1 << " : " << endl ;
                cout << "Enter Name : " ;
                cin >> name[i] ;
                cout << "Enter Roll No : " ;
                cin >> rollno[i] ;
                cout << "Enter Course : " ;
                cin >> course[i] ;
                cout << "Enter Class : " ;
                cin >> classSec[i] ;
                cout << "Enter Contact : " ;
                cin >> contact[i] ;

            }

            else{
                cout << "Roll No not found!" << endl ;
            }
        }
        main();
    }
}


void del(){

    if(cnt==0){
        cout << "No data is entered." << endl ;
        main();
    }

    else{
        cout << "\n\nPress 1 to delete all the records." << endl ;
        cout << "Press 2 to delete a specific record." << endl ;

        int ch;
        cout << "\nPlease enter your choice : " ;
        cin >> ch ;

        if(ch==1){
            cnt = 0 ;
            cout << "All the records deleted successfully ! " << endl ;
            main();
        }

        else if(ch==2){
            int rollNo,chk=0;
            cout << "\n\nEnter the Roll No of the Student whose data you want to delete : " ;
            cin >> rollNo;

            for(int i=0 ; i<cnt ; i++){

                if(rollNo==rollno[i]){

                    for(int j=i ; j<cnt ; j++){

                        name[j]=name[j+1];
                        rollno[j]=rollno[j+1];
                        course[j]=course[j+1];
                        classSec[j]=classSec[j+1];
                        contact[j]=contact[j+1];
                    }
                    cnt--;
                    chk=1;
                    cout << "Your record has been deleted." << endl ;
                }
            }
            if (chk==0){
                cout << "Invalid Roll No ! " << endl ;
            }
            main();
        }

        else{
            cout << "Invalid option ! " << endl ;
            main();
        }
    }
}