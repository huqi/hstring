#ifndef KM_STRING_H
#define KM_STRING_H

#include <iostream>
using namespace std;

class KM_String
{
    friend ostream &operator<<(ostream &os, KM_String &str);
    friend istream &operator>>(istream &is, KM_String &str);

    public:
        KM_String(void);
        KM_String(const KM_String &str);
        KM_String(const char *str);
        ~KM_String(void);

        void assign(const char *str);
        void append(const char *str);
        bool compare(const char *str);
        char *c_str(void) const;
        void clear(void);
        unsigned int length(void);

        KM_String &operator+(KM_String &str);
        KM_String &operator=(KM_String &str);
        bool operator==(KM_String &str);

    private:
        char *data;
        unsigned int len;
};

#endif /* KM_STRING_H */
