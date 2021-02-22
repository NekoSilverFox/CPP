#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void main()
{
    system("chcp 65001 && cls");
    DeleteFile("Result.bmp");

    string sFileName;
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    int Width, Height;
    RGBQUAD Palette[256];
    RGBTRIPLE* inBuf;
    BYTE* outBuf;
    HANDLE hInputFile, hOutFile;
    DWORD RW;

    cout << "Enter the full name, please: ";
    sFileName = "pict.bmp";
    hInputFile = CreateFile(sFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hInputFile == INVALID_HANDLE_VALUE)
        return;

    hOutFile = CreateFile("Result.bmp", GENERIC_WRITE, 0, NULL, CREATE_NEW, 0, NULL);
    if (hOutFile == INVALID_HANDLE_VALUE)
    {
        CloseHandle(hInputFile);
        return;
    }

    // Считываем инфу
    ReadFile(hInputFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    ReadFile(hInputFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);

    // Установим указатель на начало растра
    SetFilePointer(hInputFile, bmpFileHeader.bfOffBits, NULL, FILE_BEGIN);
    Width = bmpInfoHeader.biWidth;
    Height = bmpInfoHeader.biHeight;

    // Выделим память
    inBuf = new RGBTRIPLE[Width];
    outBuf = new BYTE[Width];

    // Заполним заголовки
    bmpFileHeader.bfOffBits = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader) + 1024;
    bmpInfoHeader.biBitCount = 8;
    bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + Width * Height + Height * (3 * Width % 4);

    // Запишем заголовки
    WriteFile(hOutFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    WriteFile(hOutFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);
    // Палитра черно-белая
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                Palette[i * 32 + j * 4 + k].rgbRed = i * 32;
                Palette[i * 32 + j * 4 + k].rgbGreen = j * 32;
                Palette[i * 32 + j * 4 + k].rgbBlue = k * 64;
            }
        }
    }
    WriteFile(hOutFile, Palette, 256 * sizeof(RGBQUAD), &RW, NULL);

    // Начнем преобразовывать
    for (int i = 0; i < Height; i++)
    {
        ReadFile(hInputFile, inBuf, sizeof(RGBTRIPLE) * Width, &RW, NULL);
        for (int j = 0; j < Width; j++)
            outBuf[j] = 32 * (inBuf[j].rgbtRed / 32) + 4 * (inBuf[j].rgbtGreen / 32) + inBuf[j].rgbtBlue / 64;

        WriteFile(hOutFile, outBuf, sizeof(BYTE) * Width, &RW, NULL);

        // Пишем мусор для выравнивания
        WriteFile(hOutFile, Palette, (3 * Width) % 4, &RW, NULL);
        SetFilePointer(hInputFile, Width % 4, NULL, FILE_CURRENT);
    }

    delete[] inBuf;
    delete[] outBuf;
    CloseHandle(hInputFile);
    CloseHandle(hOutFile);

    cout << "Updating has come to the end successfully!";
    system("pause");
}
