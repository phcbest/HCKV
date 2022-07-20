//
// Created by PengHaiChen on 2022/7/20.
//

#ifndef HCKV_HCKVLOG_H
#define HCKV_HCKVLOG_H

#include <android/log.h>

#define LOG_TAG "HCKV_lib"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#endif //HCKV_HCKVLOG_H
