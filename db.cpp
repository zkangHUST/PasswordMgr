#include "db.h"
#include<cstdio>
#include "sqlite3.h"
#include<iostream>
using namespace std;
DB::DB()
{
    dbName = "test.db";
    tableName = "passwordTable";
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


string DB::getCreateTableSql()
{   
    string sql;
    sql += "create table ";
    sql += tableName;
    sql += "("
    "id integer primary key autoincrement,"
    "addr text,"
    "username text,"
    "password text,"
    "remark text"
    ");";
    cout << sql << endl;
    return sql;
}

string DB::getInsertSql(Passworditem& it)
{
    string sql;
    sql += "insert into ";
    sql += tableName;
    sql += " (addr, username, password, remark) values(";
    // sql += it.id;
    // sql += ",";
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

void DB::insertRecord(Passworditem& it)
{
    char *zErrMsg = 0;
    string cmd = getInsertSql(it);
    int rc;
    rc = sqlite3_exec(db, cmd.c_str(), callback, 0, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    }
}

void DB::createTable()
{
    char *zErrMsg = 0;
    string cmd = getCreateTableSql();
    int rc;
    rc = sqlite3_exec(db, cmd.c_str(), callback, 0, &zErrMsg);
    if (rc) {
        cout << sqlite3_errmsg(db);
    }
}

int DB::callback_read(void *data, int argc, char **argv, char **azColName)
{
    PasswordList* it = (PasswordList*)data;
    Passworditem tmp;
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

    }
    tmp.id = (int)atoi(argv[0]);
    tmp.addr = argv[1];
    tmp.username = argv[2];
    tmp.password = argv[3];
    tmp.remark = argv[4];
    it->addItem(tmp);
    printf("\n");
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

string DB::getSelectSql()
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
    // Passworditem it;
    string cmd = getSelectSql();
    int rc;
    rc = sqlite3_exec(db, cmd.c_str(), callback_read, &it, &zErrMsg);
    cout << "______________________" << endl;
    // cout << it.id << " " << it.addr << " " << it.username << " " << it.password << " " << it.remark << endl;
    if (rc) {
        cout << sqlite3_errmsg(db);
    } 
}