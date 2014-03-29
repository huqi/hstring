#include <string.h>
#include "KM_String.h"

KM_String::KM_String(void)
            : data (new char [1])
{
    *data = '\0';
    len = 0;
}

KM_String::KM_String(const KM_String &str)
    : data (new char [1]), len(0)
{
    assign(str.c_str());
}

KM_String::KM_String(const char *str)
    : data (new char [strlen(str) + 1]), len(0)
{
    strcpy(data, str);
    len = strlen(data);
}

KM_String::~KM_String(void)
{
    delete [] data;
    len = 0;
}

void KM_String::clear(void)
{
    delete [] data;
    data = new char[1];
    len = 0;
}

void KM_String::assign(const char *str)
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

void KM_String::append(const char *str)
{
    if (str == NULL)
        return ;

    char *temp = data;
    data = new char [len + strlen(str) + 1];
    strcpy(data, temp);
    strcat(data, str);

    delete [] temp;
}

bool KM_String::compare(const char *str)
{
    if (strcmp(data, str) == 0)
        return true;

    return false;
}

char *KM_String::c_str(void) const
{
    return data;
}

unsigned int KM_String::length(void)
{
    return len;
}

KM_String &KM_String::operator+(KM_String &str)
{
    append(str.c_str());
    return *this;
}

KM_String &KM_String::operator=(KM_String &str)
{
    assign(str.c_str());
    return *this;
}

bool KM_String::operator==(KM_String &str)
{
    return compare(str.c_str());
}

ostream &operator<<(ostream &os, KM_String &str)
{
    os << str.data;
}

istream &operator>>(istream &is, KM_String &str)
{
    char temp[2048] = {0};

    is.get(temp, 2048);
    str.assign(temp);

    return is;
}
