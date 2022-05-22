/*
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for Dio Module on STM32F103x6,
 * 				Implementation is based on AUTSAR Specifications.
 * Created on: May 21, 2022
 *
 * Author: Mina-Karam
 */

#ifndef STATIC_DIO_H_
#define STATIC_DIO_H_

/* ID for the company in the AUTOSAR
 * For example Mina Karam's ID = 79U :D
 */
#define DIO_VENDOR_ID    (79U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)


/*
 * Module version 1.0.0
 */
#define PLATFORM_TYPES_SW_VERSION_MAJOR 			(1U)
#define PLATFORM_TYPES_SW_VERSION_MINOR 			(0U)
#define PLATFORM_TYPES_SW_VERSION_PATCH 			(0U)

/*
 * AUTOSAR version 4.4.0
 */
#define PLATFORM_TYPES_AR_REALEASE_MAJOR_VERSION 	(4U)
#define PLATFORM_TYPES_AR_REALEASE_MINOR_VERSION 	(4U)
#define PLATFORM_TYPES_AR_REALEASE_PATCH_VERSION 	(0U)


/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Pre-Compile Configurations */
//#include "Dio_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

/* Needed interfaces from external units */
//#include "Port.h"

/* ================================================================ */
/* =================== API Service ID Macros ====================== */
/* ================================================================ */
/* Service Name                     Service ID [HEX] */
#define DIO_READ_CHANNEL_ID            	0x00
#define DIO_WRITE_CHANNEL_ID           	0x01
#define DIO_READ_PORT_ID           		0x02
#define DIO_WRITE_PORT_ID           	0x03
#define DIO_READ_CHANNEL_GROUP_ID       0x04
#define DIO_WRITE_CHANNEL_GROUP_ID      0x05
#define DIO_GET_VERSIOM_INFO_ID         0x12
#define DIO_FLIP_CHANNEL_ID           	0x11
#define DIO_MASKED_WRITE_PORT_ID        0x13

/* ================================================================ */
/* ====================== DET Error Codes ========================= */
/* ================================================================ */

/* Service Name                     Service ID [HEX] */
#define DIO_E_PARAM_INVALID_CHANNEL_ID	0x0A	/* Invalid channel requested. 				*/
#define DIO_E_PARAM_INVALID_PORT_ID	   	0x14	/* Invalid port requested. 					*/
#define DIO_E_PARAM_INVALID_GROUP_ID   	0x1F	/* Invalid channel group requested. 		*/
#define DIO_E_PARAM_POINTER_ID   		0x20	/* API service called with a NULL pointer. 	*/

/* ================================================================ */
/* =================== Module Types Definitions  ================== */
/* ================================================================ */

/* Type definition for Dio_ChannelType used by the DIO APIs*/
typedef uint8 Dio_ChannelType; /* Numeric ID of a DIO channel. */

/* Type definition for Dio_PortType used by the DIO APIs*/
typedef uint8 Dio_PortType; /* Numeric ID of a DIO port */

typedef struct
{
	/* This element mask which defines the positions of the channel group. */
	uint8 mask;
	/* This element shall be the position of the Channel Group on the port, counted from the LSB */
	uint8 offset;
	/* This shall be the port on which the Channel group is defined. */
	Dio_PortType port;
}Dio_ChannelGroupType; /* Type for the definition of a channel group, which consists of several adjoining channels within a port. */

/* Type definition for Dio_LevelType used by the DIO APIs*/
typedef uint8 Dio_LevelType; /* These are the possible levels a DIO channel can have (input or output) */

/* Type definition for Dio_PortLevelType used by the DIO APIs*/
typedef uint8 Dio_PortLevelType; /* If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port. */

/* ================================================================ */
/* ==================== Functions Prototypes ====================== */
/* ================================================================ */

/* Function for DIO read Channel API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Channel API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO read Port API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Port API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* This Service reads a subset of the adjoining bits of a port. */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/* Service to set a subset of the adjoining bits of a port to a specified level.*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/* Service to set the value of a given port with required mask*/
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

#endif /* STATIC_DIO_H_ */
