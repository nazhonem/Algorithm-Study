#include <stdio.h>

#define ARRAY_SIZE 5000

void bubble_sort(int arr[]);
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
        fscanf(file, "%d", &numbers[i]);

        if (feof(file)) {
            break;
        }
    }

    fclose(file);

    bubble_sort(numbers);

    FILE *sorted_file = fopen("sorted.txt", "wb");
    if (sorted_file) {
        fwrite(numbers, sizeof(int), ARRAY_SIZE, sorted_file);
        fclose(sorted_file);
    } else {
        perror("Error opening sorted.txt");
    }

    return 0;

}

void bubble_sort(int arr[])
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