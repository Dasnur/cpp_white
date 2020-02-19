
int factorial(int x)
{
	int	res;
	if (x < 0)
		return 1;
	if (x == 1)
		return 1;
	if (x == 0)
		return 1;
	return (x * factorial(x - 1));
}