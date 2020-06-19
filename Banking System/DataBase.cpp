#include "DataBase.h"

DataBase::Account::Account(std::string name_in, std::string number_in, std::string password_in, int balance_in)
    :
    name(name_in),
    number(number_in),
    password(password_in),
    balance(balance_in)
{
}

void DataBase::Account::deposit(int cash_in)
{
    balance += cash_in;
}

bool DataBase::Account::withdraw(int cash_out)
{
    if (cash_out < this->GetBalance())
    {
        balance -= cash_out;
        return true;
    }
    return false;
}

int DataBase::Account::GetBalance() const
{
    return balance;
}

void DataBase::Account::ModifyName(std::string new_name)
{
    this->SetName(new_name);
}

void DataBase::Account::SetName(const std::string& name_in)
{
    name = name_in;
}

std::string DataBase::Account::GetName() const
{
    return name;
}

void DataBase::Account::SetNumber(const std::string& number_in)
{
    number = number_in;
}

std::string DataBase::Account::GetNumber() const
{
    return number;
}

void DataBase::Account::SetPassword(const std::string& pass_in)
{
    password = pass_in;
}

bool DataBase::Account::CheckPassword(const std::string& pass_in) const
{
    return ( password == pass_in ) ;
}

DataBase::~DataBase()
{
    for (int i = 0; i < nAccount; i++)
    {
        delete accounts[i];
    }
}

void DataBase::AddAccount(std::string name_in, std::string number_in, std::string password_in, int balance_in)
{
    accounts[nAccount] = new Account(name_in, number_in, password_in, balance_in);
    nAccount++;
}

LoginDataOut DataBase::Login(const std::string& acc_number, const std::string& password_in)
    // try to implement it to return a pointer to the account directly :) 
{
    LoginDataOut loginData;
    loginData.accountIndex = GetAccount(acc_number);

    if (loginData.accountIndex == -1)
    {
        loginData.statues = LoginStatus::WrongNumber;
        return loginData;
    }

    else if (! accounts[(loginData.accountIndex)]->CheckPassword(password_in) )
    {
        loginData.statues = LoginStatus::WrongPassword;
        return loginData;
    }
    else
    {
        loginData.statues =  LoginStatus::Success;
        return loginData;
    }
    
}

int DataBase::GetAccount(const std::string& acc_number) // returns acc number  || or -1 if no account exists
{
    for (int i = 0; i < nAccount; i++)
    {
        if (acc_number == accounts[i]->GetNumber() )
        {
            return i;
        }
    }

    return -1;
}

bool DataBase::CheckPass(const std::string& password_in , int index)
{
    return accounts[index]->CheckPassword(password_in);
}

void DataBase::ViewAllAccounts() const
{
}
