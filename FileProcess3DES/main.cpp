#include <openssl/des.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
//黄皓恒 2021150109
using namespace std;

void process_file(const char *input_file, const char *output_file, int encrypt) {
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");

    if (!in_file || !out_file) {
        fprintf(stderr, "Could not open file.\n");
        exit(1);
    }

    static DES_cblock key1 = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    static DES_cblock key2 = {0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10};
    static DES_cblock key3 = {0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18};
    DES_key_schedule schedule1, schedule2, schedule3;

    DES_set_key_unchecked(&key1, &schedule1);
    DES_set_key_unchecked(&key2, &schedule2);
    DES_set_key_unchecked(&key3, &schedule3);

    unsigned char buffer[8];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, 8, in_file)) > 0) {
        if (bytes_read < 8) {
            // Padding
            memset(buffer + bytes_read, 8 - bytes_read, 8 - bytes_read);
        }

        if (encrypt) {
            DES_ecb3_encrypt((DES_cblock*)buffer, (DES_cblock*)buffer, &schedule1, &schedule2, &schedule3, DES_ENCRYPT);
        } else {
            DES_ecb3_encrypt((DES_cblock*)buffer, (DES_cblock*)buffer, &schedule1, &schedule2, &schedule3, DES_DECRYPT);
        }

        fwrite(buffer, 1, 8, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

int main() {
    string input_file, output_file;
    int encrypt;

    cout << "Enter the path of the file to process: ";
    cin >> input_file;
    cout << "Enter the path for the output file: ";
    cin >> output_file;
    cout << "Enter 1 to encrypt or 0 to decrypt: ";
    cin >> encrypt;

    process_file(input_file.c_str(), output_file.c_str(), encrypt);

    return 0;
}

//doc测试
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\doc_Origin.docx
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\doc_Encrypted.enc
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\doc_Decrypted.docx

//txt测试
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\txt_Origin.txt
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\txt_Encrypted.enc
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\txt_Decrypted.txt

//mp3测试
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\mp3_Origin.mp3
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\mp3_Encrypted.enc
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\mp3_Decrypted.mp3

//jpg测试
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\jpg_Origin.jpg
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\jpg_Encrypted.enc
//C:\Users\BloomingWind\CLionProjects\FileProcess3DES\jpg_Decrypted.jpg