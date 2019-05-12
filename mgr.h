#ifndef MGR_H
#define MGR_H
#include "message.h"
#include "db.h"
#include "user.h"
#include "passwordlist.h"
class Mgr {
public:
    Mgr();
    void init();
    void start();
    void exit();
private:
    void login();
    void handleCmd(const string& cmd);
    string getCmd();

    // supported commands
    void lsAll();
    void add();
    void help();
    void load();
    void reset();
    void exportToFile(string& filename);
    bool checkExportCmd(const string& cmd, string& filename);
    bool checkIds(const string& cmd, vector<int>& ids);
    void lsIds(vector<int>& ids);
    
private:
    PasswordList    record;
    DB              db;
    bool            loginSuccess;
    bool            ismask = true;
    User            user;
};
#endif