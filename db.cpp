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
    "id int primary key,"
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

int DB::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}