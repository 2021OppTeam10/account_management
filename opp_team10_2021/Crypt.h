#include <windows.h>
#include <string>
#include <iostream>

class Crypt {
public:
	Crypt(void);
	~Crypt(void);

	static BOOL Encrypt(char* source, char* dest, DWORD length);
	static BOOL Decrypt(char* source, char* dest, DWORD length);
	void test(unsigned pwd);
};
