//https://www.geeksforgeeks.org/gold-mine-problem/
//Self Implementation

#include<bits/stdc++.h>
using namespace std;


int func(int n, int m, vector< vector<int> > arr)
{
  int dp[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      dp[i][j] = 0;
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m-1;j++)
    {
      if(i == 0)
      {
        if(arr[i][j+1] > arr[i+1][j+1])
        {
          dp[i][j] = 0;
        }
        else
        {
          dp[i][j] = 1;
        }
      }
      else if(i == n-1)
      {
        if(arr[i-1][j+1] > arr[i][j+1])
        {
          dp[i][j] = -1;
        }
        else
        {
          dp[i][j] = 0;
        }
      }
      else
      {
        if(arr[i-1][j+1] > arr[i][j+1] && arr[i-1][j+1] > arr[i+1][j+1])
        {
          dp[i][j] = -1;
        }
        else if(arr[i][j+1] > arr[i-1][j+1] && arr[i][j+1] > arr[i+1][j+1])
        {
          dp[i][j] = 0;
        }
        else
        {
          dp[i][j] = 1;
        }
      }
    }
  }
  int max = 0;
  for(int x=0;x<n;x++)
  {
    int max_temp = 0;
    int i = x;
    int j = 0;
    while(j < n)
    {
      //cout<<"Iteration "<<j<<endl;
      //cout<<arr[i][j]<<endl;
      max_temp += arr[i][j];
      i = i + dp[i][j];
      j = j + 1;
    }
    if(max_temp > max)
    {
      max = max_temp;
    }
  }
  return max;
}

int main()
{
  int n, m;
  cin>>n>>m;
  vector< vector<int> > arr(n, vector<int>(m));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
    }
  }
  cout<<func(n, m, arr)<<endl;
  return 0;
}
