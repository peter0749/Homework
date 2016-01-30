#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime_bit_map[46341] = {0};
int prime_number_list[46340] = {0};

void make_prime(void);
int is_prime(int);

#define true 1
#define false 0

int main()
{
make_prime(); /*never write void make_prime(void)*/

int input;/*if int can make it, don't use long long int, the result will be TLE*/
while(scanf("%d", &input) != EOF) {
if(is_prime(input) == true)
printf("質數\n");
else
printf("非質數\n");
}

return 0;
}

void make_prime(void)
{
int i, j, index = 0;
for(i = 3; i <= 46340; i+=2) {
if(prime_bit_map[i] == 0) {
for(j = i + i; j <= 46340; j = j + i) {
prime_bit_map[j] = 1;
}
prime_number_list[index++] = i;
}
}
}

int is_prime(int input)
{
if(input == 2)
return true;
else if(input % 2 == 0)
return false;
else if(input <= 46340)
return !prime_bit_map[input];
else {
int i;
for(i = 0; prime_number_list[i] != 0 && prime_number_list[i] * prime_number_list[i] <= input ; i++) {
if(input % prime_number_list[i] == 0)
return false;
}
return true;
}
}
