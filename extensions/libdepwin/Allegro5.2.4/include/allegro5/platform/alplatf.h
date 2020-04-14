/* alplatf.h is generated from alplatf.h.cmake */
/* #undef ALLEGRO_MINGW32 */
/* #undef ALLEGRO_UNIX */
#define ALLEGRO_MSVC
/* #undef ALLEGRO_MACOSX */
/* #undef ALLEGRO_BCC32 */
/* #undef ALLEGRO_IPHONE */
/* #undef ALLEGRO_ANDROID */
/* #undef ALLEGRO_RASPBERRYPI */
/* #undef ALLEGRO_CFG_NO_FPU */
/* #undef ALLEGRO_CFG_DLL_TLS */
/* #undef ALLEGRO_CFG_PTHREADS_TLS */
#define ALLEGRO_CFG_RELEASE_LOGGING

#define ALLEGRO_CFG_D3D
/* #undef ALLEGRO_CFG_D3D9EX */
#define ALLEGRO_CFG_D3DX9
#define ALLEGRO_CFG_XINPUT
#define ALLEGRO_CFG_OPENGL
/* #undef ALLEGRO_CFG_OPENGLES */
/* #undef ALLEGRO_CFG_OPENGLES2 */
/* #undef ALLEGRO_CFG_OPENGLES3 */
#define ALLEGRO_CFG_OPENGL_PROGRAMMABLE_PIPELINE
#define ALLEGRO_CFG_SHADER_GLSL
#define ALLEGRO_CFG_SHADER_HLSL

/* #undef ALLEGRO_CFG_ANDROID_LEGACY */

/*---------------------------------------------------------------------------*/

/* Define to 1 if you have the corresponding header file. */
/* #undef ALLEGRO_HAVE_DIRENT_H */
#define ALLEGRO_HAVE_INTTYPES_H
/* #undef ALLEGRO_HAVE_LINUX_AWE_VOICE_H */
/* #undef ALLEGRO_HAVE_LINUX_INPUT_H */
/* #undef ALLEGRO_HAVE_LINUX_SOUNDCARD_H */
/* #undef ALLEGRO_HAVE_MACHINE_SOUNDCARD_H */
/* #undef ALLEGRO_HAVE_SOUNDCARD_H */
#define ALLEGRO_HAVE_STDBOOL_H
#define ALLEGRO_HAVE_STDINT_H
/* #undef ALLEGRO_HAVE_SV_PROCFS_H */
/* #undef ALLEGRO_HAVE_SYS_IO_H */
/* #undef ALLEGRO_HAVE_SYS_SOUNDCARD_H */
#define ALLEGRO_HAVE_SYS_STAT_H
/* #undef ALLEGRO_HAVE_SYS_TIME_H */
#define ALLEGRO_HAVE_TIME_H
/* #undef ALLEGRO_HAVE_SYS_UTSNAME_H */
#define ALLEGRO_HAVE_SYS_TYPES_H
/* #undef ALLEGRO_HAVE_OSATOMIC_H */
/* #undef ALLEGRO_HAVE_SYS_INOTIFY_H */
#define ALLEGRO_HAVE_SAL_H

/* Define to 1 if the corresponding functions are available. */
/* #undef ALLEGRO_HAVE_GETEXECNAME */
/* #undef ALLEGRO_HAVE_MKSTEMP */
/* #undef ALLEGRO_HAVE_MMAP */
/* #undef ALLEGRO_HAVE_MPROTECT */
/* #undef ALLEGRO_HAVE_SCHED_YIELD */
/* #undef ALLEGRO_HAVE_SYSCONF */
/* #undef ALLEGRO_HAVE_SYSCTL */

/* #undef ALLEGRO_HAVE_FSEEKO */
/* #undef ALLEGRO_HAVE_FTELLO */
/* #undef ALLEGRO_HAVE_STRERROR_R */
#define ALLEGRO_HAVE_STRERROR_S
#define ALLEGRO_HAVE_VA_COPY
#define ALLEGRO_HAVE_FTELLI64
#define ALLEGRO_HAVE_FSEEKI64

/* Define to 1 if procfs reveals argc and argv */
/* #undef ALLEGRO_HAVE_PROCFS_ARGCV */

/*---------------------------------------------------------------------------*/

/* Define if target machine is little endian. */
#define ALLEGRO_LITTLE_ENDIAN

/* Define if target machine is big endian. */
/* #undef ALLEGRO_BIG_ENDIAN */

/* Define if target platform is Darwin. */
/* #undef ALLEGRO_DARWIN */

/*---------------------------------------------------------------------------*/

/* Define if you need support for X-Windows. */
/* #undef ALLEGRO_WITH_XWINDOWS */

/* Define if XCursor ARGB extension is available. */
/* #undef ALLEGRO_XWINDOWS_WITH_XCURSOR */

/* Define if XF86VidMode extension is supported. */
/* #undef ALLEGRO_XWINDOWS_WITH_XF86VIDMODE */

/* Define if Xinerama extension is supported. */
/* #undef ALLEGRO_XWINDOWS_WITH_XINERAMA */

/* Define if XRandR extension is supported. */
/* #undef ALLEGRO_XWINDOWS_WITH_XRANDR */

/* Define if XIM extension is supported. */
/* #undef ALLEGRO_XWINDOWS_WITH_XIM */

/* Define if XInput 2.2 X11 extension is supported. */
/* #undef ALLEGRO_XWINDOWS_WITH_XINPUT2 */

/* Define if Xpm is found. Useful on Ubuntu Unity to set icon. */
/* #undef ALLEGRO_XWINDOWS_WITH_XPM */

/*---------------------------------------------------------------------------*/

/* Define if target platform is linux. */
/* #undef ALLEGRO_LINUX */

/* Define if we are building with SDL backend. */
/* #undef ALLEGRO_SDL */

/*---------------------------------------------------------------------------*/
/* vi: set ft=c ts=3 sts=3 sw=3 et: */
