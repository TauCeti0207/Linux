class string
{
public:
    string(const char *p = 0);
    string(const string &s);                 // 拷贝构造函数
    string &operator=(const string &x);      // 拷贝复制函数
    ~string();                               // 析构函数，离开作用域时被调用
    char *get_c_char() const { return ptr; } // 方便丢进cout
private:
    char *ptr;
};

inline string::string(const char *p = 0)
{
    if (p)
    {
        ptr = new char[strlen(p) + 1];
        strcpy(ptr, p);
    }
    else
    {
        ptr = new char[1];
        *ptr = '\0'
    }
}
inline string(const string &s)
{
    ptr = new char[strlen(s.ptr) + 1]; // 相同class的成员函数互为friend
    strcpy(ptr, s.ptr);
}

inline string &string::operator=(const string &x)
{ // 拷贝复制函数
    if (this == &x)
        return *this; // 防止自我赋值
    delete[] ptr;
    ptr = new char[strlen(x.ptr) + 1];
    strcpy(ptr, x.ptr);
    return *this;
}
inline string::~string()
{
    delete[] ptr;
}