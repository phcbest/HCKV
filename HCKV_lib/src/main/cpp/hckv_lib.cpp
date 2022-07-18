#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring  extern "C" JNICALL
Java_org_phcbest_hckv_1lib_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}