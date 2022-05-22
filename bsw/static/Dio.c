/*
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for Dio Module on STM32F103x6,
 * 				Implementation is based on AUTSAR Specifications.
 * Created on: May 21, 2022
 *
 * Author: Mina-Karam
 */

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "Dio.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	#include "Det.h"

/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

