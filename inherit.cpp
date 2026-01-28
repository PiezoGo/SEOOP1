#include <iostream>
using namespace std;
class Person{
    protected:
        std::string name;
        std::string gender;
        int yob;
        int age;

    public:
        Person();
        Person(string,string,int);
        void viewDetails();
        int getAge();

};

Person::Person(std::string n,std::string g,int Y){
    name=n;
    gender=g;
    yob = Y;
    cout<<"This is the parameterised constr\n";
    age = 2025 - yob;
}

void Person::viewDetails(){
    cout<<"Your name is "<<name<<" \nyour age is "<<2025-yob<<" \nYour yob is "<<yob<<endl;
    

}

int Person::getAge(){
    cout<<"Please enter the current year: ";
    int cyr;
    cin>>cyr;
    int age = cyr-yob;
    return age;
}


Person::Person(){
    cout<<"Please enter your name: \n";
    cin>>name;
    cout<<"Please enter your gender: \n";
    cin>>gender;
    cout<<"Please enter your year of birth: \n";
    cin>>yob;


}

class Student:public Person{
    private:
        string regNo;
        double feeBal;
    public:
        Student();
        Student(string,string,int,string,double);
        void checkBalance();

};

void Student::checkBalance(){
    cout<<name<<"Your balance is : "<<feeBal;
}

Student::Student(){
    cout<<"Please enter your registration no: ";
    cin>>regNo;

}

Student::Student(std::string n, std::string k, int i,std::string r,double f){
    Person(n,k,i);
    feeBal =f;
    regNo=r;
}

int main(){
    Student S2("MichaelOchieng'","Male",2005,"CIT-227-033/2024",20000.00);
    // S1.viewDetails();
    S2.viewDetails();



    // while(true){
    //     cin<<"What do you want to do?\n";
    //     cin<<"1. View"        
    // }
    //Person P1,P2("Mike","Female",2005);
    //P1.viewDetails();
    return 0;
}