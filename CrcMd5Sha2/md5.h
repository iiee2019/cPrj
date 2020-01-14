#ifndef MD5_H
#define MD5_H

#include <stdio.h>


void md5init(void);

int add_bits(unsigned char * buf, size_t src_len);


void  md54file(const char * filename,char * md5str);

void useOftransform();

#endif
