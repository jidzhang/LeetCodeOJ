#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

class Solution {
public:
	int evalRPN1(vector<string> &tokens) {
		if (tokens.size() ==0 )
			return 0;

		while (tokens.size() >= 3) {
			for (int i=0; i<tokens.size(); ++i) {
				if (tokens.size() < 3)
					break;
				if (IsNum(tokens[i]) && IsNum(tokens[i+1]) && IsOprt(tokens[i+2])) {
					tokens[i] = Calc(tokens[i], tokens[i+1], tokens[i+2]);
					tokens.erase(tokens.begin()+i+2);
					tokens.erase(tokens.begin()+i+1);
					--i;
				}
			}
		}
		return atoi(tokens[0].c_str());
	}
	int evalRPN2(vector<string> &tokens) {
		if (tokens.size() ==0 )
			return 0;
		list<string> localStr(tokens.begin(), tokens.end());
		list<string>::iterator itr1;
		list<string>::iterator itr2;
		list<string>::iterator itr3;
		while (localStr.size() >= 3) {
			for (itr1=localStr.begin(); itr1!=localStr.end();) {
				if (distance(itr1, localStr.end()) < 3)
					break;
				itr2 = itr1;
				itr3 = ++itr2;
				++itr3;
				if (IsNum(*itr1) && IsNum(*itr2) && IsOprt(*itr3)) {
					*itr1 = Calc(*itr1, *itr2, *itr3);
					localStr.erase(itr3);
					localStr.erase(itr2);
				} else {
					++itr1;
				}
			}
		}
		return atoi(localStr.begin()->c_str());
	}
private:
	enum  MyOperator
	{
		plus_,
		minus_,
		multip_,
		division_
	};

	int IsOperator(const string & str)
	{
		if (str == "+")
			return plus_;
		if (str == "-")
			return minus_;
		if (str == "*")
			return multip_;
		if (str == "/")
			return division_;
		return -1;
	}
	bool IsOprt(const string & str)
	{
		return IsOperator(str) >= 0;
	}
	bool IsNum(const string & str)
	{
		return IsOperator(str) < 0;
	}
	string Calc(const string & a, const string & b, const string & opt)
	{
		int opr = IsOperator(opt);
		int ia = atoi(a.c_str());
		int ib = atoi(b.c_str());
		int ans = 0;
		if (opr == plus_)
			ans = ia + ib;
		else if (opr == minus_)
			ans = ia - ib;
		else if (opr == multip_)
			ans = ia * ib;
		else if (opr == division_)
			ans = ia / ib;
		char buffer[20];
		memset(buffer, 0, 20 * sizeof(char));
		sprintf_s(buffer, "%d", ans);
	//	itoa(ans, buffer, 10);
		string ss(buffer);
		return ss;
	}
};

//test
int main()
{
	vector<string> str;
	str.push_back("3");
	str.push_back("1");
	str.push_back("2");
	str.push_back("+");
	str.push_back("*");
	str.push_back("2");
	str.push_back("1");
	str.push_back("+");
	str.push_back("3");
	str.push_back("*");
	str.push_back("+");
	Solution sol;
	cout << sol.evalRPN(str) << endl;
}

