#pragma once 
#include<cstring>
#include <iostream>
#include <assert.h>
#include <ostream>
#include <algorithm>
#include <utility>

using std::ostream;
namespace wkn
{

    class string
    {
        friend ostream& operator<< (ostream& out,const string& s);
        public:
            string(const char* s = "")
                :_capacity(strlen(s))
                 ,_size(_capacity)
            {
                _str = new char[_capacity + 1];
                strcpy(_str,s);
            }

            string(const string& s)
            {
                _str = new char[s.size() + 1];
                strcpy(_str,s._str);
                _size =s._size;
                _capacity = _size;
            }

            ~string()
            {
                delete[] _str;
                _capacity = _size = 0;
            }

            //赋值的现代写法
            string& operator=(const string& s)
            {
                string tmp(s);
                std::swap(tmp._str,_str);
                _size = s._size;
                _capacity = s._capacity;
                return *this;
            }

            //string& operator =(const string& s)
            //{
            //    if(this != &s)
            //    {
            //        char* tmp = new char[s.size() + 1];
            //        strcpy(tmp,s._str);
            //        delete[]_str;
            //        _str = tmp;
            //        _capacity = _size = s._size;

            //    }
            //    return *this;
            //}

            void reserve(size_t n)
            {
                if(n > _capacity)
                {
                    char* tmp = new char[n + 1];
                    strcpy(tmp,_str);
                    delete[]  _str;
                    _str = tmp;
                    _capacity = n;
                }
            }

            void resize(size_t n,char ch = '\0')
            {
                if(n > _size)
                {
                    for(size_t i =_size;i < n;i++)
                    {
                        push_back(ch);
                    }
                }
                else
                {
                    _str[n]= '\0';
                    _size = n;
                }
                    
            }

            void push_back(char c)
            {
                //判断是否需要增容
                if(_size == _capacity)
                {
                    size_t newcapacity = _capacity == 0 ? 10 : _capacity * 2;
                    reserve(newcapacity);
                }
                _str[_size++] = c;
                _str[_size] = 0;
            }


            size_t size()const
            {
                return _size;
            }
            
        private:
            char* _str;
            size_t _capacity;
            size_t _size;
    };


    ostream& operator<<(ostream& out,const string& s)
    {
        out<<s._str;
        return out;
    }
}
