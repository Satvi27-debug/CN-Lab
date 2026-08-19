#include <stdio.h>

int main() {
    int n, window, i, lost;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("Enter lost frame number: ");
    scanf("%d", &lost);

    printf("\nSending frames...\n");

    for (i = 1; i <= n; i++) {

        printf("Frame %d sent\n", i);

        if (i == lost) {
            printf("Frame %d lost!\n", i);
            break;
        }

        printf("ACK %d received\n", i);
    }

    // Go back and retransmit from lost frame
    printf("\nGo-Back-N: Retransmitting from Frame %d\n", lost);

    for (i = lost; i <= n; i++) {
        printf("Frame %d retransmitted\n", i);
        printf("ACK %d received\n", i);
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}
