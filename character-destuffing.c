#include <stdio.h>
#include <string.h>

int main() {
    char stuffed[100], destuffed[100];
    int i, j = 0;

    printf("Enter the stuffed data: ");
    scanf("%s", stuffed);

    // Skip starting flag $
    i = 1;

    while (stuffed[i] != '\0') {

        // Stop at ending flag $
        if (stuffed[i] == '$') {
            break;
        }

        // If escape character is found, skip it
        if (stuffed[i] == '/') {
            i++;
        }

        destuffed[j++] = stuffed[i];
        i++;
    }

    destuffed[j] = '\0';

    printf("After Character De-stuffing: %s\n", destuffed);

    return 0;
}
