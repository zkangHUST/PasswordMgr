#include "message.h"
#include<iostream>
using namespace std;
void Msg::showWelcomeMsg()
{
    cout << "welcome to the Password Manage System!\nplease input password:";
}
void Msg::showLoginMsg()
{
    cout << "login correct!" << endl;
}

void Msg::showTitle()
{
    cout << "[vincent]$ ";
}
void Msg::showLoginErrMsg()
{
    cout << "login incorrect!" << endl;
}

void Msg::showLogoutMsg()
{
    cout << "Bye Bye!" << endl;
}
void Msg::showSaveCompleteMsg()
{
    cout <<"save complete!" << endl;
}