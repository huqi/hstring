#include "KM_String.h"
#include <vector>


void foo(KM_String x)
{

}

void bar(const KM_String &x)
{

}

KM_String baz(void)
{
    KM_String ret("world");
    return ret;
}

int main(int argc, char **argv)
{
    KM_String s0;
    KM_String s1("hello");
    KM_String s2(s0);
    KM_String s3 = s1;
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    KM_String s4 = baz();

    vector<KM_String> svec;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(baz());
    svec.push_back("good job");

    return 0;
}
