#ifndef HSTRING_H
#define HSTRING_H

#include <iostream>
using namespace std;

class hstring
{
    friend ostream &operator<<(ostream &os, hstring &str);
    friend istream &operator>>(istream &is, hstring &str);

    public:
        hstring(void);
        hstring(const hstring &str);
        hstring(const char *str);
        ~hstring(void);

        void assign(const char *str);
        void append(const char *str);
        bool compare(const char *str);
        char *c_str(void) const;
        void clear(void);
        unsigned int length(void);

        hstring &operator+(hstring &str);
        hstring &operator=(hstring &str);
        bool operator==(hstring &str);

    private:
        char *data;
        unsigned int len;
};

#endif /* HSTRING_H */
