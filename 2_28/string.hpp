#pragma once 
#include <cstring>
#include <iostream>
#include <assert.h>
#include <ostream>
#include <algorithm>
#include <utility>
#include <cstring>
using std::ostream;
using std::istream;
namespace wkn
{

    class string
    {
        typedef char* iterator;
        typedef const char* const_iterator;
        friend istream& operator>>(istream& _in,string& s);
        public:
            static size_t npos;
            string(const char* s = "")
                :_capacity(strlen(s))
                 ,_size(_capacity)
            {
                _str = new char[_capacity + 1];
                strcpy(_str,s);
            }

            string(const string& s)
                :_str(nullptr)
            {
                string tmp(s._str);
                Swap(tmp);
            }

            //string(const string& s)
            //{
            //    _str = new char[s.size() + 1];
            //    strcpy(_str,s._str);
            //    _size =s._size;
            //    _capacity = _size;
            //}

            ~string()
            {
                delete[] _str;
                _capacity = _size = 0;
            }

            iterator begin()
            {
                return _str;
            }

            const_iterator begin()const
            {
                return _str;
            }

            const_iterator end()const 
            {
                return _str + _size;
            }

            iterator end()
            {
                return _str + _size;
            }

            void Swap(string& s)
            {
                std::swap(_str,s._str);
                std::swap(_size,s._size);
                std::swap(_capacity,s._capacity);
            }


            //赋值的现代写法
            string& operator=(const string& s)
            {
                string tmp(s);
                Swap(tmp);
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
            
            string& insert(size_t pos,const char*s)
            {
                assert(pos<=_size);
                size_t len = strlen(s);
                if(_size + len > _capacity)
                {
                    reserve(_size + len);
                }

                size_t newend = _size + len;
                size_t end = _size + 1;
                while(end > pos)
                {
                    _str[newend] = _str[end - 1];
                    end--;
                    newend--;
                }
                memcpy(_str + pos,s,len);
                _size += len;
                return *this;
            }
            
            string& insert(size_t pos,size_t n,char c)
            {
                string tmp;
                tmp.resize(n,c);
                insert(pos,tmp._str);
                return *this;
            }

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
                    reserve(n);
                    memset(_str,ch,n - _size);
                    _size = n;
                }
                else
                {
                    _str[n]= '\0';
                    _size = n;
                }
                    
            }

            void push_back(char c)
            {
                ////判断是否需要增容
                //if(_size == _capacity)
                //{
                //    size_t newcapacity = _capacity == 0 ? 10 : _capacity * 2;
                //    reserve(newcapacity);
                //}
                //_str[_size++] = c;
                //_str[_size] = 0;
                
                insert(_size ,1, c);
            }

            string& operator+=(const char*s)
            {
                insert(_size,s);
                return *this;
            }

            string& operator+=(const char c)
            {
                insert(_size,1,c);
                return *this;
            }

            string& append(const string& s)
            {
                insert(_size,s._str);
                return *this;
            }

            string& append(const char* s)
            {
                insert(_size , s);
                return *this;
            }
            size_t size()const
            {
                return _size;
            }
           
            size_t capacity()const
            {
                return _capacity;
            }

            char& operator[](size_t pos)
            {
                assert(pos < _size && pos >= 0);
                return _str[pos];
            }

            const char& operator[](size_t pos)const
            {
                assert(pos < _size && pos >= 0);
                return _str[pos];
            }

            const char* c_str()const
            {
                return _str;
            }

            bool empty()const 
            {
                return _size == 0;
            }

            void clear()
            {
                _size = 0;
                _str[0] = 0;
            }

            bool operator<(const string& s)const
            {
                return strcmp(_str ,s._str) < 0;
            }
            bool operator<=(const string&s)const
            {
                return strcmp(_str,s._str) <= 0;
            }

            bool operator >(const string& s)const
            {
                return s < *this;
            }

            bool operator >=(const string& s)const
            {
                return s <= *this;
            }

            bool operator==(const string& s)const
            {
                return (*this > s  == false) && (*this < s ==false);
            }

            bool operator!=(const string& s)const 
            {
                return  (*this == s) == false;
            }

            size_t find(const char* s,size_t pos = 0)const 
            {
                char* p =  strstr(_str + pos,s);
                if(p != nullptr)
                    return p - _str;
                return npos;
            }

            string& erase(size_t pos = 0,size_t len = npos)
            {
                assert(pos < _size && pos >= 0);
                if(len == npos || len + pos >= _size)
                {
                    //清空
                    _str[pos] = 0;
                    _size = pos;
                }
                else 
                {
                    memmove(_str + pos,_str + pos + len, _size - pos -len);
                    _size -= len;
                    _str[_size] = 0;
                }
                return *this;
            }
        private:
            char* _str;
            size_t _capacity;
            size_t _size;
    };

    size_t string::npos = -1;
    ostream& operator<<(ostream& out,const string& s)
    {
        for(size_t i = 0;i < s.size();i++)
        {
            out<< s[i];
        }
        return out;
    }
    istream& operator>>(istream& _in,string& s)
    {
        s.resize(0);
        char ch = _in.get();
        while(ch != ' '&& ch != '\n')
        {
            s += ch;
            ch = _in.get();
        }
        return _in;
    }
}
