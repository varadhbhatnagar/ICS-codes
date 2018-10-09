#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  CryptoPP::SHA1 sha1;
  string srg , source =""; 
  ifstream filestream("testinput.txt");

  if (filestream.is_open())  
  {  
    while ( getline (filestream,srg) )  
    {  
      source+=srg;  
    }  
    filestream.close();  
  }  

  string hash = "";
  CryptoPP::StringSource(source, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));

  cout<<hash;

}
