#include <unistd.h>

int	main()
{
	char *a = "hola que tal estas";
    while (*a)
    {
        if (*a == 'a')
            printf("hola");
    }

	return (0);
}