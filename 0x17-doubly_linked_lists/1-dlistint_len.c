#include "lists.h"
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
    
	for (; h != NULL; h = h->next)
		count++;
    
	return (count);
}
