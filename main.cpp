#include <iostream>
#include "CPU.h"

void ReadFileIntoMemoryAt(Emulator emu, const char* filename, uint32_t offset)
{
	FILE *f = fopen(filename, "rb");
	if (f == NULL)
	{
		printf("error: Couldn't open %s\n", filename);
		exit(1);
	}
	fseek(f, 0L, SEEK_END);
	int fsize = ftell(f);
	fseek(f, 0L, SEEK_SET);

	uint8_t *buffer = &emu.EmuState->memory[offset];
	fread(buffer, fsize, 1, f);
}

int main() {
	std::cout << "Hello World" << std::endl;

	int done = 0;
	int vblankcycles = 0;
	Emulator MyEmu;
	MyEmu.EmuState = MyEmu.init();

	ReadFileIntoMemoryAt(MyEmu, "invaders.h", 0);
	ReadFileIntoMemoryAt(MyEmu, "invaders.g", 0x800);
	ReadFileIntoMemoryAt(MyEmu, "invaders.f", 0x1000);
	ReadFileIntoMemoryAt(MyEmu, "invaders.e", 0x1800);

	while (done == 0)
	{
		done = MyEmu.Emulate();
	}

	char value;
	std::cin >> value;
	return 0;
}