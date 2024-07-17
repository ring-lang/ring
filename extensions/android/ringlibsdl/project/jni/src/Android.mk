LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2

RING_PATH := ../ring/src

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
	$(LOCAL_PATH)/../ring/include \
	$(LOCAL_PATH)/../SDL2_image \
	$(LOCAL_PATH)/../SDL2_mixer \
	$(LOCAL_PATH)/../SDL2_ttf \
	$(LOCAL_PATH)/../SDL2_net 

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	ringapp.c \
	$(RING_PATH)/rstring.c \
	$(RING_PATH)/rlist.c \
	$(RING_PATH)/ritem.c \
	$(RING_PATH)/ritems.c \
	$(RING_PATH)/rhtable.c \
	$(RING_PATH)/general.c \
	$(RING_PATH)/state.c \
	$(RING_PATH)/scanner.c \
	$(RING_PATH)/parser.c \
	$(RING_PATH)/hashlib.c \
	$(RING_PATH)/vmgc.c \
	$(RING_PATH)/stmt.c \
	$(RING_PATH)/expr.c \
	$(RING_PATH)/codegen.c \
	$(RING_PATH)/vm.c \
	$(RING_PATH)/vmerror.c \
	$(RING_PATH)/vmeval.c \
	$(RING_PATH)/vmthread.c \
	$(RING_PATH)/vmexpr.c \
	$(RING_PATH)/vmvars.c \
	$(RING_PATH)/vmlists.c \
	$(RING_PATH)/vmfuncs.c \
	$(RING_PATH)/ringapi.c \
	$(RING_PATH)/vmoop.c \
	$(RING_PATH)/vmtry.c \
	$(RING_PATH)/vmstr.c \
	$(RING_PATH)/vmjump.c \
	$(RING_PATH)/vmrange.c \
	$(RING_PATH)/vmperf.c \
	$(RING_PATH)/vmexit.c \
	$(RING_PATH)/vmstack.c \
	$(RING_PATH)/vmstate.c \
	$(RING_PATH)/genlib_e.c \
	$(RING_PATH)/math_e.c \
	$(RING_PATH)/file_e.c \
	$(RING_PATH)/os_e.c \
	$(RING_PATH)/list_e.c \
	$(RING_PATH)/meta_e.c \
	$(RING_PATH)/ext.c \
	$(RING_PATH)/dll_e.c \
	$(RING_PATH)/objfile.c \
	$(RING_PATH)/ring_libsdl.c 

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf SDL2_net

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
