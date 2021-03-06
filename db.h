#ifndef DB_H
#define DB_H
#include "passworditem.h"
#include "passwordlist.h"
#include "user.h"
#include "sqlite3.h"
#include<string>
using namespace std;
class DB {
public:
    DB();
    void init();
    void attachDB();
    void closeDB();
    void createTable(const string& tableName);
    void createLoginMsgTable(const string& tableName);
    void insertRecord(const Passworditem& it);
    void insertRecord(PasswordList& it);
    void updateUserMsg(User& user);
    void readToList(PasswordList& it);
    void readLoginMsg(User& it);
    void dropTable(const string& tablename);
    void deletAllRecords(const string& tablename);
    void deletRecord(const string& tablename, int id);
private:
    string getCreateTableSql(const string& tableName);
    string getInsertSql(const Passworditem& it, const string& tableName = "passwordTable");
    string getSelectSql(const string& tableName = "passwordTable");
    // callback
    static int callback(void *data, int argc, char **argv, char **azColName);
    static int onReadToList(void *data, int argc, char **argv, char **azColName);
    static int onReadLoginMsg(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3*    db;
    string      dbName;
};
#endif