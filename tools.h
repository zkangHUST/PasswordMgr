#ifndef TOOLS_H
#define TOOLS_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string getpass(const char *prompt, bool show_asterisk);
void stringSplit(const string& src, vector<string>& output);
string trim(const string& src);
#endif