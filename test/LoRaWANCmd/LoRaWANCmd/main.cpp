#include <stdlib.h>
#include "LoRaWANCmd.h"

int main() {
	char str[] = "12";
	printf("Ҫ���͵����ݣ�%s\nAT����Ϊ��", str);
	sendData(str);
	printf("\n");
	system("pause");
	return 0;
}