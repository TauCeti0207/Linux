#ifndef __STRING_H__
#define __STRING_H__
#include <cstring>

using namespace std;

class String
{
public:
    String(const char *cstr = 0); // 若在声明和定义间使用函数，需将默认参数放在声明中
    String(const String &str);
    String &operator=(const String &str);
    ~String();
    inline char *get_c_str() const { return m_data; }

private:
    char *m_data;
};

inline String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String::String(const char *cstr)
{
    if (cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String()
{
    delete[] m_data;
}

inline String &String::operator=(const String &str)
{
    if (this == &str)
    {
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(this->m_data, str.m_data);
    return *this;
}

inline ostream &operator<<(ostream &os, const String &str)
{
    return os << str.get_c_str();
}

#endif /* String_h */
