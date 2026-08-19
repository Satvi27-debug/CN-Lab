#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[200];
    int i, j = 0;

    printf("Enter the data: ");
    scanf("%s", data);

    // Start flag
    stuffed[j++] = '$';

    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == '$' || data[i] == '/') {
            stuffed[j++] = '/';   // Stuff escape character
        }

        stuffed[j++] = data[i];
    }

    // End flag
    stuffed[j++] = '$';
    stuffed[j] = '\0';

    printf("After Character Stuffing: %s\n", stuffed);

    return 0;
}
