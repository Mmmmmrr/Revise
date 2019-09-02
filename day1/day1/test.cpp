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


//两种排序方法
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool DicSort(vector<string> s)
{
	for (int i = 0; i < s.size() - 1; ++i)
	{
		if (s[i] > s[i + 1])
			return false;
	}
	return true;
}
bool LenSort(vector<string> s)
{
	for (int i = 0; i < s.size() - 1; ++i)
	{
		if (s[i].length() > s[i + 1].length())
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	vector<string> s;
	s.resize(n);
	for (auto& str : s)
	{
		cin >> str;
	}
	if (DicSort(s) && LenSort(s))
		cout << "both" << endl;
	else if (DicSort(s))
		cout << "lexicographically" << endl;
	else if (LenSort(s))
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}


//最小公倍数
#include <iostream>
using namespace std;
int GYS(int& a, int& b)
{
	while (int c = a%b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	int A, B;
	cin >> A >> B;
	int C = A*B;
	cout << C / GYS(A, B) << endl;

	return 0;
}


//加法
class UnusualAdd 
{
public: 
	int addAB(int A, int B)
{
			int sum = 0, carry = 0; 
			while (B != 0)
			{
				//对应位的和 
				sum = A^B;
				//对应位和的进位，既然是进位，就要整体左移一位 
				carry = (A&B)<<1; 
				A=sum;
				B=carry; 
			}
			return sum;
	}
};


//求路径总数
#include<iostream> 
using namespace std; 
int pathNum(int n,int m) 
{
	if(n > 1 && m > 1) 
		//b情况，递归
		return pathNum(n-1,m) + pathNum(n,m-1); 
	else if(((n >= 1)&&(m == 1))||((n == 1)&&(m >= 1)))
		// a情况，终止条件 
		return n + m; else
		//格子为0时， 路径为0 
		return 0; 
}
int main() 
{
	int n,m; 
	while(cin>>n>>m) 
	{
		cout<<pathNum(n,m)<<endl;
	}
	return 0;
}



//最近公共祖先
class LCA 
{
public:
	int getLCA(int a, int b) 
	{
		while (a != b)
		{
			if (a > b)
				a /= 2; 
			else
				b /= 2;
		} 
		return a;
	}
};


//最大bit数
#include<iostream> 
#include<string> 
#include<algorithm>
using namespace std;
int main() 
{
	int n; 
	while (cin >> n)
	{
		int count = 0, maxCount = 0; 
		// n右移32次就变为0
		while (n) 
		{ 
			//获取当前位的二进制值 
			if (n & 1) 
			{
				//如果1的值连续，计数累加，并且跟新最大计数
				++count; 
				maxCount = max(count, maxCount); 
			}
			else
			{
				//如果1的值不连续，重新累加
				count = 0;
			}
			//右移一次，为获取下一位二进制值做准备 
			n = n >> 1; 
		}
		cout << maxCount << endl;
	}
	return 0;
}


//井字棋
class Board {
public: 
	bool checkWon(vector<vector<int> > board)
	{
		int row = board.size(); 
		//检查每一行的和是是否等于row 
		int i,j,sum;
		for(i=0;i<row;i++) 
		{
			sum = 0; 
			for(j=0;j<row;j++)
			{
				sum += board[i][j]; 
			}
			if(sum==row)
				return true; 
		}
		//检查每一列的和是是否等于row 
		for(i=0;i<row;i++)
		{
			sum = 0;
			for(j=0;j<row;j++)
			{
				sum += board[j][i]; 
			}
			if(sum==row)
				return true; 
		}
		//检查主对角线的和是是否等于row 
		sum = 0;
		for(i = 0; i<row; i++)
		{
			sum += board[i][i];
		}
		if(sum == row)
			return true;
		//检查副对角线的和是是否等于row 
		sum = 0;
		for(i=0;i<row;i++)
		{
			sum += board[i][row-i-1];
		}
		if(sum==row)
			return true; 
		return false; 
	}
};
