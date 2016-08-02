#include<map> 
#include<iterator> 
#include<string> 
#include<iostream> 
#include<cstring> 
using   namespace   std;
struct   itemstruct
{
	int   a;
	char   b[20];
	itemstruct(int   t, char*str)
	{
		a = t;
		strcpy(b, str);
	}
};
int   main()
{
	string a = "000";
	string b = "11";
	cout << a.size() << " " << b.size() << endl;
	return   0;
}