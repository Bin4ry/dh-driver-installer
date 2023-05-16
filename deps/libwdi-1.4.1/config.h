/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* CoInstaller subdirectory for WinUSB redist files ("winusb" or "wdf") */
#define COINSTALLER_DIR "wdf"

/* Debug message logging (forced) */
/* #undef ENABLE_DEBUG_LOGGING */

/* Message logging */
#define ENABLE_LOGGING 1

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Debug message logging (toggable) */
#define INCLUDE_DEBUG_LOGGING 1

/* embed libusb0 driver files from the following location */
#define LIBUSB0_DIR "../../../drivers/libusb-win32-bin-1.2.6.0/"

/* embed libusbK driver files from the following location */
#define LIBUSBK_DIR "../../../drivers/libusbK-3.1.0.0-bin/bin/"

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* 32 bit support */
/* #undef OPT_M32 */

/* 64 bit support */
#define OPT_M64 /**/

/* Name of package */
#define PACKAGE "libwdi"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "libwdi-devel@lists.sourceforge.net"

/* Define to the full name of this package. */
#define PACKAGE_NAME "libwdi"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libwdi 1.3.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libwdi"

/* Define to the home page for this package. */
#define PACKAGE_URL "http://libwdi.akeo.ie"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.3.1"

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* embed user defined driver files from the following location */
#define USER_DIR "../../../drivers/kedacom_adb/"

/* Version number of package */
#define VERSION "1.3.1"

/* WDK WDF/KMDF coinstaller version */
#define WDF_VER 1011

/* embed WinUSB driver files from the following WDK location */
#define WDK_DIR "../../../drivers/wdk-8.0"

/* 64bit subdirectory for WinUSB redist files ("x64" or "amd64") */
#define X64_DIR "x64"

/* Use GNU extensions */
#define _GNU_SOURCE /**/

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
