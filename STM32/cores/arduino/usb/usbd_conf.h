/**
  ******************************************************************************
  * @file           : usbd_conf.h
  * @version        : v1.0_Cube
  * @brief          : Header for usbd_conf file.
  ******************************************************************************
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  * 1. Redistributions of source code must retain the above copyright notice,
  * this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of its contributors
  * may be used to endorse or promote products derived from this software
  * without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__
#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stm32_def.h"

#include "usbd_def.h"

/** @addtogroup USBD_OTG_DRIVER
  * @{
  */

/** @defgroup USBD_CONF
  * @brief usb otg low level driver configuration file
  * @{
  */

/** @defgroup USBD_CONF_Exported_Defines
  * @{
  */

/*---------- -----------*/
#if (USE_USBDCOMPOSITE)  /*huaweiwx@sina.com 2017.9.15 add*/
 #define USBD_MAX_NUM_INTERFACES     3
#else
 #define USBD_MAX_NUM_INTERFACES     1
#endif

#ifndef USBD_MAX_NUM_CONFIGURATION
 #define USBD_MAX_NUM_CONFIGURATION     1
#endif

#ifndef USBD_MAX_STR_DESC_SIZ
#define USBD_MAX_STR_DESC_SIZ     512
#endif

#ifndef USBD_SUPPORT_USER_STRING
#define USBD_SUPPORT_USER_STRING     0
#endif

#ifndef USBD_DEBUG_LEVEL
#define USBD_DEBUG_LEVEL     0
#endif

#ifndef USBD_SELF_POWERED
#define USBD_SELF_POWERED     1
#endif

#ifndef USBD_CDC_INTERVAL
#define USBD_CDC_INTERVAL     1000
#endif

#ifndef MAX_STATIC_ALLOC_SIZE
#define MAX_STATIC_ALLOC_SIZE     512
#endif
/****************************************/
/* #define for FS and HS identification */


#ifndef DEVICE_FS
#define DEVICE_FS 		0
#endif
/** @defgroup USBD_Exported_Macros
  * @{
  */

/* Memory management macros */
#if (USE_USBDCOMPOSITE)  /*huaweiwx@sina.com 2017.9.15 add*/
 #ifndef USBD_malloc
  #define USBD_malloc               malloc
 #endif
 #ifndef USBD_free
  #define USBD_free                 free
 #endif
#else
 #ifndef USBD_malloc
  #define USBD_malloc               (uint32_t *)USBD_static_malloc
 #endif
 #ifndef USBD_free
  #define USBD_free                 USBD_static_free
 #endif	
#endif

#define USBD_memset               /* Not used */
#define USBD_memcpy               /* Not used */

#define USBD_Delay   HAL_Delay

#if (USE_USBDDFU)
/* DFU Class Config */
#define USBD_DFU_MAX_ITF_NUM                   1
#define USBD_DFU_XFER_SIZE                     1024   /* Max DFU Packet Size   = 1024 bytes */
#define USBD_DFU_APP_DEFAULT_ADD               0x08007000 /*ADDR_FLASH_PAGE_24*/
#define USBD_DFU_APP_END_ADD                   0x0801FFFF /*ADDR_FLASH_PAGE_64*/
#endif

/* For footprint reasons and since only one allocation is handled in the HID class
   driver, the malloc/free is changed into a static allocation method */
void *USBD_static_malloc(uint32_t size);
void USBD_static_free(void *p);

/* DEBUG macros */
#if (USBD_DEBUG_LEVEL > 0)
#define  USBD_UsrLog(...)   printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_UsrLog(...)
#endif


#if (USBD_DEBUG_LEVEL > 1)

#define  USBD_ErrLog(...)   printf("ERROR: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_ErrLog(...)
#endif


#if (USBD_DEBUG_LEVEL > 2)
#define  USBD_DbgLog(...)   printf("DEBUG : ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_DbgLog(...)
#endif

/**
  * @}
  */



/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Types
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Macros
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Variables
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_FunctionsPrototype
  * @{
  */
/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /*__USBD_CONF__H__*/

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

