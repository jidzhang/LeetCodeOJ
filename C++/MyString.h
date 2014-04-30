#ifndef MY_STRING_H
#define MY_STRING_H

namespace MyString {

//split string
template <typename T>
std::vector<T> split(const T & str, const T & delimiters);
//wstring to string
std::string ws2s(const std::wstring & ws);
//string to wstring
std::wstring s2ws(const std::string & s);

};

#include "MyString_imp.hpp"

#endif	//MY_STRING_H
