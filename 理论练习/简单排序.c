#include <stdio.h>
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ����Ԫ��
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        // �����ǰ������������
        printf("��%d������", i + 1);
        for (int i = 0; i < size; i++) {
		        printf("%d,", arr[i]);
		}
		printf("\n");
    }
}

int main() {
    int arr[] = {44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    return 0;
}
