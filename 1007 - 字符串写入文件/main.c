#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

static char msg_file_save[256] = { 0 };
const static char  save_file[] = "text.txt";

void write_string_sile(const char* str)
{
	FILE* fp = NULL;

	const char* filename = save_file;

	fp = fopen(filename, "w+");

	for (int i = 0; i < strlen(str); i++)
	{
		fputc(str[i], fp);
	}

	fclose(fp);
}

const char* read_string_file()
{
    FILE* file = fopen(save_file, "r");

    if (file == NULL)
    {
        printf("Error: file pointer is null.");
        exit(1);
    }

    int maximumLineLength = 128;
    char* lineBuffer = (char*)malloc(sizeof(char) * maximumLineLength);

    if (lineBuffer == NULL)
    {
        printf("Error allocating memory for line buffer.");
        exit(1);
    }

    char ch = getc(file);
    int count = 0;

    while ((ch != '\n') && (ch != EOF))
    {
        if (count == maximumLineLength)
        {
            maximumLineLength += 128;
            lineBuffer = realloc(lineBuffer, maximumLineLength);
            if (lineBuffer == NULL) {
                printf("Error reallocating space for line buffer.");
                exit(1);
            }
        }
        lineBuffer[count] = ch;
        count++;

        ch = getc(file);
    }

    lineBuffer[count] = '\0';
    strncpy(msg_file_save, lineBuffer, (count + 1));
    free(lineBuffer);
    const char* constLine = msg_file_save;
    return constLine;
}


int main()
{
	const char* str = "sdfkfghftusdfs5df";
    char str2[] = "sdfkfghftusdfs5df";

    write_string_sile(str2);

	read_string_file();
	printf("%s\n", read_string_file());//msg_file_save
}