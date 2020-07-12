#ifndef MD5_C
#define MD5_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <limits.h>
#include <dirent.h>
#include <stdint.h>

#include "md5.h"

#define BITS_PER_BYTE   8

#define GROUP_BITS      512
#define GROUP_SIZE      (GROUP_BITS / BITS_PER_BYTE)    // 64
#define SUBGROUPS_PER_GROUP 16
#define SUBGROUP_BITS       (GROUP_BITS / SUBGROUPS_PER_GROUP)  // 32
#define SUBGROUP_SIZE       (GROUP_SIZE / SUBGROUPS_PER_GROUP)  // 4


#define F(x,y,z)    (((x) & (y)) | ((~(x)) & (z)))
#define G(x,y,z)    (((x) & (z)) | ((y) & (~(z))))
#define H(x,y,z)    ((x) ^ (y) ^ (z))
#define I(x,y,z)    (y ^ ((x) | (~(z))))
#define MIN(x,y)    (((x) < (y)) ? (x) : (y))


#define VAR_INPUT_LEN_SIZE  8

#define ROL(val,n)  (((val) << (n)) | ((val) >> (32 - (n))))
#define ABS(x)      ((x) >= 0 ? (x) : -(x))


#define BUF_SIZE    1024

void transform(unsigned char sub_group[SUBGROUPS_PER_GROUP][SUBGROUP_SIZE], unsigned int * state);
unsigned char read_buf[BUF_SIZE + GROUP_SIZE] = { 0 };


bool has_init_ti = false;

unsigned int state_init[] = {
        0x67452301,
        0xEFCDAB89,
        0x98BADCFE,
        0x10325476
};

unsigned int ti[64];
//static unsigned int round_index[64];
const unsigned int s[][4] = {
        { 7, 12, 17, 22 },{ 7, 12, 17, 22 },{ 7, 12, 17, 22 },{ 7, 12, 17, 22 },
        { 5, 9, 14, 20 },{ 5, 9, 14, 20 },{ 5, 9, 14, 20 },{ 5, 9, 14, 20 },
        { 4, 11, 16, 23 },{ 4, 11, 16, 23 },{ 4, 11, 16, 23 },{ 4, 11, 16, 23 },
        { 6, 10, 15, 21 },{ 6, 10, 15, 21 },{ 6, 10, 15, 21 },{ 6, 10, 15, 21 }
};

void md5init(void)
{
        if (!has_init_ti)
        {
                for (int i = 0; i < 64; i++){
			ti[i] = (1UL << 32) * ABS(sin(i + 1));
		}
                has_init_ti = true;
        }

}

unsigned char sub_group[SUBGROUPS_PER_GROUP][SUBGROUP_SIZE];
unsigned int * state;
void useOftransform(){

	transform(sub_group[SUBGROUPS_PER_GROUP][SUBGROUP_SIZE], state);
}
void  md54file(const char * filename,char * md5str){
        unsigned char * group_start = NULL;
        size_t dest_len = 0;
        unsigned char sub_group[SUBGROUPS_PER_GROUP][SUBGROUP_SIZE] = { 0 };
        unsigned int state[4] = { 0 };
        unsigned char * pstate = (unsigned char *)state;
        char * poutput = md5str;

        md5init();

        FILE * fp;
        size_t count;

        if ((fp = fopen(filename, "r")) == NULL)
        {
                perror("fopen");
                return ;
        }

        memcpy(state, state_init, sizeof(int) * 4);

        memset(read_buf, 0, BUF_SIZE + GROUP_SIZE);
        while ((count = fread(read_buf, 1, BUF_SIZE, fp)) > 0)
        {
                dest_len += count;
                group_start = read_buf;
                for (int i = 0;
                        i < count / GROUP_SIZE;
                        i++, group_start += GROUP_SIZE)
                {
                        memcpy((unsigned char *)sub_group, group_start, GROUP_SIZE);
                        transform(sub_group, state);
                }

                if (count % GROUP_SIZE != 0)
                {
                        count %= GROUP_SIZE;
                        break;
                }

                memset(read_buf, 0, BUF_SIZE);
        }
        if (ferror(fp))
        {
                perror("fread");
                return ;
        }
        else if (feof(fp))
        {
                int times = 0;
                if (count == 0)
                {
                        memset(read_buf, 0, BUF_SIZE);
                        group_start = read_buf;
                }
                else
                        memset(group_start + count, 0, GROUP_SIZE - count);
                times = add_bits(group_start, dest_len);

                for (int i = 0; i < times; i++)
                {
                        memcpy((unsigned char *)sub_group, group_start, GROUP_SIZE);
                        transform(sub_group, state);
                        group_start += GROUP_SIZE;
                }
		 }

        if (fclose(fp) != 0)
        {
                perror("fclose");
                return ;
        }

        for (int i = 0; i < 16; i++)
        {
                snprintf(poutput, 3, "%02x", *pstate);
                poutput += 2;
                pstate++;
        }

}

int add_bits(unsigned char * buf, size_t src_len)
{
        size_t current_len;
        size_t rest_len;
        size_t dest_len;
        int times = 1;

        current_len = src_len % GROUP_SIZE;
        if (current_len == 0){
		dest_len = GROUP_SIZE;
	}
        else{
		dest_len = (current_len + GROUP_SIZE - 1) / GROUP_SIZE * GROUP_SIZE;
	}
        rest_len = GROUP_SIZE - current_len % GROUP_SIZE;

        if (rest_len <= VAR_INPUT_LEN_SIZE)
        {
                dest_len += GROUP_SIZE;
                memset(read_buf + BUF_SIZE, 0, GROUP_SIZE);
                times++;
        }

        buf[current_len] = 0x80;
		*(uint64_t *)(buf + dest_len - VAR_INPUT_LEN_SIZE) = (uint64_t)src_len * BITS_PER_BYTE;

        return times;
}

/*
* transform: 转换分组
*/
void transform(unsigned char sub_group[SUBGROUPS_PER_GROUP][SUBGROUP_SIZE], unsigned int * state)
{
        unsigned int a;
        unsigned int b;
        unsigned int c;
        unsigned int d;
        unsigned int tmp;
        unsigned int result, index;

        a = state[0];
        b = state[1];
        c = state[2];
        d = state[3];

        for (int i = 0; i < 64; i++)
        {
                if (i < 16)
                {
						result = F(b, c, d);
                        index = i;
                }
                else if (i < 32)
                {
                        result = G(b, c, d);
                        index = (5 * i + 1) % 16;
                }
                else if (i < 48)
                {
                        result = H(b, c, d);
                        index = (3 * i + 5) % 16;
                }
                else
                {
                        result = I(b, c, d);
                        index = (7 * i) % 16;
                }

                tmp = d;
                d = c;
                c = b;
                b = b + ROL(
                        a + result + *(unsigned int *)&sub_group[index] + ti[i],
                        *((const unsigned int *)s + i));
                a = tmp;
        }
        state[0] += a;
        state[1] += b;
        state[2] += c;
        state[3] += d;
}

#endif
