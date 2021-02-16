#include<bits/stdc++.h>
using namespace std;

int main()
{
	set<int> s;
	s.insert(100); // O(logn)
	s.insert(-1);
	s.insert(12);
	s.insert(90);
	for(int x: s)
	{
		cout << x << " " << endl;
	}
	
	//to find whether an element is present or not 
	// if not iterator returns to last element
	auto it = s.find(100);
	cout << *it << endl; // prints 100 as it is present
	auto it2 = s.find(101);
	
	cout << *it2 << endl;// prints 4 i.e. the size of set
	if( it == s.end())
	{
		cout << "not present\n";
	}
	else
	{
		cout << "YES\n";
	}
	cout << "hhh" << endl;
	auto it3= s.lower_bound(110); // greater than or equal to -1
	cout << *it3 << endl;
	auto it4 = s.upper_bound(-1);// strictly greater than -1
	cout << *it4 << endl;
	auto it5 = s.lower_bound(1000); // returns 12 as just greater than 2 is 12 even tho 2 isn't present
	
	cout << "wehatsss" << endl;
	cout << *it5 << endl;
	if( it5 == s.end())
	{
		cout << "not present\n";
	}
	else
	{
		cout << "YES\n";
	}
	auto it6 = s.upper_bound(2); // returns 12 as just greater than 2 is 12
	cout << *it6 << endl;
	cout << *--it6 << endl;//returns -1 because of -- , i.e. it goes back 1 index
	
	auto it7= s.lower_bound(-10);// returns -1
	cout << *it7 << endl;
	
	auto it8 = s.upper_bound(-10);// returns -1
	cout << *it8 << endl;
	
	auto it9 = s.lower_bound(200);
	cout << *it9 << endl; // returns 4 i.e. size of vector.. same with upper bound
	
	
	s.erase(-1); // O(logn)
	for(int x: s)
	{
		cout << x << endl;
	}
}

