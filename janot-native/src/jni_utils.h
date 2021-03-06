/*
 * MIT License
 *
 * Copyright (c) 2019-2020 Piotr Dobiech
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef JNI_UTILS_HEADER
#define JNI_UTILS_HEADER

#include <jni.h>

typedef const char* Chars;

Chars string_to_chars(JNIEnv* jni_environment, jstring string);

void release_string(JNIEnv* jni_environment, jstring string, Chars chars);

jstring create_string(JNIEnv* jni_environment, Chars chars);

jobject pointer_to_buffer(JNIEnv* jni_environment, void* pointer, jlong size);

void* buffer_to_pointer(JNIEnv* jni_environment, jobject buffer);

int get_array_length(JNIEnv* jni_environment, jobjectArray array);

jobject get_array_object_element(JNIEnv* jni_environment, jobjectArray array, int index);

jobject create_global_reference(JNIEnv* jni_environment, jobject object);

void delete_global_reference(JNIEnv* jni_environment, jobject reference);

void call_java_void_method(JNIEnv* jni_environment, Chars name, Chars signature, jobject object, ...);

#endif
