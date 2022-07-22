//
// Created by PengHaiChen on 2022/7/19.
//

#include <jni.h>
#include <string>
#include "HCKVLOG.h"

using namespace std;

//库加载的时候缓存
static jclass g_cls = nullptr;
static jfieldID g_fidId = nullptr;
static JavaVM *g_currentJVM = nullptr;

static int registerNativeMethods(JNIEnv *env, jclass cls);

/**
 * 动态注册会调用该函数
 */
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    //提前缓存jclass和g_fieldID
    g_currentJVM = vm;
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    if (g_cls) {
        //调用env指针下的deleteGlobalRef函数删除g_cls
        env->DeleteGlobalRef(g_cls);
    }
    //获取类名
    static const char *clsName = "org/phcbest/hckv_lib/HCKV";
    //找到类
    jclass instance = env->FindClass(clsName);
    if (!instance) {
        LOGE("寻找本地类 %s 错误", clsName);
        return -2;
    }
    //获取类的实例
    g_cls = reinterpret_cast<jclass>(env->NewGlobalRef(instance));
    if (!g_cls) {
        LOGE("创建全局引用错误 %s", clsName);
        return -3;
    }
    //动态注册函数
    int ret = registerNativeMethods(env, g_cls);
    if (ret != 0) {
        LOGE("无法为类注册本机方法 %s, ret = %d", clsName, ret);
        return -4;
    }
    g_fidId = env->GetFieldID(g_cls, "nativeHandle", "J");

    if (!g_fidId) {
        LOGE("定位fidID失败");
        return -5;
    }

    return JNI_VERSION_1_6;
}


#define HCKV_JNI static

namespace hckv {
    static string jstring2string(JNIEnv *env, jstring jstr) {
        if (jstr) {
            const char *str = env->GetStringUTFChars(jstr, nullptr);
            if (str) {
                string result(str);
                env->ReleaseStringUTFChars(jstr, str);
                return result;
            }
        }
        return "";
    }

    static jstring string2jstring(JNIEnv *env, const string &str) {
        return env->NewStringUTF(str.c_str());
    }

    HCKV_JNI void nInitialize(JNIEnv *env, jobject thiz,
                              jstring root_dir) {
        if (!root_dir) {
            return;
        }
        const char *kstr = env->GetStringUTFChars(root_dir, nullptr);
        if (kstr) {
            //todo
            return;
        }
    }

}


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