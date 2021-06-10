#include <windows.h>

class Crypt {
public:
	Crypt(void);
	~Crypt(void);

	static BOOL Encrypt(BYTE* source, BYTE* dest, DWORD length);
	static BOOL Decrypt(BYTE* source, BYTE* dest, DWORD length);
};
