/*
ID:jinyimi1
TASK:job
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;
int n,m1,m2;

int timeA[31], timeB[31];
int A[31], B[31];
int job_a[1001], job_b[1001];

void Mysort(int*a,int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int key = a[low];
	int left = low;
	int right = high;
	while (left < right)
	{
		while (left<right && a[right]>= key)
		{
			right--;
		}
		a[left] = a[right];
		while (left	< right &&a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	Mysort(a, low, left - 1);
	Mysort(a, left + 1, high);
}

void solve()
{
	int time=0;
	int numA=0, numB=0;
	int num = n;
	int minTime = 10000;
	int left = 0;
	int result_A = 0;


	for (int i = 0; i < m1; i++ )
	{
		if (num >= 1)
		{
			num--;
			A[i] = timeA[i];
			if (A[i] < minTime)
			{
				minTime = A[i];
			}
			numA++;
		}
	}


	do
	{
		time += minTime;
		for (int i = 0; i < m1; i++)
		{
			if (A[i] != 0)
			{
				A[i] -= minTime;
				if (A[i] == 0)
				{
					left++;
					numA--;
				}
			}
		}

		for (int i = 0; i < m2; i++)
		{
			if (B[i] != 0)
			{
				B[i] -= minTime;
				if (B[i] == 0)
				{
					numB--;
				}
			}
		}



		minTime = 10000;
		for (int i = 0; i < m1; i++)
		{
			if (num >= 1 && A[i]==0)
			{
				A[i] = timeA[i];
				num--;
				numA++;
			}
			if (A[i] != 0 && A[i] < minTime)
			{
				minTime = A[i];
			}
		}

		for (int i = 0; i < m2; i++)
		{
			if (left >= 1 && B[i] == 0)
			{
				B[i] = timeB[i];
				numB++;
				left--;
			}
			if (B[i] != 0 && B[i] < minTime)
			{
				minTime = B[i];
			}
		}


		
	
		for (int i = 0; i < m2; i++)
		{
			cout << B[i] << " ";
		}
		cout << endl;

	} while (num != 0 || numA != 0 || numB != 0 || left != 0);
	cout << time << endl;
}

void show(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int get_A()
{
	int minT = 10000000;
	int minI = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		minT = 10000000;
		for (int j = 0; j < m1; j++)
		{
			if (timeA[j] + A[j] < minT)
			{
				minT = timeA[j] + A[j];
				minI = j;
			}
		}
		//cout << minT << endl;
		job_a[i] = minT;
		A[minI] = minT;
		//cout << A[minI] << endl;
	}
	//cout << "here"<<job_a[1] << endl;
	return job_a[n - 1];
}

int get_B()
{
	int minT = 10000000;
	int minI = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		minT = 10000000;
		for (int j = 0; j < m2; j++)
		{
			if (timeB[j] + B[j] < minT)
			{
				minT = timeB[j] + B[j];
				minI = j;
			}
		}
		//cout << minT << endl;
		job_b[i] = minT;
		B[minI] = minT;
		//cout << A[minI] << endl;
	}

	//int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (job_a[i] + job_b[n - 1 - i] > ans)
		{
			ans = job_a[i] + job_b[n - 1 - i];
		//	cout << job_a[0] << endl;
		}
	}
	//cout << ans << endl;
	return ans;
}

int main()
{
	ifstream input("job.in");
	ofstream output("job.out");

	input >> n>>m1>>m2;
	for (int i = 0; i < m1; i++)
	{
		input >> timeA[i];
	}
	for (int i = 0; i < m2; i++)
	{
		input >> timeB[i];
	}

	//Mysort(timeA, 0, m1 - 1);
	//Mysort(timeB, 0, m2 - 1);
	//solve();
	output<<get_A()<<" ";
	output << get_B() << endl;;
	//get_B();

	return 0;
}