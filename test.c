#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char** argv)
{
 
    FILE *read;
    FILE *write;
    fopen_s(&read, "dll.dll", "rb");
    fopen_s(&write,"dll.txt", "w");
    fseek(read, 0, SEEK_END);
    unsigned int size = ftell(read);
    fseek(read, 0, SEEK_SET);
    unsigned char *mem = (unsigned char*)malloc(size);
    printf("Size: %dkb\n", size);
 
    fread(mem, size, 1, read);
  
    for(unsigned int i = 0; i < size; ++i)
    {
        fprintf(write, "0x%.2X, ", mem[i]);
        if(((i + 1) % 10) == 0)
            fprintf(write, "\n");
    }
    fclose(read);
    fclose(write);
    system("pause");
    return 0;
}
