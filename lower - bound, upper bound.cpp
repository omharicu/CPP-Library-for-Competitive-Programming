#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
int main()
{ 
    // Initializing vector with array values 
    int arr[] = {1, 3, 3, 6,9,10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
    // Sort the array to make sure that lower_bound() 
    // and upper_bound() work. 
    sort(vect.begin(), vect.end()); 
  
    // Returns the first occurrence of 20 
    auto q = lower_bound(vect.begin(), vect.end(), 12); 
  
    // Returns the last occurrence of 20 
    auto p = upper_bound(vect.begin(), vect.end(),9); 
  
    cout << "The lower bound is at position: "; 
    cout << q-vect.begin() << endl; 
  
    cout << "The upper bound is at position: "; 
    cout << p-vect.begin() << endl; 
  
    return 0; 
} 
