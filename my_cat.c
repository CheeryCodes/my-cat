#include <stdio.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
    // Check if at least one file is provided as argument
    if (argc < 2) {
        printf("Usage: %s file1 [file2 ...]\n", argv[0]);
        return 1;
    }

    // Buffer to hold file contents
    char buffer[BUFFER_SIZE];

    // Iterate through each file provided as argument
    for (int i = 1; i < argc; i++) {
        // Open the file
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error: Unable to open file '%s'\n", argv[i]);
            continue;  // Move to the next file
        }

        // Read and print the content of the file
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
            fwrite(buffer, 1, bytes_read, stdout);
        }

        // Close the file
        fclose(file);
    }

    return 0;
}
