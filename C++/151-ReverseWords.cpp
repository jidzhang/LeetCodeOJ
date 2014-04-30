#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <cstdlib>
#include <cstring>

class Solution {
public:
    void reverseWords1(std::string & s)
    {
    	std::string wide = s;
        std::vector<std::string> v = split<std::string>(wide, " ");
        int count = v.size();
        wide.clear();
        for (int i=0; i<count-1; ++i)
            wide += v[count -1 -i] + " ";
        if (count > 0)
        	wide += v[0];
		s = wide;
    }
   	void reverseWords2(std::string & s)
	{
		std::string rs;
		for (int i = s.size()-1; i >= 0; )
		{
			while (i >= 0 && s[i] == ' ') i--;
			if (i < 0) break;
			if (!rs.empty()) rs.push_back(' ');
			std::string t;
			//ugly
			while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);
			std::reverse(t.begin(), t.end());
			rs.append(t);
		}
		s = rs;
	}
private:
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
};


int main()
{
    Solution sol;
    std::string s = "A D E\t\tFF  ";
    std::cout << s << std::endl;
    sol.reverseWords2(s);
    std::cout << s << std::endl;
}

