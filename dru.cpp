#include <bits/stdc++.h>

using namespace std;

vector<int> k,w;
int tab[1007];
int cboard[1007][1007] = {0};	
int board[1007][1007];
int po, ko;

bool check(int n, int x, int y, int t)
{
    for (int j = 0; j < y; j++)
    {
		for(int i = 0; i < x; i++)
		{	
			if(cboard[i][j] != t)
            {
                if(board[i][j] != po)
                {
                    return 0;
                }
                else
                {
                    bool pasx = false;
                    //sprawdz czy nie wykracza poza zakres
                    if(i + n - 1 <= x - 1)
                    {
                        pasx = true;
                        //sprawdz klucz poziom
                        for(int c = 0; c < n; c++)
                        {
                            if(board[i+c][j] != k[c+1] || cboard[i+c][j] == t)
                            {
                                pasx = false;
                                break;
                            }
                        }
                    }

                    if (pasx == true)
                    {  
                        //uzupełnienie
                        for (int c = 0; c < n; c++)
                        {
                            cboard[i+c][j] = t; 
                        }
                        i += n-1;
                    }
                    else
                    {
                        if(j + n - 1 <= y - 1)
                        {
                            //sprawdz klucz pion
                            for (int c = 0; c < n; c++)
                            {
                                if (board[i][j+c] != k[c + 1] || cboard[i][j+c] == t)
                                {
                                    return 0;
                                }
                            }

                            for (int c = 0; c < n; c++)
                            {
                                cboard[i][j+c] = t; 
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
            }
		}
	}
    return 1;
}

void factorise(int s) //q[0] musi byc 0
{
	int n = s-1;
	stack<int> later;
    if(n == 1)
        tab[1] = 1;

	for(int i = 1; i * i < n; i++)
	{
	//	cout << n << " " << i << "\n";
		if(n%i == 0)
		{
			later.push(n/i);
			tab[i] = 1;
		}
		if((i+1)*(i+1) == n)
		later.push(n/(i+1));
	}
	while(!later.empty())
	{
		int i = later.top();
		later.pop();
		tab[i] = 1;
    }	
}



int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
	int x, y;
	cin >> y >> x;
    bool xkey = true, nothing = false;
	int w = 0;
	bool allidentical = true;
    stack<int> punk;

	for(int j = 0 ; j < y; j++)
	{
		for(int i = 0; i < x; i++)
		{
			char a;
			cin >> a;
			board[i][j] = (int)a;
			if(i == 0 && j == 0)
				po = (int)a;
			else if(a !=po)
				allidentical = false;
			
		}
	}

    ko = board[x-1][y-1];

    if(allidentical == true) //klucze to dzielniki x i y
    {
        //tworzenie klucza
        k.push_back(0);
        for (int i = 1; i <= min(x,y); i++)
        {
            k.push_back(board[0][0]);
            //	cout << i << " " <<  k[i] << "\n";
        }
        //cout << k.size() -1;
        factorise(k.size());
        if(x != y)
        {
            for (int i = min(x, y); i < max(x, y); i++)
            {
                k.push_back(board[0][0]);
                //	cout << i << " " <<  k[i] << "\n";
            }
            //cout << k.size() - 1;
            factorise(k.size());
        }
    }
    else
    {
        if(x == 1)
        {
            xkey = false;
        }
        else if(y == 1)
        {
            xkey = true;
        }
        else
        {
            for(int i = 1; i < min(x,y); i++)
            {
                if(board[0][i] == board[i][0])
                {
                    if(i+1 >= min(x,y))
                    {
                        //klucz max(x,y)
                        if(x < y)
                            xkey = false;
                        else
                            xkey = true;
                        
                    }
                    if(board[0][i] != board[0][0])
                    {
                        nothing = true;
                        break;  //wyjdz calkowicie, zero to jedyny wynik
                    }
                }
                else if(board[0][i] != board[i][0])
                {
                    if(board[0][i] == board[0][0])
                    {
                        //klucz 1szy poziomy
                        xkey = true;
                        break;

                    }
                    else if(board[i][0] == board[0][0])
                    {
                        //klucz 1szy pionowy
                        xkey = false;
                        break;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
            }
        }
        //cout << xkey;
        if(nothing == false)
        {
            if(xkey == true)
            {
                //tworzenie klucza w poziomie 
                k.push_back(0);
                for (int i = 0; i < x; i++)
                {
                    k.push_back(board[i][0]);
                    if(board[i][0] == ko)
                    {
                        punk.push(i+1);
                    }
                    //	cout << i << " " <<  k[i] << "\n";
                }
        
            }
            else
            {
                //tworzenie klucza w pionie
                k.push_back(0);
                for (int i = 0; i < y; i++)
                {
                    k.push_back(board[0][i]);
                    //	cout << i << " " <<  k[i] << "\n";
                    if(board[0][i] == ko)
                    {
                        punk.push(i+1);
                    }
                }
            } 

            int t = 0;
            while(!punk.empty())
            {
                if((x*y)%punk.top() == 0)
                {
                    t++;
                    tab[punk.top()] = check(punk.top(), x, y, t);
                }
                punk.pop();
            }
        }

    }
    //wypisz wynik
    for(int i = 0; i <= 1000; i++)
    {
        if(tab[i] == 1)
            w++;
    }
    cout << w << "\n";
    for(int i = 1; i <= 1000; i++)
    {
        if(tab[i] == 1)
            cout << i << " ";
    }

}
