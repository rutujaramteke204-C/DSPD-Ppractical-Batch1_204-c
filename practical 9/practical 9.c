#include <stdio.h>

int main() {
    int hash[7], key, index, i;
    for (i = 0; i < 7; i++) hash[i] = -1;

    printf("Enter keys (-1 to stop): ");
    while (1) {
        scanf("%d", &key);
        if (key == -1) break;

        index = key % 7;
        while (hash[index] != -1)
            index = (index + 1) % 7;  // linear probing

        hash[index] = key;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < 7; i++)
        printf("Slot %d → %d\n", i, hash[i]);

    return 0;
}