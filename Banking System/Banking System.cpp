// Banking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataBase.h"
enum input
{
    NewAccount = 1,
    Login,
    leave = 0
};

enum AccountFunctions
{
    Deposit = 1,
    Withdraw,
    CheckBalance,
    ModifyName,
    DeleteAccount,
    Leave
};
int main()
{
    std::cout << "Hello !\n";
    DataBase db;
    std::cout << "Welcome To Our Banking Acc!" << std::endl;

    std::string input;

    while(1)
    { 

    do
    {
        system("cls");
        std::cout << "Press 1 to add account.." << std::endl;
        std::cout << "Press 2 Login .." << std::endl;

        std::cin >> input;
        switch (std::stoi(input))
        {
        case input::NewAccount :
        {
            std::string name;
            std::string number;
            std::string password;
            int balance = 0;
            system("cls");
            std::cout << "Enter Account Name.." << std::endl;
            std::cin >> name;
            std::cout << "Enter Number.." << std::endl;
            std::cin >> number;
            std::cout << "Enter Password.." << std::endl;
            std::cin >> password;
            std::cout << "Enter Balance.." << std::endl;
            std::cin >> balance;
            db.AddAccount(name, number, password, balance);
            std::cout << "Added!.." << std::endl;
            getchar();
            getchar();

            system("cls");
            input = std::to_string( input::leave );
            break;
        }

        case input::Login :
        {
            system("cls");
            std::string accNumber;
            std::string pass;
            std::cout << "Enter Acc number.." << std::endl;
            std::cin >> accNumber;
            std::cout << "Enter password.. " << std::endl;
            std::cin >> pass;
            LoginDataOut log = db.Login(accNumber, pass);

            switch (log.statues)
            {
            case LoginStatus::WrongNumber:
                std::cout << "You entered Wrong Account Number.." << std::endl;
                getchar();
                getchar();
                break;
            case LoginStatus::WrongPassword:
                std::cout << " You entered Wrong Password..." << std::endl;
                getchar();
                getchar();
                break;
            case LoginStatus::Success :
            {

                std::string input2;

                do
                {

                system("cls");
                std::cout << "Press 1 to  Deposit Money   " << std::endl;
                std::cout << "Press 2 to Withdraw Money " << std::endl;
                std::cout << "Press 3 to Check balance  " << std::endl;
                std::cout << "Press 4 to Modify Account  " << std::endl;
                std::cout << "Press 6 to Log out" << std::endl;
                
                    std::cin >> input2;
                    switch (std::stoi(input2))
                    {
                    case AccountFunctions::Withdraw:
                    {
                        int cash_out;
                        system("cls");
                        std::cout << "Enter Amount to withdraw..." << std::endl;
                        std::cin >> cash_out;
                        if (db.accounts[log.accountIndex]->withdraw(cash_out))
                        {
                            std::cout << "Success!.." << std::endl;
                        }
                        else
                        {
                            std::cout << "Insuffecient Funds" << std::endl;
                        }
                        getchar();
                        getchar();

                        break;
                    }
                    case AccountFunctions::Deposit:
                    {
                        system("cls");
                        int cash;
                        std::cout << "Enter Ammount of $ .. " << std::endl;
                        std::cin >> cash;
                        db.accounts[log.accountIndex]->deposit(cash);
                        std::cout << " Deposited.. " << std::endl;
                        getchar();
                        getchar();
                        break;
                    }
                    case AccountFunctions::CheckBalance:
                    {
                        system("cls");
                        std::cout << "Your Balance is  " << db.accounts[log.accountIndex]->GetBalance();
                        std::cout << " $ " << std::endl;
                        getchar();
                        getchar();
                        break;
                    }
                    case AccountFunctions::ModifyName:
                    {
                        std::string name;
                        std::cout << " Enter The New Name... " << std::endl;
                        std::cin >> name;
                        db.accounts[log.accountIndex]->SetName(name);
                        std::cout << " Saved.. " << std::endl;
                        getchar();
                        getchar();
                        break;
                    }
                    break;
                    // case AccountFunctions::DeleteAccount:

                    case AccountFunctions::Leave:
                        input2 = std::to_string(AccountFunctions::Leave);
                        break;
                    }


                } while ((std::stoi(input2)) != AccountFunctions::Leave);
                break;
            }
            }
            break;
        }

        }
    } while (std::stoi(input) != input::leave);

    }
    system("pause");
}

