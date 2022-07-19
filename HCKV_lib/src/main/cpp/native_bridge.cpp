//
// Created by PengHaiChen on 2022/7/19.
//

#include <jni.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_org_phcbest_hckv_1lib_NativeLib_stringFromJNI(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("测试HCKV成功!!!");
}

extern "C"
JNIEXPORT void JNICALL
Java_org_phcbest_hckv_1lib_HCKV_00024Companion_nInitialize(JNIEnv *env, jobject thiz,
                                                           jstring root_dir) {
    // TODO: implement nInitialize()
}

extern "C"
JNIEXPORT jlong JNICALL
Java_org_phcbest_hckv_1lib_HCKV_00024Companion_nGetDefaultHCKV(JNIEnv *env, jobject thiz) {
    // TODO: implement nGetDefaultHCKV()
}

extern "C"
JNIEXPORT jlong JNICALL
Java_org_phcbest_hckv_1lib_HCKV_00024Companion_nPageSize(JNIEnv *env, jobject thiz) {
    // TODO: implement nPageSize()
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nEncodeInt(JNIEnv *env, jobject thiz, jlong handle, jstring key,
                                           jint value) {
    // TODO: implement nEncodeInt()
}

extern "C"
JNIEXPORT jint JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nDecodeInt(JNIEnv *env, jobject thiz, jlong handle, jstring key,
                                           jint default_value) {
    // TODO: implement nDecodeInt()
}

extern "C"
JNIEXPORT jstring JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nDecodeString(JNIEnv *env, jobject thiz, jlong handle, jstring key,
                                              jstring default_value) {
    // TODO: implement nDecodeString()
}

extern "C"
JNIEXPORT void JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nRemoveValueForKey(JNIEnv *env, jobject thiz, jlong handle,
                                                   jstring key) {
    // TODO: implement nRemoveValueForKey()
}

extern "C"
JNIEXPORT jlong JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nTotalSize(JNIEnv *env, jobject thiz, jlong handle) {
    // TODO: implement nTotalSize()
}

extern "C"
JNIEXPORT jlong JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nCount(JNIEnv *env, jobject thiz, jlong handle) {
    // TODO: implement nCount()
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_org_phcbest_hckv_1lib_HCKV_nEncodeString(JNIEnv *env, jobject thiz, jlong handle, jstring key,
                                              jstring value) {
    // TODO: implement nEncodeString()
}