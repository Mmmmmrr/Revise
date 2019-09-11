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


//密码强度
#include<iostream>
#include<string> 
using namespace std; 
int numChar(string str, int k)
{ 
	//根据ASCII码判断字母大小写 
	int small = 0; 
	int big = 0; 
	for (int i = 0; i < k; i++) 
	{
		if (str[i] >= 65 && str[i] <= 90) 
			big++; 
		else if (str[i] >= 97 && str[i] <= 122) 
			small++; 
	}
	if ((small + big) == 0)
	return 0; 
	else if (small == k || big == k) 
		return 10; 
	else if (small > 0 && big > 0)
		return 20; 
	return 0; 
}
int numNumber(string str, int k)
{ 
	//根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字
	int num = 0; 
	for (int i = 0; i < k; i++) 
	{ 
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			num++; 
	}
	if (num == 0) 
		return 0; 
	else if (num == 1)
		return 10; 
	else
		return 20;
}
int numSymbal(string str, int k) 
{ 
	int num = 0;
	for (int i = 0; i < k; i++) 
	{ 
		//除去字母，数字，其它都为符号
		if (!(str[i] >= 65 && str[i] <= 90)&& !(str[i] >= 97 && str[i] <= 122) && !(str[i] - '0' >= 0 && str[i] - '0' <= 9)) 
			num++;
	}
	if (num == 0)
		return 0; 
	else if (num == 1) 
		return 10; 
	else
		return 25;
}
int main()
{ 
	string str;
	while (cin >> str) 
	{ 
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0; 
		int k = str.size(); 
		if (k <= 4)
			sum1 = 5; 
		else if (k >= 8) 
			sum1 = 25; 
		else
			sum1 = 10;
		sum2 = numChar(str, k); 
		sum3 = numNumber(str, k);
		sum4 = numSymbal(str, k); 
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{ 
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5; 
		}
			else if (sum2 > 0 && sum3 > 0 && sum4 == 0) 
				sum5 = 2;
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80) 
			cout << "SECURE" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl; 
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50) 
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25) 
			cout << "WEAK" << endl; 
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}


//二进制插入
class BinInsert 
{ 
public: 
	int binInsert(int n, int m, int j, int i)
	{
		m <<= j; 
		return n | m;
	}
};


//查找组成一个偶数最接近的素数
#include<iostream>
#include<algorithm>
using namespace std; 
//判断素数
bool isPrime(int num) 
{
	int tmp = sqrt(num); 
	//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
	for (int i = 2; i <= tmp; i++) 
	{
		if (num %i == 0) 
			return false; 
	}
	return true; 
}
int main()
{
	int num;
	int half;
	int i; 
	while (cin >> num) 
	{ 
		half = num / 2;
		//从中间向两边找 
		for (i = half; i > 0; i--)
		{ 
			if (isPrime(i) && isPrime(num - i))
				break; 
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}


//参数解析
#include <iostream> 
#include <string>
using namespace std;
int main()
{ 
	string str; 
	while (getline(cin, str))
	{ 
		int count = 0;
		//首先计算参数数量
		for (int i = 0; i < str.size(); i++) 
		{ 
			if (str[i] == ' ') 
				count++; 
			//如果是双引号，向后遍历，直到下一个双引号结束
			if (str[i] == '"') 
			{ 
				do{i++;
				}
		while (str[i] != '"');
			}
		}
		//以空格计算个数，空格数量比参数个数少1
		cout << count + 1 << endl; 
		//用flag表示是否包含双引号，0表示有双引号
		//双引号中的空格要打印出来
		//用异或改变flag的值，两个双引号可以使flag复原
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{ 
			//有双引号，flag通过异或变为0，下一次再遇到双引号，flag置为1
			if (str[i] == '"')
				flag ^= 1; 
			//双引号和普通空格不打印
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//双引号中的空格要打印 
			if (str[i] == ' ' && (!flag)) 
				cout << str[i];
			//遇到双引号之外的空格就换行
			if (str[i] == ' ' && flag) 
				cout << endl;
		}
		cout << endl; 
	}
	return 0;
}

//最接近的数
class CloseNumber {
public:
	int Count(int x)
	{
		int count = 0;
		while (x)
		{
			if (x & 1)
				count++;
			x = x >> 1;
		}
		return count;
	}
	vector<int> getCloseNumber(int x) {
		// write code here
		vector<int> v;
		int ret = Count(x);
		int i;
		for (i = x - 1; Count(i) != ret&& i > 0; i--);
		v.push_back(i);
		for (i = x + 1; Count(i) != ret; i++);
		v.push_back(i);
		return v;
	}
};


//二进制小数
class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		string s = "0.";
		double base = 0.5;
		while (num > 0)
		{
			if (num >= base)
			{
				num -= base;
				s += "1";
			}
			else
				s += "0";
			base /= 2;
			if (s.size() > 32)
			{
				s = "Error";
				break;
			}
		}
		return s;
	}
};


//手套问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};
int main()
{
	/*int n = 4;
	vector<int> left{ 0, 7, 1, 6 };
	vector<int> right{ 1, 5, 0, 6 };*/
	int n = 0;
	cin >> n;
	vector<int> left(n);
	vector<int> right(n);
	for (int i = 0; i < n; i++)
	{
		cin >> left[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> right[i];
	}
	cout << Gloves().findMinimum(n, left, right) << endl;
	system("pause");
	return 0;
}


//杨辉三角形的变形
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; j++)
			{
				if (j == 1)
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
		int k;
		for (k = 0; k < m; k++)
		{
			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}
		if (k == m)
			cout << -1 << endl;
	}
	return 0;
}

//扑克牌大小
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int base = str.find('-');
			string str1 = str.substr(0, base);
			string str2 = str.substr(base + 1);
			int s1 = count(str1.begin(), str1.end(), ' ');
			int s2 = count(str2.begin(), str2.end(), ' ');
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			string s = "345678910JQKA2jokerJOKER";
			if (s1 == s2)
			{
				if (s.find(first1) > s.find(first2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else{
				if (s1 == 3)
					cout << str1 << endl;
				else if (s2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}