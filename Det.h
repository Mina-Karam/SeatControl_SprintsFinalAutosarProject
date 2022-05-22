/*
 * Module: Default Error Tracer
 *
 * File Name: Det.h
 *
 * Description: Det stores the development errors reported by other modules.
 *
 * Created on: May 22, 2022
 *
 * Author: Mina-Karam
 */

#ifndef DET_H_
#define DET_H_

/* ID for the company in the AUTOSAR
 * For example Mina Karam's ID = 79U :D
 */
#define DET_VENDOR_ID    (79U)

/* Det Module Id */
#define DET_MODULE_ID    (15U)

/* Det Instance Id */
#define DET_INSTANCE_ID  (0U)


/*
 * Module version 1.0.0
 */
#define DET_SW_VERSION_MAJOR 			(1U)
#define DET_SW_VERSION_MINOR 			(0U)
#define DET_SW_VERSION_PATCH 			(0U)

/*
 * AUTOSAR version 4.4.0
 */
#define DETS_AR_REALEASE_MAJOR_VERSION 	(4U)
#define DETS_AR_REALEASE_MINOR_VERSION 	(4U)
#define DET_AR_REALEASE_PATCH_VERSION 	(0U)

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Det Modules */
#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* ================================================================ */
/* ==================== Functions Prototypes ====================== */
/* ================================================================ */

/* Service to initialize the Default Error Tracer. */
void Det_Init();

/* Service to report development errors. */
Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

/*TODO Service to start the Default Error Tracer. */
//void Det_Start(void);

/*TODO Service to report runtime errors. */
//Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/*TODO Service to report transient faults. */
//Std_ReturnType Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId);

/*TODO Returns the version information of this module. */
//void Det_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif /* DET_H_ */
