#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int sort_incres(string);
int sort_decres(string);
int max_min(int, int);
int main()
{
	string num;
	cout << "Please input the five digits number:";
	cin >> num;
	cout << "The value of MAX-MIN is " << max_min(sort_incres(num), sort_decres(num)) << "<" << sort_incres(num) << "-" << sort_decres(num) << ">" << endl;
	system("pause");
	return 0;
}
int sort_incres(string num)
{
	stringstream ss;
	int number;
	for (int i = 0; i < num.length(); i++)
	{
		for (int j = 0; j<i; j++)
		{
			if (num[i]>num[j])
				swap(num[i], num[j]);
		}
	}
	ss << num;
	ss >> number;
	return number;
}
int sort_decres(string num)
{
	stringstream ss;
	int number;
	for (int i = 0; i < num.length(); i++)
	{
		for (int j = 0; j<i; j++)
		{
			if (num[i]<num[j])
				swap(num[i], num[j]);
		}
	}
	ss << num;
	ss >> number;
	return number;
}
int max_min(int m, int n)
{
	return m - n;
}