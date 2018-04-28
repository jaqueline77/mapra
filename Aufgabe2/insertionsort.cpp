#include <cmath>
#include "unit.h"


using namespace std;

int main()
{
	unsigned int *feld;	
	size_t l=5;
	for(int k=1; k<=AnzahlBeispiele; k++)
	{
		start(k, l, feld);
		for(int i=0; i<l; i++)
		{
			int r= i;
			for(int j=i; j<l-1; j++)
			{
				if (feld[j+1]<feld[r])
				{
					r=j+1;
				}
			}
			tausche(feld, i, r);
		}
		ergebnis(feld);
		
	}
	return 0;
}
