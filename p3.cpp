#include <iostream>
#include <vector>

using namespace std;




		
int lis(vector<int> v, int n, int l)
{
   	vector<int> var;
	for(int i=l; i<l+n; i++)
	{
		int num=v[i];
		vector<int> :: iterator it;
		it=lower_bound(var.begin(),var.end(),num);
		if(it==var.end())
		 	var.push_back(num);
		else
			*it=num;
	}
	int temp=var.size();
	var.clear();
    return temp;
 
}

vector <int> v;
 
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int temp;


		for(int i=0; i<n; i++)
		{
			cin>>temp;
			v.push_back(temp);
		}
		for(int i=0; i<n; i++)
		{
			temp=v[i];
			v.push_back(temp);
		}
	
		
		int maxGuests=0;
		for(int i=0; i<n; i++)
		{
			int temp1=lis(v,n,i);
			if(temp1>maxGuests)
			maxGuests=temp1;
		}
		cout<<maxGuests<<endl;
		v.clear();
	}
	return 0;
} 