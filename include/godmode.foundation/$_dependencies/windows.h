#pragma once
#pragma comment(lib, "Shell32.lib")
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_preprocessor.h>
#ifndef NOMINMAX
    #define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif
#ifndef DIRECTINPUT_VERSION
    #define DIRECTINPUT_VERSION 0x0800
#endif
#ifndef _WINSOCKAPI_
    #define _WINSOCKAPI_
#endif
#include <winsock2.h>
#include <windows.h>
#include <mmsystem.h>
#undef ERROR