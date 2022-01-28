#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *input, *output;
    struct timespec start, end, diff;
    int target, n_num, x, y, *arr;

    srand(time(NULL));
    n_num = rand() % 1000000;
    arr = (int *)calloc(n_num, sizeof(int));
    for (int i = 0; i < n_num; ++i) {
        arr[i] = rand() % 100000000 - 50000000;
    }
    do {
        x = rand() % n_num;
        y = rand() % n_num;
    } while (x == y);
    target = arr[x] + arr[y];
    input = fopen("./input.txt", "w+");
    if (input == NULL) {
        fprintf(stderr, "Open input.txt error\n");
        exit(1);
    }
    fprintf(input, "%d %d\n", target, n_num);
    for (int i = 0; i < n_num; ++i) {
        fprintf(input, "%d%c", arr[i], " \n"[i == n_num - 1]);
    }
    fclose(input);

    clock_gettime(CLOCK_MONOTONIC, &start);
    system("./Two_Sum_in_C < input.txt | cat > output.txt");
    clock_gettime(CLOCK_MONOTONIC, &end);
    diff.tv_sec = end.tv_sec - start.tv_sec;
    diff.tv_nsec = end.tv_nsec - start.tv_nsec;
    if (diff.tv_sec >= 0 && diff.tv_nsec < 0) {
        diff.tv_nsec += 1000000000;
        diff.tv_sec -= 1;
    } else if (diff.tv_sec < 0 && diff.tv_nsec > 0) {
        diff.tv_nsec -= 1000000000;
        diff.tv_sec += 1;
    }

    output = fopen("./output.txt", "r");
    if (output == NULL) {
        fprintf(stderr, "Open output.txt error\n");
        exit(1);
    }
    fscanf(output, "%d %d", &x, &y);
    if (arr[x] + arr[y] == target) {
        printf("test passed\n");
        printf("Time spend: %ld.%03lds in array size %d\n", diff.tv_sec, diff.tv_nsec / 1000000, n_num);
    } else {
        printf("test failed\n");
    }
    fclose(output);
    free(arr);

    system("rm -f input.txt output.txt");
    return 0;
}
