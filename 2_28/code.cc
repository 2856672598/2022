#include "string.hpp"
using namespace wkn;
using std::cout;
using std::endl;

void text1()
{
    string s1("hello");
    string s2;
    s2 = s1;
    s1 = s1;
    cout<<s2<<endl;
    cout<<s1<<endl;
    s1.resize(0);
    cout<<s1<<endl;
    s1.resize(10,'c');
    cout<<s1<<endl;

}

int main()
{
    text1();
    return 0;
}
