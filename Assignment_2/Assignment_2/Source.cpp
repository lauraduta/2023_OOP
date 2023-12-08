#include <iostream>
#include<cassert>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

//HOMEWORK - Implementati o clasa care sa lucreze cu siruri de caractere, asemeni clasei String din std.
/*class MyString
* {
* char* str;
* int len;
* public:
* -constructor cu 2 parametri
* -constructor de copiere
* -metode de set si get
* -deconstructor
* -supraincarcare operator =
* };
* - exemplificare in main pentru toate functionalitatile in main:
*  ~ evidentiere apel contructor cu param
*  ~ evidentiere constructor de copiere
*  ~ evidentiere operator =
*/

class MyString {
private:
    char* str;
    int len;

public:
    MyString(const char* s = "") {
        len = static_cast<int>(strlen(s));
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }

    MyString(const MyString& other) {
        len = other.len;
        str = new char[len + 1];
        strcpy_s(str, len + 1, other.str);
    }

    void setString(const char* s) {
        delete[] str;
        len = static_cast<int>(strlen(s));
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }

    const char* getString() const {
        return str;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            len = other.len;
            str = new char[len + 1];
            strcpy_s(str, len + 1, other.str);
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2 = str1;
    MyString str3;
    str3 = str1;

    cout << "str1: " << str1.getString() << endl;
    cout << "str2: " << str2.getString() << endl;
    cout << "str3: " << str3.getString() << endl;

    str1.setString("World");
    cout << "str1 after modification: " << str1.getString() << endl;

    return 0;
}