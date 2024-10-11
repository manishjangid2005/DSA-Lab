// Linear Search in C

#include <stdio.h>

int linearSearch(int arr[], int key, int size) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 6, 5, 3, 7};
    int key = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = linearSearch(arr, key, size);
    (index == -1)
        ? printf("Error, Key is not present in this array index")
        : printf("%d", index);
    return 0;
}
