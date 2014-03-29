#include <string.h>
#include "hstring.h"

hstring::hstring(void)
            : data (new char [1])
{
    *data = '\0';
    len = 0;
}

hstring::hstring(const hstring &str)
    : data (new char [1]), len(0)
{
    assign(str.c_str());
}

hstring::hstring(const char *str)
    : data (new char [strlen(str) + 1]), len(0)
{
    strcpy(data, str);
    len = strlen(data);
}

hstring::~hstring(void)
{
    delete [] data;
    len = 0;
}

void hstring::clear(void)
{
    delete [] data;
    data = new char[1];
    len = 0;
}

void hstring::assign(const char *str)
{
    if (str == NULL)
    {
        clear();
    }
    else
    {
        delete [] data;
        data = new char [strlen(str) + 1];
        strcpy(data, str);
        len = strlen(str);
    }
}

void hstring::append(const char *str)
{
    if (str == NULL)
        return ;

    char *temp = data;
    data = new char [len + strlen(str) + 1];
    strcpy(data, temp);
    strcat(data, str);

    delete [] temp;
}

bool hstring::compare(const char *str)
{
    if (strcmp(data, str) == 0)
        return true;

    return false;
}

char *hstring::c_str(void) const
{
    return data;
}

unsigned int hstring::length(void)
{
    return len;
}

hstring &hstring::operator+(hstring &str)
{
    append(str.c_str());
    return *this;
}

hstring &hstring::operator=(hstring &str)
{
    assign(str.c_str());
    return *this;
}

bool hstring::operator==(hstring &str)
{
    return compare(str.c_str());
}

ostream &operator<<(ostream &os, hstring &str)
{
    return os << str.data;
}

istream &operator>>(istream &is, hstring &str)
{
    char temp[2048] = {0};

    is.get(temp, 2048);
    str.assign(temp);

    return is;
}
