#ifndef TOOLS_H
#define TOOLS_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#if defined(_WIN32) || defined(WIN32)
#include <conio.h>
string getpass(const char *prompt, bool show_asterisk);
#elif defined(__unix__)
#include<unistd.h>
char *getpass(const char *prompt);
#endif
void stringSplit(const string& src, vector<string>& output);
string trim(const string& src);
#endif