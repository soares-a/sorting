#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipo das funções de ordenação
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);

// Função para imprimir um array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    printf("Digite os elementos da lista:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: ");
    printArray(arr, size);
    printf("Tempo: %.6f segundos\n", timeTaken);

    // Selection Sort
    start = clock();
    selectionSort(arr, size);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: ");
    printArray(arr, size);
    printf("Tempo: %.6f segundos\n", timeTaken);

    // Insertion Sort
    start = clock();
    insertionSort(arr, size);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: ");
    printArray(arr, size);
    printf("Tempo: %.6f segundos\n", timeTaken);

    // Merge Sort
    start = clock();
    mergeSort(arr, 0, size - 1);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: ");
    printArray(arr, size);
    printf("Tempo: %.6f segundos\n", timeTaken);

    // Quick Sort
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: ");
    printArray(arr, size);
    printf("Tempo: %.6f segundos\n", timeTaken);

    free(arr);

    return 0;
}

// Implementação dos algoritmos de ordenação

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
