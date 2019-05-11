#include "mgr.h"
#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
Mgr::Mgr()
{
    loginSuccess = false;
}
void Mgr::init()
{
    msg.showWelcomeMsg();
    string p;
    cin >> p;
    if (p == "v") {
        msg.showLoginMsg();
        loginSuccess = true;
    } else {
        msg.showLoginErrMsg();
        loginSuccess = false;
    }
    record.readFromFile();
}

void Mgr::start()
{
    if (!loginSuccess) {
        return ;
    }
    while (loginSuccess) {
        msg.showTitle();
        string cmd = getCmd();
        handleCmd(cmd);
    }
}
string Mgr::getCmd()
{
    string cmd;
    cin >> cmd;
    getchar();
    return cmd;
}


void Mgr::handleCmd(string cmd)
{
    if (cmd == "quit") {
        loginSuccess = false;
    } else if (cmd == "ls") {
        ls();
    } else if (cmd == "add") {
        add();
    } else if (cmd == "save") {
        save();

    }
}

void Mgr::exit()
{
    save();
    msg.showLogoutMsg();
}

void Mgr::ls()
{
    record.display();
}

void Mgr::add()
{
    record.add();
}

void Mgr::save()
{
    record.writeToFile();
    msg.showSaveCompleteMsg();
}