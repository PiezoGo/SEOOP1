y
#include <iostream>
using namespace std;
#include <fstream>

void writeFile(){
    cout<<"Okay we want to write into a file!"<<endl;
    ofstream file("text.txt", ios::app);
    //file.open();
    string text;
    cout<<"Type the sentence you want to add to the file: ";
    getline(cin,text);
    file<<text<<endl;
    file.close();
}

void readFile(){
    cout<<"Here is the output from the file: "<<endl;
    ifstream file("text.txt");
    //file.open();
    
    string sent;
    while(getline(file,sent)){
    cout<<sent<<endl;
}
   file.close();
}

int main(){
    writeFile();
readFile();
return 0;
}
