#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int > > ans;

struct UF
{
    vector<int> pai,r;
    UF(int n)
    {
        pai.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++)
        {
            pai[i]=i;
            r[i]=1;
        }
    }
    int acha(int x)
    {
        if(pai[x]==x){
			 return x;
		}
        return pai[x]=acha(pai[x]);
    }
    void unir(int x, int y)
    {
        x=acha(x);
        y=acha(y);
        if(r[x]>r[y])
        {
            pai[y]=x;
            r[x]+=r[y];
        }
        else
        {
            pai[x]=y;
            r[y]+=r[x];
        }
    }
    bool mesmoConjunto(int x,int y)
    {
        return acha(x)==acha(y);
    }
};

int main()
{
	vector<pair<int,pair<int,int> > >arestas;
	//arestas.push_back({p,{a,b}});
	//LONDRES
	arestas.push_back({5558,{0,1}});
	arestas.push_back({3469,{0,2}});
	arestas.push_back({214,{0,3}});
	arestas.push_back({5074,{0,4}});
	arestas.push_back({5959,{0,5}});
	
	//CIDADE DO MEXICO
	arestas.push_back({2090,{1,2}});
	arestas.push_back({5725,{1,3}});
	arestas.push_back({7753,{1,4}});
	arestas.push_back({7035,{1,5}});
	
	//NOVA IORQUE
	arestas.push_back({3636,{2,3}});
	arestas.push_back({6844,{2,4}});
	arestas.push_back({6757,{2,5}});
	
	//PARIS
	arestas.push_back({5120,{3,4}});
	arestas.push_back({6053,{3,5}});
	
	//PEQUIM
	arestas.push_back({1307,{4,5}});
	
	sort(arestas.begin(),arestas.end()); // aqui esta o projeto de algotitmo guloso.
	UF stru(7);
	for(int i=0;i<(int)arestas.size();i++)
	{
		int peso=arestas[i].first;
		int a=arestas[i].second.first;
		int b=arestas[i].second.second;
		if(!stru.mesmoConjunto(a,b))
		{
			stru.unir(a,b);
			ans.push_back({{a,b},peso});
		}
	}
	cout << "ARESTAS DA MST: " << endl;
	for(int i = 0; i<(int)ans.size(); i++)
	{
		cout << "ARESTA " << i+1 << ": " << ans[i].first.first << "--" << ans[i].first.second << " com peso: " << ans[i].second << endl;
	}

}
