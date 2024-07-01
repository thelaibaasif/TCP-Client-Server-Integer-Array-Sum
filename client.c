#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 12345

int main() {
struct sockaddr_in address;
int sock = 0, valread;
struct sockaddr_in serv_addr;
int buffer[1024] = {0};
int sum;

if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
printf("\n error \n");
return -1;
}

memset(&serv_addr, '0', sizeof(serv_addr));

serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);

if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
printf("\nConnection Failed \n");
return -1;
}

printf("Enter the size of the array: ");
int size;
scanf("%d", &size);
printf("Enter the elements of the array: ");
for (int i = 0; i < size; i++) {
scanf("%d", &buffer[i]);
}
send(sock , buffer , sizeof(buffer) , 0 );
printf("Array sent to server\n");
valread = read( sock , &sum, sizeof(sum));
printf("Sum of array elements received from server: %d\n", sum);
return 0;
}
