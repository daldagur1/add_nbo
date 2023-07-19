#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>  

int main() {
    FILE* file1 = fopen("thousand.bin", "rb");
    FILE* file2 = fopen("five-hundred.bin", "rb");

    if (!file1 || !file2) {
        perror("Error opening files");
        return 1;
    }

    uint32_t num1, num2;
    uint32_t sum = 0;

    while (fread(&num1, sizeof(uint32_t), 1, file1) == 1) {
        num1 = ntohl(num1); 
        sum += num1;
    }

    while (fread(&num2, sizeof(uint32_t), 1, file2) == 1) {
        num2 = ntohl(num2); 
        sum += num2;
    }

    printf("Sum of numbers: %u\n", sum);
    printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", num1, num1, num2, num2, sum, sum);

    fclose(file1);
    fclose(file2);

    return 0;
}
