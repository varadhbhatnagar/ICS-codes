#include<bits/stdc++.h>
using namespace std;

int main()
{

	cout << "******************CHINESE REMAINDER THEOREM********************";

	int n;
	cout << "\n Enter number of pairs ";
	cin >> n;

	int i, ara[n + 1], arn[n + 1], tempgcd = 0, M = 1 , arM[n + 1], ary[n + 1], z, k = 0, answer = 0;

	for(i = 0; i < n; i++)
	{
		cout << "\n Enter pair " << i + 1 << "\n\n";
		cout << "a" << i + 1 << "=";
		cin >> ara[i];
		cout << "n" << i + 1 << "=";
		cin >> arn[i];

		if(!tempgcd)
		{
			tempgcd = arn[i];
		}
		else
		{
			if(__gcd(tempgcd, arn[i]) != 1)
			{
				cout << "Invalid value of n, Enter the pair again";
				i--;
				continue;
			}
			tempgcd = __gcd(tempgcd, arn[i]);
		}
		M = M * arn[i];
	}

	for(i = 0; i < n; i++)
	{
		arM[i] = M / arn[i];

		z=1;
		while(1)
		{
			if((z * arM[i]) % arn[i] == 1)
			{
				ary[k++] = z;
				break;
			}
			z++;
		}

	}

	for(i = 0; i < n; i++)
	{
		answer += (ara[i] * arM[i] * ary[i]) % M;
	}

	answer %= M;

	cout<<"\n The answer of the given problem is "<<answer<<"\n\n";
}
