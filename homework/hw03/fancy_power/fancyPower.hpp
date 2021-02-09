#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancyPower(int n, int m)
{
	if (n == 0)
	{
		return 1;
	}
	else 
	{
		if ((n % 2) ==0)
		{
			if (n == 2)
			{
				return m*m;
			}
			return fancyPower(n/2, fancyPower(2,m));
		}
		else 
		{
		return (m*fancyPower((n-1)/2,fancyPower(2,m)));
		}
	}
	return 0;
}

#endif
