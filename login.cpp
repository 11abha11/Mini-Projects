#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void login();
void registration();
void forgot();

int main(){

    int choice;
    cout << "____________________________________________\n\n" ;
    cout << "         WELCOME TO THE LOGIN PAGE          \n\n" ;
    cout << "_________________ MENU _____________________\n\n" ;
    cout << "| Press 1 to LOGIN                    |" << endl ;
    cout << "| Press 2 to REGISTER                 |" << endl ;
    cout << "| Press 3 if you forgot your password |" << endl ;
    cout << "| Press 4 to EXIT                     |" << endl ;

    cout << "\nPlease enter your choice : " ;
    cin >> choice ;
    cout << endl ;


    switch (choice)
    {
    case 1 :
        login();
        break;

    case 2 :
        registration();
        break;

    case 3 : 
        forgot();
        break;

    case 4 :
        cout << "Thank You !!!" << endl ;
        break;
    
    default:
        system("cls");
        cout << "Please select from the options given above. \n" << endl ;
        main();
    }

}

void login(){

    int flag=0;
    string userId , userPass , id , pass;
    system("cls");

    cout << "Please enter username and password : " << endl ;
    cout << "USERNAME : " ;
    cin >> userId ;
    cout << "PASSWORD : " ;
    cin >> userPass ;

    ifstream f1("records.txt");

    while(f1 >> id >> pass){

        if(userId==id && userPass==pass){
            flag=1;
            system("cls");
        }
    }

    f1.close();

    if(flag==1){
        cout << "Your login was successful ! " << endl ;
        main();
    }
    else{
        cout << "LOGIN ERROR ! \nPlease check the credentials again." << endl ;
        main();
    }

}


void registration(){

    string ruserId ,rpass ;
    system("cls");

    cout << "Enter the username : " ;
    cin >> ruserId ;
    cout << "Enter the password : " ;
    cin >> rpass ;

    ofstream f2("records.txt" , ios::app);

    f2 << ruserId << " " << rpass ;
    system("cls");
    f2.close();

    cout << "Registration completed successfully ! " << endl ;
    main();
}


void forgot(){
    int op;
    cout << "Forgot password?" << endl ;
    cout << "Press 1 to get the password." << endl ;
    cout << "Press 2 to return to the menu.\n" << endl ;
    cout << "Please enter your choice : \n\n" ;
    cin >> op ;

    switch (op)
    {
    case 1:{
        int flag = 0;
        string fuserId , fId , pass ;

        cout << "Enter the username : " ;
        cin >> fuserId ;

        ifstream f3("records.txt");

        while(f3 >> fId >> pass){

            if(fuserId==fId){
                flag=1;
            }
        }

        f3.close();

        if(flag==1){
            cout << "\n\t\tFound your account ! " << endl ;
            cout << "\t\tHere's your password : " << pass << endl ;
            main();
        }

        else{
            cout << "\n\t\tSorry! Your account is not found.\n" << endl ;
            main();
        }

        break;
    }

    case 2:
        main();
    
    default:
        cout << "\n\t\tPlease enter a choice from the given options.\n" << endl ;
        forgot();
    }
}