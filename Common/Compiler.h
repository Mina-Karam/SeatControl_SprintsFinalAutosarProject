/*
 * Module: Compiler Abstraction
 *
 * File Name: Compiler.h
 *
 * Description: Header file that contains the definitions and macros specified by
 * 				AUTOSAR for the abstraction of compiler specific keywords.
 *
 * Created on: May 22, 2022
 *
 * Author: Mina-Karam
 */


#ifndef COMPILER_H_
#define COMPILER_H_

/* ID for the company in the AUTOSAR
 * For example Mina Karam's ID = 79U :D
 */
#define PLATFORM_TYPES_VENDOR_ID    				(79U)

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

/* The memory class is used for the declaration of local pointers */
#define AUTOMATIC

/* The memory class is used within type definitions, where no memory
   qualifier can be specified */
#define TYPEDEF

/* This is used to define the void pointer to zero definition */
#define NULL_PTR          ((void *)0)

/* This is used to define the abstraction of compiler keyword inline */
#define INLINE            inline

/* This is used to define the local inline function */
#define LOCAL_INLINE      static inline

/* This is used to define the abstraction of compiler keyword static */
#define STATIC            static

#endif /* COMPILER_H_ */
