
/**
 * \file sha2.h
 *
 *  Copyright (C) 2006-2010, Brainspark B.V.
 *
 *  This file is part of PolarSSL (http://www.polarssl.org)
 *  Lead Maintainer: Paul Bakker <polarssl_maintainer at polarssl.org>
 *
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef SHA256_H
#define SHA256_H

typedef struct
{
    unsigned long total[2];     /*!< number of bytes processed  */
    unsigned long state[8];     /*!< intermediate digest state  */
    unsigned char buffer[64];   /*!< data block being processed */

    unsigned char ipad[64];     /*!< HMAC: inner padding        */
    unsigned char opad[64];     /*!< HMAC: outer padding        */
    int is224;                  /*!< 0 => SHA-256, else SHA-224 */
}
sha2_context;

void sha2_process( sha2_context *ctx, const unsigned char data[64] );
/**
 * \brief          SHA-256 context setup
 *
 * \param ctx      context to be initialized
 * \param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2_starts( sha2_context *ctx, int is224 );

/**
 * \brief          SHA-256 process buffer
 *
 * \param ctx      SHA-256 context
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 */
void sha2_update( sha2_context *ctx, const unsigned char *input, int ilen );

/**
 * \brief          SHA-256 final digest
 *
 * \param ctx      SHA-256 context
 * \param output   SHA-224/256 checksum result
 */
void sha2_finish( sha2_context *ctx, unsigned char output[32] );

/**
 * \brief          Output = SHA-256( input buffer )
 *
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 * \param output   SHA-224/256 checksum result
 * \param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2( const unsigned char *input, int ilen,
           unsigned char output[32], int is224 );

/**
 * \brief          Output = SHA-256( file contents )
 *
 * \param path     input file name
 * \param output   SHA-224/256 checksum result
 * \param is224    0 = use SHA256, 1 = use SHA224
 *
 * \return         0 if successful, 1 if fopen failed,
 *                 or 2 if fread failed
 */
int sha2_file( const char *path, unsigned char output[32], int is224 );

/**
 * \brief          SHA-256 HMAC context setup
 *
 * \param ctx      HMAC context to be initialized
 * \param key      HMAC secret key
 * \param keylen   length of the HMAC key
 * \param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2_hmac_starts( sha2_context *ctx, const unsigned char *key, int keylen,
                       int is224 );

/**
 * \brief          SHA-256 HMAC process buffer
 *
 * \param ctx      HMAC context
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 */
void sha2_hmac_update( sha2_context *ctx, const unsigned char *input, int ilen );

/**
 * \brief          SHA-256 HMAC final digest
 *
 * \param ctx      HMAC context
 * \param output   SHA-224/256 HMAC checksum result
 */
void sha2_hmac_finish( sha2_context *ctx, unsigned char output[32] );

/**
 * \brief          SHA-256 HMAC context reset
 *
 * \param ctx      HMAC context to be reset
 */
void sha2_hmac_reset( sha2_context *ctx );

/**
 * \brief          Output = HMAC-SHA-256( hmac key, input buffer )
 *
 * \param key      HMAC secret key
 * \param keylen   length of the HMAC key
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 * \param output   HMAC-SHA-224/256 result
 * \param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2_hmac( const unsigned char *key, int keylen,
                const unsigned char *input, int ilen,
                unsigned char output[32], int is224 );

/**
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
int sha2_self_test( int verbose );

#ifdef __cplusplus
}
#endif

#endif /* sha2.h */
