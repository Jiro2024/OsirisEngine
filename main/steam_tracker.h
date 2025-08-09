/**************************************************************************/
/*  steam_tracker.h                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                              PTAH ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-2025 Godot Engine contributor (see GODOTAUTHORS.md).*/
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/* Copyright (c) 2025-present Jiro(候杨宝鑫), FranJ2 Studio                */
/* If you want to know your rights, please read LICENSE                   */
/**************************************************************************/

#pragma once

#if defined(STEAMAPI_ENABLED)

#include "core/os/os.h"

// SteamTracker is used to load SteamAPI dynamic library and initialize
// the interface, this notifies Steam that Godot editor is running and
// allow tracking of the usage time of child instances of the engine
// (e.g., opened projects).
//
// Currently, SteamAPI is not used by the engine in any way, and is not
// exposed to the scripting APIs.

enum SteamAPIInitResult {
	SteamAPIInitResult_OK = 0,
	SteamAPIInitResult_FailedGeneric = 1,
	SteamAPIInitResult_NoSteamClient = 2,
	SteamAPIInitResult_VersionMismatch = 3,
};

// https://partner.steamgames.com/doc/api/steam_api#SteamAPI_Init
typedef bool (*SteamAPI_InitFunction)();
typedef SteamAPIInitResult (*SteamAPI_InitFlatFunction)(char *r_err_msg);

// https://partner.steamgames.com/doc/api/steam_api#SteamAPI_Shutdown
typedef void (*SteamAPI_ShutdownFunction)();

class SteamTracker {
	void *steam_library_handle = nullptr;
	SteamAPI_InitFunction steam_init_function = nullptr;
	SteamAPI_InitFlatFunction steam_init_flat_function = nullptr;
	SteamAPI_ShutdownFunction steam_shutdown_function = nullptr;
	bool steam_initialized = false;

public:
	SteamTracker();
	~SteamTracker();
};

#endif // STEAMAPI_ENABLED
