/*******************************************************************************
* File Name: cyfitter_cfg.c
* 
* PSoC Creator  4.0 Update 1
*
* Description:
* This file contains device initialization code.
* Except for the user defined sections in CyClockStartupError(), this file should not be modified.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2016 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "cyfitter_cfg.h"

#define CY_NEED_CYCLOCKSTARTUPERROR 1


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CYPACKED 
    #define CYPACKED_ATTR __attribute__ ((packed))
    #define CYALIGNED __attribute__ ((aligned))
    #define CY_CFG_UNUSED __attribute__ ((unused))
    #ifndef CY_CFG_SECTION
        #define CY_CFG_SECTION __attribute__ ((section(".psocinit")))
    #endif
    
    #if CYDEV_CONFIGURATION_DMA
        #if (defined(__ARMCC_VERSION) || defined(__GNUC__))
            #ifndef DMAINITSEC
                #define DMAINITSEC __attribute__ ((section(".dma_init")))
            #endif
        #elif defined(__ICCARM__)
            #define DMAINITSEC _Pragma("location=\".dma_init\"")
        #endif
    #else
        #define DMAINITSEC
    #endif

    #if defined(__ARMCC_VERSION)
        #define CY_CFG_MEMORY_BARRIER() __memory_changed()
    #else
        #define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
    #endif
    
#elif defined(__ICCARM__)
    #include <intrinsics.h>

    #define CYPACKED __packed
    #define CYPACKED_ATTR 
    #define CYALIGNED _Pragma("data_alignment=4")
    #define CY_CFG_UNUSED _Pragma("diag_suppress=Pe177")
    #define CY_CFG_SECTION _Pragma("location=\".psocinit\"")
    
    #if CYDEV_CONFIGURATION_DMA
        #if (defined(__ARMCC_VERSION) || defined(__GNUC__))
            #ifndef DMAINITSEC
                #define DMAINITSEC __attribute__ ((section(".dma_init")))
            #endif
        #elif defined(__ICCARM__)
            #define DMAINITSEC _Pragma("location=\".dma_init\"")
        #endif
    #else
        #define DMAINITSEC
    #endif

    #define CY_CFG_MEMORY_BARRIER() __DMB()
    
#else
    #error Unsupported toolchain
#endif


CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n);
CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n)
{
	(void)memset(s, 0, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}




/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0u
#define CYCLOCKSTART_XTAL_ERROR  1u
#define CYCLOCKSTART_32KHZ_ERROR 2u
#define CYCLOCKSTART_PLL_ERROR   3u


#ifdef CY_NEED_CYCLOCKSTARTUPERROR
/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc.), the system will end up here.  Unless reimplemented by
*  the customer, this function will stop in an infinite loop.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode);
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

#ifdef CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK
	CY_CFG_Clock_Startup_ErrorCallback();
#else
	/*  If not using CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK, place your clock startup code here. */
    /* `#START CyClockStartupError` */

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

    /* `#END` */

    /* If nothing else, stop here since the clocks have not started         */
    /* correctly.                                                           */
    while(1) {}
#endif /* CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK */ 
}
#endif

/* IOPORT_5 Address: CYDEV_PRTDSI_PRT5_BASE Size (bytes): 7 */
#define BS_IOPORT_5_VAL ((const uint8 CYFAR *)0x48000000u)

/* IDMUX_IRQ Address: CYREG_IDMUX_IRQ_CTL0 Size (bytes): 8 */
#define BS_IDMUX_IRQ_VAL ((const uint8 CYFAR *)0x48000008u)

/* TMR0 Address: CYREG_TMR0_CFG0 Size (bytes): 12 */
#define BS_TMR0_VAL ((const uint8 CYFAR *)0x48000010u)

/* UDB_0_2_0_CONFIG Address: CYDEV_UCFG_B0_P4_U1_BASE Size (bytes): 128 */
#define BS_UDB_0_2_0_CONFIG_VAL ((const uint8 CYFAR *)0x4800001Cu)

/* UDB_1_0_0_CONFIG Address: CYDEV_UCFG_B1_P2_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_0_0_CONFIG_VAL ((const uint8 CYFAR *)0x4800009Cu)

/* UDB_1_0_1_CONFIG Address: CYDEV_UCFG_B1_P2_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_0_1_CONFIG_VAL ((const uint8 CYFAR *)0x4800011Cu)

/* UDB_1_1_1_CONFIG Address: CYDEV_UCFG_B1_P3_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_1_1_CONFIG_VAL ((const uint8 CYFAR *)0x4800019Cu)

/* UDB_1_1_0_CONFIG Address: CYDEV_UCFG_B1_P3_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_1_0_CONFIG_VAL ((const uint8 CYFAR *)0x4800021Cu)

/* UDB_0_1_1_CONFIG Address: CYDEV_UCFG_B1_P4_U0_BASE Size (bytes): 128 */
#define BS_UDB_0_1_1_CONFIG_VAL ((const uint8 CYFAR *)0x4800029Cu)

/* UDB_0_1_0_CONFIG Address: CYDEV_UCFG_B1_P4_U1_BASE Size (bytes): 128 */
#define BS_UDB_0_1_0_CONFIG_VAL ((const uint8 CYFAR *)0x4800031Cu)

/* UDB_0_0_0_CONFIG Address: CYDEV_UCFG_B1_P5_U0_BASE Size (bytes): 128 */
#define BS_UDB_0_0_0_CONFIG_VAL ((const uint8 CYFAR *)0x4800039Cu)

/* UDB_0_0_1_CONFIG Address: CYDEV_UCFG_B1_P5_U1_BASE Size (bytes): 128 */
#define BS_UDB_0_0_1_CONFIG_VAL ((const uint8 CYFAR *)0x4800041Cu)

/* UWRK_B1_WRK_STATCTL_BITS Address: CYDEV_UWRK_UWRK8_B1_BASE + 0x00000070u Size (bytes): 32 */
#define BS_UWRK_B1_WRK_STATCTL_BITS_VAL ((const uint8 CYFAR *)0x4800049Cu)

/* UCFG_BCTL1 Address: CYREG_BCTL1_MDCLK_EN Size (bytes): 16 */
#define BS_UCFG_BCTL1_VAL ((const uint8 CYFAR *)0x480004BCu)

/* DSISWITCH_0_0 Address: CYDEV_UCFG_DSI13_BASE Size (bytes): 128 */
#define BS_DSISWITCH_0_0_VAL ((const uint8 CYFAR *)0x480004CCu)

/* DSI0_0_HV_ROUTING Address: CYDEV_UCFG_DSI13_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI0_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x4800054Cu)

/* DSI0_1_HV_ROUTING Address: CYDEV_UCFG_DSI12_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI0_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480005CCu)

/* DSI0_2_HV_ROUTING Address: CYDEV_UCFG_DSI7_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI0_2_HV_ROUTING_VAL ((const uint8 CYFAR *)0x4800064Cu)

/* DSISWITCH_0_3 Address: CYDEV_UCFG_DSI6_BASE Size (bytes): 128 */
#define BS_DSISWITCH_0_3_VAL ((const uint8 CYFAR *)0x480006CCu)

/* DSI0_3_HV_ROUTING Address: CYDEV_UCFG_DSI6_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI0_3_HV_ROUTING_VAL ((const uint8 CYFAR *)0x4800074Cu)

/* DSI0_4_HV_ROUTING Address: CYDEV_UCFG_DSI5_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI0_4_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480007CCu)

/* DSISWITCH_0_5 Address: CYDEV_UCFG_DSI4_BASE Size (bytes): 128 */
#define BS_DSISWITCH_0_5_VAL ((const uint8 CYFAR *)0x4800084Cu)

/* DSI0_5_HV_ROUTING Address: CYDEV_UCFG_DSI4_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI0_5_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480008CCu)

/* UDBSWITCH_0_0 Address: CYDEV_UCFG_B1_P5_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_0_0_VAL ((const uint8 CYFAR *)0x4800094Cu)

/* UDB_1_0_HV_ROUTING Address: CYDEV_UCFG_B1_P5_ROUTE_BASE + 0x00000080u Size (bytes): 128 */
#define BS_UDB_1_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480009CCu)

/* UDBSWITCH_1_0 Address: CYDEV_UCFG_B1_P2_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_0_VAL ((const uint8 CYFAR *)0x48000A4Cu)

/* UDB_2_0_HV_ROUTING Address: CYDEV_UCFG_B1_P2_ROUTE_BASE + 0x00000080u Size (bytes): 128 */
#define BS_UDB_2_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000ACCu)

/* UDBSWITCH_0_1 Address: CYDEV_UCFG_B1_P4_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_0_1_VAL ((const uint8 CYFAR *)0x48000B4Cu)

/* UDB_1_1_HV_ROUTING Address: CYDEV_UCFG_B1_P4_ROUTE_BASE + 0x00000080u Size (bytes): 128 */
#define BS_UDB_1_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000BCCu)

/* UDBSWITCH_1_1 Address: CYDEV_UCFG_B1_P3_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_1_VAL ((const uint8 CYFAR *)0x48000C4Cu)

/* UDB_2_1_HV_ROUTING Address: CYDEV_UCFG_B1_P3_ROUTE_BASE + 0x00000080u Size (bytes): 128 */
#define BS_UDB_2_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000CCCu)

/* UDBSWITCH_0_2 Address: CYDEV_UCFG_B0_P4_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_0_2_VAL ((const uint8 CYFAR *)0x48000D4Cu)

/* UDB_2_2_HV_ROUTING Address: CYDEV_UCFG_B0_P3_ROUTE_BASE + 0x00000080u Size (bytes): 128 */
#define BS_UDB_2_2_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000DCCu)

/* DSI3_0_HV_ROUTING Address: CYDEV_UCFG_DSI9_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI3_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000E4Cu)

/* DSISWITCH_1_1 Address: CYDEV_UCFG_DSI8_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_1_VAL ((const uint8 CYFAR *)0x48000ECCu)

/* DSI3_1_HV_ROUTING Address: CYDEV_UCFG_DSI8_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI3_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000F4Cu)

/* DSISWITCH_1_2 Address: CYDEV_UCFG_DSI3_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_2_VAL ((const uint8 CYFAR *)0x48000FCCu)

/* DSI3_2_HV_ROUTING Address: CYDEV_UCFG_DSI3_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI3_2_HV_ROUTING_VAL ((const uint8 CYFAR *)0x4800104Cu)

/* DSISWITCH_1_3 Address: CYDEV_UCFG_DSI2_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_3_VAL ((const uint8 CYFAR *)0x480010CCu)

/* DSI3_3_HV_ROUTING Address: CYDEV_UCFG_DSI2_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI3_3_HV_ROUTING_VAL ((const uint8 CYFAR *)0x4800114Cu)

/* DSI3_4_HV_ROUTING Address: CYDEV_UCFG_DSI1_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI3_4_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480011CCu)

/* DSISWITCH_1_5 Address: CYDEV_UCFG_DSI0_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_5_VAL ((const uint8 CYFAR *)0x4800124Cu)

/* DSI3_5_HV_ROUTING Address: CYDEV_UCFG_DSI0_BASE + 0x00000080u Size (bytes): 128 */
#define BS_DSI3_5_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480012CCu)

/* IOPINS0_1 Address: CYREG_PRT1_DR Size (bytes): 10 */
#define BS_IOPINS0_1_VAL ((const uint8 CYFAR *)0x4800134Cu)

/* IOPINS0_2 Address: CYREG_PRT2_DM0 Size (bytes): 8 */
#define BS_IOPINS0_2_VAL ((const uint8 CYFAR *)0x48001358u)

/* IOPINS0_5 Address: CYREG_PRT5_DM0 Size (bytes): 8 */
#define BS_IOPINS0_5_VAL ((const uint8 CYFAR *)0x48001360u)

/* CYDEV_CLKDIST_ACFG0_CFG0 Address: CYREG_CLKDIST_ACFG0_CFG0 Size (bytes): 4 */
#define BS_CYDEV_CLKDIST_ACFG0_CFG0_VAL ((const uint8 CYFAR *)0x48001368u)


/*******************************************************************************
* Function Name: cfg_dma_init
********************************************************************************
* Summary:
*  This function is used to copy device configuration data from constant values
*  stored in memory into the proper chip configuration registers using DMA.  It
*  pulls data out of the CFG_TD_LISTs to know exactly how/what to configure.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_dma_init(void);
static void cfg_dma_init(void)
{
	/* TD structure for little-endian systems. Does not require endian swap */
	CYPACKED struct td_t {
		uint16 size;
		uint8 next_td_ptr;
		uint8 flags;
		uint16 src;
		uint16 dest;
	} CYPACKED_ATTR;

	/* PHUB_CH1_CFGMEM_CFG0/1 initialization data */
	DMAINITSEC static const uint8 CYCODE CH1_ADDR_DATA0[] = { 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x20u, 0x00u, 0x40u };

	/* PHUB_CH2_CFGMEM_CFG0/1 initialization data */
	DMAINITSEC static const uint8 CYCODE CH2_ADDR_DATA0[] = { 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x20u, 0x01u, 0x40u };

	/* PHUB_CH5_CFGMEM_CFG0/1 initialization data */
	DMAINITSEC static const uint8 CYCODE CH5_ADDR_DATA0[] = { 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x48u, 0x00u, 0x40u };

	/* PHUB_CH6_CFGMEM_CFG0/1 initialization data */
	DMAINITSEC static const uint8 CYCODE CH6_ADDR_DATA0[] = { 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x48u, 0x01u, 0x40u };

	/* Initialization data for each DMA channel's TD registers */
	DMAINITSEC static const uint8 CYCODE DMA_TD_START_CMD[] = { 0x01u, 0x00u, 0x00u, 0x00u, 0x01u };

	CYALIGNED static uint32 CYXDATA DMA_ZERO_VAL;

	/* This table holds all of the initialization data necessary for the DMA
	   process to transfer data from the source location to the destination. */
	/* Source addresses can be relocated, but only when in 32bit addresses.
	   Because the standard TD table only has 16bit addresses, we generate a
	   separate CFG_TD_ADDR table for the source addresses that supports 32bit
	   addresses. */
	DMAINITSEC static const struct td_t CYCODE CFG_TD_LIST0[] = {
		/* Size, Next, Flags, Source, Destination */
		{ 8u, 0x02u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CFGMEM1_CFG0) },	/* TD 1 */
		{ 8u, 0x03u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CFGMEM2_CFG0) },	/* TD 2 */
		{ 8u, 0x04u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CFGMEM5_CFG0) },	/* TD 3 */
		{ 8u, 0x05u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CFGMEM6_CFG0) },	/* TD 4 */
		{ 5u, 0x06u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CH1_BASIC_CFG) },	/* TD 5 */
		{ 5u, 0x07u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CH2_BASIC_CFG) },	/* TD 6 */
		{ 5u, 0x08u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CH5_BASIC_CFG) },	/* TD 7 */
		{ 5u, 0xFEu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_PHUB_CH6_BASIC_CFG) },	/* TD 8 */
		{ 16u, 0x0Au, 0x22u, (uint16)(uint32)(0u), (uint16)(CYREG_PRT0_DR) },	/* TD 9 */
		{ 32u, 0x0Bu, 0x22u, (uint16)(uint32)(0u), (uint16)(CYREG_PRT3_DR) },	/* TD 10 */
		{ 16u, 0x0Cu, 0x22u, (uint16)(uint32)(0u), (uint16)(CYREG_PRT6_DR) },	/* TD 11 */
		{ 16u, 0x0Du, 0x22u, (uint16)(uint32)(0u), (uint16)(CYREG_PRT12_DR) },	/* TD 12 */
		{ 16u, 0xFEu, 0x22u, (uint16)(uint32)(0u), (uint16)(CYREG_PRT15_DR) },	/* TD 13 */
		{ 1920u, 0x0Fu, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B0_P0_U0_BASE) },	/* TD 14 */
		{ 128u, 0x10u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B0_P4_U0_BASE) },	/* TD 15 */
		{ 1664u, 0x11u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B0_P4_ROUTE_BASE + 0x00000080u) },	/* TD 16 */
		{ 128u, 0x12u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI1_BASE) },	/* TD 17 */
		{ 128u, 0x13u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI5_BASE) },	/* TD 18 */
		{ 128u, 0x14u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI7_BASE) },	/* TD 19 */
		{ 128u, 0x15u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI9_BASE) },	/* TD 20 */
		{ 128u, 0x16u, 0x22u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI12_BASE) },	/* TD 21 */
		{ 16u, 0xFEu, 0x22u, (uint16)(uint32)(0u), (uint16)(CYREG_BCTL0_MDCLK_EN) },	/* TD 22 */
		{ 7u, 0x18u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_PRTDSI_PRT5_BASE) },	/* TD 23 */
		{ 12u, 0x19u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_TMR0_CFG0) },	/* TD 24 */
		{ 32u, 0xFEu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UWRK_UWRK8_B1_BASE + 0x00000070u) },	/* TD 25 */
		{ 8u, 0x1Bu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_IDMUX_IRQ_CTL0) },	/* TD 26 */
		{ 128u, 0x1Cu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B0_P4_U1_BASE) },	/* TD 27 */
		{ 128u, 0x1Du, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P2_U0_BASE) },	/* TD 28 */
		{ 128u, 0x1Eu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P2_U1_BASE) },	/* TD 29 */
		{ 128u, 0x1Fu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P3_U0_BASE) },	/* TD 30 */
		{ 128u, 0x20u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P3_U1_BASE) },	/* TD 31 */
		{ 128u, 0x21u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P4_U0_BASE) },	/* TD 32 */
		{ 128u, 0x22u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P4_U1_BASE) },	/* TD 33 */
		{ 128u, 0x23u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P5_U0_BASE) },	/* TD 34 */
		{ 128u, 0x24u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P5_U1_BASE) },	/* TD 35 */
		{ 16u, 0x25u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYREG_BCTL1_MDCLK_EN) },	/* TD 36 */
		{ 128u, 0x26u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI13_BASE) },	/* TD 37 */
		{ 128u, 0x27u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI13_BASE + 0x00000080u) },	/* TD 38 */
		{ 128u, 0x28u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI12_BASE + 0x00000080u) },	/* TD 39 */
		{ 128u, 0x29u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI7_BASE + 0x00000080u) },	/* TD 40 */
		{ 128u, 0x2Au, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI6_BASE) },	/* TD 41 */
		{ 128u, 0x2Bu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI6_BASE + 0x00000080u) },	/* TD 42 */
		{ 128u, 0x2Cu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI5_BASE + 0x00000080u) },	/* TD 43 */
		{ 128u, 0x2Du, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI4_BASE) },	/* TD 44 */
		{ 128u, 0x2Eu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI4_BASE + 0x00000080u) },	/* TD 45 */
		{ 128u, 0x2Fu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P5_ROUTE_BASE) },	/* TD 46 */
		{ 128u, 0x30u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P5_ROUTE_BASE + 0x00000080u) },	/* TD 47 */
		{ 128u, 0x31u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P2_ROUTE_BASE) },	/* TD 48 */
		{ 128u, 0x32u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P2_ROUTE_BASE + 0x00000080u) },	/* TD 49 */
		{ 128u, 0x33u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P4_ROUTE_BASE) },	/* TD 50 */
		{ 128u, 0x34u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P4_ROUTE_BASE + 0x00000080u) },	/* TD 51 */
		{ 128u, 0x35u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P3_ROUTE_BASE) },	/* TD 52 */
		{ 128u, 0x36u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B1_P3_ROUTE_BASE + 0x00000080u) },	/* TD 53 */
		{ 128u, 0x37u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B0_P4_ROUTE_BASE) },	/* TD 54 */
		{ 128u, 0x38u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_B0_P3_ROUTE_BASE + 0x00000080u) },	/* TD 55 */
		{ 128u, 0x39u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI9_BASE + 0x00000080u) },	/* TD 56 */
		{ 128u, 0x3Au, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI8_BASE) },	/* TD 57 */
		{ 128u, 0x3Bu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI8_BASE + 0x00000080u) },	/* TD 58 */
		{ 128u, 0x3Cu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI3_BASE) },	/* TD 59 */
		{ 128u, 0x3Du, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI3_BASE + 0x00000080u) },	/* TD 60 */
		{ 128u, 0x3Eu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI2_BASE) },	/* TD 61 */
		{ 128u, 0x3Fu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI2_BASE + 0x00000080u) },	/* TD 62 */
		{ 128u, 0x40u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI1_BASE + 0x00000080u) },	/* TD 63 */
		{ 128u, 0x41u, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI0_BASE) },	/* TD 64 */
		{ 128u, 0xFEu, 0x23u, (uint16)(uint32)(0u), (uint16)(CYDEV_UCFG_DSI0_BASE + 0x00000080u) },	/* TD 65 */
	};

	/* Source addresses can be relocated, but only when in 32bit addresses.
	   Because the standard TD table only has 16bit addresses, we generate a
	   separate table for the source addresses that does use 32bit addresses. This
	   table will be re-merged with the corresponding CFG_TD_LIST table during
	   initialization. */
	static const void * const CFG_TD_ADDR0[] = {
		(const void *)(CH1_ADDR_DATA0),	/* TD 1 */
		(const void *)(CH2_ADDR_DATA0),	/* TD 2 */
		(const void *)(CH5_ADDR_DATA0),	/* TD 3 */
		(const void *)(CH6_ADDR_DATA0),	/* TD 4 */
		(const void *)(DMA_TD_START_CMD),	/* TD 5 */
		(const void *)(DMA_TD_START_CMD),	/* TD 6 */
		(const void *)(DMA_TD_START_CMD),	/* TD 7 */
		(const void *)(DMA_TD_START_CMD),	/* TD 8 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 9 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 10 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 11 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 12 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 13 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 14 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 15 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 16 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 17 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 18 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 19 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 20 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 21 */
		(const void *)(&DMA_ZERO_VAL),	/* TD 22 */
		(const void *)(BS_IOPORT_5_VAL),	/* TD 23 */
		(const void *)(BS_TMR0_VAL),	/* TD 24 */
		(const void *)(BS_UWRK_B1_WRK_STATCTL_BITS_VAL),	/* TD 25 */
		(const void *)(BS_IDMUX_IRQ_VAL),	/* TD 26 */
		(const void *)(BS_UDB_0_2_0_CONFIG_VAL),	/* TD 27 */
		(const void *)(BS_UDB_1_0_0_CONFIG_VAL),	/* TD 28 */
		(const void *)(BS_UDB_1_0_1_CONFIG_VAL),	/* TD 29 */
		(const void *)(BS_UDB_1_1_1_CONFIG_VAL),	/* TD 30 */
		(const void *)(BS_UDB_1_1_0_CONFIG_VAL),	/* TD 31 */
		(const void *)(BS_UDB_0_1_1_CONFIG_VAL),	/* TD 32 */
		(const void *)(BS_UDB_0_1_0_CONFIG_VAL),	/* TD 33 */
		(const void *)(BS_UDB_0_0_0_CONFIG_VAL),	/* TD 34 */
		(const void *)(BS_UDB_0_0_1_CONFIG_VAL),	/* TD 35 */
		(const void *)(BS_UCFG_BCTL1_VAL),	/* TD 36 */
		(const void *)(BS_DSISWITCH_0_0_VAL),	/* TD 37 */
		(const void *)(BS_DSI0_0_HV_ROUTING_VAL),	/* TD 38 */
		(const void *)(BS_DSI0_1_HV_ROUTING_VAL),	/* TD 39 */
		(const void *)(BS_DSI0_2_HV_ROUTING_VAL),	/* TD 40 */
		(const void *)(BS_DSISWITCH_0_3_VAL),	/* TD 41 */
		(const void *)(BS_DSI0_3_HV_ROUTING_VAL),	/* TD 42 */
		(const void *)(BS_DSI0_4_HV_ROUTING_VAL),	/* TD 43 */
		(const void *)(BS_DSISWITCH_0_5_VAL),	/* TD 44 */
		(const void *)(BS_DSI0_5_HV_ROUTING_VAL),	/* TD 45 */
		(const void *)(BS_UDBSWITCH_0_0_VAL),	/* TD 46 */
		(const void *)(BS_UDB_1_0_HV_ROUTING_VAL),	/* TD 47 */
		(const void *)(BS_UDBSWITCH_1_0_VAL),	/* TD 48 */
		(const void *)(BS_UDB_2_0_HV_ROUTING_VAL),	/* TD 49 */
		(const void *)(BS_UDBSWITCH_0_1_VAL),	/* TD 50 */
		(const void *)(BS_UDB_1_1_HV_ROUTING_VAL),	/* TD 51 */
		(const void *)(BS_UDBSWITCH_1_1_VAL),	/* TD 52 */
		(const void *)(BS_UDB_2_1_HV_ROUTING_VAL),	/* TD 53 */
		(const void *)(BS_UDBSWITCH_0_2_VAL),	/* TD 54 */
		(const void *)(BS_UDB_2_2_HV_ROUTING_VAL),	/* TD 55 */
		(const void *)(BS_DSI3_0_HV_ROUTING_VAL),	/* TD 56 */
		(const void *)(BS_DSISWITCH_1_1_VAL),	/* TD 57 */
		(const void *)(BS_DSI3_1_HV_ROUTING_VAL),	/* TD 58 */
		(const void *)(BS_DSISWITCH_1_2_VAL),	/* TD 59 */
		(const void *)(BS_DSI3_2_HV_ROUTING_VAL),	/* TD 60 */
		(const void *)(BS_DSISWITCH_1_3_VAL),	/* TD 61 */
		(const void *)(BS_DSI3_3_HV_ROUTING_VAL),	/* TD 62 */
		(const void *)(BS_DSI3_4_HV_ROUTING_VAL),	/* TD 63 */
		(const void *)(BS_DSISWITCH_1_5_VAL),	/* TD 64 */
		(const void *)(BS_DSI3_5_HV_ROUTING_VAL),	/* TD 65 */
	};


	uint32 i;

	DMA_ZERO_VAL = 0u;
	CY_SET_REG8((void CYXDATA *)CYREG_PHUB_CFGMEM0_CFG0, 0x10u);	/* set burstcnt */
	CY_SET_REG8((void CYXDATA *)CYREG_PHUB_CH0_BASIC_CFG, 0x01u);	/* enable ch0 */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_CH0_BASIC_STATUS+1u), 0x00u);	/* set first TD to 0 */
	CY_SET_REG16((void CYXDATA *)CYREG_PHUB_TDMEM0_ORIG_TD0, 65u*8u);	/* transfer size */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_TDMEM0_ORIG_TD0+2u), 0x01u);	/* set next TD to 1 */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_TDMEM0_ORIG_TD0+3u), 0x03u);	/* set TD flags */
	CY_SET_REG16((void CYXDATA *)CYREG_PHUB_TDMEM0_ORIG_TD1, (uint16)((uint32)CFG_TD_LIST0 & 0x0000FFFFu));	/* set td0's src addr */
	CY_SET_REG16((void CYXDATA *)(CYREG_PHUB_TDMEM0_ORIG_TD1+2u), CYDEV_PHUB_TDMEM1_BASE);	/* set td0's dst addr */
	CY_SET_REG16((void CYXDATA *)CYREG_PHUB_CFGMEM0_CFG1, (uint16)(CYDEV_FLASH_BASE >> 16));	/* set ch0's src high addr */
	CY_SET_REG16((void CYXDATA *)(CYREG_PHUB_CFGMEM0_CFG1+2u), (uint16)(CYDEV_PHUB_TDMEM1_BASE >> 16));	/* set ch0's dst high addr */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_CH1_BASIC_STATUS+1u), 0x09u);	/* ch1 first TD: 9 */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_CH2_BASIC_STATUS+1u), 0x0Eu);	/* ch2 first TD: 14 */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_CH5_BASIC_STATUS+1u), 0x17u);	/* ch5 first TD: 23 */
	CY_SET_REG8((void CYXDATA *)(CYREG_PHUB_CH6_BASIC_STATUS+1u), 0x1Au);	/* ch6 first TD: 26 */

	CY_CFG_MEMORY_BARRIER();
	CY_SET_REG8((void CYXDATA *)CYREG_PHUB_CH0_ACTION, 0x01u); /* cpu_req */
	CY_CFG_MEMORY_BARRIER();

	/* Wait for TDs to be copied into TDMEM */
	while (CY_GET_REG16((void CYXDATA *)CYREG_PHUB_TDMEM0_ORIG_TD0) != 0u) { }

	/* Recombine TD source table (CFG_TD_ADDR0) with full TD table (CFG_TD_LIST0) */
	for (i = 0u; i < 65u; i++)
	{
		CY_SET_REG16((void CYXDATA *)(CYREG_PHUB_TDMEM1_ORIG_TD1 + (sizeof(struct td_t)*i)), (uint16)(uint32)CFG_TD_ADDR0[i]);
	}

	CY_CFG_MEMORY_BARRIER();
	CY_SET_REG8((void CYXDATA *)CYREG_PHUB_CH0_ACTION, 0x01u); /* cpu_req */
	CY_CFG_MEMORY_BARRIER();

	/* Wait for all DMA transfers to complete */
	while(0u != (CY_GET_REG8((void CYXDATA *)CYREG_PHUB_CH0_BASIC_STATUS) & 0x01u)){}
	while(0u != (CY_GET_REG8((void CYXDATA *)CYREG_PHUB_CH1_BASIC_STATUS) & 0x01u)){}
	while(0u != (CY_GET_REG8((void CYXDATA *)CYREG_PHUB_CH2_BASIC_STATUS) & 0x01u)){}
	while(0u != (CY_GET_REG8((void CYXDATA *)CYREG_PHUB_CH5_BASIC_STATUS) & 0x01u)){}
	while(0u != (CY_GET_REG8((void CYXDATA *)CYREG_PHUB_CH6_BASIC_STATUS) & 0x01u)){}


}
/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*  Performs the initialization of all of the clocks in the device based on the
*  settings in the Clock tab of the DWR.  This includes enabling the requested
*  clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void ClockSetup(void);
static void ClockSetup(void)
{
	uint32 timeout;
	uint8 pllLock;


	/* Configure Digital Clocks based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x0000u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0 + 0x2u), 0x50u);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0), 0x0001u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0 + 0x2u), 0x18u);

	/* Configure Analog Clocks based on settings from Clock DWR */
	CYCONFIGCPY((void CYFAR *)(CYREG_CLKDIST_ACFG0_CFG0), (const void CYFAR *)(BS_CYDEV_CLKDIST_ACFG0_CFG0_VAL), 4u);

	/* Configure ILO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_SLOWCLK_ILO_CR0), 0x02u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_CR), 0x08u);

	/* Configure IMO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_FASTCLK_IMO_CR), 0x03u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8((void CYFAR *)CYREG_FLSHID_CUST_TABLES_IMO_3MHZ)));

	/* Configure PLL based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_P), 0x0010u);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_CFG0), 0x1251u);
	/* Wait up to 250us for the PLL to lock */
	pllLock = 0u;
	for (timeout = 250u / 10u; (timeout > 0u) && (pllLock != 0x03u); timeout--)
	{ 
		pllLock = 0x03u & ((uint8)((uint8)pllLock << 1) | ((CY_GET_XTND_REG8((void CYFAR *)CYREG_FASTCLK_PLL_SR) & 0x01u) >> 0));
		CyDelayCycles(10u * 48u); /* Delay 10us based on 48MHz clock */
	}
	/* If we ran out of time the PLL didn't lock so go to the error function */
	if (timeout == 0u)
	{
		CyClockStartupError(CYCLOCKSTART_PLL_ERROR);
	}

	/* Configure Bus/Master Clock based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x0100u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x07u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG2), 0x48u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_LD), 0x02u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DLY1), 0x04u);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG2), ((CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG2) | 0x03u)));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG1), ((CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG1) | 0x01u)));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG0), ((CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0) | 0x80u)));
}


/* Analog API Functions */


/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void AnalogSetDefault(void);
static void AnalogSetDefault(void)
{
	uint8 bg_xover_inl_trim = CY_GET_XTND_REG8((void CYFAR *)(CYREG_FLSHID_MFG_CFG_BG_XOVER_INL_TRIM + 1u));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_BG_DFT0), (bg_xover_inl_trim & 0x07u));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_BG_DFT1), ((bg_xover_inl_trim >> 4) & 0x0Fu));
	CY_SET_XTND_REG8((void CYFAR *)CYREG_BUS_SW0, 0x05u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, 0x44u);
}


/*******************************************************************************
* Function Name: SetAnalogRoutingPumps
********************************************************************************
*
* Summary:
* Enables or disables the analog pumps feeding analog routing switches.
* Intended to be called at startup, based on the Vdda system configuration;
* may be called during operation when the user informs us that the Vdda voltage
* crossed the pump threshold.
*
* Parameters:
*  enabled - 1 to enable the pumps, 0 to disable the pumps
*
* Return:
*  void
*
*******************************************************************************/
void SetAnalogRoutingPumps(uint8 enabled)
{
	uint8 regValue = CY_GET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0);
	if (enabled != 0u)
	{
		regValue |= 0x22u;
	}
	else
	{
		regValue &= (uint8)~0x22u;
	}
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, regValue);
}

#define CY_AMUX_UNUSED CYREG_BOOST_SR
/* This is an implementation detail of the AMux. Code that depends on it may be
   incompatible with other versions of PSoC Creator. */
uint8 CYXDATA * const CYCODE ResistiveTouch_ADC_AMux__addrTable[2] = {
	(uint8 CYXDATA *)CYREG_DSM0_SW3, 
	(uint8 CYXDATA *)CY_AMUX_UNUSED, 
};

/* This is an implementation detail of the AMux. Code that depends on it may be
   incompatible with other versions of PSoC Creator. */
const uint8 CYCODE ResistiveTouch_ADC_AMux__maskTable[2] = {
	0x40u, 
	0x00u, 
};

/*******************************************************************************
* Function Name: ResistiveTouch_ADC_AMux_Set
********************************************************************************
* Summary:
*  This function is used to set a particular channel as active on the AMux.
*
* Parameters:  
*   channel - The mux channel input to set as active
*
* Return:
*   void
*
*******************************************************************************/
void ResistiveTouch_ADC_AMux_Set(uint8 channel)
{
	if (channel < 2)
	{
		*ResistiveTouch_ADC_AMux__addrTable[channel] |= ResistiveTouch_ADC_AMux__maskTable[channel];
	}
}

/*******************************************************************************
* Function Name: ResistiveTouch_ADC_AMux_Unset
********************************************************************************
* Summary:
*  This function is used to clear a particular channel from being active on the
*  AMux.
*
* Parameters:  
*   channel - The mux channel input to mark inactive
*
* Return:
*   void
*
*******************************************************************************/
void ResistiveTouch_ADC_AMux_Unset(uint8 channel)
{
	if (channel < 2)
	{
		*ResistiveTouch_ADC_AMux__addrTable[channel] &= (uint8)~ResistiveTouch_ADC_AMux__maskTable[channel];
	}
}

int8 ResistiveTouch_AMux_curChannel = -1;

void ResistiveTouch_AMux_DisconnectAll(void)
{
	ResistiveTouch_AMux_curChannel = -1;
	CY_SET_REG8((void CYXDATA *)CYREG_PRT1_AG, 0x00u);
	CY_SET_REG8((void CYXDATA *)CYREG_DSM0_SW0, 0x00u);
}

#if defined(__C51__) || defined(__CX51__)
    #pragma OT(5, SPEED)
#endif
void ResistiveTouch_AMux_Next(void)
{
	ResistiveTouch_AMux_curChannel++;
	switch (ResistiveTouch_AMux_curChannel)
	{
	case 3: /* to force jump table (not executed) */
		ResistiveTouch_AMux_curChannel = 3;
	case 4: /* to force jump table (not executed) */
		ResistiveTouch_AMux_curChannel = 4;
	case 5: /* to force jump table (not executed) */
		ResistiveTouch_AMux_curChannel = 5;
	case 6: /* to force jump table (not executed) */
		ResistiveTouch_AMux_curChannel = 6;
	case 7: /* to force jump table (not executed) */
		ResistiveTouch_AMux_curChannel = 7;
	case 2:
	default:
		ResistiveTouch_AMux_curChannel = 0;
	case 0:
		CY_SET_REG8((void CYXDATA *)CYREG_PRT1_AG, 0x40u);
		CY_SET_REG8((void CYXDATA *)CYREG_DSM0_SW0, 0x04u);
		break;
	case 1:
		CY_SET_REG8((void CYXDATA *)CYREG_PRT1_AG, 0x10u);
		CY_SET_REG8((void CYXDATA *)CYREG_DSM0_SW0, 0x01u);
		break;
	}
}



/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/

void cyfitter_cfg(void)
{
#ifdef CYGlobalIntDisable
	/* Disable interrupts by default. Let user enable if/when they want. */
	CYGlobalIntDisable
#endif

	/* Enable/Disable Debug functionality based on settings from System DWR */
	CY_SET_XTND_REG8((void CYFAR *)CYREG_MLOGIC_DEBUG, (CY_GET_XTND_REG8((void CYFAR *)CYREG_MLOGIC_DEBUG) | 0x04u));

	{
		cfg_dma_init();

		/* Perform normal device configuration. Order is not critical for these items. */
		CY_SET_XTND_REG8((void CYFAR *)(CYREG_DSM0_CR3), 0x0Au);

		/* Enable digital routing */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL) | 0x02u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0) | 0x40u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2) | 0x10u);
	}


	/* Perform second pass device configuration. These items must be configured in specific order after the regular configuration is done. */
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT1_DR), (const void CYFAR *)(BS_IOPINS0_1_VAL), 10u);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT2_DM0), (const void CYFAR *)(BS_IOPINS0_2_VAL), 8u);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT5_DM0), (const void CYFAR *)(BS_IOPINS0_5_VAL), 8u);
	/* Switch Boost to the precision bandgap reference from its internal reference */
	CY_SET_REG8((void CYXDATA *)CYREG_BOOST_CR2, (CY_GET_REG8((void CYXDATA *)CYREG_BOOST_CR2) | 0x08u));

	/* Set Flash Cycles based on max possible frequency in case a glitch occurs during ClockSetup(). */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0x01u : 0x00u));
	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();
	/* Set Flash Cycles based on newly configured 48.00MHz Bus Clock. */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0xC1u : 0xC0u));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PANTHER_WAITPIPE), 0x01u);

	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (const void CYFAR *)CYDEV_PM_ACT_BASE, 14u);
}
