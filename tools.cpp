#include "tools.h"
#include <cctype>
#if defined(_WIN32) || defined(WIN32)
// mask password 
string getpass(const char *prompt, bool show_asterisk=true)
{
    const char BACKSPACE = 8;
    const char RETURN = 13;

    string password;
    unsigned char ch = 0;

    cout << prompt;

    while ((ch = getch()) != RETURN) {
        if (ch == BACKSPACE) {
            if (password.length() != 0) {
                if(show_asterisk) {
                    cout <<"\b \b";
                }
                password.resize(password.length()-1);
            }
        } else if (ch == 0 || ch == 224) { // handle escape sequences
            getch(); // ignore non printable chars
            continue;
        } else {
            password += ch;
            if (show_asterisk) {
                cout <<'*';
            }
        }
    }
    cout << endl;
    return password;
}
#endif


string trim(const string& src)
{
    string ret;
    vector<string> tmp;
    stringSplit(src, tmp);
    for (vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++) {
        ret += *it;
        if (it != tmp.end() - 1) {
            ret += " ";
        }
    }
    return ret;
}

void stringSplit(const string& src, vector<string>& output)
{
    string::size_type pos1, pos2;
    pos1 = 0;
    pos2 = 0;
    while (pos2 < src.size()) {
        while (isblank(src[pos1])  && pos1 < src.size()) {
            pos1++;
        }
        pos2 = pos1;
        while (!isblank(src[pos2]) && pos2 < src.size()) {
            pos2++;
        }
        if (pos1 < pos2 && pos2 <= src.size()) {
            output.push_back(src.substr(pos1, pos2 - pos1));
        } 
        pos1 = pos2;
    }
}