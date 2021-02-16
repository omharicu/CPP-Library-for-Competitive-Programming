#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define fast 
#define endl "\n"
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class node{
public:
   ll value=0;
    node* left;
    node* right;
};



void insert(int n,node* head){
    node* curr = head;
  
    for(int i=31;i>=0;i--)
    {
        int b = (n>>i)&1;
        
        if(b==0)
        {
            if(!curr->left)
                curr->left = new node();
            
            curr = curr->left;
            
        }
        else{
            if(!curr->right)
                curr->right = new node();
            
            curr = curr->right;
            
        }
        curr->value++;
        
    }
    
   
}

ll findsub(node* head, int p,int k){
    node* curr = head;
    ll ans=0;
    for(int i=31;i>=0;i--){
        int a,b;
        a = (k>>i)&1;
        b = (p>>i)&1;
        if(a==1 && b ==1){
            if(curr->right){
                node* add = curr->right;
           		ans += add->value;	
            }
        	
           if(curr->left)
           curr = curr->left;
           else return ans;
        }
        else if(a==1 && b==0){
            if(curr->left){
                node* add = curr->left;
            	ans += add->value;
            }
            
            if(curr->right)
            curr = curr->right;
             else return ans;
        }
        else if(a==0 && b==0){
            if(curr->left)
            curr = curr->left;
             else return ans;
        }
        else if(a==0 && b==1){
            if(curr->right)
            curr = curr->right;
             else return ans;
        }
    }
    return ans;
}

ll subXor(int* a, int n,int k){
    node* head = new node();
    insert(a[0],head);
    ll currXor = a[0];
    
    ll count = 0;
    if(currXor < k)
        count = 1;
    
    for(int i=1;i<n;i++){
        currXor = a[i]^currXor;
        count += findsub(head,currXor,k);
        if(currXor < k)
            count++;
        insert(currXor,head);
    }
    return count;
}

       
int main(){
	IOS;
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << subXor(arr,n,k) <<endl;
        delete[] arr;
    }
    
    return 0;
    
}
