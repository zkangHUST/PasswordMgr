#include "message.h"
#include<iostream>
using namespace std;
void Msg::showWelcomeMsg()
{
    cout << "welcome to the Password Manage System!\n";
}
void Msg::showLoginMsg()
{
    cout << "login correct!" << endl;
}

void Msg::showTitle(const string& user) const
{
    cout << "[" << user << "]$ ";
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

void Msg::showHelpMsg()
{
    cout << "usage:[help] [h] [ls] [add] [quit] [exit] [load] [toogle mask]" << endl << endl;
    cout << "  help, h      show help messages." << endl;
    cout << "  add          add a password record." << endl;
    cout << "  load         load records form a file." << endl;
    cout << "  toogle mask  show password as \"******\" or normal" << endl;
    cout << "  exit, quit   exit the program." << endl;
    cout << "  reset        reset user name and password" << endl;
    cout << endl;
}