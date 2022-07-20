#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
int hextodec(uint32_t htd) {
	int dec = 0;
	char str[10];
	sprintf(str, "%x", htd);
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'F')
			dec = dec * 16 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			dec = dec * 16 + str[i] - 'a' + 10;
		else if (str[i] >= '0' && str[i] <= '9')
			dec = dec * 16 + str[i] - '0';
	}
	return dec;
}
int main(int argc, char* argv[]) {
	if(argc != 3) {
		printf("인자 2개 필요\n");
	} else {
		FILE* fp1 = fopen(argv[1], "rb");
       		FILE* fp2 = fopen(argv[2], "rb");
		if (fp1 == NULL) {
			printf("fopen Error\n");
			return 1;
		} else {
			uint32_t data1, data2;
			fread(&data1, sizeof(uint32_t), 1, fp1);
			fread(&data2, sizeof(uint32_t), 1, fp2);
			data1 = ntohl(data1);
			data2 = ntohl(data2);
			printf("%d(0x%x) + ", hextodec(data1), data1);
			printf("%d(0x%x) = ", hextodec(data2), data2);
			printf("%d(0x%x)\n", hextodec(data1+data2), data1+data2);
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
	}
}
