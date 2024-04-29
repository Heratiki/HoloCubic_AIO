#ifndef APP_CONTROLLER_GUI_H
#define APP_CONTROLLER_GUI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

// Uncomment the following line to enable waiting for animations to complete
// #define ANIEND_WAIT

// This macro waits for all running animations to complete
#define ANIEND_WAIT                 \
    while (lv_anim_count_running()) \
        lv_task_handler(); // Wait for animations to complete

// Uncomment the following line to enable waiting for animations to complete
// #define ANIEND_WAIT                      \
//     while (lv_anim_count_running());

// Function declarations
void app_control_gui_init(void);
void app_control_gui_release(void);
void display_app_scr_release(void);
void display_app_scr_init(const void *src_img, const char *app_name);
void app_control_display_scr(const void *src_img, const char *app_name,
                             lv_scr_load_anim_t anim_type, bool force);

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

// External image descriptors
extern const lv_img_dsc_t app_loading;
extern const lv_img_dsc_t app_loading1;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif