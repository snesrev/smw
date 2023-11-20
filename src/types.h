#ifndef SM_TYPES_H_
#define SM_TYPES_H_

#pragma warning(disable: 4244)

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined(_WIN32) && !COMPILER_TCC
#include <crtdbg.h>
#ifndef assert
#define assert _ASSERTE
#endif
#else
#include <assert.h>
#endif

typedef uint8_t uint8;
typedef int8_t int8;
typedef uint16_t uint16;
typedef int16_t int16;
typedef uint32_t uint32;
typedef int32_t int32;
typedef uint64_t uint64;
typedef int64_t int64;
typedef unsigned int uint;

typedef uint16 VoidP;

#define arraysize(x) sizeof(x)/sizeof(x[0])
#define sign8(x) ((x) & 0x80)
#define sign16(x) ((x) & 0x8000)
#define sign32(x) ((x) & 0x80000000)
#define load24(x) ((*(uint32*)&(x))&0xffffff)

#ifdef _MSC_VER
#define countof _countof
#define NORETURN __declspec(noreturn)
#define FORCEINLINE __forceinline
#define NOINLINE __declspec(noinline)
#else
#define countof(a) (sizeof(a)/sizeof(*(a)))
#define NORETURN
#define FORCEINLINE inline
#define NOINLINE
#endif

#ifdef _DEBUG
#define kDebugFlag 1
#else
#define kDebugFlag 0
#endif

static FORCEINLINE uint16 abs16(uint16 t) { return sign16(t) ? -t : t; }
static FORCEINLINE uint8 abs8(uint8 t) { return sign8(t) ? -t : t; }
static FORCEINLINE int IntMin(int a, int b) { return a < b ? a : b; }
static FORCEINLINE int IntMax(int a, int b) { return a > b ? a : b; }
static FORCEINLINE uint UintMin(uint a, uint b) { return a < b ? a : b; }
static FORCEINLINE uint UintMax(uint a, uint b) { return a > b ? a : b; }

// windows.h defines this too
#ifdef HIBYTE
#undef HIBYTE
#endif

#define BYTE(x) (*(uint8*)&(x))
#define WORD(x) (*(uint16*)&(x))
#define DWORD(x) (*(uint32*)&(x))
#define XY(x, y) ((y)*64+(x))

#ifndef swap16
static inline uint16 swap16(uint16 v) { return (v << 8) | (v >> 8); }
#endif

void NORETURN Die(const char *error);
void Warning(const char *error);

// compile time assertion
#define __CASSERT_N0__(l) COMPILE_TIME_ASSERT_ ## l
#define __CASSERT_N1__(l) __CASSERT_N0__(l)
#define CASSERT(cnd) typedef char __CASSERT_N1__(__LINE__) [(cnd) ? 1 : -1]

#pragma pack(push, 1)
typedef struct LongPtr {
  VoidP addr;
  uint8 bank;
} LongPtr;
#pragma pack (pop)
#define LONGPTR(t) {(t) & 0xffff, (t) >> 16}

static inline uint8 __CFSHL__(uint8 x, uint8 t) { return x >> (8 - t); }
static inline uint8 __CFSHL__uint16(uint16 x) { return x >> 15; }

static inline bool __CFADD__uint16(uint16 x, uint16 y) { return (uint16)(x) > (uint16)(x + y); }
static inline bool __CFADD__uint8(uint8 x, uint8 y) { return (uint8)(x) > (uint8)(x + y); }
static inline bool __CFADD__(uint8 x, uint8 y) { return (uint8)(x) > (uint8)(x + y); }

typedef struct PairU16 {
  uint16 first, second;
} PairU16;

typedef struct PointU16 {
  uint16 x, y;
} PointU16;

typedef struct PointU8 {
  uint8 x, y;
} PointU8;

typedef struct OamEnt {
  uint8 xpos;
  uint8 ypos;
  uint8 charnum;
  uint8 flags;
} OamEnt;

typedef void FuncU8(uint8 kk);
typedef void FuncV(void);

// Some convenience macros to make partial accesses nicer
#define LAST_IND(x,part_type)    (sizeof(x)/sizeof(part_type) - 1)
#define HIGH_IND(x,part_type)  LAST_IND(x,part_type)
#define LOW_IND(x,part_type)   0
// first unsigned macros:
#define BYTEn(x, n)   (*((uint8*)&(x)+n))
#define WORDn(x, n)   (*((uint16*)&(x)+n))

#define LOBYTE(x)  BYTEn(x,LOW_IND(x,uint8))
#define LOWORD(x)  WORDn(x,LOW_IND(x,uint16))
#define HIBYTE(x)  BYTEn(x,1)
#define HIWORD(x)  WORDn(x,HIGH_IND(x,uint16))

#define GET_HIBYTE(x) (((x) & 0xff00) >> 8)

// Generate a pair of operands.
#define PAIR16(high, low) ((uint16)((high) << 8) | (uint8)(low))
#define __PAIR16__   PAIR16
#define __PAIR32__(high, low)   (((uint32) (high) << 16) | (uint16)(low))

// Helper functions to represent some assembly instructions.

// compile time assertion
#define __CASSERT_N0__(l) COMPILE_TIME_ASSERT_ ## l
#define __CASSERT_N1__(l) __CASSERT_N0__(l)
#define CASSERT(cnd) typedef char __CASSERT_N1__(__LINE__) [(cnd) ? 1 : -1]

static inline PairU16 MakePairU16(uint16 k, uint16 j) {
  PairU16 r = { k, j };
  return r;
}

#define MakePairU16_AX MakePairU16
#define MakePairU16_AY MakePairU16


typedef struct MemBlk {
  const uint8 *ptr;
  size_t size;
} MemBlk;
MemBlk FindIndexInMemblk(MemBlk data, size_t i);
const uint8 *FindAddrInMemblk(MemBlk data, uint32 addr);

#endif  // SM_TYPES_H_

