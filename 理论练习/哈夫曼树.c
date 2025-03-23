#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 256
#define MAX_CODE_LENGTH 32
// ����ڵ�
typedef struct {
    char character;
    char code[MAX_CODE_LENGTH];
    int code_length;
} Code;
// ����Ƿ�Ϊ����������
int is_huffman_encoding(Code codes[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                int k;
                for (k = 0; k < codes[i].code_length && k < codes[j].code_length; ++k) {
                    if (codes[i].code[k] != codes[j].code[k]) {
                        break;
                    }
                }
                // ����ַ�i�ı������ַ�j�����ǰ׺�����߷�֮�����ǹ���������
                if (k == codes[i].code_length && codes[j].code_length > k) {
                    return 0;
                }
                if (k == codes[j].code_length && codes[i].code_length > k) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main() {
    Code codes[MAX_CHARS];
	int size = 0;
	printf("������ڵ��Լ���Ӧ�Ĺ��������루��������'a:0'��ʾ�ַ�'a'�ı���Ϊ'0'����\n");
	while (scanf(" %c:%s", &codes[size].character, codes[size].code) == 2) {
	    codes[size].code_length = strlen(codes[size].code);
	    size++;
	    if (size >= 4) { // �����������4���ַ�����
	        break;
	    }
	}
	for (int i = 0; i < size; i++) {
	    printf("%c:%s\n", codes[i].character, codes[i].code);
	}
    // ����Ƿ�Ϊ����������
    if (is_huffman_encoding(codes, size)) {
        printf("�����ı����ǹ��������롣\n");
    } else {
        printf("�����ı��벻�ǹ��������롣\n");
    }
    return 0;
}
