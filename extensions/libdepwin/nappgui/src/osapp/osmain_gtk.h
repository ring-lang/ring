/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmain_gtk.h
 *
 */

/* Cross-platform main */

#define osmain(func_create, func_destroy, options, type) \
    int main(int argc, char *argv[]) \
    { \
        FUNC_CHECK_APP_CREATE(func_create, type), \
            FUNC_CHECK_DESTROY(func_destroy, type), \
            osmain_imp( \
                (uint32_t)argc, (char_t **)argv, NULL, 0., \
                (FPtr_app_create)func_create, \
                (FPtr_app_update)NULL, \
                (FPtr_destroy)func_destroy, \
                (char_t *)options); \
        return 0; \
    }

#define osmain_sync(lframe, func_create, func_destroy, func_update, options, type) \
    int main(int argc, char *argv[]) \
    { \
        FUNC_CHECK_APP_CREATE(func_create, type), \
            FUNC_CHECK_APP_UPDATE(func_update, type), \
            FUNC_CHECK_DESTROY(func_destroy, type), \
            osmain_imp( \
                (uint32_t)argc, (char_t **)argv, NULL, lframe, \
                (FPtr_app_create)func_create, \
                (FPtr_app_update)func_update, \
                (FPtr_destroy)func_destroy, \
                (char_t *)options); \
        return 0; \
    }
