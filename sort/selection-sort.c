#include <stdio.h>

#define ARRAY_SIZE 5000

void selection_sort(int arr[]);
void swap(int *a, int *b);

int main(int argc, char *argv[])
{
    // Check for correct number of args
    if (argc != 2) {
        printf("Usage: ./bubble <filename>\n");
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
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            printf("Failed to read number at index %d\n", i);
            break;
        }
    }

    fclose(file);

    selection_sort(numbers);

    FILE *sorted_file = fopen("sorted.txt", "w");
    if (sorted_file) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (fprintf(sorted_file, "%d\n", numbers[i]) < 0) {
                printf("Failed to write number at index %d\n", i);
            }
        }
        fclose(sorted_file);
    } else {
        perror("Error opening sorted.txt");
        return 1;
    }

    return 0;
}

void selection_sort(int arr[])
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int smallest = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        swap(&arr[i], &arr[smallest]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}