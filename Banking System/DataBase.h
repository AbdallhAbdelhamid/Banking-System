#pragma once

#include <string>
#include <vector>
#include <stdio.h>

enum class LoginStatus
{
	Success,
	WrongNumber,
	WrongPassword
};

struct LoginDataOut
{
	LoginStatus statues;
	int accountIndex;
};

class DataBase
{

private:

	class Account
	{
	public:
	
		Account() = default;
		Account(std::string name_in , std::string number_in , std::string password_in , int balance_in);
		
		void deposit(int cash_in);
		bool withdraw(int cash_out);
		int GetBalance()const;

		void ModifyName(std::string new_name);

		void SetName(const std::string& name_in);
		std::string GetName() const;

		void SetNumber(const std::string& number_in);
		std::string GetNumber()const;

		void SetPassword(const std::string& pass_in);
		bool CheckPassword(const std::string& pass_in) const ;
	
	private:

		std::string name;
		std::string number;
		std::string password;
		int balance = 0;

	};

public:


	~DataBase();
	void AddAccount(std::string name_in, std::string number_in, std::string password_in, int balance_in);
	LoginDataOut Login(const std::string& acc_number, const std::string& password_in);
	int GetAccount(const std::string& acc_number);
	bool CheckPass(const std::string& password_in , int index);
	void ViewAllAccounts() const;



private:
	int nAccount = 0;
	static constexpr int accNumber = 10;

	public:
		Account* accounts[accNumber];



};

