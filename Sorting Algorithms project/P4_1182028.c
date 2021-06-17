//muntherr anati 1182028
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define init_size 1000

void SelectionSort(int arr[], int n);

void swap(int *a, int *b);

void max_heap(int array[], int size, int i);

void Heap_sort(int array[], int size);

//void display(int array[], int n);

void mergeSort(int arr[], int start, int end);

int find_max(int array[], int size);

int find_min(int array[], int size);

void pigeonhole_sort(int arr[], int size, int min, int max);

int main() {
    char ch[1];
    FILE *fout;

    int choice;
    int left, right;
    double time_spent = 0.0;
    static int array1[init_size], array2[10000], array3[100000], array4[1000000], array5[5000000];
    printf("Welcome to the best Array Generator program\n");
    printf("Please choose generator type of ayrray from the list below\n");
    printf("a-Sorted.\n"
           "b-Random.\n"
           "c-Reversed Order.\n"
           "e-Exit.\n");
    printf("Your choice:");
    scanf("%s", ch);
    while (ch[0] != 'e') {
        int c = 1;
        switch (ch[0]) {

            case 'a': {
                printf("Generate Sorted Array size with:\n1-1000\t2-10000\t3-100000\t4-1000000\t5-5000000\n");
                switch (c) {
                    case 1:
                        array1[1000];
                        for (int i = 0; i < 1000; i++) { array1[i] = i; }
                    case 2:
                        array2[10000];
                        for (int i = 0; i < 10000; i++) { array2[i] = i; }
                    case 3:
                        array3[100000];
                        for (int i = 0; i < 100000; i++) { array3[i] = i; }
                    case 4:
                        array4[1000000];
                        for (int i = 0; i < 1000000; i++) { array4[i] = i; }
                    case 5:
                        array5[5000000];
                        for (int i = 0; i < 5000000; i++) { array5[i] = i; }
                }
            }
                break;
            case 'b': {
                printf("Generate Randomly Array size with:\n1-1000\t2-10000\t3-100000\t4-1000000\t5-5000000\n");
                printf(">>>>>>");
                switch (c) {
                    case 1:

                        array1[1000];
                        for (int i = 0; i < 1000; i++) { array1[i] = (rand() % 1000); }
                    case 2:
                        array2[10000];
                        for (int i = 0; i < 10000; i++) { array2[i] = (rand() % 10000); }
                    case 3:
                        array3[100000];
                        for (int i = 0; i < 100000; i++) { array3[i] = (rand() % 100000); }
                    case 4:
                        array4[1000000];
                        for (int i = 0; i < 1000000; i++) { array4[i] = (rand() % 1000000); }
                    case 5:
                        array5[5000000];
                        for (int i = 0; i < 5000000; i++) { array5[i] = (rand() % 5000000); }
                }
            }
                break;
            case 'c': {
                printf("Generate Reverse Order Array size with:\n1-1000\t2-10000\t3-100000\t4-1000000\t5-5000000\n");
                switch (c) {
                    case 1:

                        array1[1000];
                        int size1 = 1000 - 1;
                        for (int i = 0; i < 1000; i++, size1--) { array1[i] = size1; }
                    case 2:
                        array2[10000];
                        int size2 = 10000 - 1;
                        for (int i = 0; i < 10000; i++, size2--) { array2[i] = size2; }
                    case 3:
                        array3[100000];
                        int size3 = 100000 - 1;
                        for (int i = 0; i < 100000; i++, size3--) { array3[i] = size3; }
                        //display(array3,size3);
                    case 4:
                        array4[1000000];
                        int size4 = 1000000 - 1;
                        for (int i = 0; i < 1000000; i++, size4--) { array4[i] = size4; }
                    case 5:
                        array5[5000000];
                        int size5 = 5000000 - 1;
                        for (int i = 0; i < 5000000; i++, size5--) { array5[i] = size5; }

                }
            }
                break;

        }

        printf("Please choose generator type of array from the list below\n");
        printf("a-Sorted.\n"
               "b-Random.\n"
               "c-Reversed Order.\n"
               "e-Exit.\n");
        printf("Your choice:");
        scanf("%s", ch);
    }

    clock_t begin;
    clock_t end;
    int flag = 0;
    fout = fopen("Generate.txt", "wt");

    //  fclose(fout);
    printf("Please choose the type of sorting algorithm to be used from the list below:.\n"
           "1-Selection Sort.\n"
           "2-Heap Sort.\n"
           "3-merge Sort.\n"
           "4-pigeonhole Sort.\n"
           "5-All.\n"
           "6-Exit.\n");
    scanf("%d", &choice);
    while (choice != 6) {
        if (flag == 0) {
            fprintf(fout,
                    "Algorithm Sort :\t \"1000\"      |    \"10000\"      |    \"100000\"     |    \"1000000\"   |    \"5000000\"    |");
            flag = 1;
        }
        switch (choice) {
            case 1: {
fout=fopen("Selection sort Generator.txt","w");
                // printf("Selection Sort  for array1 with size 1000\n" );
                begin = clock();
                SelectionSort(array1, 1000);//Selection sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "Selection Sort :\t \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                //  printf("Selection Sort  for array2 with size 10000\n" );
                begin = clock();
                SelectionSort(array2, 10000);//Selection sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                // printf("Selection Sort  for array3 with size 100000\n" );
                begin = clock();
                SelectionSort(array3, 100000);//Selection sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                //printf("Selection Sort  for array4 with size 1000000\n" );
                begin = clock();
                SelectionSort(array4, 1000000);//Selection sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                // printf("Selection Sort  for array5 with size 5000000\n" );
                begin = clock();
                SelectionSort(array5, 5000000);//Selection sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);
                fclose(fout);

            }
                break;
            case 2: {
                fout = fopen("Heap Sort Generator.txt", "w");
                begin = 0;
                end = 0;
                time_spent = 0.0;
                fprintf(fout, "\n");
                begin = clock();
                Heap_sort(array1, 1000);//Heap_sort sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "Heap Sort      :\t \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                Heap_sort(array2, 10000);//Heap_sort sort for array1 and size 10000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                begin = clock();
                Heap_sort(array3, 100000);//Heap_sort for array3 and size 100000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                Heap_sort(array4, 1000000);//Heap_sort for array4 and size 1000000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                Heap_sort(array5, 5000000);//Heap_sort for array1 and size 5000000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);
                fclose(fout);


            }
                break;
            case 3: {
                fout = fopen("Merge Sort Generator.txt", "w");
                begin = 0;
                end = 0;
                time_spent = 0.0;
                fprintf(fout, "\n");
                //printf("Algorithm Sort:\t \"1000\"      |    \"10000\"      |    \"100000\"      |    \"1000000\"      |    \"5000000\"\n");
                // printf("Selection Sort  for array1 with size 1000\n" );
                begin = clock();
                left = find_min(array1, 1000);
                right = find_max(array1, 1000);
                mergeSort(array1, left, right);//mergeSort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "Merge Sort    :\t \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                left = find_min(array2, 10000);
                right = find_max(array2, 10000);
                mergeSort(array2, left, right);//mergeSort for array2 and size 10000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                left = find_min(array3, 100000);
                right = find_max(array3, 100000);
                mergeSort(array3, left, right);//mergeSort for array3 and size 100000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                left = find_min(array4, 1000000);
                right = find_max(array4, 1000000);
                mergeSort(array4, left, right);//mergeSort for array4 and size 1000000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                begin = clock();
                left = find_min(array5, 5000000);
                right = find_max(array5, 5000000);
                mergeSort(array5, left, right);//mergeSort for array5 and size 5000000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);
                fclose(fout);

            }
                break;
            case 4: {
                fout = fopen("pigeonhole Sort Generator.txt", "w");
                begin = 0;
                end = 0;
                time_spent = 0.0;
                fprintf(fout, "\n");

                begin = clock();
                left = find_min(array1, 1000);
                right = find_max(array1, 1000);
                pigeonhole_sort(array1, 1000, left, right);//pigeonhole_sort for array1 and size 1000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "pigeonhole Sort:\t \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                left = find_min(array2, 10000);
                right = find_max(array2, 10000);
                pigeonhole_sort(array2, 10000, left, right);//pigeonhole_sort for array2 and size 10000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                left = find_min(array3, 100000);
                right = find_max(array3, 100000);
                pigeonhole_sort(array3, 100000, left, right);//pigeonhole_sort for array3 and size 100000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;

                begin = clock();
                left = find_min(array4, 1000000);
                right = find_max(array4, 1000000);
                pigeonhole_sort(array4, 1000000, left, right);//pigeonhole_sort for array4 and size 1000000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"  |", time_spent);

                time_spent = 0.0;
                begin = 0;
                end = 0;
                // printf(" pigeonhole_sort  for array5 with size 5000000\n" );
                begin = clock();
                left = find_min(array5, 5000000);
                right = find_max(array5, 5000000);
                pigeonhole_sort(array5, 5000000, left, right);//pigeonhole_sort for array5 and size 5000000
                end = clock();
                time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                fprintf(fout, "    \"%f\"   |", time_spent);
                fclose(fout);


            }
                break;
            case 5:
                switch (1) {
                    case 1: {
                        fout = fopen("ALL.txt", "w");
                        // printf("Selection Sort  for array1 with size 1000\n" );
                        begin = clock();
                        SelectionSort(array1, 1000);//Selection sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "\nSelection Sort :\t \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        //  printf("Selection Sort  for array2 with size 10000\n" );
                        begin = clock();
                        SelectionSort(array2, 10000);//Selection sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        // printf("Selection Sort  for array3 with size 100000\n" );
                        begin = clock();
                        SelectionSort(array3, 100000);//Selection sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        //printf("Selection Sort  for array4 with size 1000000\n" );
                        begin = clock();
                        SelectionSort(array4, 1000000);//Selection sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        // printf("Selection Sort  for array5 with size 5000000\n" );
                        begin = clock();
                        SelectionSort(array5, 5000000);//Selection sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);
                    }
                    case 2: {
                        begin = 0;
                        end = 0;
                        time_spent = 0.0;
                        fprintf(fout, "\n");
                        begin = clock();
                        Heap_sort(array1, 1000);//Heap_sort sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "Heap Sort      :\t \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        Heap_sort(array2, 10000);//Heap_sort sort for array1 and size 10000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        begin = clock();
                        Heap_sort(array3, 100000);//Heap_sort for array3 and size 100000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        Heap_sort(array4, 1000000);//Heap_sort for array4 and size 1000000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        Heap_sort(array5, 5000000);//Heap_sort for array1 and size 5000000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                    }
                    case 3: {
                        begin = 0;
                        end = 0;
                        time_spent = 0.0;
                        fprintf(fout, "\n");
                        //printf("Algorithm Sort:\t \"1000\"      |    \"10000\"      |    \"100000\"      |    \"1000000\"      |    \"5000000\"\n");
                        // printf("Selection Sort  for array1 with size 1000\n" );
                        begin = clock();
                        left = find_min(array1, 1000);
                        right = find_max(array1, 1000);
                        mergeSort(array1, left, right);//mergeSort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "Merge Sort    :\t \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        left = find_min(array2, 10000);
                        right = find_max(array2, 10000);
                        mergeSort(array2, left, right);//mergeSort for array2 and size 10000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        left = find_min(array3, 100000);
                        right = find_max(array3, 100000);
                        mergeSort(array3, left, right);//mergeSort for array3 and size 100000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        left = find_min(array4, 1000000);
                        right = find_max(array4, 1000000);
                        mergeSort(array4, left, right);//mergeSort for array4 and size 1000000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        begin = clock();
                        left = find_min(array5, 5000000);
                        right = find_max(array5, 5000000);
                        mergeSort(array5, left, right);//mergeSort for array5 and size 5000000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);
                    }
                    case 4: {
                        begin = 0;
                        end = 0;
                        time_spent = 0.0;
                        fprintf(fout, "\n");

                        begin = clock();
                        left = find_min(array1, 1000);
                        right = find_max(array1, 1000);
                        pigeonhole_sort(array1, 1000, left, right);//pigeonhole_sort for array1 and size 1000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "pigeonhole Sort:\t \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        left = find_min(array2, 10000);
                        right = find_max(array2, 10000);
                        pigeonhole_sort(array2, 10000, left, right);//pigeonhole_sort for array2 and size 10000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        left = find_min(array3, 100000);
                        right = find_max(array3, 100000);
                        pigeonhole_sort(array3, 100000, left, right);//pigeonhole_sort for array3 and size 100000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;

                        begin = clock();
                        left = find_min(array4, 1000000);
                        right = find_max(array4, 1000000);
                        pigeonhole_sort(array4, 1000000, left, right);//pigeonhole_sort for array4 and size 1000000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"  |", time_spent);

                        time_spent = 0.0;
                        begin = 0;
                        end = 0;
                        // printf(" pigeonhole_sort  for array5 with size 5000000\n" );
                        begin = clock();
                        left = find_min(array5, 5000000);
                        right = find_max(array5, 5000000);
                        pigeonhole_sort(array5, 5000000, left, right);//pigeonhole_sort for array5 and size 5000000
                        end = clock();
                        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
                        fprintf(fout, "    \"%f\"   |", time_spent);

                    }
                        fclose(fout);
                }
        }
        printf("\nPlease choose the type of sorting algorithm to be used from the list below:.\n"
               "1-Selection Sort.\n"
               "2-Heap Sort.\n"
               "3-merge Sort.\n"
               "4-pigeonhole Sort.\n"
               "5-All.\n"
               "6-Exit.\n");
        scanf("%d", &choice);
    }


    // clock_t begin = clock();


    //  printf("After Sorting\n=====================\n");
    //  display(array3, 100000);
    //  clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds

    fclose(fout);


    return 0;
}

void SelectionSort(int arr[], int n) {
    /*Selection sort is a sorting algorithm,
move through the array and finds the smallest number in the array,
and swaps it with the first element if the smallest number in array is smaller than the first element.*/
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        //printf("%d\t", i);
        for (j = i + 1; j < n; j++) {
            if (arr[j] <
                arr[i]) { //if the next element is smaller than the first one then it will swap to get the smaller element
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                //printf("%d\t",temp);
            }
        }

    }
    return;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heap(int array[], int size, int i) {
    int max = i;
    int left = 2 * i + 1; //Left child will be at index 2*i+1 in the array
    int right = 2 * i + 2;//Right child will be at index 2*i+2 in the array
//The parent of right and left child will be at index (i-1)/2
    if (left < size && array[left] > array[max])//if left child greater than max element then max equal the left child
        max = left;

    if (right < size &&
        array[right] > array[max])//if Right child greater than max element then max equal the Right child
        max = right;

    if (max != i) {//If The max element isn't the parent then swap it
        swap(&array[max], &array[i]);
        max_heap(array, size, max);
    }
}

void Heap_sort(int array[], int size) { //I edit the code to sort the array in Ascending Order
    int j = size / 2 - 1;
    for (int i = j; i >= 0; i--)
        max_heap(array, size, i);

    for (int i = size - 1; i >= 0; i--) {//Swap the first Element to be last element in the array
        swap(&array[0], &array[i]);
        max_heap(array, i, 0); //array with index 0 will be the new root or new first element
    }
}
void merge(int arr[], int left, int mid, int right) {

    int l1 = mid - left + 1;// length 1 for left sub array = mid - left +1
    int l2 = right - mid;//length array for right sub array= Right - mid

    static int *leftArray;//Temp arrays used it when split the array from mid
    static int *rightArray;
    rightArray = calloc(l2, sizeof(int));
    leftArray = calloc(l1, sizeof(int));
    //I use Calloc to allocate memory becuase l1 and l2 are changed variables at the run time



    for (int i = 0; i < l1; i++) //copy data from original array to the temp left array (from 0 to mid -1)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < l2; j++)//Copy data from original array to temp right array (from mid to the end or the array)
        rightArray[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    //return data from temp array to the original array
    while (i < l1 && j < l2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    //Copy the remaining elements of Left array .
    for (i; i < l1; i++, k++) {
        arr[k] = leftArray[i];
    }
    //Copy the remaining elements of Right array .
    for (j; j < l2; j++, k++) {
        arr[k] = rightArray[j];
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
/* Same as (left+right)/2, but avoids overflow for
large left and right */

        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int find_max(int array[], int size) {

    int t, i;
    t = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > t)
            t = array[i];
    }
    return (t);
}

int find_min(int array[],
             int size) { //Find min number to use it in worst case of function pigeonhole. worst case (Randomly array sorted)
    int t, i;
    t = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] < t)
            t = array[i];
    }
    return (t);
}

void pigeonhole_sort(int arr[], int size, int min, int max)//it's also called by count sort
{
    if (min == 0 && max == 0) {
        max = find_max(arr, size);// Get Maximum number in the array
        // printf("<%d>",max);
        min = find_min(arr, size);// Get the minimum number in the array
        //printf("<%d>",min);
    }

    int length, i, j, k, count;
    length = max - min + 1;//Number of holes needed(number of element)
    // array of pigeonholes
    static int *holes;
    holes = calloc(length, sizeof(int));

    for (i = 0; i < length; i++)//
    {
        holes[i] = 0;//Make Null array
    }
    // fill the pigeonholes array.
    for (j = 0; j < size; j++)
        holes[arr[j] - min]++;
    // Put the elements back into the array in order.
    k = 0;
    for (count = 0; count < length; count++)
        while ((holes[count]--) > 0) {
            arr[k] = count + min;//Current element is count + minimum element
            k++;
        }
}
