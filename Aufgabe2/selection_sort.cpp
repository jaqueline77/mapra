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
		for(int i=1; i<l; i++)
		{
			for(int j=i; j>=1; j--)
			{		
				if(feld[j]<feld[j-1])
				{
					tausche(feld, j, j-1);
				}
			}
		}
		ergebnis(feld);
		
	}
	return 0;
}
