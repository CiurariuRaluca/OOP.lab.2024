#include "GlobalFunctions.h"

bool Final( int distance,int speed, int con, int cap)
{
	int dist = cap * con;
	return distance <= dist;
	
}

void strcpy(char* a, const char* b)
{
	int i = 0;
	while (b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}