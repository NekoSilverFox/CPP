#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <xmmintrin.h>
#include <dvec.h>
#include <immintrin.h>
#include <time.h>
// ָ����ͣ� https://blog.csdn.net/hksoobe/article/details/100638536

int main(void)
{
	_DVEC_H_INCLUDED;

	char c_arr_1[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	char c_arr_2[8] = { 2, 2, 2, 2, 2, 2, 2, 2 };

	int i_arr_1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i_arr_2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };


	float a[8] = { 1.1, 2.2, 3.3, 4.4 };
	float b[8] = { 11.1, 12.2, 13.3, 14.4 };
	float c[8] = { 1, 2, 3, 4 };
	float d[8] = { 5, 6, 7, 8 };

	double f[2] = { 16, 4 };
	double e[2] = { 3, 5 };

	char a128[16] = { 1,18,3,19,521,7,23,9,25,11,27,13,29,15,31 };
	char b128[16] = { 17,2,19,4,21,6,23,8,25,10,27,12,29,14,31,16 };

	// dvev
	F32vec4 aa[8];
	aa[1] = aa[2] + aa[3];

	__m64 _mm_add_pi8(__m64 a, __m64 b);  // �����Ĵ����ֳɼ�bit��pi8->��һ��8λ���з������Σ�i����int��8����8λ
	__m128 _mm_add_pi16(__m128 a128, __m128 b128);
	__m256 _mm_add_pi32(__m256 c, __m256 d);
	__m128i _mm_cmpeq_epi16(__m128i a, __m128i b);
	_mm256_and_ps(*(__m256*)c, *(__m256*)d);  // int in

	std::cout << "a - " << a << std::endl;

	// >>>>>>>>>>>>>>>>>>>>>>> mmx
	_asm {
		movq	mm0, c_arr_1
		movq	mm1, c_arr_2
		pcmpeqb	mm0, mm1  //��p compare�� pcmpeqb XMM,XMM/m128
		movq	c_arr_1, mm0  // Ŀ�ļĴ�����Դ�洢�����ֽڱȽ�,�����Ӧ�ֽ����,����Ŀ�ļĴ�����Ӧ�ֽ�Ϊ0ffh,����Ϊ00h�ڴ������������ڴ�16�ֽ�
	}
	std::cout << "Summing elements of vectors c_arr_1 + c_arr_2 :" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << c_arr_1[i] << " ";
	}
	std::cout << std::endl;



	// >>>>>>>>>>>>>>>>>>>>>>> sse
	_asm {
		movups  xmm0, c
		movups	xmm1, d
		addps   xmm0, xmm1  // Դ�洢�����ݰ�˫�ֶ���, ��4�������ȸ�������Ŀ�ļĴ������, �������Ŀ�ļĴ���, �ڴ������������ڴ�16�ֽ�
		movups	c, xmm0
	}
	std::cout << "Summing elements of vectors c + d :" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;


	// >>>>>>>>>>>>>>>>>>>>>>> sse2
	__asm {
		movups xmm1, f
		sqrtpd xmm0, xmm1  // Դ�洢������˫���ȸ������Ŀ��������ӦĿ�ļĴ���,�ڴ������������ڴ�16�ֽ�.
		movups f, xmm0
	}

	std::cout << "Square of " << f[0] << "is" << f[1] << std::endl;
	__asm {
		movups xmm0, a128
		movups xmm1, b128
		pminub xmm0, xmm1  // ��Դ�洢����Ŀ�ļĴ������ֽ��޷��������Ƚ�,��С������Ŀ�ļĴ�����Ӧ�ֽ�, Դ�洢��Ϊm128ʱ,�ڴ������������ڴ�16�ֽ�
		movups a128, xmm0
	}

	std::cout << "Comparing elements: " << std::endl;
	for (int i = 0; i < 16; i++)
	{
		std::cout << "(" << a128[i] << ", " << b128[i] << "); ";
	}
	std::cout << std::endl;

	std::cout << "Minimum elements: " << std::endl;
	for (int i = 0; i < 16; i++)
	{
		std::cout << a128[i] << " ";
	}
	std::cout << std::endl;


	// >>>>>>>>>>>>>>>>>>>>>>> sse3 vHADDPS
	__asm {
		// LDDQU ָ���ܹ��ڽ������볤�Ȳ�һ����������ֵʱ��ø��ѵ�Ч��
		vLDDQU ymm1, a                // �� �� �� ��
		vLDDQU ymm2, b                // �� �� �� ��
		vHADDPS ymm1, ymm2, ymm2      // �� �� �� ��  (1,2), (3,4), (5,6), (7,8)
		vmovups a, ymm1
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	// >>>>>>>>>>>>>>>>>>>>>>> sse3 HSUBPS
	__asm {
		LDDQU xmm1, a
		LDDQU xmm2, b
		HSUBPS xmm1, xmm2
		movups a, xmm1
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
