#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "sha256.h"
#include "md5.h"
#include "crc_crc32.h"



int main(int argc, char **argv)
{
	int hashi;
	unsigned int  calcoff = 0,blksz = 0;
	FILE *f;

	unsigned char calchash[32];
	unsigned char cmphash[32];
	unsigned char *buf=NULL;

	memset(calchash, 0, 32);
	memset(cmphash, 0, 32);
   	if (argc != 3){
        	fprintf(stderr, "Usage: %s file_name hashformat(crc32/md5/sha256)\n", argv[0]);
       		 exit(EXIT_FAILURE);
   	}
	f = fopen(argv[1], "rb");
	if(f==NULL)
	{
		printf("failed to open file\n");
		return 0;
	}
	char* data=NULL;
	if (strcmp(argv[2], "crc32") == 0){  

		long lFileLen;
		/*获取文件字节大小lFileLen*/
		fseek(f, 0, SEEK_END);
		lFileLen = ftell(f); 
		if(lFileLen > 0){
			data = (char *)calloc((lFileLen+1),sizeof(char));
		}
		  /*读文件内容*/
		fseek(f, 0, SEEK_SET);
		fread(data, lFileLen, 1, f);		
		fclose(f);

		uint32_t b;
      	b = crc32(data, (uint32_t)lFileLen);
		free(data);
		printf("%s crc32:  %x", argv[1],b);
    }
    else if (strcmp(argv[2], "md5") == 0)
    {	
		
		/*获取文件字节大小lFileLen*/
		fseek(f, 0, SEEK_END);
		long lFileLen= ftell(f); 
		if(lFileLen > 0){
			data = (char *)malloc((lFileLen+1)*sizeof(char));
		}
		strcpy(data, argv[1]);
		char* str =(char*)malloc(lFileLen*sizeof(char)); 
		if(str!=NULL){
			md54file(data, str);
			free(data);
			printf("%s  md5:   %s", argv[1],str);
			free(str);
		}

    }else if(strcmp(argv[2], "sha256") == 0){
		fseek(f, calcoff, SEEK_SET);
		fread(buf, 1, blksz, f);
		fclose(f);

		sha2(buf, blksz, calchash, 0);
		printf("%s SHA256:  ", argv[1]);
		for(hashi=0; hashi<32; hashi++){
			printf("%02x", calchash[hashi]);
		}
	}else{
			fprintf(stderr, "unsupported hashformat, support(crc32/md5/sha256).\n");
			exit(EXIT_FAILURE);
	}	
	printf("\n");
	return 0;
}


