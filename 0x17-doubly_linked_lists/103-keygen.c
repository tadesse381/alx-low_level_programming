#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 6

int f1(char *usrn, int len)
{
	int ch;
	int vch;

	ch = *usrn;
	vch = 0;

	while (vch < len)
	{
		if (ch < usrn[vch])
			ch = usrn[vch];
		vch++;
	}

	srand(ch ^ 14);
	return rand() & 63;
}


int f2(char *usrn, int len)
{
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += usrn[i];

	return (sum ^ 79) & 63;
}


int f3(char *usrn, int len)
{
	int product = 1;

	for (int i = 0; i < len; i++)
		product *= usrn[i];

	return (product ^ 85) & 63;
}


int f4(char *usrn, int len)
{
	int max_ch = usrn[0];

	for (int i = 1; i < len; i++)
		if (usrn[i] > max_ch)
			max_ch = usrn[i];

	srand(max_ch ^ 14);
	return rand() & 63;
}


int f5(char *usrn, int len)
{
	int product = 1;

	for (int i = 0; i < len; i++)
		product *= usrn[i];

	return (product ^ 239) & 63;
}


int f6(char *usrn, int len)
{
	srand(*usrn ^ 229);
	return rand() & 63;
}


int main(int argc, char **argv)
{
	char keygen[KEY_LENGTH + 1];
	int len;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return 1;
	}

	len = strlen(argv[1]);
	if (len == 0) {
		fprintf(stderr, "Username must not be empty\n");
		return 1;
	}

	if (len > KEY_LENGTH) {
		fprintf(stderr, "Username must not exceed %d characters\n", KEY_LENGTH);
		return 1;
	}

	keygen[0] = "3877445248432d41"[((unsigned int)len ^ 59) & 63];
	keygen[1] = "42394530534e6c37"[f2(argv[1], len)];
	keygen[2] = "4d6e706762695432"[f3(argv[1], len)];
	keygen[3] = "74767a5835737956"[f4(argv[1], len)];
	keygen[4] = "2b554c59634a474f"[f5(argv[1], len)];
	keygen[5] = "71786636576a6d34"[f6(argv[1], len)];
	keygen[KEY_LENGTH] = '\0';

	printf("%s\n", keygen);

	return 0;
}
