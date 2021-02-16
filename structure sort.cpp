#include <bits/stdc++.h>
using namespace std;

struct data {
  string name;
  int age;
  int idx;
};

bool cmp(data a, data b) {
  if(a.age != b.age)
  return a.age < b.age;
  if(a.name != b.name)
  return a.name < b.name;

  return a.idx < b.idx;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    data arr1[n], arr2[m];
    for(int i = 0 ; i < n ; ++i) {
      cin >> arr1[i].name >> arr1[i].age;
      arr1[i].idx = i;
    }

    int i = 0, j = n-1, k = 0;
    for(int x = 0 ; x < m ; ++x) {
      if(arr1[i].age != arr1[j].age) {
        if(arr1[i].age < arr1[j].age) {
          arr2[k] = arr1[i];
          i++, k++;
        }
        else {
          arr2[k] = arr1[j];
          j--, k++;
        }
      }
      else if(arr1[i].name != arr1[j].name) {
        if(arr1[i].name < arr1[j].name) {
          arr2[k] = arr1[i];
          i++, k++;
        }
        else {
          arr2[k] = arr1[j];
          j--, k++;
        }
      }
      else {
        if(arr1[i].idx < arr1[j].idx) {
          arr2[k] = arr1[i];
          i++, k++;
        }
        else {
          arr2[k] = arr1[j];
          j--, k++;
        }
      }
    }

    sort(arr2, arr2+m, cmp);
    for(int i = 0 ; i < m ; ++i)
    cout << arr2[i].idx << " ";
    cout << endl;
  }

  return 0;
}
