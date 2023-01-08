/*  SHA224��SHA256�ǹ���һ�׺���Դ��ʵ��
    ֻ����������������һ��is_224�ı�����
    ��ʶ��ִ��SHA224���㻹��SHA256����     */
#ifndef __SHA224_256_H__
#define __SHA224_256_H__

#include <stdint.h>

#define SHA224_DIGEST_LEN 28			// SHA224 outputs a 28 byte digest
#define SHA256_DIGEST_LEN 32         	// SHA256 outputs a 32 byte digest

typedef struct _sha224_256_ctx_t {
    uint32_t 	total[2];          		/*!< The number of Bytes processed.  */
    uint32_t 	state[8];          		/*!< The intermediate digest state.  */
    uint8_t 	buffer[64];   			/*!< The data block being processed. */
    int32_t		is_224;                 /*!< Determines which function to use:
                                             0: Use SHA-256, or 1: Use SHA-224. */
} sha224_256_ctx_t;


void sha224(const uint8_t* message, uint32_t len, uint8_t* digest);
void sha256(const uint8_t* message, uint32_t len, uint8_t* digest);
#endif   // __SHA224_256_H__
