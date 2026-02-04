#include <iostream>
#include <fstream>

using namespace std;

class FileDemo{
    public:
        void fileOutput(){
            ofstream myfile;
            myfile.open("myfile.txt", ios::app);
            string text;
            cout<<"Type a sentence and press enter at the end : ";
            getline(cin,text);
            myfile<<text;
            // myfile<<"Welcome to file output.\n";
            myfile.close();
            // cout<<"Writing to the file has ended\n";


        }
	void fileReader(){
	    ifstream content;
	    string text;
	    content.open("myfile.txt");
	    while(content>>text){
		
		cout<<text<<endl;
	    }
	content.close();

	}
};

int main(){
    // cout<<"Welcme to file output!!\n";
    FileDemo fd;
    // fd.fileOutput();
    fd.fileReader();
    return 0;
}
