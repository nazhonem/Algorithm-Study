// simple linear search implementation in C
#include <stdio.h>

#define ARRAY_SIZE 5000

int linear_search(int arr[], int target);

int main(int argc, char *argv[])
{
    // Check for correct number of args
    if (argc != 2) {
        printf("Usage: ./linear <filename>\n");
        return 1;
    }

    int numbers[ARRAY_SIZE];
    int target, location;

    // Open file from CLI
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // scan in numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        fscanf(file, "%d", &numbers[i]);

        if (feof(file)) {
            break;
        }
    }

    fclose(file);

    do {
        printf("Number to search for ");
        scanf("%d", &target);
    } while (target <= 0);

    location = linear_search(numbers, target);

    if (location != -1) {
        printf("Found %d at index %d\n", target, location);
    } else {
        printf("%d not found in the array\n", target);
    }

    return 0;
}

int linear_search(int arr[], int target)
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
