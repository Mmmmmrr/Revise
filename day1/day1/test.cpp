//连续最大整数和
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int sum = v[0];
	int MaxSum = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (sum > 0)
			sum += v[i];
		else
			sum = v[i];
		if (MaxSum < sum)
			MaxSum = sum;

	}
	cout << MaxSum << endl;
	return 0;
}

//统计回文
#include <iostream>
#include <string>
using namespace std;
bool IsHW(string s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] == s[end])
		{
			++begin;
			--end;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int count = 0;
	//插入
	for (int i = 0; i <= s1.size(); i++)
	{
		string str = s1;
		str.insert(i, s2);
		if (IsHW(str))
			count++;

	}
	cout << count << endl;
	return 0;
}



//不要二
#include<iostream> 
#include<vector>
using namespace std; 
int main()
{
	int w,h,res = 0;
	cin >> w >> h; 
	vector<vector<int>> a; 
	a.resize(w); 
	for(auto& e : a) 
		e.resize(h, 1);
	for(int i=0;i<w;i++) 
	{
		for(int j=0;j<h;j++)
		{
			if(a[i][j]==1)
			{
				res++; // 标记不能放蛋糕的位置 
				if((i+2)<w) 
					a[i+2][j] = 0;
				if((j+2)<h)
					a[i][j+2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}


//字符串转为整数
class Solution {
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0; 
		int symbol = 1;
		if (str[0] == '-') //处理负号 
		{
			symbol = -1;
			str[0] = '0'; //这里是字符'0',不是0 
		}
		else if(str[0] == '+') //处理正号 
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0; 
		for(int i=0;i<str.size();++i) 
		{
			if(str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break; 
			}
			sum = sum *10 + str[i] - '0'; 
		}
		return symbol * sum; 
	}
};


//Fibonacci数
#include <iostream> 
#include <algorithm>
using namespace std; 
int main()
{
	int N, f, l = 0,r = 0,f0 = 0,f1 = 1;
	cin >> N;
	while(1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f; //找到比N小且距离N最近的数，求出距离 
		if(f < N) 
			l = N-f;
		else
		{
			//找到比N大且距离N最近的数，求出距离 
			r = f - N;
			break;
		}
	} //取最小距离 
	cout << min(l,r) << endl;
	return 0;
}


//判断括号合法性
#include <iostream>
#include <stack>
using namespace std;
class Parenthesis {
public: 
	bool chkParenthesis(string A, int n) 
	{
		// write code here 
		stack<char> sc; 
		for (auto ele : A)
		{
			switch (ele) 
			{
			case '(':	
				sc.push(ele); 
				break;
			case ')':{
						 if (sc.empty() || sc.top() != '(')
							 return false; 
						 else
							 sc.pop();
			}
				break; 
			default:
				return false;
			}
		}
		return true;
	}
};