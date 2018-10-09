#include<bits/stdc++.h>
using namespace std;

long long cuspow(long long a, long long b, long long n)
{
	long long i, temp;
	temp =a;
	for(i=2;i<=b;i++)
	{
		a=(a*temp) % n;
	}

	return a;
}

bool isPrime(long long n)
{
	long long i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
			{
				return 0;
			}	
	}

	return 1;
}

long long returnGCD( long long a , long long b)
	{
		long long t;
		if(b>a)
		{
			t=a;
			a=b;
			b=t;
		}
	
		while(a%b!=0)
		{
			t = a%b;
			a = b;
			b = t;
		}

		return b;
	}


pair<long long , char> rsa(long long plaintext , long long p , long long q)
{
	long long n , phi_of_n , i , e , d  , ciphertext;
	char dplaintext;

	n = p*q;
	phi_of_n = (p-1) * (q-1);

	for(i=2;i<phi_of_n/2;i++)
	{
		if(returnGCD(i,phi_of_n)==1)
			{
				e = i;
				break;
			}
	}

	for(i=1 ; i<=phi_of_n;i++)
	{
		if(((i * e) % phi_of_n) ==1)
		{
			d = i;
			break;
		}
	}

	ciphertext = cuspow(plaintext, e, n);	
	dplaintext = cuspow(ciphertext, d, n);
	pair<long long , char> rpairs = make_pair(ciphertext , dplaintext);

	return rpairs;	
}

main()
{
	long long p , q , i;
	string plaintext;
	vector<char> ciphertext;
	do
	{
		cout<<"\n Enter first prime number";
		cin>>p;
	}while(!isPrime(p));

	do
	{
		cout<<"\n Enter second prime number";
		cin>>q;
	}while(!isPrime(q));

	cout<<"\n Enter Plaintext ";
	cin>>plaintext;

	cout<<"\n Encrypted Text ";
	for(i=0;i<plaintext.size();i++)
	{
		pair <long long , char> rpairs = rsa(plaintext[i] , p , q);
		cout<<rpairs.first;
		ciphertext.push_back(rpairs.second);
	}

	cout<<"\n Decrypted Text ";

	for(i=0;i<ciphertext.size();i++)
	{
		cout<<ciphertext[i];
	}

	cout<<endl;
}
	

	
		

	
