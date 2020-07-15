//
// Created by Lysenkov on 15.07.2020.
//

#ifndef LAN_4GATELIB_VISIBILITYMACROSES_H
#define LAN_4GATELIB_VISIBILITYMACROSES_H

#if defined(_MSC_VER)
//  Microsoft 
    #define LANTER_EXPORT __declspec(dllexport)
    #define LANTER_IMPORT __declspec(dllimport)
#elif defined(_GCC) || defined(__GNUC__) || defined(__clang__)
//  GCC
    #define LANTER_EXPORT __attribute__((visibility("default")))
    #define LANTER_IMPORT
#else
    #define LANTER_EXPORT
    #define LANTER_IMPORT
#endif

#if defined(LANTER_BUILD_SHARED)
    #define LANTER_VISIBILITY LANTER_EXPORT
#else
    #define LANTER_VISIBILITY LANTER_IMPORT
#endif

#endif //LAN_4GATELIB_VISIBILITYMACROSES_H
