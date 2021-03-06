#include "user.h"
#include "db.h"
#include <iostream>
using namespace std;
User::User():name("vincent"), loginPassword("space")
{

}

void User::setName(const string& m)
{
    name = m;
}
void User::setLoginPassword(const string& p)
{
    loginPassword  = p;
}

void User::getLoginMsgFromDB()
{
    DB login;
    login.attachDB();
    login.readLoginMsg(*this);
    login.closeDB();
}

void User::print()
{
    cout << name << " " << loginPassword << endl;
}

string User::getName()
{
    return name;
}

string User::getLoginPassword()
{
    return loginPassword;
}

void User::writeToDB()
{
    DB db;
    db.attachDB();
    db.updateUserMsg(*this);
    db.closeDB();
}