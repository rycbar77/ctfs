#ifndef PROGRAM_H_GENERATED_
#define PROGRAM_H_GENERATED_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "wasm-rt.h"

#ifndef WASM_RT_MODULE_PREFIX
#define WASM_RT_MODULE_PREFIX
#endif

#define WASM_RT_PASTE_(x, y) x ## y
#define WASM_RT_PASTE(x, y) WASM_RT_PASTE_(x, y)
#define WASM_RT_ADD_PREFIX(x) WASM_RT_PASTE(WASM_RT_MODULE_PREFIX, x)

/* TODO(binji): only use stdint.h types in header */
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef float f32;
typedef double f64;

extern void WASM_RT_ADD_PREFIX(init)(void);

/* import: 'wasi_unstable' 'fd_prestat_get' */
extern u32 (*Z_wasi_unstableZ_fd_prestat_getZ_iii)(u32, u32);
/* import: 'wasi_unstable' 'fd_prestat_dir_name' */
extern u32 (*Z_wasi_unstableZ_fd_prestat_dir_nameZ_iiii)(u32, u32, u32);
/* import: 'env' 'boom' */
extern void (*Z_envZ_boomZ_vii)(u32, u32);
/* import: 'wasi_unstable' 'clock_time_get' */
extern u32 (*Z_wasi_unstableZ_clock_time_getZ_iiji)(u32, u64, u32);
/* import: 'wasi_unstable' 'proc_exit' */
extern void (*Z_wasi_unstableZ_proc_exitZ_vi)(u32);
/* import: 'wasi_unstable' 'fd_fdstat_get' */
extern u32 (*Z_wasi_unstableZ_fd_fdstat_getZ_iii)(u32, u32);
/* import: 'wasi_unstable' 'fd_close' */
extern u32 (*Z_wasi_unstableZ_fd_closeZ_ii)(u32);
/* import: 'wasi_unstable' 'args_sizes_get' */
extern u32 (*Z_wasi_unstableZ_args_sizes_getZ_iii)(u32, u32);
/* import: 'wasi_unstable' 'args_get' */
extern u32 (*Z_wasi_unstableZ_args_getZ_iii)(u32, u32);
/* import: 'wasi_unstable' 'fd_seek' */
extern u32 (*Z_wasi_unstableZ_fd_seekZ_iijii)(u32, u64, u32, u32);
/* import: 'wasi_unstable' 'fd_read' */
extern u32 (*Z_wasi_unstableZ_fd_readZ_iiiii)(u32, u32, u32, u32);
/* import: 'wasi_unstable' 'fd_write' */
extern u32 (*Z_wasi_unstableZ_fd_writeZ_iiiii)(u32, u32, u32, u32);

/* export: 'memory' */
extern wasm_rt_memory_t (*WASM_RT_ADD_PREFIX(Z_memory));
/* export: '_start' */
extern void (*WASM_RT_ADD_PREFIX(Z__startZ_vv))(void);
/* export: 'print_greeting' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_print_greetingZ_ii))(u32);
#ifdef __cplusplus
}
#endif

#endif  /* PROGRAM_H_GENERATED_ */
