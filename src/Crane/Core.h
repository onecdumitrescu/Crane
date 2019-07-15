#pragma once

#define CRANE_API

#ifdef CRANE_DEBUG
    #define CRANE_ENABLE_ASSERTS
#endif

#ifdef CRANE_ENABLE_ASSERTS
    #define CRANE_ASSERT(x, ...) { if(!(x)) { CRANE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define CRANE_CORE_ASSERT(x, ...) { if(!(x)) { CRANE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define CRANE_ASSERT(x, ...)
    #define CRANE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
