#include <iostream>
using namespace std;

class Account{
    protected:
        string name;
        int idNo;
        int Amount;
        int accountNo;
    public:
        Account();
        void Deposit();
        void checkBalance();
        virtual void withdraw()=0;
        void viewDetails();
};

void Account::viewDetails(){
    cout<<"Below shows  you bank details";
    cout<<"Name: "<<name<<endl;
    cout<<"ID Number: "<<idNo;
    cout<<"Balance: "<<Amount<<endl;
    cout<<"Done\n";
}

Account::Account(){
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your ID Number: ";
    cin>>idNo;
    cout<<"Please enter your opening amount: ";
    cin>>Amount;
    cout<<"Your details have been recorded! \nYour Account Number is now being processed";

}
void Account::Deposit(){
    cout<<"Please enter the amount you want to deposit: ";
    int dep;
    cin>>dep;
    while(dep<0){
        cout<<"Please enter a valid amount\n";
        cout<<"Enter amount: ";
        cin>>dep;
    }
    cout<<dep<<" Ksh has been deposited to your account\n";
    Amount+=dep;

}
void Account::checkBalance(){
    cout<<"Your account balance is: "<<Amount<<endl;
}

class CurrentAccount:public Account{
    private:
        int overdraft=2000;
    public:
        void withdraw(){
            cout<<"Please enter the amount you want to withdraw: ";
            int withd;
            cin>>withd;
            while (Amount+overdraft<withd || withd < 0)
            {
                cout<<"Please try a lower amount\n";
                cout<<"Enter amount: ";
                cin>>withd;

            }
            cout<<"Mount withdrawn successfully\\n";
            
        }
        
};


class Saving:public Account{
    public:
        void withdraw(){
            cout<<"Please enter the amount you want to withdraw: ";
            int withd;
            cin>>withd;
            while (Amount<withd)
            {
                cout<<"Please try a lower amount\n";
                cout<<"Enter amount: ";
                cin>>withd;

            }
            cout<<"Mount withdrawn successfully\n";
            
        }
};

int main(){
    while(true){
    cout<<"What kind of account do you want to create?\n(Select 1 or 2 for:)\n1. Savings Account.\n2. Current Account\n";
    int opt;
    cout<<"Enter option: ";
    cin>>opt;
    while(opt!=1 && opt!=2){
        cout<<"Please enter a valid option: ";
        cin>>opt;
    }
    if(opt==1){
        cout<<"Creating a savings acoount!\n";
        Saving s1;
        while(true){
            cout<<"What do you want to do?\n1. Deposit\n2. Check Account Balance.\n3. Withdraw from account.\n4. View Bank details.\n5. Quit\n";
            int opt2;
            cin>>opt2;
            switch (opt2){
                case 1:
                    s1.Deposit();
                    break;
                case 2:
                    s1.checkBalance();
                    break;
                case 3:
                    s1.withdraw();
                    break;
                case 4:
                    s1.viewDetails();
                    break;
                case 5:
                    break;
            }
    }
    }
    else if (opt==2)
    {
        cout<<"Creating a current acoount!\n";
        CurrentAccount c1;
        while(true){
            cout<<"What do you want to do?\n1. Deposit\n2. Check Account Balance.\n3. Withdraw from account.\n4. View Bank details.\n5. Quit\n";
            int opt2;
            cin>>opt2;
            switch (opt2){
                case 1:
                    c1.Deposit();
                    break;
                case 2:
                    c1.checkBalance();
                    break;
                case 3:
                    c1.withdraw();
                    break;
                case 4:
                    c1.viewDetails();
                    break;
                case 5:
                    break;
            }
    }
    }
}
    


    return 0;
}