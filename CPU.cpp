#include "CPU.h"

Emulator::Emulator()
{
}

Emulator::~Emulator()
{
}

int Emulator::Disassembler(int pc, unsigned char * codeBuff)
{
	unsigned char *code = &codeBuff[pc];
	int opbytes = 1;
	printf("%04x ", pc);
	switch (*code)
	{
	case 0x00: printf("NOP"); break;
	case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x02: printf("STAX   B"); break;
	case 0x03: printf("INX    B"); break;
	case 0x04: printf("INR    B"); break;
	case 0x05: printf("DCR    B"); break;
	case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes = 2; break;
	case 0x07: printf("RLC"); break;
	case 0x08: printf("NOP"); break;
	case 0x09: printf("DAD    B"); break;
	case 0x0a: printf("LDAX   B"); break;
	case 0x0b: printf("DCX    B"); break;
	case 0x0c: printf("INR    C"); break;
	case 0x0d: printf("DCR    C"); break;
	case 0x0e: printf("MVI    C,#$%02x", code[1]); opbytes = 2;	break;
	case 0x0f: printf("RRC"); break;

	case 0x10: printf("NOP"); break;
	case 0x11: printf("LXI    D,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x12: printf("STAX   D"); break;
	case 0x13: printf("INX    D"); break;
	case 0x14: printf("INR    D"); break;
	case 0x15: printf("DCR    D"); break;
	case 0x16: printf("MVI    D,#$%02x", code[1]); opbytes = 2; break;
	case 0x17: printf("RAL"); break;
	case 0x18: printf("NOP"); break;
	case 0x19: printf("DAD    D"); break;
	case 0x1a: printf("LDAX   D"); break;
	case 0x1b: printf("DCX    D"); break;
	case 0x1c: printf("INR    E"); break;
	case 0x1d: printf("DCR    E"); break;
	case 0x1e: printf("MVI    E,#$%02x", code[1]); opbytes = 2; break;
	case 0x1f: printf("RAR"); break;

	case 0x20: printf("NOP"); break;
	case 0x21: printf("LXI    H,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x22: printf("SHLD   $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x23: printf("INX    H"); break;
	case 0x24: printf("INR    H"); break;
	case 0x25: printf("DCR    H"); break;
	case 0x26: printf("MVI    H,#$%02x", code[1]); opbytes = 2; break;
	case 0x27: printf("DAA"); break;
	case 0x28: printf("NOP"); break;
	case 0x29: printf("DAD    H"); break;
	case 0x2a: printf("LHLD   $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x2b: printf("DCX    H"); break;
	case 0x2c: printf("INR    L"); break;
	case 0x2d: printf("DCR    L"); break;
	case 0x2e: printf("MVI    L,#$%02x", code[1]); opbytes = 2; break;
	case 0x2f: printf("CMA"); break;

	case 0x30: printf("NOP"); break;
	case 0x31: printf("LXI    SP,#$%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x32: printf("STA    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x33: printf("INX    SP"); break;
	case 0x34: printf("INR    M"); break;
	case 0x35: printf("DCR    M"); break;
	case 0x36: printf("MVI    M,#$%02x", code[1]); opbytes = 2; break;
	case 0x37: printf("STC"); break;
	case 0x38: printf("NOP"); break;
	case 0x39: printf("DAD    SP"); break;
	case 0x3a: printf("LDA    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0x3b: printf("DCX    SP"); break;
	case 0x3c: printf("INR    A"); break;
	case 0x3d: printf("DCR    A"); break;
	case 0x3e: printf("MVI    A,#$%02x", code[1]); opbytes = 2; break;
	case 0x3f: printf("CMC"); break;

	case 0x40: printf("MOV    B,B"); break;
	case 0x41: printf("MOV    B,C"); break;
	case 0x42: printf("MOV    B,D"); break;
	case 0x43: printf("MOV    B,E"); break;
	case 0x44: printf("MOV    B,H"); break;
	case 0x45: printf("MOV    B,L"); break;
	case 0x46: printf("MOV    B,M"); break;
	case 0x47: printf("MOV    B,A"); break;
	case 0x48: printf("MOV    C,B"); break;
	case 0x49: printf("MOV    C,C"); break;
	case 0x4a: printf("MOV    C,D"); break;
	case 0x4b: printf("MOV    C,E"); break;
	case 0x4c: printf("MOV    C,H"); break;
	case 0x4d: printf("MOV    C,L"); break;
	case 0x4e: printf("MOV    C,M"); break;
	case 0x4f: printf("MOV    C,A"); break;

	case 0x50: printf("MOV    D,B"); break;
	case 0x51: printf("MOV    D,C"); break;
	case 0x52: printf("MOV    D,D"); break;
	case 0x53: printf("MOV    D.E"); break;
	case 0x54: printf("MOV    D,H"); break;
	case 0x55: printf("MOV    D,L"); break;
	case 0x56: printf("MOV    D,M"); break;
	case 0x57: printf("MOV    D,A"); break;
	case 0x58: printf("MOV    E,B"); break;
	case 0x59: printf("MOV    E,C"); break;
	case 0x5a: printf("MOV    E,D"); break;
	case 0x5b: printf("MOV    E,E"); break;
	case 0x5c: printf("MOV    E,H"); break;
	case 0x5d: printf("MOV    E,L"); break;
	case 0x5e: printf("MOV    E,M"); break;
	case 0x5f: printf("MOV    E,A"); break;

	case 0x60: printf("MOV    H,B"); break;
	case 0x61: printf("MOV    H,C"); break;
	case 0x62: printf("MOV    H,D"); break;
	case 0x63: printf("MOV    H.E"); break;
	case 0x64: printf("MOV    H,H"); break;
	case 0x65: printf("MOV    H,L"); break;
	case 0x66: printf("MOV    H,M"); break;
	case 0x67: printf("MOV    H,A"); break;
	case 0x68: printf("MOV    L,B"); break;
	case 0x69: printf("MOV    L,C"); break;
	case 0x6a: printf("MOV    L,D"); break;
	case 0x6b: printf("MOV    L,E"); break;
	case 0x6c: printf("MOV    L,H"); break;
	case 0x6d: printf("MOV    L,L"); break;
	case 0x6e: printf("MOV    L,M"); break;
	case 0x6f: printf("MOV    L,A"); break;

	case 0x70: printf("MOV    M,B"); break;
	case 0x71: printf("MOV    M,C"); break;
	case 0x72: printf("MOV    M,D"); break;
	case 0x73: printf("MOV    M.E"); break;
	case 0x74: printf("MOV    M,H"); break;
	case 0x75: printf("MOV    M,L"); break;
	case 0x76: printf("HLT");        break;
	case 0x77: printf("MOV    M,A"); break;
	case 0x78: printf("MOV    A,B"); break;
	case 0x79: printf("MOV    A,C"); break;
	case 0x7a: printf("MOV    A,D"); break;
	case 0x7b: printf("MOV    A,E"); break;
	case 0x7c: printf("MOV    A,H"); break;
	case 0x7d: printf("MOV    A,L"); break;
	case 0x7e: printf("MOV    A,M"); break;
	case 0x7f: printf("MOV    A,A"); break;

	case 0x80: printf("ADD    B"); break;
	case 0x81: printf("ADD    C"); break;
	case 0x82: printf("ADD    D"); break;
	case 0x83: printf("ADD    E"); break;
	case 0x84: printf("ADD    H"); break;
	case 0x85: printf("ADD    L"); break;
	case 0x86: printf("ADD    M"); break;
	case 0x87: printf("ADD    A"); break;
	case 0x88: printf("ADC    B"); break;
	case 0x89: printf("ADC    C"); break;
	case 0x8a: printf("ADC    D"); break;
	case 0x8b: printf("ADC    E"); break;
	case 0x8c: printf("ADC    H"); break;
	case 0x8d: printf("ADC    L"); break;
	case 0x8e: printf("ADC    M"); break;
	case 0x8f: printf("ADC    A"); break;

	case 0x90: printf("SUB    B"); break;
	case 0x91: printf("SUB    C"); break;
	case 0x92: printf("SUB    D"); break;
	case 0x93: printf("SUB    E"); break;
	case 0x94: printf("SUB    H"); break;
	case 0x95: printf("SUB    L"); break;
	case 0x96: printf("SUB    M"); break;
	case 0x97: printf("SUB    A"); break;
	case 0x98: printf("SBB    B"); break;
	case 0x99: printf("SBB    C"); break;
	case 0x9a: printf("SBB    D"); break;
	case 0x9b: printf("SBB    E"); break;
	case 0x9c: printf("SBB    H"); break;
	case 0x9d: printf("SBB    L"); break;
	case 0x9e: printf("SBB    M"); break;
	case 0x9f: printf("SBB    A"); break;

	case 0xa0: printf("ANA    B"); break;
	case 0xa1: printf("ANA    C"); break;
	case 0xa2: printf("ANA    D"); break;
	case 0xa3: printf("ANA    E"); break;
	case 0xa4: printf("ANA    H"); break;
	case 0xa5: printf("ANA    L"); break;
	case 0xa6: printf("ANA    M"); break;
	case 0xa7: printf("ANA    A"); break;
	case 0xa8: printf("XRA    B"); break;
	case 0xa9: printf("XRA    C"); break;
	case 0xaa: printf("XRA    D"); break;
	case 0xab: printf("XRA    E"); break;
	case 0xac: printf("XRA    H"); break;
	case 0xad: printf("XRA    L"); break;
	case 0xae: printf("XRA    M"); break;
	case 0xaf: printf("XRA    A"); break;

	case 0xb0: printf("ORA    B"); break;
	case 0xb1: printf("ORA    C"); break;
	case 0xb2: printf("ORA    D"); break;
	case 0xb3: printf("ORA    E"); break;
	case 0xb4: printf("ORA    H"); break;
	case 0xb5: printf("ORA    L"); break;
	case 0xb6: printf("ORA    M"); break;
	case 0xb7: printf("ORA    A"); break;
	case 0xb8: printf("CMP    B"); break;
	case 0xb9: printf("CMP    C"); break;
	case 0xba: printf("CMP    D"); break;
	case 0xbb: printf("CMP    E"); break;
	case 0xbc: printf("CMP    H"); break;
	case 0xbd: printf("CMP    L"); break;
	case 0xbe: printf("CMP    M"); break;
	case 0xbf: printf("CMP    A"); break;

	case 0xc0: printf("RNZ"); break;
	case 0xc1: printf("POP    B"); break;
	case 0xc2: printf("JNZ    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xc3: printf("JMP    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xc4: printf("CNZ    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xc5: printf("PUSH   B"); break;
	case 0xc6: printf("ADI    #$%02x", code[1]); opbytes = 2; break;
	case 0xc7: printf("RST    0"); break;
	case 0xc8: printf("RZ"); break;
	case 0xc9: printf("RET"); break;
	case 0xca: printf("JZ     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xcb: printf("JMP    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xcc: printf("CZ     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xcd: printf("CALL   $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xce: printf("ACI    #$%02x", code[1]); opbytes = 2; break;
	case 0xcf: printf("RST    1"); break;

	case 0xd0: printf("RNC"); break;
	case 0xd1: printf("POP    D"); break;
	case 0xd2: printf("JNC    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xd3: printf("OUT    #$%02x", code[1]); opbytes = 2; break;
	case 0xd4: printf("CNC    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xd5: printf("PUSH   D"); break;
	case 0xd6: printf("SUI    #$%02x", code[1]); opbytes = 2; break;
	case 0xd7: printf("RST    2"); break;
	case 0xd8: printf("RC");  break;
	case 0xd9: printf("RET"); break;
	case 0xda: printf("JC     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xdb: printf("IN     #$%02x", code[1]); opbytes = 2; break;
	case 0xdc: printf("CC     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xdd: printf("CALL   $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xde: printf("SBI    #$%02x", code[1]); opbytes = 2; break;
	case 0xdf: printf("RST    3"); break;

	case 0xe0: printf("RPO"); break;
	case 0xe1: printf("POP    H"); break;
	case 0xe2: printf("JPO    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xe3: printf("XTHL"); break;
	case 0xe4: printf("CPO    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xe5: printf("PUSH   H"); break;
	case 0xe6: printf("ANI    #$%02x", code[1]); opbytes = 2; break;
	case 0xe7: printf("RST    4"); break;
	case 0xe8: printf("RPE"); break;
	case 0xe9: printf("PCHL"); break;
	case 0xea: printf("JPE    $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xeb: printf("XCHG"); break;
	case 0xec: printf("CPE     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xed: printf("CALL   $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xee: printf("XRI    #$%02x", code[1]); opbytes = 2; break;
	case 0xef: printf("RST    5"); break;

	case 0xf0: printf("RP");  break;
	case 0xf1: printf("POP    PSW"); break;
	case 0xf2: printf("JP     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xf3: printf("DI");  break;
	case 0xf4: printf("CP     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xf5: printf("PUSH   PSW"); break;
	case 0xf6: printf("ORI    #$%02x", code[1]); opbytes = 2; break;
	case 0xf7: printf("RST    6"); break;
	case 0xf8: printf("RM");  break;
	case 0xf9: printf("SPHL"); break;
	case 0xfa: printf("JM     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xfb: printf("EI");  break;
	case 0xfc: printf("CM     $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xfd: printf("CALL   $%02x%02x", code[2], code[1]); opbytes = 3; break;
	case 0xfe: printf("CPI    #$%02x", code[1]); opbytes = 2; break;
	case 0xff: printf("RST    7"); break;
	}

	return opbytes;
}

int Emulator::Emulate()
{
	int cycles = 4;
	unsigned char *opcode = &Emulator::EmuState->memory[Emulator::EmuState->pc];

	Emulator::Disassembler(Emulator::EmuState->pc, Emulator::EmuState->memory);

	Emulator::EmuState->pc += 1;
	switch (*opcode)
	{
	case 0x00: break;	//NOP
	case 0x01: 							//LXI	B,word
		Emulator::EmuState->c = opcode[1];
		Emulator::EmuState->b = opcode[2];
		Emulator::EmuState->pc += 2;
		break;
	case 0x02: UnimplementedInstruction(); break;
	case 0x03: UnimplementedInstruction(); break;
	case 0x04: UnimplementedInstruction(); break;
	case 0x05: 							//DCR    B
	{
		uint8_t res = Emulator::EmuState->b - 1;
		Emulator::EmuState->cc.z = (res == 0);
		Emulator::EmuState->cc.s = (0x80 == (res & 0x80));
		Emulator::EmuState->cc.p = parity(res, 8);
		Emulator::EmuState->b = res;
	}
	break;
	case 0x06: 							//MVI B,byte
		Emulator::EmuState->b = opcode[1];
		Emulator::EmuState->pc++;
		break;
	case 0x07: UnimplementedInstruction(); break;
	case 0x08: UnimplementedInstruction(); break;
	case 0x09: 							//DAD B
	{
		uint32_t hl = (Emulator::EmuState->h << 8) | Emulator::EmuState->l;
		uint32_t bc = (Emulator::EmuState->b << 8) | Emulator::EmuState->c;
		uint32_t res = hl + bc;
		Emulator::EmuState->h = (res & 0xff00) >> 8;
		Emulator::EmuState->l = res & 0xff;
		Emulator::EmuState->cc.cy = ((res & 0xffff0000) > 0);
	}
	break;
	case 0x0a: UnimplementedInstruction(); break;
	case 0x0b: UnimplementedInstruction(); break;
	case 0x0c: UnimplementedInstruction(); break;
	case 0x0d: 							//DCR    C
	{
		uint8_t res = Emulator::EmuState->c - 1;
		Emulator::EmuState->cc.z = (res == 0);
		Emulator::EmuState->cc.s = (0x80 == (res & 0x80));
		Emulator::EmuState->cc.p = parity(res, 8);
		Emulator::EmuState->c = res;
	}
	break;
	case 0x0e: 							//MVI C,byte
		Emulator::EmuState->c = opcode[1];
		Emulator::EmuState->pc++;
		break;
	case 0x0f: 							//RRC
	{
		uint8_t x = Emulator::EmuState->a;
		Emulator::EmuState->a = ((x & 1) << 7) | (x >> 1);
		Emulator::EmuState->cc.cy = (1 == (x & 1));
	}
	break;
	case 0x10: UnimplementedInstruction(); break;
	case 0x11: 							//LXI	D,word
		Emulator::EmuState->e = opcode[1];
		Emulator::EmuState->d = opcode[2];
		Emulator::EmuState->pc += 2;
		break;
	case 0x12: UnimplementedInstruction(); break;
	case 0x13: 							//INX    D
		Emulator::EmuState->e++;
		if (Emulator::EmuState->e == 0)
			Emulator::EmuState->d++;
		break;
	case 0x14: UnimplementedInstruction(); break;
	case 0x15: UnimplementedInstruction(); break;
	case 0x16: UnimplementedInstruction(); break;
	case 0x17: UnimplementedInstruction(); break;
	case 0x18: UnimplementedInstruction(); break;
	case 0x19: 							//DAD    D
	{
		uint32_t hl = (Emulator::EmuState->h << 8) | Emulator::EmuState->l;
		uint32_t de = (Emulator::EmuState->d << 8) | Emulator::EmuState->e;
		uint32_t res = hl + de;
		Emulator::EmuState->h = (res & 0xff00) >> 8;
		Emulator::EmuState->l = res & 0xff;
		Emulator::EmuState->cc.cy = ((res & 0xffff0000) != 0);
	}
	break;
	case 0x1a: 							//LDAX	D
	{
		uint16_t offset = (Emulator::EmuState->d << 8) | Emulator::EmuState->e;
		Emulator::EmuState->a = Emulator::EmuState->memory[offset];
	}
	break;
	case 0x1b: UnimplementedInstruction(); break;
	case 0x1c: UnimplementedInstruction(); break;
	case 0x1d: UnimplementedInstruction(); break;
	case 0x1e: UnimplementedInstruction(); break;
	case 0x1f: UnimplementedInstruction(); break;
	case 0x20: UnimplementedInstruction(); break;
	case 0x21: 							//LXI	H,word
		Emulator::EmuState->l = opcode[1];
		Emulator::EmuState->h = opcode[2];
		Emulator::EmuState->pc += 2;
		break;
	case 0x22: UnimplementedInstruction(); break;
	case 0x23: 							//INX    H
		Emulator::EmuState->l++;
		if (Emulator::EmuState->l == 0)
			Emulator::EmuState->h++;
		break;
	case 0x24: UnimplementedInstruction(); break;
	case 0x25: UnimplementedInstruction(); break;
	case 0x26:  							//MVI H,byte
		Emulator::EmuState->h = opcode[1];
		Emulator::EmuState->pc++;
		break;
	case 0x27: UnimplementedInstruction(); break;
	case 0x28: UnimplementedInstruction(); break;
	case 0x29: 								//DAD    H
	{
		uint32_t hl = (Emulator::EmuState->h << 8) | Emulator::EmuState->l;
		uint32_t res = hl + hl;
		Emulator::EmuState->h = (res & 0xff00) >> 8;
		Emulator::EmuState->l = res & 0xff;
		Emulator::EmuState->cc.cy = ((res & 0xffff0000) != 0);
	}
	break;
	case 0x2a: UnimplementedInstruction(); break;
	case 0x2c: UnimplementedInstruction(); break;
	case 0x2d: UnimplementedInstruction(); break;
	case 0x2e: UnimplementedInstruction(); break;
	case 0x2f: UnimplementedInstruction(); break;
	case 0x30: UnimplementedInstruction(); break;
	case 0x31: 							//LXI	SP,word
		Emulator::EmuState->sp = (opcode[2] << 8) | opcode[1];
		Emulator::EmuState->pc += 2;
		break;
	case 0x32: 							//STA    (word)
	{
		uint16_t offset = (opcode[2] << 8) | (opcode[1]);
		Emulator::EmuState->memory[offset] = Emulator::EmuState->a;
		Emulator::EmuState->pc += 2;
	}
	break;
	case 0x33: UnimplementedInstruction(); break;
	case 0x34: UnimplementedInstruction(); break;
	case 0x35: UnimplementedInstruction(); break;
	case 0x36: 							//MVI	M,byte
	{
		//AC set if lower nibble of h was zero prior to dec
		uint16_t offset = (Emulator::EmuState->h << 8) | Emulator::EmuState->l;
		Emulator::EmuState->memory[offset] = opcode[1];
		Emulator::EmuState->pc++;
	}
	break;
	case 0x37: UnimplementedInstruction(); break;
	case 0x38: UnimplementedInstruction(); break;
	case 0x39: UnimplementedInstruction(); break;
	case 0x3a: 							//LDA    (word)
	{
		uint16_t offset = (opcode[2] << 8) | (opcode[1]);
		Emulator::EmuState->a = Emulator::EmuState->memory[offset];
		Emulator::EmuState->pc += 2;
	}
	break;
	case 0x3b: UnimplementedInstruction(); break;
	case 0x3c: UnimplementedInstruction(); break;
	case 0x3d: UnimplementedInstruction(); break;
	case 0x3e: 							//MVI    A,byte
		Emulator::EmuState->a = opcode[1];
		Emulator::EmuState->pc++;
		break;
	case 0x3f: UnimplementedInstruction(); break;
	case 0x40: UnimplementedInstruction(); break;
	case 0x41: UnimplementedInstruction(); break;
	case 0x42: UnimplementedInstruction(); break;
	case 0x43: UnimplementedInstruction(); break;
	case 0x44: UnimplementedInstruction(); break;
	case 0x45: UnimplementedInstruction(); break;
	case 0x46: UnimplementedInstruction(); break;
	case 0x47: UnimplementedInstruction(); break;
	case 0x48: UnimplementedInstruction(); break;
	case 0x49: UnimplementedInstruction(); break;
	case 0x4a: UnimplementedInstruction(); break;
	case 0x4b: UnimplementedInstruction(); break;
	case 0x4c: UnimplementedInstruction(); break;
	case 0x4d: UnimplementedInstruction(); break;
	case 0x4e: UnimplementedInstruction(); break;
	case 0x4f: UnimplementedInstruction(); break;
	case 0x50: UnimplementedInstruction(); break;
	case 0x51: UnimplementedInstruction(); break;
	case 0x52: UnimplementedInstruction(); break;
	case 0x53: UnimplementedInstruction(); break;
	case 0x54: UnimplementedInstruction(); break;
	case 0x55: UnimplementedInstruction(); break;
	case 0x56: 							//MOV D,M
	{
		uint16_t offset = (Emulator::EmuState->h << 8) | (Emulator::EmuState->l);
		Emulator::EmuState->d = Emulator::EmuState->memory[offset];
	}
	break;
	case 0x57: UnimplementedInstruction(); break;
	case 0x58: UnimplementedInstruction(); break;
	case 0x59: UnimplementedInstruction(); break;
	case 0x5a: UnimplementedInstruction(); break;
	case 0x5b: UnimplementedInstruction(); break;
	case 0x5c: UnimplementedInstruction(); break;
	case 0x5d: UnimplementedInstruction(); break;
	case 0x5e: 							//MOV E,M
	{
		uint16_t offset = (Emulator::EmuState->h << 8) | (Emulator::EmuState->l);
		Emulator::EmuState->e = Emulator::EmuState->memory[offset];
	}
	break;
	case 0x5f: UnimplementedInstruction(); break;
	case 0x60: UnimplementedInstruction(); break;
	case 0x61: UnimplementedInstruction(); break;
	case 0x62: UnimplementedInstruction(); break;
	case 0x63: UnimplementedInstruction(); break;
	case 0x64: UnimplementedInstruction(); break;
	case 0x65: UnimplementedInstruction(); break;
	case 0x66: 							//MOV H,M
	{
		uint16_t offset = (Emulator::EmuState->h << 8) | (Emulator::EmuState->l);
		Emulator::EmuState->h = Emulator::EmuState->memory[offset];
	}
	break;
	case 0x67: UnimplementedInstruction(); break;
	case 0x68: UnimplementedInstruction(); break;
	case 0x69: UnimplementedInstruction(); break;
	case 0x6a: UnimplementedInstruction(); break;
	case 0x6b: UnimplementedInstruction(); break;
	case 0x6c: UnimplementedInstruction(); break;
	case 0x6d: UnimplementedInstruction(); break;
	case 0x6e: UnimplementedInstruction(); break;
	case 0x6f: Emulator::EmuState->l = Emulator::EmuState->a; break; //MOV L,A
	case 0x70: UnimplementedInstruction(); break;
	case 0x71: UnimplementedInstruction(); break;
	case 0x72: UnimplementedInstruction(); break;
	case 0x73: UnimplementedInstruction(); break;
	case 0x74: UnimplementedInstruction(); break;
	case 0x75: UnimplementedInstruction(); break;
	case 0x76: UnimplementedInstruction(); break;
	case 0x77: 							//MOV    M,A
	{
		uint16_t offset = (Emulator::EmuState->h << 8) | (Emulator::EmuState->l);
		Emulator::EmuState->memory[offset] = Emulator::EmuState->a;
	}
	break;
	case 0x78: UnimplementedInstruction(); break;
	case 0x79: UnimplementedInstruction(); break;
	case 0x7a: Emulator::EmuState->a = Emulator::EmuState->d;  break;	//MOV D,A
	case 0x7b: Emulator::EmuState->a = Emulator::EmuState->e;  break;	//MOV E,A
	case 0x7c: Emulator::EmuState->a = Emulator::EmuState->h;  break;	//MOV H,A
	case 0x7d: UnimplementedInstruction(); break;
	case 0x7e: 							//MOV A,M
	{
		uint16_t offset = (Emulator::EmuState->h << 8) | (Emulator::EmuState->l);
		Emulator::EmuState->a = Emulator::EmuState->memory[offset];
	}
	break;
	case 0x7f: UnimplementedInstruction(); break;
	case 0x80: UnimplementedInstruction(); break;
	case 0x81: UnimplementedInstruction(); break;
	case 0x82: UnimplementedInstruction(); break;
	case 0x83: UnimplementedInstruction(); break;
	case 0x84: UnimplementedInstruction(); break;
	case 0x85: UnimplementedInstruction(); break;
	case 0x86: UnimplementedInstruction(); break;
	case 0x87: UnimplementedInstruction(); break;
	case 0x88: UnimplementedInstruction(); break;
	case 0x89: UnimplementedInstruction(); break;
	case 0x8a: UnimplementedInstruction(); break;
	case 0x8b: UnimplementedInstruction(); break;
	case 0x8c: UnimplementedInstruction(); break;
	case 0x8d: UnimplementedInstruction(); break;
	case 0x8e: UnimplementedInstruction(); break;
	case 0x8f: UnimplementedInstruction(); break;
	case 0x90: UnimplementedInstruction(); break;
	case 0x91: UnimplementedInstruction(); break;
	case 0x92: UnimplementedInstruction(); break;
	case 0x93: UnimplementedInstruction(); break;
	case 0x94: UnimplementedInstruction(); break;
	case 0x95: UnimplementedInstruction(); break;
	case 0x96: UnimplementedInstruction(); break;
	case 0x97: UnimplementedInstruction(); break;
	case 0x98: UnimplementedInstruction(); break;
	case 0x99: UnimplementedInstruction(); break;
	case 0x9a: UnimplementedInstruction(); break;
	case 0x9b: UnimplementedInstruction(); break;
	case 0x9c: UnimplementedInstruction(); break;
	case 0x9d: UnimplementedInstruction(); break;
	case 0x9e: UnimplementedInstruction(); break;
	case 0x9f: UnimplementedInstruction(); break;
	case 0xa0: UnimplementedInstruction(); break;
	case 0xa1: UnimplementedInstruction(); break;
	case 0xa2: UnimplementedInstruction(); break;
	case 0xa3: UnimplementedInstruction(); break;
	case 0xa4: UnimplementedInstruction(); break;
	case 0xa5: UnimplementedInstruction(); break;
	case 0xa6: UnimplementedInstruction(); break;
	case 0xa7: Emulator::EmuState->a = Emulator::EmuState->a & Emulator::EmuState->a; LogicFlagsA();	break; //ANA A
	case 0xa8: UnimplementedInstruction(); break;
	case 0xa9: UnimplementedInstruction(); break;
	case 0xaa: UnimplementedInstruction(); break;
	case 0xab: UnimplementedInstruction(); break;
	case 0xac: UnimplementedInstruction(); break;
	case 0xad: UnimplementedInstruction(); break;
	case 0xae: UnimplementedInstruction(); break;
	case 0xaf: Emulator::EmuState->a = Emulator::EmuState->a ^ Emulator::EmuState->a; LogicFlagsA();	break; //XRA A
	case 0xb0: UnimplementedInstruction(); break;
	case 0xb1: UnimplementedInstruction(); break;
	case 0xb2: UnimplementedInstruction(); break;
	case 0xb3: UnimplementedInstruction(); break;
	case 0xb4: UnimplementedInstruction(); break;
	case 0xb5: UnimplementedInstruction(); break;
	case 0xb6: UnimplementedInstruction(); break;
	case 0xb7: UnimplementedInstruction(); break;
	case 0xb8: UnimplementedInstruction(); break;
	case 0xb9: UnimplementedInstruction(); break;
	case 0xba: UnimplementedInstruction(); break;
	case 0xbb: UnimplementedInstruction(); break;
	case 0xbc: UnimplementedInstruction(); break;
	case 0xbd: UnimplementedInstruction(); break;
	case 0xbe: UnimplementedInstruction(); break;
	case 0xbf: UnimplementedInstruction(); break;
	case 0xc0: UnimplementedInstruction(); break;
	case 0xc1: 						//POP    B
	{
		Emulator::EmuState->c = Emulator::EmuState->memory[Emulator::EmuState->sp];
		Emulator::EmuState->b = Emulator::EmuState->memory[Emulator::EmuState->sp + 1];
		Emulator::EmuState->sp += 2;
	}
	break;
	case 0xc2: 						//JNZ address
		if (0 == Emulator::EmuState->cc.z)
			Emulator::EmuState->pc = (opcode[2] << 8) | opcode[1];
		else
			Emulator::EmuState->pc += 2;
		break;
	case 0xc3:						//JMP address
		Emulator::EmuState->pc = (opcode[2] << 8) | opcode[1];
		break;
	case 0xc4: UnimplementedInstruction(); break;
	case 0xc5: 						//PUSH   B
	{
		Emulator::EmuState->memory[Emulator::EmuState->sp - 1] = Emulator::EmuState->b;
		Emulator::EmuState->memory[Emulator::EmuState->sp - 2] = Emulator::EmuState->c;
		Emulator::EmuState->sp = Emulator::EmuState->sp - 2;
	}
	break;
	case 0xc6: 						//ADI    byte
	{
		uint16_t x = (uint16_t)Emulator::EmuState->a + (uint16_t)opcode[1];
		Emulator::EmuState->cc.z = ((x & 0xff) == 0);
		Emulator::EmuState->cc.s = (0x80 == (x & 0x80));
		Emulator::EmuState->cc.p = parity((x & 0xff), 8);
		Emulator::EmuState->cc.cy = (x > 0xff);
		Emulator::EmuState->a = (uint8_t)x;
		Emulator::EmuState->pc++;
	}
	break;
	case 0xc7: UnimplementedInstruction(); break;
	case 0xc8: UnimplementedInstruction(); break;
	case 0xc9: 						//RET
		Emulator::EmuState->pc = Emulator::EmuState->memory[Emulator::EmuState->sp] | (Emulator::EmuState->memory[Emulator::EmuState->sp + 1] << 8);
		Emulator::EmuState->sp += 2;
		break;
	case 0xca: UnimplementedInstruction(); break;
	case 0xcb: UnimplementedInstruction(); break;
	case 0xcc: UnimplementedInstruction(); break;
	case 0xcd: 						//CALL adr
	{
		uint16_t	ret = Emulator::EmuState->pc + 2;
		Emulator::EmuState->memory[Emulator::EmuState->sp - 1] = (ret >> 8) & 0xff;
		Emulator::EmuState->memory[Emulator::EmuState->sp - 2] = (ret & 0xff);
		Emulator::EmuState->sp = Emulator::EmuState->sp - 2;
		Emulator::EmuState->pc = (opcode[2] << 8) | opcode[1];
	}
	break;
	case 0xce: UnimplementedInstruction(); break;
	case 0xcf: UnimplementedInstruction(); break;
	case 0xd0: UnimplementedInstruction(); break;
	case 0xd1: 						//POP    D
	{
		Emulator::EmuState->e = Emulator::EmuState->memory[Emulator::EmuState->sp];
		Emulator::EmuState->d = Emulator::EmuState->memory[Emulator::EmuState->sp + 1];
		Emulator::EmuState->sp += 2;
	}
	break;
	case 0xd2: UnimplementedInstruction(); break;
	case 0xd3:
		//Don't know what to do here (yet)
		Emulator::EmuState->pc++;
		break;
	case 0xd4: UnimplementedInstruction(); break;
	case 0xd5: 						//PUSH   D
	{
		Emulator::EmuState->memory[Emulator::EmuState->sp - 1] = Emulator::EmuState->d;
		Emulator::EmuState->memory[Emulator::EmuState->sp - 2] = Emulator::EmuState->e;
		Emulator::EmuState->sp = Emulator::EmuState->sp - 2;
	}
	break;
	case 0xd6: UnimplementedInstruction(); break;
	case 0xd7: UnimplementedInstruction(); break;
	case 0xd8: UnimplementedInstruction(); break;
	case 0xd9: UnimplementedInstruction(); break;
	case 0xda: UnimplementedInstruction(); break;
	case 0xdb: UnimplementedInstruction(); break;
	case 0xdc: UnimplementedInstruction(); break;
	case 0xdd: UnimplementedInstruction(); break;
	case 0xde: UnimplementedInstruction(); break;
	case 0xdf: UnimplementedInstruction(); break;
	case 0xe0: UnimplementedInstruction(); break;
	case 0xe1: 					//POP    H
	{
		Emulator::EmuState->l = Emulator::EmuState->memory[Emulator::EmuState->sp];
		Emulator::EmuState->h = Emulator::EmuState->memory[Emulator::EmuState->sp + 1];
		Emulator::EmuState->sp += 2;
	}
	break;
	case 0xe2: UnimplementedInstruction(); break;
	case 0xe3: UnimplementedInstruction(); break;
	case 0xe4: UnimplementedInstruction(); break;
	case 0xe5: 						//PUSH   H
	{
		Emulator::EmuState->memory[Emulator::EmuState->sp - 1] = Emulator::EmuState->h;
		Emulator::EmuState->memory[Emulator::EmuState->sp - 2] = Emulator::EmuState->l;
		Emulator::EmuState->sp = Emulator::EmuState->sp - 2;
	}
	break;
	case 0xe6: 						//ANI    byte
	{
		Emulator::EmuState->a = Emulator::EmuState->a & opcode[1];
		LogicFlagsA();
		Emulator::EmuState->pc++;
	}
	break;
	case 0xe7: UnimplementedInstruction(); break;
	case 0xe8: UnimplementedInstruction(); break;
	case 0xe9: UnimplementedInstruction(); break;
	case 0xea: UnimplementedInstruction(); break;
	case 0xeb: 					//XCHG
	{
		uint8_t save1 = Emulator::EmuState->d;
		uint8_t save2 = Emulator::EmuState->e;
		Emulator::EmuState->d = Emulator::EmuState->h;
		Emulator::EmuState->e = Emulator::EmuState->l;
		Emulator::EmuState->h = save1;
		Emulator::EmuState->l = save2;
	}
	break;
	case 0xec: UnimplementedInstruction(); break;
	case 0xed: UnimplementedInstruction(); break;
	case 0xee: UnimplementedInstruction(); break;
	case 0xef: UnimplementedInstruction(); break;
	case 0xf0: UnimplementedInstruction(); break;
	case 0xf1: 					//POP PSW
	{
		Emulator::EmuState->a = Emulator::EmuState->memory[Emulator::EmuState->sp + 1];
		uint8_t psw = Emulator::EmuState->memory[Emulator::EmuState->sp];
		Emulator::EmuState->cc.z = (0x01 == (psw & 0x01));
		Emulator::EmuState->cc.s = (0x02 == (psw & 0x02));
		Emulator::EmuState->cc.p = (0x04 == (psw & 0x04));
		Emulator::EmuState->cc.cy = (0x05 == (psw & 0x08));
		Emulator::EmuState->cc.ac = (0x10 == (psw & 0x10));
		Emulator::EmuState->sp += 2;
	}
	break;
	case 0xf2: UnimplementedInstruction(); break;
	case 0xf3: UnimplementedInstruction(); break;
	case 0xf4: UnimplementedInstruction(); break;
	case 0xf5: 						//PUSH   PSW
	{
		Emulator::EmuState->memory[Emulator::EmuState->sp - 1] = Emulator::EmuState->a;
		uint8_t psw = (Emulator::EmuState->cc.z |
			Emulator::EmuState->cc.s << 1 |
			Emulator::EmuState->cc.p << 2 |
			Emulator::EmuState->cc.cy << 3 |
			Emulator::EmuState->cc.ac << 4);
		Emulator::EmuState->memory[Emulator::EmuState->sp - 2] = psw;
		Emulator::EmuState->sp = Emulator::EmuState->sp - 2;
	}
	break;
	case 0xf6: UnimplementedInstruction(); break;
	case 0xf7: UnimplementedInstruction(); break;
	case 0xf8: UnimplementedInstruction(); break;
	case 0xf9: UnimplementedInstruction(); break;
	case 0xfa: UnimplementedInstruction(); break;
	case 0xfb: Emulator::EmuState->int_enable = 1;  break;	//EI
	case 0xfc: UnimplementedInstruction(); break;
	case 0xfd: UnimplementedInstruction(); break;
	case 0xfe: 						//CPI  byte
	{
		uint8_t x = Emulator::EmuState->a - opcode[1];
		Emulator::EmuState->cc.z = (x == 0);
		Emulator::EmuState->cc.s = (0x80 == (x & 0x80));
		Emulator::EmuState->cc.p = parity(x, 8);
		Emulator::EmuState->cc.cy = (Emulator::EmuState->a < opcode[1]);
		Emulator::EmuState->pc++;
	}
	break;
	case 0xff: UnimplementedInstruction(); break;
	}
	printf("\t");
	printf("%c", Emulator::EmuState->cc.z ? 'z' : '.');
	printf("%c", Emulator::EmuState->cc.s ? 's' : '.');
	printf("%c", Emulator::EmuState->cc.p ? 'p' : '.');
	printf("%c", Emulator::EmuState->cc.cy ? 'c' : '.');
	printf("%c  ", Emulator::EmuState->cc.ac ? 'a' : '.');
	printf("A $%02x B $%02x C $%02x D $%02x E $%02x H $%02x L $%02x SP %04x\n", Emulator::EmuState->a, Emulator::EmuState->b, Emulator::EmuState->c,
		Emulator::EmuState->d, Emulator::EmuState->e, Emulator::EmuState->h, Emulator::EmuState->l, Emulator::EmuState->sp);
	return 0;
}

State8080 * Emulator::init(void)
{
	State8080* state =(State8080*) calloc(1, sizeof(State8080));
	state->memory = (uint8_t*) malloc(0x10000);  //16K
	return state;
}

int Emulator::parity(int x, int size)
{
	int i;
	int p = 0;
	x = (x & ((1 << size) - 1));
	for (i = 0; i < size; i++)
	{
		if (x & 0x1) p++;
		x = x >> 1;
	}
	return (0 == (p & 0x1));
}

void Emulator::LogicFlagsA()
{
	EmuState->cc.cy = EmuState->cc.ac = 0;
	EmuState->cc.z = (EmuState->a == 0);
	EmuState->cc.s = (0x80 == (EmuState->a & 0x80));
	EmuState->cc.p = parity(EmuState->a, 8);
}

void Emulator::ArithFlagsA(uint16_t res)
{
	EmuState->cc.cy = (res > 0xff);
	EmuState->cc.z = ((res & 0xff) == 0);
	EmuState->cc.s = (0x80 == (res & 0x80));
	EmuState->cc.p = parity(res & 0xff, 8);
}

void Emulator::UnimplementedInstruction()
{
	printf("Error: Unimplemented instruction\n");
	Emulator::EmuState->pc--;
	Emulator::Disassembler((Emulator::EmuState)->pc, Emulator::EmuState->memory);
	printf("\n");
	exit(1);
}
