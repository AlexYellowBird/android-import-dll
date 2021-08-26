#include <jni.h>
#include <string>

#include "testdll.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_project_testdll_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_project_testdll_MainActivity_stringFromDll(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = getDllString();
    return env->NewStringUTF(hello.c_str());
}