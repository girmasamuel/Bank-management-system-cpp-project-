#include <iostream>
#include <string>
#include <cstdlib>//for clearing console
#include <thread>//for sleeping time
#include <chrono>//to set site bound

//header file
#include "../../headers/graphic/graphics.h"
using namespace std;

//colors decorations
string END="\033[0m";
string RED="\033[31m";
string GREEN="\033[32m";
string YELLOW="\033[33m";
string BLUE="\033[34m";
string CYAN="\033[36m";

//clearing the console command
void clear_console() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For UNIX-like systems
    #endif
};
//delaying time for real system simulation
void delay_time(int second){
    chrono::seconds duration(second);
    this_thread::sleep_for(duration);
}

//dashboard banner
void dash_board() {
    const int width = 50;//give value for banner width
    const string border(width, '*');
    const string title = "bank management system";
    const string copyright = "© 2024,Gemini";

    int padding = (width - 2 - title.length()) / 2;
    int padding2 = (width - 2 - copyright.length()) / 2;

    clear_console();//always clear console  before printing banner
    cout<<GREEN + border<<endl;//top border with '*'
    cout<<'*';
    
    cout << string(padding, ' ') <<YELLOW + title + END << string(padding, ' ');//dispalay title at center
    if ((width - 2 - title.length()) % 2 != 0 ) {
        cout << ' ';
    }
    cout << GREEN + '*' << endl;
    cout<<'*'<<' ';

    cout << string(padding2, ' ') <<CYAN + copyright + END<< string(padding2, ' ');//diaplay copyright at center
    if ((width - 2 - copyright.length()) % 2 != 0 ) {
        cout << ' ';
    }

    cout <<GREEN + '*' << endl;
    cout << border << endl; // Bottom border with '*'
};
