#include <cstring>
#include <iostream>

class String {
private:
    char* str;
    int len;
public:
    String(const char* s) {
        len = static_cast<int>(std::strlen(s));
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }

    char& operator[](int index) {
        if (index >= 0 && index < len)
            return str[index];
        static char dummy = ' ';
        return dummy;
    }

    int operator()(char c) {
        for (int i = 0; i < len; i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }

    operator int() const {
        return len;
    }

    ~String() {
        delete[] str;
    }
};

int main() {
    String myString("Hello!");

    char character = myString[5];
    std::cout << "Character at index 5: " << character << std::endl;

    int index = myString('W');
    std::cout << "Index of 'W': " << index << std::endl;

    int length = myString;
    std::cout << "Length of the string: " << length << std::endl;

    return 0;
}
