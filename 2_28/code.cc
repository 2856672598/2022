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
    s1.resize(1);
    cout<<s1<<endl;
    s1.resize(10,'c');
    cout<<s1<<endl;
    string s3;
    s3.reserve(10);
    cout<< " s3 reserve = " <<s3.capacity()<<endl;
}

void text2()
{
    string s1("hello");
    s1.insert(0,"aaaaaaaa");
    cout<<s1<<endl;
    s1.insert(0,2,'w');
    for(auto e: s1)
        cout<<e<<" ";
    string s2(s1);
    auto it = s2.begin();
    while(it != s2.end())
    {
        *it += 1;
        it++;
    }
    cout<<s2<<endl;
}
void text3()
{
    string s1("hello");
    s1+=" world";
    cout<< s1<<endl;
    s1 += 'c';
    cout << s1 << endl;
    cout<<"size = "<<s1.size()<<",capacity = "<<s1.capacity()<<endl;

    s1.append(" nihao");
    s1.push_back('1');
    cout<<s1<<endl;
    s1[0] += 1;
    cout<< s1[0] <<" "<<s1[7]<<endl;

    const string s2(s1);
}

void text4()
{
    string s1("abcd");
    string s2("b");
    cout<< (s1<s2)<<endl;
    cout<<(s1 > s2)<<endl;
    cout << ( s1 <= s2 ) << endl;
    cout<<(s1>=s2)<<endl;
    string s3(s1);
    cout<< (s3 == s1)<<endl;
    cout<<(s3 <= s1)<<endl;
    cout<<(s1 != s2)<<endl;
}
void text5()
{
    string s1("hello hello");
    cout<< s1.find("hel",2)<<endl;
    cout<<s1<<endl;
    s1.erase(3,2);
    cout << s1 <<endl;
    cout<<s1.size()<<endl;
}
int main()
{
    //text1();
    //text2();
    //text3();
    //text4();
    text5();
    return 0;
}
