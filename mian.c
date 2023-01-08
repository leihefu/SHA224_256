#include "sha224_256.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char string[62] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

int main(void)
{
	char clear_text[32];
	uint8_t sha224_digest[SHA224_DIGEST_LEN] = { 0 };
	uint8_t sha256_digest[SHA256_DIGEST_LEN] = { 0 };

	srand((uint16_t)time(NULL));

	printf("clear_text:\r\n");
	for (uint8_t i = 0; i < sizeof(clear_text); i++)
	{
		clear_text[i] = string[rand() % 62];
		printf("%C", clear_text[i]);
	}
	printf("\r\n");

	sha224(clear_text, sizeof(clear_text), sha224_digest);
	printf("sha224_digest:\r\n");
	for (uint8_t i = 0; i < SHA224_DIGEST_LEN; i++)
	{
		printf("%02X ", sha224_digest[i]);
		if (i % 14 >= 13)
		{
			printf("\r\n");
		}
	}

	sha256(clear_text, sizeof(clear_text), sha256_digest);
	printf("sha256_digest:\r\n");
	for (uint8_t i = 0; i < SHA256_DIGEST_LEN; i++)
	{
		printf("%02X ", sha256_digest[i]);
		if (i % 16 >= 15)
		{
			printf("\r\n");
		}
	}
	return 0;
}