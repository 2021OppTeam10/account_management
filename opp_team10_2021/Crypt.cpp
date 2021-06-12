#include "Crypt.h"

const INT C1 = 52845;
const INT C2 = 22719;
const INT KEY = 78695;

Crypt::Crypt(void) {

}
Crypt::~Crypt(void) {

}

BOOL Crypt::Encrypt(BYTE* source, BYTE* dest, DWORD length) {
	DWORD i;
	INT key = KEY;
	if (!source || !dest || length <= 0) {
		return FALSE;
	}
	for (i = 0; i < length; i++)
	{
		dest[i] = source[i] ^ key >> 8;
		key = (dest[i] + key) * C1 + C2;
	}
	return TRUE;
}

BOOL Crypt::Decrypt(BYTE* source, BYTE* dest, DWORD length) {
	DWORD i;
	BYTE previousBlock;
	INT key = KEY;
	if (!source || !dest || length <= 0) {
		return FALSE;
	}
	for (i = 0; i < length; i++)
	{
		previousBlock = source[i];
		dest[i] = source[i] ^ key >> 8;
		key = (previousBlock + key)* C1 + C2;
	}
	return TRUE;
}

using namespace std;

//void Crypt::test(string tmp)
//{
//	BYTE origin[];
//	BYTE encrypt[10];
//	BYTE decrypt[10];
//
//	ZeroMemory(encrypt, sizeof(encrypt));
//	ZeroMemory(decrypt, sizeof(decrypt));
//
//	Crypt::Encrypt(origin, encrypt, sizeof(origin));
//	Crypt::Decrypt(encrypt, decrypt, sizeof(origin));
//}
