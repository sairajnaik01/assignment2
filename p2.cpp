#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;



class AvoidRoads
{
	public:
	long long numWays(int w, int h,vector < pair<int,int> > v[2]);
};

//for checking the bad paths
int check(int a,int b,int c,int d,vector < pair<int,int> > v[2])
{
	int n=v[0].size();
	for(int i=0;i<n;i++)
	{
		if(v[0][i].first==a&&v[0][i].second==b&&v[1][i].first==c&&v[1][i].second==d)
		return 1;
		if(v[0][i].first==c&&v[0][i].second==d&&v[1][i].first==a&&v[1][i].second==b)
		return 1;
	}
	return 0;
}

long long AvoidRoads::numWays(int width, int height,vector < pair<int,int> > v[2])
{
	long long  dp[height+1][width+1];
	for(int i=height;i>=0;i--)
	{
		for(int j=width;j>=0;j--)
		{
			long long  ans=0;
			if(j<width)
			{
				//checking with the right one
				if(check(i,j,i,j+1,v)==0)
				ans+=dp[i][j+1];
			}
			if(i<height)
			{
				//checking with the upper one
				if(check(i,j,i+1,j,v)==0)
				ans+=dp[i+1][j];
			}
			if(j==width&&i==height)
			ans=1;
			dp[i][j]=ans;
		}
	}
	return dp[0][0];
}

int main() {
	int width,height;
	cin>>width>>height;
	int k;
	int n=0;
	vector < pair<int,int> > v[2];
	while(cin>>k)
	{
		if(k<0)
		break;
		int p,q,r;
		cin>>p>>q>>r;
		v[0].push_back(make_pair(k,p));
		v[1].push_back(make_pair(q,r));
		n++;
	}
	AvoidRoads xyz;
	cout<<xyz.numWays(width,height,v);
	return 0;
}

/* sample input

6 6
0 0 0 1
6 6 5 6
-1

output:
252

*/