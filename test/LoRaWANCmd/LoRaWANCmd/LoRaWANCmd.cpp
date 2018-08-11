#include "LoRaWANCmd.h"

void sendData(char data[]) {
	int n = 0;
	while (data[n++] != '\0');
	n--;
	char str[0xFF];
	char t[3];
	int i;
	for (i = 0; i<n; i++) {
		sprintf_s(t, "%x", data[i]);
		str[i * 2] = t[0];
		str[i * 2 + 1] = t[1];
	}
	str[2 * n] = '\0';
	if (n < 10)
		sprintf_s(t, "0%d", n);
	else
		sprintf_s(t, "%d", n);
	printf("AT+TX=02+00+01+%s+%s", t,str);
}