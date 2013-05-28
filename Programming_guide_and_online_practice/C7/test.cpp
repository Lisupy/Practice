Source Code

Problem: 2835   User: Darren
Memory: 732K    Time: 0MS
Language: G++   Result: Accepted
Source Code
#include<iostream>
using namespace std;
#include<cmath>

long long lcm,zd,zdg,ys,yushu,x2,y2;
long long a[10],m[10],k[10],zg[10];
long long result[10],m1[11],zg1[10];

long long kzojld(long long a,long long b,long long &x1,long long &y1)//扩展欧几里得
{
  long long d;
  if(b==0)
  {
    x1=1;
    y1=0;

    return a;
  }

  d=kzojld(b,a%b,x1,y1);

  long long tmp=x1;
  x1=y1;
  y1=tmp-a/b*y1;

  return d;
}

int main()
{
  int n;
  while(cin>>n)
  {
    if(n==0)
      break;
    for(int i=0;i<n;i++)
      cin>>a[i];

    lcm=a[0];
    for(int i=0;i<n;i++)
    {
      lcm=lcm/kzojld(lcm,a[i],x2,y2)*a[i];
    }
    for(int i=0;i<n;i++)
      m[i]=lcm/a[i];
    for(int i=0;i<n;i++)
      m1[i]=m[i];
    m1[n]=lcm;
    zd=m[n-1];
    zg[n-1]=lcm;
    for(int i=n-1;i>0;i--)
    {
      zg[i-1]=kzojld(zd,m[i],x2,y2);
      zd=zg[i-1];
    }
    for(int i=0;i<n;i++)
      zg1[i]=zg[i];

    long long x,y;
    yushu=1;
    for(int i=0;i<n;i++)
    {
      zdg=kzojld(m[i],zg[i],x,y);
      m1[i]/=zdg;
      zg1[i]/=zdg;
      ys=yushu;
      while(ys<0)
        ys+=lcm;
      ys/=zdg;
      ys%=zg1[i];
      kzojld(m1[i],zg1[i],x,y);

      k[i]=ys*x;
      while(k[i]<=0)
        k[i]+=a[i];
      result[i]=m[i];
      result[i]*=k[i];

      yushu-=result[i];
    }

    for(int i=0;i<n;i++)
      cout<<result[i]<<" ";
    cout<<endl;

  }
  return 0;
}
