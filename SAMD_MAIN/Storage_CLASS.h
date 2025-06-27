#ifndef STORAGE_CLASS_H
#define STORAGE_CLASS_H

/* Global ::: Variables */
/* Local ::: Variables */

/* Auxiliary ::: Control Functions */
/* Prototype ::: Control Functions */
/* Development ::: Control Functions */

/* Statement ::: Function Variables */
/* Statement ::: Constant Variables */
/* Statement ::: Constant Enumerations */
/* Statement ::: External Variables */
/* Statement ::: Auxiliary Functions */

/* Definition ::: Typedef Storage Class */
/* Definition ::: Configuration Macros */

/* * Functions Type Definitions
 *
 * Unsigned (u)
 * Void (v)
 * Base_Type (t)
 * bool (b)
 * Char (c)
 * Short (s)
 * Long (l)
 * Float/Double (d)
 * Emun (e)
 * Pointer (p)
 * Struct / Others (x) */

/*----------------------------------------------------------------------------*/

/* Include ::: Header Integer Types */
#include "stdint.h"

/* Include ::: Header Standard Types */
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/* Include ::: SAM */
#include <xc.h>

/* Definition ::: Oscillator Clock System */
#define FSC_CLOCK_SYSTEM (uint32_t)(48000000UL)

/* Definition ::: Typedef uint01_t Class */
typedef bool uint01_t;

/* Definition ::: Typedef uint08_t Class */
typedef uint8_t uint08_t;
typedef int8_t int08_t;
#define UINT08_MAX UINT8_MAX

/* Definition ::: Get Type pf Variable */
enum VALUE_TYPE_UNSIGNED { UINT1, UINT8, UINT16, UINT32, UINT64, UINVALID };
#define TYPE_NAME_UNSIGNED(X) _Generic((X), uint01_t: UINT1, uint08_t: UINT8, uint16_t: UINT16, uint32_t: UINT32, uint64_t: UINT64, default: UINVALID)

enum VALUE_TYPE_SIGNED { INT8, INT16, INT32, INT64, INVALID };
#define TYPE_NAME_SIGNED(X)    _Generic((X), int08_t: INT8, int16_t: INT16, int32_t: INT32, int64_t: INT64, default: INVALID)

/* Definition ::: Configuration Macros Management Bits */
#define BIT_GET(REG, BIT)      (REG & (1U << BIT))
#define BIT_SET(REG, BIT)      (REG |= (1U << BIT))
#define BIT_CLR(REG, BIT)      (REG &= ~(1U << BIT))
#define BIT_TGL(REG, BIT)      (REG ^= (1U << BIT))
#define BIT_WRT(VAL, REG, BIT) (VAL ? BIT_SET(REG, BIT) : BIT_CLR(REG, BIT))

/* Definition ::: Configuration Macros Management Bytes */
#define SWAP_BYTE(A, B)        ((&(A) == &(B)) ? (A) : ((A) ^= (B), (B) ^= (A), (A) ^= (B)))
#define SWAP_UINT08(BYTE)      (uint08_t)((BYTE >> 4U) | (BYTE << 4U))
#define SWAP_UINT16(WORD)      (uint16_t)((WORD >> 8U) | (WORD << 8U))
#define SWAP_UINT32(LONG)      (uint32_t)((LONG >> 24U) | ((LONG & 0x00FF0000) >> 8U) | ((LONG & 0x0000FF00) << 8U) | (LONG << 24U))
#define ROUND_UP(A, B)         (((A)-1U) / (B) + 1U)
#define ABS(X)                 ((X) > 0U ? (X) : -(X))

/* Definition ::: Configuration Macros Management Min & Max */
#define MAX(X, Y)      \
  ({                   \
    typeof(X) A = (X); \
    typeof(Y) B = (Y); \
    A > B ? A : B;     \
  })

#define MIN(X, Y)      \
  ({                   \
    typeof(X) A = (X); \
    typeof(Y) B = (Y); \
    A < B ? A : B;     \
  })

/* Definition ::: Configuration Macros Management Utils */
#define CONTAINER_OF(Ptr, Type, Field) ((Type *)(((uint08_t *)Ptr) - offsetof(Type, Field))) // Retrieve pointer to parent structure
#define ARRAY_SIZE(A)                  (sizeof(A) / sizeof((A)[0]))                          // Retrieve array size
#define COMPILER_PRAGMA(Arg)           _Pragma(#Arg)                                         // The pragma directive as it would appear after \e \#pragma
#define COMPILER_PACK_SET(Alig)        COMPILER_PRAGMA(pack(Alig))                           // Set maximum alignment for subsequent struct and union definitions to \a alignment.
#define COMPILER_PACK_RESET()          COMPILER_PRAGMA(pack())                               // Set default alignment for subsequent struct and union definitions

/* Definition ::: Configuration Macros Management Simple Read Input */
#define READ_PULSE_DIRECT(I)           ((I && true) ? true : false)
#define READ_PULSE_INVERT(I)           ((!I && false) ? true : false)

/* Definition ::: Configuration Macros Management Debug NOP */
#define INTERRUPTS_DISABLE()           __ASM volatile(" cpsid i " ::: "memory")
#define INTERRUPTS_ENABLE()            __ASM volatile(" cpsie i " ::: "memory")

#define NOP()                          __ASM volatile("nop")
#define RESET()                        NVIC_SystemReset()

#ifdef __DEBUG
  #define pdNOP() NOP()
#else
  #define pdNOP()
#endif

#define ENTER_CRITICAL_MANAGEMENT()
#define EXIT_CRITICAL_MANAGEMENT()

/* Definition ::: Configuration Macros Management Bits Labels */
#define pdCLR         (false)
#define pdSET         (true)

#define pdEVEN        (false)
#define pdODD         (true)

/* Definition ::: Configuration Macros Management Control Labels */
#define pdNULL        (0U)
#define pdPASSED      (1U)
#define pdDISABLE     (2U)
#define pdENABLE      (3U)
#define pdPROGRAM     (4U)
#define pdSTOCK       (5U)
#define pdOVERLOAD    (6U)
#define pdREVIEW      (7U)
#define pdEMPHY       (9U)
#define pdFULL        (10U)
#define pdERROR       (11U)
#define pdFAILED      (12U)
#define pdBAD_ADDRESS (13U)
#define pdINVALID_ARG (14U)
#define pdDENIED      (15U)
#define pdUNSUPPORTED (16U)
#define pdRESET       (255U)

/* Definition ::: Configuration Macros Management Loops Labels */
#define RUN_LOOP      (true)
#define RUN_MAIN      (true)
#define RUN_TASK      (true)
#define RUN_FUNCTION  (true)
#define RUN_RUTINE    (true)
#define RUN_CORUTINE  (true)
#define RUN_THREAD    (true)
#define RETURN_FREE   (true)
#define RETURN_PASS   (true)

#endif /* STORAGE_CLASS_H */
