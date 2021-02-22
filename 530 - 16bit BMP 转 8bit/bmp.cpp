
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

    WORD* inBuf;    // RGBTRIPLE --> WORD
    BYTE* outBuf;

    HANDLE hInputFile, hOutFile;
    DWORD RW;

    cout << "Enter the full name, please: ";
    sFileName = "pict.bmp";
    //cin >> sFileName;

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

#if 0
    std::cout
        << std::endl
        << "--------- info ---------" << std::endl
        << "Разрешение   изображения:  " << Width << " x " << Height << std::endl
        << "Количество бит на пиксел: " << bmpInfoHeader.biBitCount << std::endl
        << "Размер       изображения: " << bmpFileHeader.bfSize / 1024 << "KB" << std::endl
        << "----------------------" << std::endl
        << std::endl;
#endif

    // Выделим память 分配内存
    inBuf = new WORD[Width];    //  --> WORD
    outBuf = new BYTE[Width];    // 16bit --> 8bit

    // Заполним заголовки
    bmpFileHeader.bfOffBits = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader);
    bmpInfoHeader.biBitCount = 8;
    bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + Width * Height + Width * Height % 4;

    // Запишем заголовки
    WriteFile(hOutFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    WriteFile(hOutFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);

    // Палитра черно-белая 输入颜色
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

#if 0
    for (int i = 0; i < 4; i++)
    {
        Palette[i].rgbBlue = i;
        for (int j = 0; j < 16; j++)
        {
            Palette[j].rgbGreen = j;
            for (int k = 0; k < 256; k++)
            {
                Palette[k].rgbRed = k;
            }
        }
    }

    for (int b = 0; b < 2; b++)
    {
        for (int r = 0; r < 2; r++)
        {
            for (int g = 0; g < 4; g++)
            {
                Palette[(b << 3) + (r << 2) + g + 21].rgbBlue = b * 255;
                Palette[(b << 2) + (r << 2) + g + 21].rgbRed = r * 255;
                Palette[(b << 3) + (r << 2) + g + 21].rgbGreen = g * 85;
            }
        }
    }


    // Палитра черно-белая 调色板是黑色和白色的
    for (int i = 0; i < 256; i++)
    {
        Palette[i].rgbBlue = i;
        Palette[i].rgbGreen = i;
        Palette[i].rgbRed = i;
        Palette[i].rgbReserved = 0xff;
    }
#endif


    // Начнем преобразовывать 开始转换
    for (int i = 0; i < Height; i++)
    {

        ReadFile(hInputFile, inBuf, sizeof(WORD) * Width, &RW, NULL);

        for (int j = 0; j < Width; j++)
        {
            outBuf[j] = 0;

            //int tmpRed = inBuf[j] >> 8;
            //int tmpGreen = inBuf[j] >> 8;
            //int tmpBlue = inBuf[j] >> 8;
            //outBuf[j] = tmpRed + tmpGreen + tmpBlue;

            int tmpRed = inBuf[j]    & 0b0111110000000000;
            int tmpGreen = inBuf[j] & 0b0000001111100000;
            int tmpBlue = inBuf[j]    & 0b0000000000011111;

            tmpRed >> 10;
            tmpGreen >> 5;

            if (j % 2 == 0)
            {
                outBuf[j] |= ((tmpBlue +tmpRed + tmpGreen) / (766 / 2)) << 4;
            }
            else
            {
                outBuf[j] |= ((tmpBlue + tmpRed + tmpGreen) / (766 / 2));
            }
        }

        WriteFile(hOutFile, outBuf, sizeof(BYTE) * Width, &RW, NULL);

        // Пишем мусор для выравнивания
        WriteFile(hOutFile, Palette, (3 * Width) % 4, &RW, NULL);
        SetFilePointer(hInputFile, Width % 4, NULL, FILE_CURRENT);
    }

    delete[] inBuf;
    delete[] outBuf;
    CloseHandle(hInputFile);
    CloseHandle(hOutFile);

    cout << "Updating has come to the end successfully!" << std::endl;
    // system("pause");
}