
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e15;
const int mod=1e9+7;


const int N=500005;
int dp[N];

struct job
{
    int st,ed,pt;
};

bool cmp(job x,job y)
{
    return x.ed<y.ed;
}

vector<job> v;

int srch(int st)
{
    int l=0,h=st-1,idx=-1;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(st>=v[mid].ed)
        {
            idx=mid;
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }

    return idx;


}

int fun()
{
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++)
    {
        int strt=v[i].st;
        int fin=v[i].ed;
        int prft=v[i].pt;

        int idx=srch(strt);

        int ans=prft;

        if(idx!=-1) ans+=dp[idx];

        dp[i]=max(dp[i-1],ans);

        cout<<"dp "<<dp[i]<<endl;
    }

    return dp[v.size()-1];
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        int s,f,p;cin>>s>>f>>p;
        v.push_back({s,f,p});
    }

    int mx=fun();

    cout<<mx<<endl;

    return 0;

}

/*

4
1 6 6
2 5 5
5 7 5
6 8 3

*/



