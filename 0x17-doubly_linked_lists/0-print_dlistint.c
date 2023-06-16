#include "lists.h"

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
    
	for (; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		count++;
	}
    
	return (count);
}
