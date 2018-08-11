#include <stdlib.h>
#include "LoRaWANCmd.h"

int main() {
	char str[] = "12";
	printf("要发送的数据：%s\nAT命令为：", str);
	sendData(str);
	printf("\n");
	system("pause");
	return 0;
}