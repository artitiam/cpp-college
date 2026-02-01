#include <iostream>
#include <string>

class MyString {
private:
    std::string data;

public:
    MyString() : data("") {}

    MyString(const char* s) {
        if (s) {
            data = s;
        } else {
            data = "";
        }
    }

    MyString(const MyString& other) {
        data = other.data;
    }

    int length() {
        return data.length();
    }

    MyString concat(const MyString& other) {
        MyString res;
        res.data = data + other.data;
        return res;
    }

    int compare(const MyString& other) {
        return data.compare(other.data);
    }

    MyString insert(int pos, const MyString& str) {
        int n = data.length();
        if (pos > n) pos = n;
        MyString res;
        res.data = data;
        res.data.insert(pos, str.data);
        return res;
    }

    void print() {
        std::cout << data;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    MyString operator+(const MyString& other) {
        return concat(other);
    }

    MyString& operator+=(const MyString& other) {
        data += other.data;
        return *this;
    }

    char& operator[](int i) {
        return data[i];
    }

    const char& operator[](int i) const {
        return data[i];
    }
};

int main() {
    MyString s1("abc");
    MyString s2("def");
    MyString s3 = s1 + s2;
    s3.print();
    std::cout << std::endl;
    return 0;
}