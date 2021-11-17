#include <bits/stdc++.h>

using namespace std;

struct all
{
	int f;
	int s;
	int i;
	
    bool operator<(const all &o) const
    {
    	if(f == o.f)
    	return s < o.s;
        return f < o.f;
    }
};

bool comp(all a, all b)
{
	
	if(a.s == b.s)
	{
		if(a.f > b.f)
			return true;
		else if(a.f == b.f)
		{
			if(a.i > b.i)
			return true;
		}
	}
	else if(a.s > b.s)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
	priority_queue<all> q;
	vector<all> v;
	int num;
	cin >> num;
	for(int i = 1; i<=num ;i++)
	{
		int a,b;
		cin >> a >> b; 
		if(a <= b)
		v.push_back({a, b, i});
	}
	sort(v.begin(),v.end(),comp);

	int val = 0;
	while(!v.empty())
	{
		all temp = v[v.size()-1];
		v.pop_back();
		if(temp.s - val - temp.f >= 0)
		{
			q.push(temp);
			val += temp.f;
		}
		else
		{
			if(q.top().f > temp.f)
			{
				val -= q.top().f;
				q.pop();
				q.push(temp);
				val += temp.f;
			}
		}
	}

	cout << q.size() << "\n";
	while(!q.empty())
	{
		v.push_back(q.top());
		//cout << q.top().f << " " << q.top().s << " " << q.top().i << "\n";
		q.pop();
	}

	val = 1;
	sort(v.begin(),v.end(),comp);
	vector<pair<int,int>> wyn;

	while(!v.empty())
	{
		wyn.push_back({v[v.size()-1].i, val});
		val += v[v.size()-1].f;
		v.pop_back();
	}

	sort(wyn.begin(), wyn.end());

	for(int i = 0; i < wyn.size(); i++)
	{
		cout << wyn[i].first << " " << wyn[i].second << "\n";
	}
}

