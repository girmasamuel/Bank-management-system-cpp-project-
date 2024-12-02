#include <iostream>

// local dependecies 
#include "../include/algorithm/searching_algorithm.h"
#include "../include/algorithm/sorting_algorithm.h"
#include "../include/data-structure/account.h"
#include "../include/data-structure/customer.h"
#include "../include/data-structure/linked_list.h"
#include "../include/data-structure/qeuee.h"
#include "../include/data-structure/stack.h"
#include "../include/data-structure/transaction.h"

using namespace std;

int main(){
    cout<<"all below systems are called from main source"<<endl;
    cout<<"-------------------------------------------------------\n";
    search_algo();
    sort();
    acc_holder();
    linked_list();
    qeuee();
    stack();
    transaction();
    cout<<"-------------------------------------------------------\n";
    return 0;
}