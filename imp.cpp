#include <bits/stdc++.h>

using namespace std;

long long len = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
   	bool error = 0;
   	int cas = -1;
   	int n;
   	vector<int> cases;
   	cin >> n;
   	int unused = n;
   	int free = n;
   	if(n < 4)
   	{
   		if(n == 2)
   		{
   			int a, b;
   			cin >> a >> b;
   			if(a == b)
   			cout << 0;
   			else
   			cout << 1;
   			
   		}
   		if(n == 3)
   		{
   			int a, b, c;
   			cin >> a >> b >> c;
   			if(a == b || b == c || a != c)
   				cout << 0;
   			else 
   				cout << 2;	
   		}
   	}
   	else  //n >= 4
	{ 
	   	int tab[n+7];
	   	for(int i = 0; i < n; i++)
	   	{
	   		int a; cin >> a;
	   		tab[i] = a;
	   	}
	   	int poss[n+7] = {0}; //possible
	   	int used[n+7] = {0}; //used numbers // 1 = must // 2 = possible

	 	poss[1] = tab[0]; used[tab[0]] = 1; unused--;free--;
		for(int i = 1; i <= n-4; i++)
		{
			if(tab[i] == tab[i+2])
			{
				if(used[tab[i]] == 1)
				{
					error = 1;
					break;
				}
				else
				{
				used[tab[i]] = 1;
				unused--;
				poss[i+1] = tab[i];
				free--;
				}
			}
			else if(poss[i-1] != 0 && poss[i-1] != tab[i])
			{
				if(used[tab[i]] == 1)
				{
			//	cout << "i: " << i << "poss[i-1]: " << poss[i-1] << "\n";
					error = 1;
					break;
				}
				else
				{
				poss[i+1] = tab[i];
				free--;
				used[tab[i]] = 1;
				unused--;
				}
			}
		}

		if(poss[n-3] != 0 && poss[n-3] != tab[n-2])
		{
			if(used[tab[n-2]] == 1)
			{
				error = 1;
			}
			else
			{
			poss[n-1] = tab[n-2];
			free--;
			used[tab[n-2]] = 1;
			unused--;
			}
		}

		if(used[tab[n-1]] == 1)
	  	{
	  		error = 1;
	  	}
	  	else
	  	{
	   		poss[n-2] = tab[n-1]; free--;  used[tab[n-1]] = 1; unused--;
		}
				for(int i = 0; i < n; i++)
		{
			//cout << i << ": " <<  poss[i] << "\n"; 	
		}	
		
		//teraz w droga strone
		for(int i = n-3; poss[i-1] == 0 && i >=1; i-=2)  //napewno nie i > 0 popraw!!!
		{
			if(used[tab[i]] == 1 && poss[i+1] != tab[i])
			{
				error = 1;
				break;
			}
			else if(used[tab[i]] == 1 && poss[i+1] == tab[i])
			{
				break;
			} 
			else
			{
				poss[i-1] = tab[i];
				free--;
				used[tab[i]] = 1;
				unused--;
			}
		}
		
	/*	for(int i = 0; i < n; i++)
		{
			cout << i << ": " <<  poss[i] << "\n"; 	
		}	
	*/
		if(error != 1)  //start
		{
			for(int i = 1; i < n-1; i++) //to trzeba zmienic, aby nie wykraczalo poza pamięć !!!
	   		{

		   		if(used[tab[i]] == 1)
		   		{
	   				if(poss[i-1] != tab[i] && poss[i+1] != tab[i] || poss[i-1] == tab[i] && poss[i+1] == tab[i] )
	   				{
	   					error = 1;
	   					break;
	   				}
	   			}	
		   		else if(used[tab[i]] == 2)  
		   		{
	   				error = 1;
	   				break;
		   		}
		   		else 
		   		{
		   		//cout << "cp 1: " << i << " poss[i-1]: " << poss[i-1] << " cas: "<< cas << " tab[i]: " << tab[i] << "\n"; 
		   			if(poss[i-1] == 0)
		   			{
		   				cases.push_back(2);
		   				poss[i-1] = cas;
		   				poss[i+1] = cas;
		   				free -= 2;
		   				cas--;
		   				used[tab[i]] = 2;
		   				unused--;
		   			}
		   			else if(poss[i-1] > 0)
		   			{
		   				poss[i+1] = tab[i];
		   				free--;
		   				used[tab[i]] = 1;
		   				unused--;	
		   			}
		   			else if(poss[i-1] < 0)
		   			{
		   				cases[(-1*poss[i-1]) - 1]++;
		   				poss[i+1] = poss[i-1];
		   				free--;
		   				used[tab[i]] = 2;
		   				unused--;
		   			}
		   			
	   			}
	   		}
/*
		for(int i = 0; i < n; i++)
		{
			cout << i << ": " <<  poss[i] << "\n"; 	
		}

		for(int i = 0; i < cases.size(); i++)
		{
			cout << i << "case: " <<  cases[i] << "\n"; 	
		}*/

	   	}
			   	//	cout << unused << " " << free << "\n";

		if(error == 1)
			cout << 0;
		else
		{
			long long w = 1;
			while(free > 0)
			{
				w*=unused;
				w = w % len;
				unused--;
				free--;
			}
			for(int i = 0; i < cases.size(); i++)
			{
				w*=cases[i]*unused;
				w = w % len;
				unused--;
			}
			cout << w % len;
		}
	}
}

