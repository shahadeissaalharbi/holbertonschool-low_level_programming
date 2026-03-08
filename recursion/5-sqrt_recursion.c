/**
 * _sqrt_helper - helper function to find square root
 * @n: the target number
 * @i: current value to check
 *
 * Return: square root of n or -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find square root of
 *
 * Return: natural square root of n, or -1 if it doesn't exist
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}
