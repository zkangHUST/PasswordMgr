#include "mgr.h"
#include<string>
#include<set>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "tools.h"
#include "user.h"
using namespace std;
Mgr::Mgr()
{
    loginSuccess = false;
}
void Mgr::init()
{
    Msg::showWelcomeMsg();
    db.init();
    user.getLoginMsgFromDB();
    login();
    record.readFromDB();
}

void Mgr::start()
{
    if (!loginSuccess) {
        return ;
    }
    while (loginSuccess) {
        Msg::showTitle(user.getName());
        string cmd = getCmd();
        handleCmd(cmd);
    }
}
string Mgr::getCmd()
{
    string cmd;
    getline(cin, cmd);
    cmd = trim(cmd);
    return cmd;
}


void Mgr::handleCmd(const string& cmd)
{
    if (cmd == "quit" || cmd == "exit") {
        loginSuccess = false;
    } else if (cmd == "ls") {
        lsAll();
    } else if (cmd == "add") {
        add();
    } else if (cmd == "load") {
        load();
    } else if (cmd == "toggle mask") {
        ismask = ismask ? false:true;
    } else if (cmd == "help" || cmd == "h") {
        help();
    } else if (cmd == "reset") {
        reset();
    } else if (cmd.find("saveas") != string::npos) {
        string filename;
        if (checkExportCmd(cmd, filename)) {
            exportToFile(filename);
        }
    } else if (cmd.find("ls") != string::npos) {
        vector<int> ids;
        if (checkIds(cmd, ids)) {
            // cout << "complete" << endl;
            lsIds(ids);
        }
    }
}

void Mgr::exit()
{
    Msg::showLogoutMsg();
}

void Mgr::lsAll()
{
    record.display(ismask);
}

void Mgr::add()
{
    Passworditem it;
    it.readFromInput();
    record.addItem(it);
    it.writeToDB(); 
}

void Mgr::login()
{
    cout << "Login:";
    string userName;
    
    getline(cin, userName);
    string p =getpass("Password:", true);
    cout << user.getName() << " " << user.getLoginPassword() << endl;
    if (userName == user.getName() && p == user.getLoginPassword()) {
        Msg::showLoginMsg();
        loginSuccess = true;
    } else {
        Msg::showLoginErrMsg();
        loginSuccess = false;
    }
}

void Mgr::load()
{
    PasswordList tmp;
    tmp.readFromFile();
    tmp.writeToDB();
    cout << "load complete!" << endl;
    vector<Passworditem> it = tmp.getRecordList();
    for (vector<Passworditem>::size_type i = 0; i < it.size(); i++) {
        record.addItem(it[i]);
    }
}

void Mgr::help()
{
    Msg::showHelpMsg();
}

void Mgr::reset()
{
    string p =getpass("Old password:", true);
    if (p != user.getLoginPassword()) {
        cout << "Wrong Password!" << endl;
        return;
    }
    string newName;
    cout << "New name:";
    cin >> newName;
    string newPassword  = getpass("New password:", true);
    user.setName(newName);
    user.setLoginPassword(newPassword);
    user.writeToDB();
    cout << "Reset success!" << endl;
}

bool Mgr::checkExportCmd(const string& cmd, string& filename)
{
    vector<string> v;
    stringSplit(cmd, v);
    if (v.size() != 2 || v[0] != "saveas") {
        return false;
    }
    filename = v[1];
    return true;
}
void Mgr::exportToFile(string& filename)
{
    cout << "saving to " << filename << " ......" << endl;
    record.writeToFile(filename);
    cout << "complete!" << endl;
}

bool Mgr::checkIds(const string& cmd, vector<int>& ids)
{
    vector<string> v;
    stringSplit(cmd, v);
    if (v[0] != "ls") {
        return false;
    }
    for (vector<string>::size_type i = 1; i < v.size(); i++) {
        ids.push_back(atoi(v[i].c_str()));
    }
    // for (vector<int>::iterator it = ids.begin(); it != ids.end(); it++) {// < v.size(); i++) {
    //     // ids.push_back(atoi((*it).c_str());
    //     cout << *it << " ";
    // }
    return true;
}

void Mgr::lsIds(vector<int>& ids)
{
    int cnt = 0;
    record.showTableHead();
    // cout << ids.size() << endl;
    set<int> idSet;
    for (vector<int>::size_type i = 0; i < ids.size(); i++) {
        idSet.insert(ids[i]);
        // record[ids[i]].display(false);
        // cout << "at here" << endl;
    }
    for (set<int>::iterator it = idSet.begin(); it !=idSet.end(); it++) {
        if (*it >= 0 && *it < record.size()) {
            record[*it].display(false);
            cnt++;
        }
    }
    cout << cnt << " items listed!" << endl;
} 