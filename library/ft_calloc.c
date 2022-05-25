#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;

	ptr = malloc(size * count);
	if (!(ptr))
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}