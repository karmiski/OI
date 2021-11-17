#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
  	long long m;
  	int oneh = 0, dw = 0;
  	cin >> m;
  	if(m <= 2)
    	cout << m;
  	else
  	{
  		long  long  a = 1, b = 1, c = 2, l = 0, w = 0 ; //nie wiem ile, dodaj później;
    
		while(c < m)
		{
			c = a+b;
			a = b;
			b = c;
			l++;
		}
		//	cout << l << "\n";

		if(m == c)
		{
			cout << l;
		}
		else
		{
			while(l > 0)
			{
				l--; 
				c = b - a;
				b = a;
				a = c; 
				//	cout << "m" << m<< " w" << w<< " c" << c<< " l" << l << " " << oneh <<"\n";
				while(m % c == 0 && c != 1)
				{
					if(c == 144) oneh++;
					if(c == 2) dw++;
					m /= c;
					w += l;
					w ++;
				//	cout << "m" << m<< " w" << w<< " c" << c<< " l" << l <<"\n"; 
				}	
			}
			if(m == 1)
				cout << w - 1;
			else 
			{
				if(oneh == 0)
					cout << "NIE";
				else
				{
					while(oneh > 0)
					{
						m *= 144;
						while(dw > 0)
						{
							m *= 2;
							dw--;
							w-=3;
						}
						w-=12;
						a = 1, b = 1, c = 2, l = 0 ; //nie wiem ile, dodaj później;
							
						while(c < 144)
						{
							c = a+b;
							a = b;
							b = c;
							l++;
						}
						//	cout << a << " " << b << " " << c<< " " << l << "\n";
						oneh = 0;

						while(l > 0)
						{
							l--; // 
							c = b - a;
							b = a;
							a = c; 
						//	cout << "m" << m<< " w" << w<< " c" << c<< " l" << l <<"\n";
							while(m % c == 0 && c != 1)
							{
							if(c == 2) dw++;
								m /= c;
								w += l;
								w ++;
							//	cout << "m" << m<< " w" << w<< " c" << c<< " l" << l <<"\n"; 
							}	
						}
						if(m == 1)
						break;
					
					}
					if(m == 1)
					cout << w-1;
					else
					cout << "NIE";
				}
			}
		}
   	// cout << c << " " << l;
  	}
  
}
