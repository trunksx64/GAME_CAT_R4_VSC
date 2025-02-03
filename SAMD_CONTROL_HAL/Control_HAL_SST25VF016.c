/* Include ::: Headers :: Origin */
#include "Control_HAL_SST25VF016.h"
/* Include ::: Header Drivers */
#include "Driver_SAMD_PORT.h"
#include "Driver_SAMD_SERCOM2_SPIM.h"

/******************************************************************************/
/* == Configuration Macros = Defines Controls  == */
/******************************************************************************/
#define vFLASH_SST25VF016_PUT(D)                vDriver_SAMD_SERCOM2_SPIM_PUT(D)
#define xFLASH_SST25VF016_GET()                 xDriver_SAMD_SERCOM2_SPIM_GET()
#define xFLASH_SST25VF016_PUTS(D,L)             vDriver_SAMD_SERCOM2_SPIM_PUTS(D,L)
#define xFLASH_SST25VF016_GETS(D,L)             vDriver_SAMD_SERCOM2_SPIM_GETS(D,L)

#define FLASH_SST25VF016_SENSE_BUSY()			pdSET
#define FLASH_SST25VF016_SS_ENABLE()			FLASH_SS_CLR();	vStorage_DELAY_US(5U)
#define FLASH_SST25VF016_SS_DISABLE()			FLASH_SS_SET();	vStorage_DELAY_US(5U)

/******************************************************************************/
/* == Development Configuration Functions == */
/******************************************************************************/

/* Functions ::: Development */
uint01_t xControl_HAL_FLASH_SST25VF016_CHECK (void) {
    /* GET ::: Serial Into FLASH Memory */
    return (xControl_HAL_FLASH_SST25VF016_GET_JEDEC() == CONTROL_HAL_FLASH_SST25VF016_JEDEC_ID ? pdSET : pdCLR);
}

void vControl_HAL_FLASH_SST25VF016_CONFIG (void) {
    /* Unlock ::: All Block Protection */
    vControl_HAL_FLASH_SST25VF016_PUT_STATUS_CLEAR(CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BPW_BIT);
}

/*----------------------------------------------------------------------------*/

void vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE (void) {
    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* PUT ::: Enable Control */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ENABLE_WRITE);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();
}

void vControl_HAL_FLASH_SST25VF016_WRITE_DISABLE (void) {
    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* PUT ::: Disable Control */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_DISABLE_WRITE);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();
}

void vControl_HAL_FLASH_SST25VF016_ENABLE_WRITE_STATUS (void) {
    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* SET Write-Status-Register instruction */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ENABLE_WRITE_STATUS_REG);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();
}

/*----------------------------------------------------------------------------*/

uint08_t xControl_HAL_FLASH_SST25VF016_GET_STATUS (void) {
    /* Local ::: Variables */
    uint08_t RETURN = 0U;

    /*------------------------------------------------------------------------*/

    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* PUT ::: Read CMD */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_READ_STATUS_REG);
        /* GET ::: Value Status */
        RETURN = xFLASH_SST25VF016_GET();
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();

    /*------------------------------------------------------------------------*/

    /* Retutn ::: Value */
    return (RETURN);
}

void vControl_HAL_FLASH_SST25VF016_PUT_STATUS (uint08_t DATA) {
    /* SET :: Write Status Register */
    vControl_HAL_FLASH_SST25VF016_ENABLE_WRITE_STATUS();

    /*------------------------------------------------------------------------*/

    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* PUT-Status-Register instruction */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_WRITE_STATUS_REG);
        vFLASH_SST25VF016_PUT(DATA);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();
}

void vControl_HAL_FLASH_SST25VF016_PUT_STATUS_SET (uint08_t DATA) {
    /* Local ::: Variables */
    uint08_t STATUS = 0U;

    /*------------------------------------------------------------------------*/

    /* GET ::: Current Status */
    STATUS = xControl_HAL_FLASH_SST25VF016_GET_STATUS();
    /* Masking ::: Status Data */
    STATUS |= DATA;

    /*------------------------------------------------------------------------*/

    /* PUT ::: Status Register */
    vControl_HAL_FLASH_SST25VF016_PUT_STATUS(STATUS);
}

void vControl_HAL_FLASH_SST25VF016_PUT_STATUS_CLEAR (uint08_t DATA) {
    /* Local ::: Variables */
    uint08_t STATUS = 0U;

    /*------------------------------------------------------------------------*/

    /* GET ::: Current Status */
    STATUS = xControl_HAL_FLASH_SST25VF016_GET_STATUS();
    /* Masking ::: Status Data */
    STATUS &= ~DATA;

    /*------------------------------------------------------------------------*/

    /* PUT ::: Status Register */
    vControl_HAL_FLASH_SST25VF016_PUT_STATUS(STATUS);
}

/*----------------------------------------------------------------------------*/

void vControl_HAL_FLASH_SST25VF016_BUSY_OUT_ENABLE (void) {
    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* SET ::: Control Write AAI */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ENABLE_BUSY_SO);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();
}

void vControl_HAL_FLASH_SST25VF016_BUSY_OUT_DISABLE (void) {
    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* CLR ::: Control Write AAI */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_DISABLE_BUSY_SO);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();
}

uint01_t xControl_HAL_FLASH_SST25VF016_CHECK_POLL_BUSY (void) {
    /* GET ::: Sens Busy Data */
    return (!FLASH_SST25VF016_SENSE_BUSY());
}

/*----------------------------------------------------------------------------*/

uint08_t xControl_HAL_FLASH_SST25VF016_GET_BYTE (uint32_t ADDRESS) {
    /* Local ::: Variables */
    uint08_t RETURN = 0U;

    /*------------------------------------------------------------------------*/

    /* Masking ::: Address */
    if (ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) {
        /* Select ::: Memory FLASH */
        FLASH_SST25VF016_SS_ENABLE();
        {
            /* PUT ::: Read Byte CMD */
            vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_READ);
            /* PUT ::: Address Byte */
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
            /* Return ::: Data */
            RETURN = (uint08_t) xFLASH_SST25VF016_GET();
        }
        /* Unselect ::: Memory FLASH */
        FLASH_SST25VF016_SS_DISABLE();
    }

    /*------------------------------------------------------------------------*/

    /* Retutn ::: Value */
    return (RETURN);
}

void vControl_HAL_FLASH_SST25VF016_PUT_BYTE (uint32_t ADDRESS, uint08_t DATA) {
    /* Masking ::: Address */
    if (ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) {
        /* SET ::: Write Memory */
        vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

        /*--------------------------------------------------------------------*/

        /* Select ::: Memory FLASH */
        FLASH_SST25VF016_SS_ENABLE();
        {
            /* PUT ::: Program Byte CMD */
            vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_PROGRAM_BYTE);
            /* PUT ::: Address Byte */
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
            vFLASH_SST25VF016_PUT(DATA);
        }
        /* Unselect ::: Memory FLASH */
        FLASH_SST25VF016_SS_DISABLE();

        /*--------------------------------------------------------------------*/

        /* Poll ::: Write Complete */
        do {
            /* DLY ::: Time */
            vStorage_DELAY_US(10U);
        } while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));
    }
}

uint01_t xControl_HAL_FLASH_SST25VF016_GET_PAGE (uint32_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH) {
    /* Local ::: Variables */
    uint08_t RETURN = 0U;

    /*------------------------------------------------------------------------*/

    /* Masking ::: Address */
    if ((ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) && pxBUFFER && LENGTH) {
        /* Select ::: Memory FLASH */
        FLASH_SST25VF016_SS_ENABLE();
        {
            /* PUT ::: Read Byte CMD */
            vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_READ);
            /* PUT ::: Address Byte */
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
            /* Return ::: Data */
            xFLASH_SST25VF016_GETS(pxBUFFER, LENGTH);
            /* Set ::: RETURN */
            RETURN = pdSET;
        }
        /* Unselect ::: Memory FLASH */
        FLASH_SST25VF016_SS_DISABLE();
    }

    /*------------------------------------------------------------------------*/

    /* Retutn ::: Value */
    return (RETURN);
}

uint01_t xControl_HAL_FLASH_SST25VF016_PUT_PAGE_BYTE (uint32_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH) {
    /* Local ::: Variables */
    uint01_t RETURN = 0U;

    /*------------------------------------------------------------------------*/

    /* Masking ::: Address */
    if (ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) {
        /* Lopp ::: Buffer */
        while (LENGTH--) {
            /* SET ::: Write Memory */
            vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

            /*----------------------------------------------------------------*/

            /* Select ::: Memory FLASH */
            FLASH_SST25VF016_SS_ENABLE();
            {
                /* PUT ::: Program Byte CMD */
                vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_PROGRAM_BYTE);
                /* PUT ::: Address Byte */
                vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
                vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
                vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
                vFLASH_SST25VF016_PUT(*pxBUFFER);

            }
            /* Unselect ::: Memory FLASH */
            FLASH_SST25VF016_SS_DISABLE();

            /*----------------------------------------------------------------*/

            /* Poll ::: Write Complete */
            while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));

            /*----------------------------------------------------------------*/

            /* ICN ::: Buffer & Address */
            ADDRESS++;
            pxBUFFER++;
        }

        /* Set ::: RETURN */
        RETURN = pdSET;
    }

    /*------------------------------------------------------------------------*/

    /* Retutn ::: Value */
    return (RETURN);
}

uint01_t xControl_HAL_FLASH_SST25VF016_PUT_PAGE_WORD (uint32_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH) {
    /* Local ::: Variables */
    uint01_t REPEAT = pdSET;

    /*------------------------------------------------------------------------*/

    /* Masking ::: Address */
    if ((ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) && pxBUFFER && LENGTH) {
        /* GET ::: Offset EVEN */
        if ((LENGTH % 2U) == 0U) {
            /* SET ::: Write Memory */
            vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

            /*----------------------------------------------------------------*/

            /* Loop ::: Put Buffer OFFSET_EVN */
            while (LENGTH) {
                /* Select ::: Memory FLASH */
                FLASH_SST25VF016_SS_ENABLE();
                {
                    /* PUT ::: Program Byte CMD */
                    vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_PROGRAM_WORD);

                    /* CHK ::: ADDRESS */
                    if (REPEAT) {
                        /* CLR ::: ADDRESS */
                        REPEAT = pdCLR;
                        /* PUT ::: Address Byte */
                        vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
                        vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
                        vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
                    }

                    /* PUT ::: Data */
                    xFLASH_SST25VF016_PUTS(pxBUFFER, CONTROL_HAL_FLASH_SST25VF016_WORD_SIZE);
                }

                /*------------------------------------------------------------*/

                /* Unselect ::: Memory FLASH */
                FLASH_SST25VF016_SS_DISABLE();

                /*------------------------------------------------------------*/

                /* Poll ::: Write Complete */
                do {
                    /* DLY ::: Time */
                    vStorage_DELAY_US(10U);
                } while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));

                /*------------------------------------------------------------*/

                /* DEC ::: Ctrl */
                LENGTH -= CONTROL_HAL_FLASH_SST25VF016_WORD_SIZE;
                /* ICN ::: Buffer */
                pxBUFFER += CONTROL_HAL_FLASH_SST25VF016_WORD_SIZE;
            }

            /*----------------------------------------------------------------*/

            /* CLR ::: Write Memory */
            vControl_HAL_FLASH_SST25VF016_WRITE_DISABLE();
        }
    }

    /* Retutn ::: Value */
    return (!REPEAT);
}

/*----------------------------------------------------------------------------*/

void vControl_HAL_FLASH_SST25VF016_BLOCK_ERASE_4K (uint32_t ADDRESS) {
    /* Masking ::: Address */
    if (ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) {
        /* SET ::: Write Memory */
        vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

        /*--------------------------------------------------------------------*/

        /* Select ::: Memory FLASH */
        FLASH_SST25VF016_SS_ENABLE();
        {
            /* PUT ::: Erase CMD */
            vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_04K_SECTORS);
            /* PUT ::: Address Sector */
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
        }
        /* Unselect ::: Memory FLASH */
        FLASH_SST25VF016_SS_DISABLE();

        /*--------------------------------------------------------------------*/

        /* Poll ::: Write Complete */
        do {
            /* DLY ::: Time */
            vStorage_DELAY_US(10U);
        } while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));
    }
}

void vControl_HAL_FLASH_SST25VF016_BLOCK_ERASE_32K (uint32_t ADDRESS) {
    /* Masking ::: Address */
    if (ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) {
        /* SET ::: Write Memory */
        vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

        /*--------------------------------------------------------------------*/

        /* Select ::: Memory FLASH */
        FLASH_SST25VF016_SS_ENABLE();
        {
            /* PUT ::: Erase CMD */
            vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_32K_BLOCK);
            /* PUT ::: Address Sector */
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
        }
        /* Unselect ::: Memory FLASH */
        FLASH_SST25VF016_SS_DISABLE();

        /*--------------------------------------------------------------------*/

        /* Poll ::: Write Complete */
        do {
            /* DLY ::: Time */
            vStorage_DELAY_US(10U);
        } while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));
    }
}

void vControl_HAL_FLASH_SST25VF016_BLOCK_ERASE_64K (uint32_t ADDRESS) {
    /* Masking ::: Address */
    if (ADDRESS <= CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY) {
        /* SET ::: Write Memory */
        vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

        /*--------------------------------------------------------------------*/

        /* Select ::: Memory FLASH */
        FLASH_SST25VF016_SS_ENABLE();
        {
            /* PUT ::: Erase CMD */
            vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_64K_BLOCK);
            /* PUT ::: Address Sector */
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 2U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 1U));
            vFLASH_SST25VF016_PUT(*((uint08_t *) (&ADDRESS) + 0U));
        }
        /* Unselect ::: Memory FLASH */
        FLASH_SST25VF016_SS_DISABLE();

        /*--------------------------------------------------------------------*/

        /* Poll ::: Write Complete */
        do {
            /* DLY ::: Time */
            vStorage_DELAY_US(10U);
        } while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));
    }
}

void vControl_HAL_FLASH_SST25VF016_CHIP_ERASE (void) {
    /* SET ::: Write Memory */
    vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE();

    /*------------------------------------------------------------------------*/

    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* PUT ::: Erase CMD */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_ALL_BLOCKS);
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();

    /*------------------------------------------------------------------------*/

    /* Poll ::: Write Complete */
    do {
        /* DLY ::: Time */
        vStorage_DELAY_US(10U);
    } while (xControl_HAL_FLASH_SST25VF016_GET_STATUS() & (CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT));
}

/*----------------------------------------------------------------------------*/

uint16_t xControl_HAL_FLASH_SST25VF016_GET_DEVICE_ID (uint01_t ADD) {
    uint16_t RETURN = 0U;

    /*------------------------------------------------------------------------*/

    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* Set ::: Mode Work */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_READ_ID);
        /* PUT ::: ADDRESS ID */
        vFLASH_SST25VF016_PUT(0x00);
        vFLASH_SST25VF016_PUT(0x00);
        vFLASH_SST25VF016_PUT((uint08_t) ADD);

        /* GET ::: Value ID */
        *((uint08_t *) (&RETURN) + 0U) = xFLASH_SST25VF016_GET();
        *((uint08_t *) (&RETURN) + 1U) = xFLASH_SST25VF016_GET();
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();

    /*------------------------------------------------------------------------*/

    /* Retutn ::: Value */
    return (RETURN);
}

uint32_t xControl_HAL_FLASH_SST25VF016_GET_JEDEC (void) {
    /* Local ::: Variables */
    uint32_t RETURN = 0U;

    /*------------------------------------------------------------------------*/

    /* Select ::: Memory FLASH */
    FLASH_SST25VF016_SS_ENABLE();
    {
        /* Set ::: Mode Work */
        vFLASH_SST25VF016_PUT(CONTROL_HAL_FLASH_SST25VF016_CMD_READ_JEDEC_ID);
        /* GET ::: Value ID */
        *((uint08_t *) (&RETURN) + 2U) = xFLASH_SST25VF016_GET();
        *((uint08_t *) (&RETURN) + 1U) = xFLASH_SST25VF016_GET();
        *((uint08_t *) (&RETURN) + 0U) = xFLASH_SST25VF016_GET();
    }
    /* Unselect ::: Memory FLASH */
    FLASH_SST25VF016_SS_DISABLE();

    /*------------------------------------------------------------------------*/

    /* Retutn ::: Value */
    return (RETURN);
}
