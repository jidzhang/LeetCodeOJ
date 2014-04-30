#ifndef MY_STING_IMP_HPP
#define MY_STING_IMP_HPP

namespace MyString {

template <typename T>
std::vector<T> split(const T & str, const T & delimiters)
{
	std::vector<T> v;
	int start = 0;
	int pos = str.find_first_of(delimiters, start);
	while(pos != T::npos) {
		if (pos != start)
			v.push_back(T(str, start, pos-start));
		start = pos + 1;
		pos  = str.find_first_of(delimiters, start);
	}
	if (start < str.length())
		v.push_back(T(str, start, str.length()-start));
	return v;
}

std::string ws2s(const std::wstring & ws)
{
	std::string curLocale = setlocale(LC_ALL, NULL);        // curLocale = "C";
	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	char *_Dest = new char[_Dsize];
	memset(_Dest,0,_Dsize);
	wcstombs(_Dest,_Source,_Dsize);
	std::string result = _Dest;
	delete []_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

std::wstring s2ws(const std::string & s)
{
	setlocale(LC_ALL, "chs");
	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest,_Source,_Dsize);
	std::wstring result = _Dest;
	delete []_Dest;
	setlocale(LC_ALL, "C");
	return result;
}

};

#endif //MY_STING_IMP_HPP
