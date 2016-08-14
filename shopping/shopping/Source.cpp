/*
ID:jinyimi1
TASK:shopping
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int s;
int b;

struct the_offer
{
	int num;
	int money;
	int code[5];
	int num_pro[5];
}offer[100];

struct sto
{
	int money;
	int code;
	int num;
}store[10];

int transfer[1000];

int dp[6][6][6][6][6];

int num_all[6];
int money_all[6];

void solve()
{
	int index_all[6];
	int tmp[5];
	int mCode = 0;


	for (index_all[0] = 0; index_all[0] <= num_all[0]; index_all[0]++)
	{
		for (index_all[1] = 0; index_all[1] <= num_all[1]; index_all[1]++)
		{
			for (index_all[2] = 0; index_all[2] <= num_all[2]; index_all[2]++)
			{
				for (index_all[3] = 0; index_all[3] <= num_all[3]; index_all[3]++)
				{
					for (index_all[4] = 0; index_all[4] <= num_all[4]; index_all[4]++)
					{
						if (s == 0)
						{
							tmp[0] = index_all[0];
							tmp[1] = index_all[1];
							tmp[2] = index_all[2];
							tmp[3] = index_all[3];
							tmp[4] = index_all[4];
							for (int k = 0; k < b; k++)
							{
								mCode = transfer[store[k].code];
								if (tmp[mCode] >= 1)
								{
									//	cout << mCode << endl;
									tmp[mCode]--;
									if (dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] != 0)
									{
										if (dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] != 0 && dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + store[k].money < dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]])
											dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] = dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + store[k].money;


									}
									else
									{
										dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] = dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + store[k].money;
									}
									break;
								}
							}
						}


						for (int i = 0; i < s; i++)
						{
							if (index_all[0] + index_all[1] + index_all[2] + index_all[3] + index_all[4] == 0)
							{
								continue;
							}

							bool isTrue = true;
							tmp[0] = index_all[0];
							tmp[1] = index_all[1];
							tmp[2] = index_all[2];
							tmp[3] = index_all[3];
							tmp[4] = index_all[4];
							//cout << offer[i].num << endl;

							if (offer[i].num == 0)
							{
								//cout << "sdfwehere" << endl;
								isTrue = false;
							}

							for (int j = 0; j < offer[i].num; j++)
							{
								mCode = transfer[offer[i].code[j]];
								//cout << index_all[mCode] << endl;
								tmp[mCode] -= offer[i].num_pro[j];
								if (tmp[mCode] < 0)
								{
									


									isTrue = false;
									break;
								}
								/*
								if (index_all[0] == 1 && index_all[1] == 1)
								{
									cout << "j: " << j << endl;
									cout << offer[i].num_pro[j]<<endl;
									cout << index_all[0] << " " << index_all[1] << " " << index_all[2] << " " << index_all[3] << " " << index_all[4] << " " << dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] << endl;
									cout << tmp[0] << " " << tmp[1] << endl;
								}
								*/
							}
							if (isTrue == true)
							{
								//cout << "here" << endl;

								//cout << index_all[0] << " " << index_all[1] << " " << index_all[2] << " " << index_all[3] << " " << index_all[4] << " " << dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] << endl;



								
									if (index_all[0] == 0 && index_all[1] == 0 && index_all[2] == 0 && index_all[3] == 2 && index_all[4] == 0)
									{
										
										//cout << "here" << endl;
									}


									
								


									if (dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] != 0 && dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + offer[i].money < dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]])
									{
										dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] = dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + offer[i].money;
									}
									else
									{
										if (dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] == 0)
										{
											dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] = dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + offer[i].money;
										}
									}
								
							}
							else
							{
								
									//cout << "here" << endl;
									//cout << index_all[0] << " " << index_all[1] << " " << index_all[2] << " " << index_all[3] << " " << index_all[4] << " " << dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] << endl;
									tmp[0] = index_all[0];
									tmp[1] = index_all[1];
									tmp[2] = index_all[2];
									tmp[3] = index_all[3];
									tmp[4] = index_all[4];
									for (int k = 0; k < b; k++)
									{
										mCode = transfer[store[k].code];
										if (tmp[mCode] >= 1)
										{
										//	cout << mCode << endl;
											tmp[mCode]--;
											if (dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] != 0)
											{
												if (dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + store[k].money < dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]])
													dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] = dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + store[k].money;
						
					
											}
											else
											{
												dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] = dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] + store[k].money;
											}
											tmp[mCode]++;
										}
									}
									//cout << index_all[0] << " " << index_all[1] << " " << index_all[2] << " " << index_all[3] << " " << index_all[4] << " " << dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] << endl;
							}
							
						}
						//cout << index_all[0] << " " << index_all[1] << " " << index_all[2] << " " << index_all[3] << " " << index_all[4] << " " << dp[index_all[0]][index_all[1]][index_all[2]][index_all[3]][index_all[4]] << endl;
					}
				}
			}
		}
	}

	//cout << dp[num_all[0]][num_all[1]][num_all[2]][num_all[3]][num_all[4]] << endl;
}


int main()
{
	ifstream input("shopping.in");
	ofstream output("shopping.out");

	for (int i = 0; i < 1000; i++)
	{
		transfer[i] = -1;
	}

	int n;
	input >> s;
	int tmp = -1;
	for (int i = 0; i < s; i++)
	{
		input >> n;
		offer[i].num = n;
		for (int j = 0; j < n;j++)
		{
			input >> offer[i].code[j] >> offer[i].num_pro[j];
			
		}
		input >> offer[i].money;
	}

	input >> b;
	for (int i = 0; i < b; i++)
	{
		input >> store[i].code >> store[i].num >> store[i].money;
		transfer[store[i].code] = i;
		//cout << transfer[store[i].code] << endl;
		num_all[transfer[store[i].code]] = store[i].num;
		money_all[transfer[store[i].code]] = store[i].money;
		switch (transfer[store[i].code])
		{
		case 0:
		{
			dp[1][0][0][0][0] = store[i].money;
			break;
		}
		case 1:
		{
			dp[0][1][0][0][0] = store[i].money;
			break;
		}
		case 2:
		{
			dp[0][0][1][0][0] = store[i].money;
			break;
		}
		case 3:
		{
			dp[0][0][0][1][0] = store[i].money;
			break;
		}
		case 4:
		{
			dp[0][0][0][0][1] = store[i].money;
			break;
		}
		}
	}

	
	solve();

	output << dp[num_all[0]][num_all[1]][num_all[2]][num_all[3]][num_all[4]] << endl;

	return 0;
}