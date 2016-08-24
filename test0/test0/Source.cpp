#include <iostream>    
#include <cmath>    
#include <cstdio>    
#include <cstring>    
#include <climits>    
#include <cassert>    
#include <string>    
#include <vector>    
#include <set>    
#include <queue>    
#include <stack>    
#include <algorithm>    

using namespace std;

const int MAXN = 10;
int options[MAXN];

const int MAXOPT = 256;
bool modpurchasable[MAXOPT];

void Mychange(int &a)
{
	a = 100;
}

int main()
{
	string s1 = "abcd";
	string s2 = "abce";
	if (s1 < s2)
	{
		cout << "yes!" << endl;
	}
	return 0;
}