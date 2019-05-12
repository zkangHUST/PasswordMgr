#ifndef MGR_H
#define MGR_H
#include "message.h"
#include "db.h"
#include "passwordlist.h"
class Mgr {
public:
    Mgr();
    void init();
    void login();
    void start();
    void exit();
private:
    void handleCmd(string cmd);
    string getCmd();
    void lsAll();
    void add();
    void help();
    // void save();
    void load();
private:
    PasswordList    record;
    Msg             msg;
    DB              db;
    bool            loginSuccess;
    const string    defaultPassword = "space";
    string          user;
    bool            ismask = true;
};
#endif