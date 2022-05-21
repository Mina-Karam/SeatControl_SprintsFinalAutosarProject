/*
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for Dio Module,
 * 				Implementation is based on AUTSAR Specifications.
 * Created on: May 21, 2022
 *
 * Author: Mina-Karam
 */

#ifndef STATIC_DIO_H_
#define STATIC_DIO_H_

/* Dio Module Id */
#define DIO_MODULE_ID    0x120
/* Dio Instance Id */
#define DIO_INSTANCE_ID  0x00


/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */


/* Pre-Compile Configurations */
//#include "Dio_Cfg.h"

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
/* ================ Module Data Types Definitions  ================ */
/* ================================================================ */



/* ================================================================ */
/* ==================== Functions Prototypes ====================== */
/* ================================================================ */


#endif /* STATIC_DIO_H_ */
