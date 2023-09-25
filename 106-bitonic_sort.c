#include <stdio.h>

#define UP 1
#define DOWN 0

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
void print_array(int *array, size_t size);

void swap_ints(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == UP && array[i] > array[i + jump]) ||
                (flow == DOWN && array[i] < array[i + jump]))
                swap_ints(array + i, array + i + jump);
        }
        bitonic_merge(array, size, start, jump, flow);
        bitonic_merge(array, size, start + jump, jump, flow);
    }
}

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t cut = seq / 2;
    char *str = (flow == UP) ? "UP" : "DOWN";

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);

        bitonic_seq(array, size, start, cut, UP);
        bitonic_seq(array, size, start + cut, cut, DOWN);
        bitonic_merge(array, size, start, seq, flow);

        printf("Result [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);
    }
}

void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_seq(array, size, 0, size, UP);
}

int main() {
    int array[] = {3, 7, 4, 8, 6, 2, 1, 5};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    print_array(array, size);

    bitonic_sort(array, size);

    printf("Sorted Array: ");
    print_array(array, size);

    return 0;
}
