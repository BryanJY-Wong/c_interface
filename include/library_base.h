#ifndef C_INTERFACE_LIBRARY_BASE_H
#define C_INTERFACE_LIBRARY_BASE_H

#include <stdlib.h>

#ifdef __cplusplus
#define LIB_EXTERN_C extern "C"
#if __cplusplus >= 201103L
#define HAS_ENUM_CLASS
#elif defined(_MSC_VER) && defined(_MSVC_LANG) && _MSVC_LANG >= 201103L
#define HAS_ENUM_CLASS
#endif
#else
#define LIB_EXTERN_C
#endif

#ifdef HAS_ENUM_CLASS
#define LIB_ENUM_START(name) enum class name : int32_t {
#define LIB_ENUM_END(name) }
#else
#define LIB_ENUM_START(name) typedef enum name {
#define LIB_ENUM_END(name) } name
#endif

#define LIB_ENUM(name, ...) LIB_ENUM_START(name) __VA_ARGS__ LIB_ENUM_END(name)

#define PASTE_ARGS(...) __VA_ARGS__
#define LIB_DEFINE_STRUCT(Name, Definition) \
    LIB_EXTERN_C typedef struct _Name { \
        PASTE_ARGS Definition \
    } Name

#ifndef LIB_USE_DLLEXPORT
#if defined(_WIN32) || defined(__CYGWIN__)
#define LIB_USE_DLLEXPORT
#endif
#endif

#ifndef LIB_CALL
#if defined(_WIN32) && (defined(__i386) || defined(_M_IX86))
#define LIB_CALL __stdcall
#define LIB_MEMORY_CALL __stdcall
#else
#define LIB_CALL
#define LIB_MEMORY_CALL
#endif
#endif

#ifdef LIB_BUILDING
#ifdef LIB_USE_DLLEXPORT
        #ifdef __GNUC__
            #define LIB_API __attribute__ ((dllexport))
        #else
            #define LIB_API __declspec(dllexport)
        #endif
    #else
        #if __GNUC__ >= 4
            #define LIB_API __attribute__ ((visibility ("default")))
        #else
            #define LIB_API
        #endif
    #endif
#else
#ifdef LIB_USE_DLLEXPORT
#ifdef __GNUC__
            #define LIB_API __attribute__ ((dllimport))
        #else
            #define LIB_API __declspec(dllimport)
        #endif
#else
#if __GNUC__ >= 4
#define LIB_API __attribute__ ((visibility ("default")))
#else
#define LIB_API
#endif
#endif
#endif

#define LIB_DECLARE_FUNC(return_type) LIB_EXTERN_C LIB_API return_type LIB_CALL

LIB_EXTERN_C LIB_API typedef void* (LIB_MEMORY_CALL* LIB_AllocateMemoryFunc)(size_t SizeInBytes, size_t Alignment);

LIB_EXTERN_C LIB_API typedef void (LIB_MEMORY_CALL* LIB_ReleaseMemoryFunc)(void* Pointer);

#ifdef _MSC_VER
#ifdef NDEBUG 
#define assert(X)
#else
#define assert(X) if (!(X)) {__debugbreak();}
#endif
#define __PRETTY_FUNCTION__ __FUNCTION__
#else
#include <assert.h>
#endif

#endif //C_INTERFACE_LIBRARY_BASE_H
