#include <iostream>
#include <string>

using namespace std;

class Person{
    string name;
    int age;
    public:
        //constructor
        Person(string name,int age){
            this->name = name;
            this->age=age;
        };
    void great(){
        cout<<"hello,my name is "<<name<<endl;
    }
};

int main(){
    Person person1("samuel",20);
    person1.great();
   

    return 0;
}