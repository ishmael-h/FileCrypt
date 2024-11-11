#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // This code is exactly the same as encrypt.c
    // XOR encryption is symmetric, so the same operation
    // is used for both encryption and decryption.

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    char *key = argv[3];
    int key_len = strlen(key);
    int key_index = 0;

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ key[key_index], output_file);
        key_index = (key_index + 1) % key_len;
    }

    fclose(input_file);
    fclose(output_file);

    printf("File decrypted successfully!\n");
    return 0;
}
