#include<iostream>
using namespace std;


int coinChange(int numbers[] , int a , int n)
{
	int i = 0;
	int* x = new int[n] {0};
	while (a>0)
	{
		x[i] = a / numbers[i];
		a = a - x[i] * numbers[i];
		i++;
	}

	int sum = 0;
	for (int j = 0; j < n; j++)
	{
		sum += x[j];
	}

	for (int j = 0; j < n; j++)
	{
		if (x[j] != 0)
			cout << "coin value : " << numbers[j]<< " , "<< "coin amount : "<<x[j] <<endl;
		
	}
	return sum;	


}

/*

int main()
{
	int d[] = { 200, 100, 50 , 20 ,10 , 5 , 2, 1 };
	cout << "Number of coins needed : " << coinChange(d, 633, 8);
}

*/