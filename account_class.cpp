// Account class 
class Account
{
private:
 long accountNumber;
 string firstName;
 string lastName;
 float balance;
 static long NextAccountNumber;
public:
 Account(){}
 Account(string fname,string lname,float balance);
 long getAccNo(){return accountNumber;}
 string getFirstName(){return firstName;}
 string getLastName(){return lastName;}
 float getBalance(){return balance;}

 void Deposit(float amount);
 void Withdraw(float amount);
 static void setLastAccountNumber(long accountNumber);
 static long getLastAccountNumber();
 friend ofstream & operator<<(ofstream &ofs,Account &acc);
 friend ifstream & operator>>(ifstream &ifs,Account &acc);
 friend ostream & operator<<(ostream &os,Account &acc);
};

ccount::Account(string fname,string lname,float balance)
{
 NextAccountNumber++;
 accountNumber=NextAccountNumber;
 firstName=fname;
 lastName=lname;
 this->balance=balance;
}
void Account::Deposit(float amount)
{
 balance+=amount;
}
void Account::Withdraw(float amount)
{
 if(balance-amount<MIN_BALANCE)
 throw InsufficientFunds();
 balance-=amount;
}
void Account::setLastAccountNumber(long accountNumber)
{
 NextAccountNumber=accountNumber;
}
long Account::getLastAccountNumber()
{
 return NextAccountNumber;
}
ofstream & operator<<(ofstream &ofs,Account &acc)
{
 ofs<<acc.accountNumber<<endl;
 ofs<<acc.firstName<<endl;
 ofs<<acc.lastName<<endl;
 ofs<<acc.balance<<endl;
 return ofs;
}
ifstream & operator>>(ifstream &ifs,Account &acc)
{
 ifs>>acc.accountNumber;
 ifs>>acc.firstName;
 ifs>>acc.lastName;
 ifs>>acc.balance;
 return ifs;

}
ostream & operator<<(ostream &os,Account &acc)
{
 os<<"First Name:"<<acc.getFirstName()<<endl;
 os<<"Last Name:"<<acc.getLastName()<<endl;
 os<<"Account Number:"<<acc.getAccNo()<<endl;
 os<<"Balance:"<<acc.getBalance()<<endl;
 return os;
}