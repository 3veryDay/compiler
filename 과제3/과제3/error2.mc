void sort_array(int arr[], int size) {
    int temp;
    int i, j;
    if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int numbers[5) = {4, 2, 5, 1, 3}; 

    sort_array(numbers, 5);

    return 0;
}
