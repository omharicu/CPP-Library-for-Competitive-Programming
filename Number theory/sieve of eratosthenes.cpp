
// C++ program to print all primes smaller than or equal to a given number n using Sieve of Eratosthenes 
#include <bits/stdc++.h> 
using namespace std; 

vector<int> pr;

void SieveOfEratosthenes(int maxn) 
{ 
    pr.clear();
	bool prime[maxn+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=maxn; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=maxn; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=maxn; p++) 
    if (prime[p]) 
    {
   	    pr.push_back(p);
    }
} 
int main() 
{ 
    int n = 40; 
    SieveOfEratosthenes(40); 
    for(int x:pr)
    	cout << x << " ";
} 
