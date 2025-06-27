/* Include ::: Header File Source */
#include "Library_SOFTWARE_CRC.h"

/******************************************************************************/
/* == Development Control Functions == */
/******************************************************************************/

uint01_t xLibray_POLYNOMIAL_CRC01(uint01_t PARITY, uint08_t BUFFER) {
  /* Loop ::: Calculation CRC_VAL for All Bits */
  for (uint08_t COUNTER = 0U; COUNTER < 8U; COUNTER++) {
    /* Calculation CRC_VAL */
    if (BUFFER & 0x01) {
      BUFFER = (BUFFER >> 1U) ^ 0x01; // Polynomial: x+1 (0x01)
    } else {
      BUFFER >>= 1U;
    }
  }

  /* Return ::: Calculation CRC_VAL */
  return (BUFFER ^ PARITY);
}

uint08_t xLibray_POLYNOMIAL_CRC03(uint08_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Check ::: Pointer */
  if (pxBUFFER != NULL) {
    /* Loop ::: Full Array */
    while (LENGTH--) {
      /* Copy ::: POLYNOMIAL & Initial CRC_VAL */
      CRC_VAL = CRC_VAL ^ *pxBUFFER++;

      /* Loop ::: Calculation CRC_VAL for All Bits */
      for (uint08_t COUNTER = 0U; COUNTER < 8U; COUNTER++) {
        /* Calculation CRC_VAL */
        if (CRC_VAL & 0x1) {
          CRC_VAL = ((CRC_VAL >> 1U) ^ 0xB); // Polynomial: x^3 + x + 1 (0x0B)
        } else {
          CRC_VAL >>= 1U;
        }
      }
    }
  }

  /* Return ::: Calculation CRC_VAL */
  return (CRC_VAL);
}

uint08_t xLibray_POLYNOMIAL_CRC08(uint08_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Check ::: Pointer */
  if (pxBUFFER != NULL) {
    /* Loop ::: Full Array */
    while (LENGTH--) {
      /* Copy ::: POLYNOMIAL & Initial CRC_VAL */
      CRC_VAL = CRC_VAL ^ *pxBUFFER++;

      /* Loop ::: Calculation CRC_VAL for All Bits */
      for (uint08_t COUNTER = 0U; COUNTER < 8U; COUNTER++) {
        /* Calculation CRC_VAL */
        if (CRC_VAL & 0x01) {
          CRC_VAL = ((CRC_VAL >> 1U) ^ 0x8C); // Polynomial: x^8 + x^5 + x^4 + 1 (0x8C)
        } else {
          CRC_VAL >>= 1U;
        }
      }
    }
  }

  /* Return ::: Calculation CRC_VAL */
  return (CRC_VAL);
}

uint16_t xLibray_POLYNOMIAL_CRC16(uint16_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Check ::: Pointer */
  if (pxBUFFER != NULL) {
    /* Loop ::: Full Array */
    while (LENGTH--) {
      /* Copy ::: POLYNOMIAL & Initial CRC_VAL */
      CRC_VAL = CRC_VAL ^ *pxBUFFER++;

      /* Loop ::: Calculation CRC_VAL for All Bits */
      for (uint08_t COUNTER = 0U; COUNTER < 8U; COUNTER++) {
        /* Calculation CRC_VAL */
        if (CRC_VAL & 0x0001) {
          CRC_VAL = (CRC_VAL >> 1U) ^ 0xA001; // Polynomial: x^16 + x^15 + x^2 + 1 (0xA001)
        } else {
          CRC_VAL >>= 1U;
        }
      }
    }
  }

  /* Return ::: CRC_VAL16 */
  return (CRC_VAL);
}

uint32_t xLibray_POLYNOMIAL_CRC32(uint32_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Check ::: Pointer */
  if (pxBUFFER != NULL) {
    /* Loop ::: Full Array */
    while (LENGTH--) {
      /* Copy ::: POLYNOMIAL & Initial CRC_VAL */
      CRC_VAL = CRC_VAL ^ *pxBUFFER++;

      /* Loop ::: Calculation CRC_VAL for All Bits */
      for (uint08_t COUNTER = 0U; COUNTER < 8U; COUNTER++) {
        /* Calculation CRC_VAL */
        if (CRC_VAL & 0x00000001) {
          CRC_VAL = (CRC_VAL >> 1U) ^ 0x04C11DB7; // Polynomial: x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1 (0x04C11DB7)
        } else {
          CRC_VAL >>= 1U;
        }
      }
    }
  }

  /* Return ::: CRC_VAL16 */
  return (CRC_VAL);
}
