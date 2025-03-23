#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 256
#define MAX_CODE_LENGTH 32
// 编码节点
typedef struct {
    char character;
    char code[MAX_CODE_LENGTH];
    int code_length;
} Code;
// 检查是否为哈夫曼编码
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
                // 如果字符i的编码是字符j编码的前缀，或者反之，则不是哈夫曼编码
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
	printf("请输入节点以及对应的哈夫曼编码（例如输入'a:0'表示字符'a'的编码为'0'）：\n");
	while (scanf(" %c:%s", &codes[size].character, codes[size].code) == 2) {
	    codes[size].code_length = strlen(codes[size].code);
	    size++;
	    if (size >= 4) { // 假设最多输入4个字符编码
	        break;
	    }
	}
	for (int i = 0; i < size; i++) {
	    printf("%c:%s\n", codes[i].character, codes[i].code);
	}
    // 检查是否为哈夫曼编码
    if (is_huffman_encoding(codes, size)) {
        printf("给定的编码是哈夫曼编码。\n");
    } else {
        printf("给定的编码不是哈夫曼编码。\n");
    }
    return 0;
}
