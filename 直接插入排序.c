#include <stdio.h>
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        // ��arr[0..i-1]�д���key��Ԫ�غ���
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        // ���ÿ������������
        printf("��%d�Σ�", i);
        for (int i = 0; i < size; i++) {
		    printf("%d,", arr[i]);
		}
		printf("\n");
    }
}
int main() {
    int arr[] = {44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    return 0;
}
