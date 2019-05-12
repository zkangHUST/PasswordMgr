#ifndef DB_H
#define DB_H
#include "passworditem.h"
#include "passwordlist.h"
#include "sqlite3.h"
#include<string>
using namespace std;
class DB {
public:
    DB();
    void attachDB();
    void closeDB();
    string getCreateTableSql();
    string getInsertSql(Passworditem& it);
    void createTable();
    void insertRecord(Passworditem& it);
    string getSelectSql();
    void readToList(PasswordList& it);
private:
    static int callback(void *data, int argc, char **argv, char **azColName);
    static int callback_read(void *data, int argc, char **argv, char **azColName);
private:
    sqlite3*    db;
    string      dbName;
    string      tableName;
};
#endif