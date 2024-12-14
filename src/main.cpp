#include <iostream>
// local dependecies 
#include "../headers/graphic/graphics.h"
#include "../headers/bank-system/admin.h"
#include "../headers/bank-system/bank_account.h"
#include "../headers/bank-system/database.h"

using namespace std;

int main(){
//
    Database database;
    BankManager manager;
    string username, password;
    double initBalance;
    BankAccount acc("", database);
    double withdrawAmt;
    double depositAmt;
    bool loggedIn = false;
    bool managerLoggedIn = false;

    char option;//store users menu choosen option

    //clear_console();
    delay_time(1);
    while(true){
        if(!loggedIn){
            dash_board();
            //display main mainu options
            cout<<RED+"\n [1]"+END+BLUE+" Create Account"; 
            cout<<RED+"\t [2]"+END+BLUE+" user login \n";               
            cout<<RED+" [3]"+END+BLUE+" admin login";             
            cout<<RED+"\t [4]"+END+BLUE+" exit\n\n";
            
            cout<<"Choose(1-4):"+RED;
            cin>>option;

            //create account ------------------------------------------------
            if(option == '1'){
                dash_board();
                string newUsername, password;
                cout << BLUE+"\nEnter new username: "+CYAN;
                cin >> newUsername;
                cout << BLUE+"Enter password: ";
                cin >> password;
                database.createUser(newUsername, password);//store the new user on database/filesystem
                username = newUsername;
                acc.setUsername(username);
                delay_time(3);
            }

            //USER LOGIN -------------------------------------------------------
            else if(option == '2'){
                dash_board();
                if (database.login()) {
                    loggedIn = true;
                    username = username;
                    acc.setUsername(username);   
                }
                delay_time(3);
            }
            //ADMIN LOGIN-----------------------------------------------------
            else if(option == '3'){
                dash_board();
                if (manager.login()){
                    loggedIn = true;
                    managerLoggedIn = true;
                }
                delay_time(3);
            }

            //exit/close system --------------------------------------------
            else if(option == '4'){
                clear_console();
                cout<<RED+"Exiting program...\n"+END;
                delay_time(2);
                clear_console();
                break;
            }

            //Unappropriate input --------------------------------------------------------
            else{
                clear_console();
                cout<<RED+"Coution:"+END+BLUE+"Invalid Input"<<endl;
                cout<<"please enter only from options "+RED+"1-4"+END<<endl;
                delay_time(5);
            }
            
        }
        else{
            //admin login
            if(managerLoggedIn){
                dash_board();
                cout << GREEN+"\t\t Manager Options\n"+END;
                cout << RED+"[1]"+BLUE+" Get List of Users and Account Details\n";
                cout << RED+"[2]"+BLUE+" Logout\n";
                cout << "option("+RED+"1-2"+BLUE+"): ";
                cin >> option;
                if (option == '1') {
                    dash_board();
                    ifstream userFile(users_data);
                    if (userFile.is_open()) {
                        cout<<"\n-------------------------------------------\n";
                        string line;
                        while (getline(userFile, line)) {
                            cout << line << endl;
                        }
                        cout<<"-------------------------------------------\n";
                        userFile.close();
                    }
                    delay_time(5);
                }
                if (option == '2') {
                    loggedIn = false;
                    managerLoggedIn = false;
                }
            }
            //bank user login
            else{
                dash_board();
                cout << GREEN+"\t\tUser Options:\n";
                cout << RED+"[1]"+BLUE+" Withdraw\n";
                cout << RED+"[2]"+BLUE+" Deposit\n";
                cout << RED+"[3]"+BLUE+" Get Account Summary\n";
                cout << RED+"[4]"+BLUE+" Close Account\n";
                cout << RED+"[5]"+BLUE+" Logout\n\n";

                cout << "option("+RED+"1-5"+BLUE+"): ";
                cin >> option;

                if (option == '1') {
                    dash_board();
                    cout << GREEN+"\nPlease enter withdrawal amount: "+BLUE;
                    cin >> withdrawAmt;
                    acc.Withdraw(withdrawAmt);
                    delay_time(5);
                } else if (option == '2') {
                    dash_board();
                    cout << "\nPlease enter deposit amount: ";
                    cin >> depositAmt;
                    acc.Deposit(depositAmt);
                    delay_time(3);
                } else if (option == '3') {
                    dash_board();
                    cout<<"\n---------------------------------------------\n";
                    acc.PrintAccountSummary();
                    cout<<"\n---------------------------------------------\n";
                    delay_time(5);

                } else if (option == '4') {
                    dash_board();
                    acc.CloseAccount(database);
                    loggedIn = false;
                    delay_time(2);
                } else if (option == '5') {
                    loggedIn = false;
                }
            }

        }
    }
    
    return 0;
}