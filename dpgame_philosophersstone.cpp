#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int a[105][105];
int dp[105][105];

int calculate(int i,int j,int n)
{
    if(j>=n || i>=n || j<0 || i< 0)
    {
        return 0;
    }
    if(dp[i+1][j]==-1)
        dp[i+1][j]=calculate(i+1,j,n);
    if(dp[i+1][j-1]==-1)
        dp[i+1][j-1]=calculate(i+1,j-1,n);
    if(dp[i+1][j+1]==-1)
        dp[i+1][j+1]=calculate(i+1,j+1,n);

    return a[i][j] + max(dp[i+1][j+1],max(dp[i+1][j],dp[i+1][j-1]));
}


int main()
{
    srand(time(0));
    memset(dp,-1,sizeof(dp));
    int n,ans,maxi=0;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t\tWELCOME TO PHILOSOPHERS STONE"<<endl;
    cout<<"\t\t\t\t\t\t*****************************"<<endl<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    while(true)
    {
    cout<<"Enter Level:\t"<<endl;
    cin>>n;
    if(n==0)
    {
        cout<<"Invalid Level !"<<endl<<endl;
        continue;
    }
    n++;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t\tTHE QUEST IS GIVEN BELOW";
    cout<<endl<<"\t\t\t\t\t\t************************"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"\t\t\t\t";
        for(int j=0;j<n;j++)
        {
            int temp = rand()%10;
            cout<<"|"<<temp<<"\t";
            a[i][j]=temp;
        }
        cout<<endl;
    }
    memset(dp,-1,sizeof(dp));
    cout<<endl<<" Help Harry grab as many philosophers stones as possible, He is subjected to the following restrictions:"<<endl<<endl;

cout<<" 1) He starts by choosing any tile in the first row, and collects the philosophers stones on that tile. Then, he moves"<<endl<<"    to a tile in the next row, collects the philosophers stones on the tile, and so on until he reaches the last row."<<endl;
cout<<endl<<" 2) When he moves from one tile to a tile in the next row, he can only move to the tile just below it or diagonally to "<<endl<<"    the left or right."<<endl<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"Find the maximum number of stones that Harry can have at the end"<<endl<<endl;
while(true)
{
cout<<"Enter Your Answer: "<<endl;
cin>>ans;
int i=0,j;
for(j=0;j<n;j++)
       {
           if(dp[i][j]==-1)
            dp[i][j] = calculate(i,j,n);
            if(dp[i][j]>maxi)
              maxi=dp[i][j];
    }
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    if(ans==maxi)
    {
        cout<<endl<<" Congratulations! You Have Successfully Helped Harry , You WON! :)"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        break;
    }

    else
    {
        cout<<endl<<" Ohh No! Wrong Answer, You LOST :( "<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    }
}
    }
}
