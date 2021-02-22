
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
    RGBQUAD* outBuf;
    HANDLE hInputFile, hOutFile;
    DWORD RW;

    cout << "Enter the full name, please: ";
    cin >> sFileName;

    hInputFile = CreateFile(sFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hInputFile == INVALID_HANDLE_VALUE)
        return;

    hOutFile = CreateFile("Result.bmp", GENERIC_WRITE, 0, NULL, CREATE_NEW, 0, NULL);
    if (hOutFile == INVALID_HANDLE_VALUE)
    {
        CloseHandle(hInputFile);
        return;
    }

    // Считываем инфу 读取图片信息
    ReadFile(hInputFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    ReadFile(hInputFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);

    // Установим указатель на начало растра 将指针设置为图像的开始
    SetFilePointer(hInputFile, bmpFileHeader.bfOffBits, NULL, FILE_BEGIN);
    Width = bmpInfoHeader.biWidth;
    Height = bmpInfoHeader.biHeight;

    std::cout
        << std::endl
        << "--------- info ---------" << std::endl
        << "Разрешение   изображения:  " << Width << " x " << Height << std::endl
        << "Количество бит на пиксел: " << bmpInfoHeader.biBitCount << std::endl
        << "Размер       изображения: " << bmpFileHeader.bfSize / 1024 << "KB" << std::endl
        << "----------------------" << std::endl
        << std::endl;

    // Выделим память 分配内存
    inBuf = new RGBTRIPLE[Width];
    outBuf = new RGBQUAD[Width];

    // Заполним заголовки
    bmpFileHeader.bfOffBits = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader);
    bmpInfoHeader.biBitCount = 32;
    bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + Width * Height * 4;

    // Запишем заголовки
    WriteFile(hOutFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    WriteFile(hOutFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);

    //// Палитра черно-белая
    //for (int i = 0; i < 256; i++)
    //{
    //    Palette[i].rgbBlue = i;
    //    Palette[i].rgbGreen = i;
    //    Palette[i].rgbRed = i;
    //}
    //WriteFile(hOutFile, Palette, 256 * sizeof(RGBQUAD), &RW, NULL);

    // Начнем преобразовывать 开始转换
    for (int i = 0; i < Height; i++)
    {
        ReadFile(hInputFile, inBuf, sizeof(RGBTRIPLE) * Width, &RW, NULL);
        for (int j = 0; j < Width; j++)
        {
            outBuf[j].rgbRed = inBuf[j].rgbtRed;
            outBuf[j].rgbBlue = inBuf[j].rgbtBlue;                          // ！！！！要给老师展示这一部分！！！！
            outBuf[j].rgbGreen = inBuf[j].rgbtGreen;                    // 这一部分的意思就是，像素的连续拷贝，原图像拷贝到新图像
        }

        WriteFile(hOutFile, outBuf, sizeof(RGBQUAD) * Width, &RW, NULL);
        SetFilePointer(hInputFile, Width % 4, NULL, FILE_CURRENT);
    }

    delete[] inBuf;
    delete[] outBuf;
    CloseHandle(hInputFile);
    CloseHandle(hOutFile);

    cout << "Updating has come to the end successfully!" << std::endl;
    system("pause");
}