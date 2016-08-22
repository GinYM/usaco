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
	int a = 0;
	Mychange(a);
	cout << a << endl;
	return 0;
}