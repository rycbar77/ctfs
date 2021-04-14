#include<iostream>
#include<Windows.h>
#include<memory.h>
using namespace std;
#define CALL_FIRST 1  
#define CALL_LAST 0
HANDLE hMutex = CreateMutex(nullptr, FALSE, nullptr);

unsigned int index = 45;

unsigned int fake_flag[] = { 220, 112, 484, 891, 696, 2550, 1048, 3332, 640, 7695, 1500, 13431, 1862, 16055, 2208, 11475, 936, 31212, 1060, 43681, 2090, 51156, 3552, 25921, 3692, 66875, 2660, 84564, 4320, 41209, 4448, 91295, 3570, 57717, 5724, 67375, 4256, 138269, 6360, 155142, 4536, 87412, 5236, 116487, 5750 };
unsigned int con[] = { 133, 31, 401, 859, 729, 2436, 1149, 3364, 755, 7776, 1532, 13332, 1834, 16082, 2262, 11446, 986, 31181, 1028, 43746, 2117, 51130, 3463, 25907, 3597, 66895, 2577, 84536, 4225, 41101, 4361, 91376, 3484, 57606, 5757, 67343, 4340, 138357, 6329, 155250, 4504, 87325, 5127, 116519, 5634, 180, 21, 452, 792, 727, 2436, 1130, 3425, 739, 7803, 1532, 13329, 1834, 16086, 2247, 11506 };
string input;

unsigned int  hh[50];
bool valid(unsigned int a[], unsigned int b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
LONG WINAPI
EXP(
	struct _EXCEPTION_POINTERS* ExceptionInfo
)
{
	UNREFERENCED_PARAMETER(ExceptionInfo);

	hh[0] += 16;
	hh[1] ^= 28;
	hh[2] = 888 - hh[2];
	hh[3] += -36;
	hh[4] ^= 426;
	hh[5] = 5450 - hh[5];
	hh[6] += 120;
	hh[7] ^= 6358;
	hh[8] = 1310 - hh[8];
	hh[9] += 3483;
	hh[10] ^= 124;
	hh[11] = 19360 - hh[11];
	hh[12] += 532;
	hh[13] ^= 6904;
	hh[14] = 4064 - hh[14];
	hh[15] += -14175;
	hh[16] ^= 62;
	hh[17] = 59245 - hh[17];
	hh[18] += -1660;
	hh[19] ^= 60451;
	hh[20] = 4180 - hh[20];
	hh[21] += 28224;
	hh[22] ^= 176;
	hh[23] = 78821 - hh[23];
	hh[24] += 1222;
	hh[25] ^= 94219;
	hh[26] = 5768 - hh[26];
	hh[27] += 3645;
	hh[28] ^= 7952;
	hh[29] = 137924 - hh[29];
	hh[30] += 1408;
	hh[31] ^= 8122;
	hh[32] = 8738 - hh[32];
	hh[33] += -50094;
	hh[34] ^= 4464;
	hh[35] = 204575 - hh[35];
	hh[36] += 2166;
	hh[37] ^= 11676;
	hh[38] = 8760 - hh[38];
	hh[39] += -12168;
	hh[40] ^= 7150;
	hh[41] = 142885 - hh[41];
	hh[42] += 2464;
	hh[43] ^= 76126;
	hh[44] = 11500 - hh[44];
	if (!valid(hh, fake_flag, 45) )
	{
		exit(0);
	}
	return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI
EXP2(
	struct _EXCEPTION_POINTERS* ExceptionInfo
)
{
	UNREFERENCED_PARAMETER(ExceptionInfo);
	for (int i = 0; i < sizeof(con) / sizeof(con[0]); i++)
	{
		cout << char(con[i] ^ hh[i % 45]);
	}
	cout << endl;
	exit(0);
	
	return EXCEPTION_CONTINUE_SEARCH;
}


void handle1()
{
	hh[index] = ((input[index] ^ index) + index) * (index + 2);
}
void handle2()
{
	hh[index] = (input[index] * (index * index));
}

DWORD WINAPI Func1(LPVOID p)
{
	while (1)
	{
		WaitForSingleObject(hMutex, 0xFFFFFFFF);
		if (index != 0)
		{
			index--;
			handle1();
			Sleep(10);
		}
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI Func2(LPVOID p)
{


	while (1)
	{
		WaitForSingleObject(hMutex, 0xFFFFFFFF);

		if (index != 0)
		{
			index--;
			handle2();
			Sleep(10);
		}
		ReleaseMutex(hMutex);
	}

	return 0;
}



void mmagic()
{
	PVOID h1;
	PVOID h2;
	h2 = AddVectoredExceptionHandler(CALL_LAST, EXP2);
	h1 = AddVectoredExceptionHandler(CALL_FIRST, EXP);
}

void magic()
{
	__asm mov ds : [0] , 0
}

int main()
{
	cout << "Hello there, welcome to npuctf2020!" << endl;
	mmagic();
	cout << "input your flag:" << endl;
	cin >> input;
	if (input.length() != 45)
	{
		cout << "Failed!" << endl;
		exit(0);
	}
	HANDLE hThread1 = CreateThread(NULL, 0, Func1, 0, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, Func2, 0, 0, NULL);
	while (index != 0);
	CloseHandle(hMutex);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	if (valid(hh, fake_flag, 45))
	{
		cout << "Congratulations?" << endl;
	}
	else
	{
		cout << "Failed?" << endl;
	}

	magic();
	return 0;
}