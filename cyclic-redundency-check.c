#include <stdio.h>
#include <string.h>

int main() {
    char data[100], generator[50], temp[150];
    int data_len, gen_len;
    int i, j;

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter generator: ");
    scanf("%s", generator);

    data_len = strlen(data);
    gen_len = strlen(generator);

    // Copy data and append zeros
    strcpy(temp, data);

    for (i = 0; i < gen_len - 1; i++) {
        temp[data_len + i] = '0';
    }

    temp[data_len + gen_len - 1] = '\0';

    // CRC division using XOR
    for (i = 0; i < data_len; i++) {

        if (temp[i] == '1') {

            for (j = 0; j < gen_len; j++) {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Append CRC remainder to original data
    printf("CRC Remainder: ");

    for (i = data_len; i < data_len + gen_len - 1; i++) {
        printf("%c", temp[i]);
    }

    printf("\nTransmitted Data: %s", data);

    for (i = data_len; i < data_len + gen_len - 1; i++) {
        printf("%c", temp[i]);
    }

    printf("\n");

    return 0;
}
