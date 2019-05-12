#include "db.h"
#include<cstdio>
#include "sqlite3.h"
#include<iostream>
#include "user.h"
using namespace std;
DB::DB():dbName("test.db"), db(NULL)
{
}

void DB::init()
{
   attachDB();
   createTable("passwordTable"); 
   createLoginMsgTable("loginmsg");
}
void DB::attachDB()
{
    int rc;
    rc = sqlite3_open(dbName.c_str(), &db);
    if (rc) {
        cout << "Cann't open " << dbName << ":" << sqlite3_errmsg(db) <<endl;
    } 
}

void DB::closeDB()
{
    int rc;
    rc = sqlite3_close(db);
}

void DB::createTable(const string& tableName)
{
    char *zErrMsg = 0;
    string cmd = getCreateTableSql(tableName);
    int rc;
    rc = sqlite3_exec(db, cmd.c_str(), callback, 0, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    }
}

string DB::getCreateTableSql(const string& tableName)
{   
    string sql;
    sql += "create table if not exists ";
    sql += tableName;
    sql += "("
    "id integer primary key autoincrement,"
    "addr text,"
    "username text,"
    "password text,"
    "remark text"
    ");";

    return sql;
}


void DB::createLoginMsgTable(const string& tableName)
{
    string sql;
    int rc;
    char *zErrMsg = 0;

    sql += "create table if not exists ";
    sql += tableName;
    sql += "("
    "id integer primary key autoincrement,"
    "username text,"
    "loginpassword text"
    ");";
  
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    }
}

string DB::getInsertSql(const Passworditem& it, const string& tableName)
{
    string sql;
    sql += "insert into ";
    sql += tableName;
    sql += " (addr, username, password, remark) values(";
    sql += "\"";
    sql += it.addr ;
    sql += "\"";
    sql +=  ",";
    sql += "\"";
    sql += it.username;
    sql += "\"";
    sql +=  ",";
    sql += "\"";
    sql += it.password;
    sql += "\"";
    sql +=  ",";
    sql += "\"";
    sql += it.remark;
    sql += "\"";
    sql +=  ")";
    cout << sql << endl;
    return sql;
}

void DB::insertRecord(const Passworditem& it)
{
    char *zErrMsg = 0;
    string cmd = getInsertSql(it);
    int rc;
    rc = sqlite3_exec(db, cmd.c_str(), callback, 0, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    }
}

void DB::insertRecord(PasswordList& list)
{
    char *zErrMsg = 0;
    string cmd;// = getInsertSql(it);
    int rc;
    vector<Passworditem> vec = list.getRecordList();
    for (vector<Passworditem>::iterator it = vec.begin(); it != vec.end(); it++) {
        cmd = getInsertSql(*it);
        rc = sqlite3_exec(db, cmd.c_str(), callback, 0, &zErrMsg);
        if (rc) {
            cout << sqlite3_errmsg(db);
        }
    }
}


int DB::onReadToList(void *data, int argc, char **argv, char **azColName)
{
    PasswordList* it = (PasswordList*)data;
    Passworditem tmp;
    tmp.id = (int)atoi(argv[0]);
    tmp.addr = argv[1];
    tmp.username = argv[2];
    tmp.password = argv[3];
    tmp.remark = argv[4];
    it->addItem(tmp);
    return 0;
}

int DB::callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

    }
    printf("\n");
    return 0;
}

string DB::getSelectSql(const string& tableName)
{
    string sql ;
    sql += "select * from " ;
    sql += tableName;
    sql += ";";
    return sql;
}

void DB::readToList(PasswordList& it)
{
    char *zErrMsg = 0;
    string cmd = getSelectSql();
    int rc;
    rc = sqlite3_exec(db, cmd.c_str(), onReadToList, &it, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    } 
}

void DB::readLoginMsg(User& it)
{
    char *zErrMsg = 0;
    string sql ;
    sql += "select * from " ;
    sql += "loginmsg where id = 0";
    sql += ";";
    int rc;
    rc = sqlite3_exec(db, sql.c_str(), onReadLoginMsg, &it, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    } 
}

int DB::onReadLoginMsg(void *data, int argc, char **argv, char **azColName)
{
    User* it = (User*)data;
    it->setName(argv[1]);           // username
    it->setLoginPassword(argv[2]);  // password
    // for (int i = 0; i < argc; i++) {
    //     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

    // }
    return 0;
}

void DB::updateUserMsg(User& user)
{
    int     rc;
    char    *zErrMsg; 
    string sql = "insert or replace into ";
    sql += "loginmsg (id, username, loginpassword) values(0, \"";
    sql += user.getName();
    sql += "\", \"";
    sql += user.getLoginPassword();
    sql += "\");";
    // cout << sql << endl;
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    } 
}

