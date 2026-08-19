#include <stdio.h>

int main() {
    char stuffed[100], destuffed[100];
    int i, j = 0, count = 0;

    printf("Enter the stuffed data: ");
    scanf("%s", stuffed);

    for (i = 0; stuffed[i] != '\0'; i++) {

        destuffed[j++] = stuffed[i];

        if (stuffed[i] == '1') {
            count++;

            // After five 1s, skip the stuffed 0
            if (count == 5) {
                if (stuffed[i + 1] == '0') {
                    i++;
                }
                count = 0;
            }
        }
        else {
            count = 0;
        }
    }

    destuffed[j] = '\0';

    printf("After Bit De-stuffing: %s\n", destuffed);

    return 0;
}
