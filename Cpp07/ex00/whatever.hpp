#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& var1, T& var2)
{
	T tmp = var1;
	var1 = var2;
	var2 = tmp;
}

template <typename T>
T min(T& var1, T& var2)
{
	if (var1 < var2)
		return var1;
	else
		return var2;
}

template <typename T>
T max(T& var1, T& var2)
{
	if (var1 > var2)
		return var1;
	else
		return var2;
}

#endif