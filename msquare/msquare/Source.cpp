/*
ID:jinyimi1
LANG:C++
TASK:msquare
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

int initial[8] = {1,2,3,4,5,6,7,8};
int store[8];


int index = -1;



map<int, bool> m_check;


int result[40321];
int index_result = -1;

int show_result[40321];
char store_result[40321];
int index_store = 1;
int m_set[40321];
char final_result[40321];
int result_index = -1;

struct Node
{
	int arr[8];
	int level = 0;
	int index = 0;
	Node* next = NULL;
};

bool isSame(int*a1, int*a2)
{
	for (int i = 0; i < 8; i++)
	{
		if (a1[i] != a2[i])
		{
			return false;
		}
	}
	return true;
}

bool ifHas(int *tmp)
{
	int num = 0;
	int mag = 1;
	for (int i = 7; i >= 0; i--)
	{
		num += tmp[i] * mag;
		mag *= 10;
	}
	if (m_check[num] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

struct listist
{
	Node *head = NULL;
	Node *tail = NULL;
};

listist *MyList = new listist;

void insert(int tmp[8],int level,int index)
{
	if (MyList->head == NULL)
	{
		MyList->head = new Node();
		for (int i = 0; i < 8; i++)
		{
			MyList->head->arr[i] = tmp[i];
		}
		MyList->head->index = index;
		MyList->head->level = level;
		MyList->tail = MyList->head;
	}
	else
	{
		MyList->tail->next = new Node();
		for (int i = 0; i < 8; i++)
		{
			MyList->tail->next->arr[i] = tmp[i];
		}
		MyList->tail->next->index = index;
		MyList->tail->next->level = level;
		MyList->tail = MyList->tail->next;
	}
}

Node* My_del()
{
	Node* tmp = MyList->head;
	if (MyList->head == NULL)
	{
		MyList->head = NULL;
	}
	else
	{
		MyList->head = MyList->head->next;
	}
	return tmp;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void A(int*initial)
{
	for (int i = 0; i <= 3; i++)
	{
		swap(initial[i], initial[7 - i]);
	}
}

void A_r(int *initial)
{
	A(initial);
}

void C(int *initial)
{
	int s1, s2, s3, s4;
	s1 = initial[1];
	s2 = initial[2];
	s3 = initial[5];
	s4 = initial[6];
	initial[1] = s4;
	initial[2] = s1;
	initial[5] = s2;
	initial[6] = s3;
}

void C_r(int *initial)
{
	int s1, s2, s3, s4;
	s1 = initial[1];
	s2 = initial[2];
	s3 = initial[5];
	s4 = initial[6];
	initial[1] = s2;
	initial[2] = s3;
	initial[5] = s4;
	initial[6] = s1;
}

void B(int *initial)
{
	int t1, t2;
	t1 = initial[3];
	t2 = initial[4];
	for (int i= 3; i >= 1; i--)
	{
		initial[i] = initial[i - 1];
		initial[7 - i] = initial[7 - (i - 1)];
	}
	initial[0] = t1;
	initial[7] = t2;
}

void B_r(int *initial)
{
	int t1, t2;
	t1 = initial[0];
	t2 = initial[7];
	for (int i = 0; i <= 2; i++)
	{
		initial[i] = initial[i + 1];
		initial[7 - i] = initial[7 - (i + 1)];
	}
	initial[3] = t1;
	initial[4] = t2;
}

bool check(int *tmp)
{
	for (int i = 0; i < 8; i++)
	{
		if (tmp[i] != store[i])
		{
			return false;
		}
	}
	return true;
	
}

void insert_r(int*tmp)
{
	++index;
	int num = 0;
	int mag = 1;
	for (int i = 7; i >= 0; i--)
	{
		num += tmp[i]*mag;
		mag *= 10;
	}
	//cout << num << endl;
	m_check[num] = 1;
}

void show(int *tmp)
{
	for (int i = 0; i < 8; i++)
	{
		cout << tmp[i];
	}
	cout << endl;
}

Node* solve()
{
	insert(initial,0,index_store);
	insert_r(initial);
	int *tmp;
	Node *n_tmp;
	int m_count = 0;
	while (true)
	{
		n_tmp = My_del();
		//cout << n_tmp->level << endl;
		if (n_tmp == NULL)
		{
			break;
		}
		//cout << "hehehe" << endl;
		//show(n_tmp->arr);
		//cout << endl;
		tmp = n_tmp->arr;
		m_count++;
		if (check(tmp))
		{
			break;
		}
		else
		{
			A(tmp);
			if (ifHas(tmp) == false)
			{
				store_result[++index_store] = 'A';
				m_set[index_store] = n_tmp->index;
				insert(tmp,n_tmp->level+1,index_store);
				insert_r(tmp);
			}
			A_r(tmp);
			B(tmp);
			if (ifHas(tmp) == false)
			{
				store_result[++index_store] = 'B';
				m_set[index_store] = n_tmp->index;
				insert(tmp,n_tmp->level+1,index_store);
				insert_r(tmp);
			}
			B_r(tmp);
			C(tmp);
			if (ifHas(tmp) == false)
			{
				store_result[++index_store] = 'C';
				m_set[index_store] = n_tmp->index;
				insert(tmp, n_tmp->level + 1,index_store);
				insert_r(tmp);
			}
			
		}
	}
	return n_tmp;
}

void m_show(int index)
{
	if (m_set[index] != 0)
	{
		m_show(m_set[index]);
		final_result[++result_index] = store_result[index];
	}
	else
	{
		return;
	}
}

int main()
{
	ifstream input("msquare.in");
	ofstream output("msquare.out");

	for (int i = 0; i < 8; i++)
	{
		input >> store[i];
	}

	
	Node*tmp = solve();
	m_show(tmp->index);

	output << tmp->level << endl;
	for (int i = 0; i <= result_index; i++)
	{
		output << final_result[i];
	}
	output << endl;

	return 0;
}