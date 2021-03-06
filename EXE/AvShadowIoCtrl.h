/*++

Copyright (c) 2009-2011  lazycat studio

Module Name:

    AvShadowIoCtrl.h

Abstract:

    Common definitions used for user mode application and kernel mode driver

Author:

    lazy_cat

Environment:

    Kernel mode only

Revision History:

--*/

#ifndef _SHADOW_IOCTL_H_
#define _SHADOW_IOCTL_H_

#include <devioctl.h>

/* PROTECT FLAGS */
#define ENABLE_OPENPROCESS                      0x00000001
#define ENABLE_CREATEPROCESSEX                  0x00000002
#define ENABLE_LOADDRIVER                       0x00000004
#define ENABLE_QUERYSYSTEMINFO                  0x00000008


#define MAX_PROCESSNAME_LENGTH                  16

#define EVENT_SHARE_NUM                         3

#define EVENT_INDEX_OPENPROCESS                 0
#define EVENT_INDEX_CREATEPROCESSEX             1
#define EVENT_INDEX_LOADDRIVER                  2

#define IOCTL_AVSHADOW_INIT                     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_SET_EVENTHANDLE          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_INIT_WHITELIST           CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_GET_PROTECTFLAG          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVSHADOW_GET_OPENPROCESS          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_SET_OPENPROCESS          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVSHADOW_GET_CREATEPROCESSEX      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x806, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_SET_CREATEPROCESSEX      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x807, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVSHADOW_GET_LOADDRIVER           CTL_CODE(FILE_DEVICE_UNKNOWN, 0x808, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_SET_LOADDRIVER           CTL_CODE(FILE_DEVICE_UNKNOWN, 0x809, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVSHADOW_START_OPENPROCESS        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_START_CREATEPROCESSEX    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_START_LOADDRIVER         CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_START_QUERYSYSINFO       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x819, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVSHADOW_PAUSE_OPENPROCESS        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x813, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_PAUSE_CREATEPROCESSEX    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x814, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_PAUSE_LOADDRIVER         CTL_CODE(FILE_DEVICE_UNKNOWN, 0x815, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_PAUSE_QUERYSYSINFO       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x820, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_AVSHADOW_STOP_OPENPROCESS         CTL_CODE(FILE_DEVICE_UNKNOWN, 0x816, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_STOP_CREATEPROCESSEX     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x817, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_STOP_LOADDRIVER          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x818, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVSHADOW_STOP_QUERYSYSINFO        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x821, METHOD_BUFFERED, FILE_ANY_ACCESS)


typedef enum _PACKET_TYPE {
    PacketOpenProcess = 0
} PACKET_TYPE;

typedef struct _OPEN_PROCESS_INFO {
    PACKET_TYPE         PackType;
    HANDLE              ulProcessID;
    HANDLE              ulTargetProcessID;
    BOOLEAN             bAllowed;
    CHAR                szProcessName[MAX_PROCESSNAME_LENGTH];
    WCHAR               szImagePath[256];
} OPEN_PROCESS_INFO, *POPEN_PROCESS_INFO;

typedef struct _CREATE_PROCESSEX_INFO {
    HANDLE              ulProcessID;
    BOOLEAN             bAllowed;
    CHAR                szParentProcessName[MAX_PROCESSNAME_LENGTH];
    WCHAR               szImagePath[256];
    WCHAR               szImagePathToCreateProcess[256];
} CREATE_PROCESSEX_INFO, *PCREATE_PROCESSEX_INFO;

typedef struct _LOAD_DRIVER_INFO {
    HANDLE  ulProcessID;
    BOOLEAN bAllowed;
    WCHAR   szImagePath[256];
    WCHAR   szRegPath[256];
    WCHAR   szSysFilePath[256];
} LOAD_DRIVER_INFO, *PLOAD_DRIVER_INFO;

// size: 12B
typedef struct _WHITE_LIST {
    ULONG       ulStringCount;
    ULONG       ulStringSize;
    WCHAR       StringTable[1];
} WHITE_LIST, *PWHITE_LIST;

#endif  /* _SHADOW_IOCTL_H_ */