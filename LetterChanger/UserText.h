#pragma once
#include <string>

using namespace std;

class UserText
{
protected:
    string str;
public:
    UserText();

    friend UserText operator==(const UserText& text, const string& str);

    void StringManip();
    
    string GetStr() { return str; }
};
