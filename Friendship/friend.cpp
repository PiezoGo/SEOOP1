#include <iostream>
using namespace std;


class Generous;
class Sample{
    private:
        string name;
    public:
        void test1();
        void test2(Generous k);

};
class Generous{
    private:
        int privateKey;

    public:
        Generous();
        void setKey();
        int getKey(){return privateKey;};
        friend void intruder(Generous g);
        friend Sample;
};

// Generous::Generous(){
//     Sample s;
//     s.name="KENYA";
//     cout<<"Enter your number to be your Key: ";
//     cin>>privateKey;
//     cout<<"Your Private key is captured.\n";

// }

void Generous::setKey(){
    cout<<"Enter the new value of your Key: ";
    cin>>privateKey;
    cout<<"New Key is captured!!\n"; 
}

void intruder(Generous g){
    cout<<"Initial key is "<<g.getKey()<<endl;
    cout<<"Enter a different value: ";
    int val;
    cin>>val;
    g.privateKey = val;
    cout<<"New key is "<<g.getKey()<<endl;


}



void Sample::test1(){
    Generous gen;
    cout<<"Private key is "<<gen.privateKey<<endl;
    gen.privateKey = 1234;
    cout<<"Key changed to "<<gen.getKey();


}

class Child:public Sample{
    public: 
    void trial(){
        Generous g;
        g.privateKey = 6789;

    }
};

void Sample::test2(Generous k){
    cout<<"Default key is "<<k.getKey();
    k.privateKey = 9875;
    cout<<"New Key= "<<k.getKey();


}

int main(){
    Generous demo;
    Sample sam;
    sam.test1();
    intruder(demo);
    // demo.setKey();
    // cout<<"Another Key value "<<demo.getKey();
    // return 0;
}

