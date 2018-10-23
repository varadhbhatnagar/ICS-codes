#include<bits/stdc++.h>
using namespace std;

long long cuspow(long long a, long long b, long long n)
{
	long long i, temp;
	temp = a;
	for(i = 2; i <= b; i++)
	{
		a = (a * temp) % n;
	}
	return a;
}

bool isPrime(long long n)
{
	long long i;
	for(i=2; i * i <= n; i++)
	{
		if(n % i==0)
        {
            return 0;
        }
	}
	return 1;
}

pair<long long , char> rsa(long long plaintext , long long e , long long d, long long n)
{
	long long ciphertext;
	char dplaintext;
	ciphertext = cuspow(plaintext, e, n);
	dplaintext = cuspow(ciphertext, d, n);
	pair<long long , char> rpairs = make_pair(ciphertext , dplaintext);
	return rpairs;
}

int main()
{
	long long p , q , i, n, e, d, phi_of_n;
	string plaintext;
	vector<char> ciphertext;
	do
	{
		cout << "\nEnter first prime number: ";
		cin >> p;
	}while(!isPrime(p));
	do
	{
		cout << "\nEnter second prime number: ";
		cin >> q;
	}while(!isPrime(q));

	n = p * q;
	phi_of_n = (p - 1) * (q - 1);
	for(i = 2; i < phi_of_n / 2; i++)
	{
		if(__gcd(i, phi_of_n) == 1)
		{
			e = i;
			break;
		}
	}
	for(i = 1; i <= phi_of_n; i++)
	{
		if(((i * e) % phi_of_n) == 1)
		{
			d = i;
			break;
		}
	}
	cout<<"\nEnter Plaintext ";
	cin>>plaintext;
	cout << "\nEncrypted Text ";
	for(i = 0; i < plaintext.size(); i++)
	{
		pair <long long , char> rpairs = rsa(plaintext[i], e, d, n);
		cout << rpairs.first;
		ciphertext.push_back(rpairs.second);
	}
	cout << "\nDecrypted Text: ";
	for(i = 0; i < ciphertext.size(); i++)
	{
		cout << (char)ciphertext[i];
	}
	cout << endl;
}
