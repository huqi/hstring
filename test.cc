#include "hstring.h"
#include <vector>


void foo(hstring x)
{

}

void bar(const hstring &x)
{

}

hstring baz(void)
{
    hstring ret("world");
    return ret;
}

int main(int argc, char **argv)
{
    hstring s0;
    hstring s1("hello");
    hstring s2(s0);
    hstring s3 = s1;
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    hstring s4 = baz();

    cout << s4[3] << endl;
    cout << s4.length() << endl;
    cout << s4.empty() << endl;

    vector<hstring> svec;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(baz());
    svec.push_back("good job");

    return 0;
}
