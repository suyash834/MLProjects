#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(a) a.begin(),a.end()
#define  pi pair <int, int>
#define vi vector<int> 
#define rep(i,j,n) for(int i=j;i<n;i++)
bool check(vector<int> &a)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        rep(i,0,n){cin>>a[i];}
        if(check(a))
        {
            if(n%2==0)
            {
                cout<<3<<endl;
                cout<<(n/2)+1<<" "<<(n)<<endl;
                cout<<1<<" "<<(n/2)<<endl;
                cout<<1<<" "<<2<<endl;
            }
            else{
                cout<<3<<endl;
                cout<<(n/2)+1<<" "<<n<<endl;
                cout<<1<<" "<<(n/2)<<endl;
                cout<<1<<" "<<2<<endl;
            }
            continue;
        }
        map<int,int> mp;// map stores<index,length>
        vector<int> ref;
        ref.push_back(1);
        for(int i=0;i<n;i++)
        {
            ref.push_back(a[i]);
        }
        ref.push_back(1);
        int start=-1;
        int end=-1;
        int k=ref.size();
        for(int i=1;i<ref.size()-1;i++)
        {
            if(ref[i]==0 && ref[i-1]!=0)
            {
                start=i;
            }
            if(ref[i]==0 && ref[i+1]!=0)
            {
                end=i;
                mp[start]=(end-start+1);
            }
        }
        int sum=0;
        vector<pair<int,int> > ans;
        for (auto it=mp.rbegin();it!=mp.rend(); ++it) 
        {
            int index=(*it).first;
            int length=(*it).second;
            sum+=length;
            if(length==1)
            {
                if(index==n)
                {
                   ans.push_back(make_pair(n-1,n));
                }
                else{
                    ans.push_back(make_pair(index,index+1));
                }
            }
            else{
                ans.push_back(make_pair(index,index+length-1));
            }
        }
        int r=n-sum+mp.size();
        if(r!=1)
        {
            ans.push_back(make_pair(1,r));

        }
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }


        
       
    }
}