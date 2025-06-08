#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a[26] = {0}, count_b[26] = {0};
    int i, distinct_a = 0, distinct_b = 0;

    for (i = 0; a[i]; i++)
        count_a[a[i] - 'a'] = 1;
    for (i = 0; b[i]; i++)
        count_b[b[i] - 'a'] = 1;

    for (i = 0; i < 26; i++) {
        distinct_a += count_a[i];
        distinct_b += count_b[i];
    }

    if (distinct_a != distinct_b)
        return distinct_a - distinct_b;

    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a != len_b)
        return len_a - len_b;
    return strcmp(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char*, const char*)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char** arr = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        arr[i] = malloc(1024 * sizeof(char));
        scanf("%s", arr[i]);
        arr[i] = realloc(arr[i], strlen(arr[i]) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    // Free memory
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
