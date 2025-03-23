#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(a) a.begin(),a.end()
#define  pi pair <int, int>
#define vi vector<int> 
#define rep(i,j,n) for(int i=j;i<n;i++)
bool ispalin(string s)
{
    string h=s;
    reverse(h.begin(),h.end());
    return (h==s);

}
bool greater1(string s)
{
    string h=s;
    reverse(h.begin(),h.end());
    return (h>s);
}
bool same(string s)
{
    int n=s.length();
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k==0)
        {
            if(ispalin(s))
            {
                cout<<"NO"<<endl;
            }
            else{
                if(greater1(s))
                {
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }

            }
        }
        else{
            if(same(s))
            {
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }

        }


    }
}