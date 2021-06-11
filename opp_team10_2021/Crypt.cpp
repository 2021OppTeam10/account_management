#include "Crypt.h"

const INT C1 = 52845;
const INT C2 = 22719;
const INT KEY = 78695;

Crypt::Crypt(void) {

}
Crypt::~Crypt(void) {

}

BOOL Crypt::Encrypt(char* source, char* dest, DWORD length) {
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

BOOL Crypt::Decrypt(char* source, char* dest, DWORD length) {
	DWORD i;
	char previousBlock;
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

void Crypt::test(unsigned pwd)
{	
	
	/*enum{HEADER = 2};
	short Size = tmp.size() * 2;
	origin[0] = Size & 0xff;
	origin[1] = (Size >> 8) & 0xff;
	memcpy_s(origin + HEADER, Size, tmp.c_str(), Size);	*/
	char tmp[10];
	sprintf_s(tmp, "%d", pwd);
	char encrypt[10];
	char decrypt[10];

	ZeroMemory(encrypt, sizeof(encrypt));
	ZeroMemory(decrypt, sizeof(decrypt));

	Crypt::Encrypt(tmp, encrypt, sizeof(tmp));
	cout << "원 본: " << tmp << endl;
	cout << "암호화: " << encrypt << endl;
	Crypt::Decrypt(encrypt, decrypt, sizeof(tmp));
	cout << "복호화: " << decrypt << endl;
}
