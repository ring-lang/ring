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
	$(RING_PATH)/ring_string.c \
	$(RING_PATH)/ring_list.c \
	$(RING_PATH)/ring_item.c \
	$(RING_PATH)/ring_items.c \
	$(RING_PATH)/ring_hashtable.c \
	$(RING_PATH)/ring_general.c \
	$(RING_PATH)/ring_state.c \
	$(RING_PATH)/ring_scanner.c \
	$(RING_PATH)/ring_parser.c \
	$(RING_PATH)/ring_hashlib.c \
	$(RING_PATH)/ring_vmgc.c \
	$(RING_PATH)/ring_stmt.c \
	$(RING_PATH)/ring_expr.c \
	$(RING_PATH)/ring_codegen.c \
	$(RING_PATH)/ring_vm.c \
	$(RING_PATH)/ring_vmexpr.c \
	$(RING_PATH)/ring_vmvars.c \
	$(RING_PATH)/ring_vmlists.c \
	$(RING_PATH)/ring_vmfuncs.c \
	$(RING_PATH)/ring_api.c \
	$(RING_PATH)/ring_vmoop.c \
	$(RING_PATH)/ring_vmcui.c \
	$(RING_PATH)/ring_vmtrycatch.c \
	$(RING_PATH)/ring_vmstrindex.c \
	$(RING_PATH)/ring_vmjump.c \
	$(RING_PATH)/ring_vmduprange.c \
	$(RING_PATH)/ring_vmperformance.c \
	$(RING_PATH)/ring_vmexit.c \
	$(RING_PATH)/ring_vmstackvars.c \
	$(RING_PATH)/ring_vmstate.c \
	$(RING_PATH)/ring_vmgenerallib.c \
	$(RING_PATH)/ring_vmmath.c \
	$(RING_PATH)/ring_vmfile.c \
	$(RING_PATH)/ring_vmos.c \
	$(RING_PATH)/ring_vmlistfuncs.c \
	$(RING_PATH)/ring_vmrefmeta.c \
	$(RING_PATH)/ring_ext.c \
	$(RING_PATH)/ring_vmdll.c \
	$(RING_PATH)/ring_objfile.c \
	$(RING_PATH)/ring_libsdl.c 

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf SDL2_net

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
