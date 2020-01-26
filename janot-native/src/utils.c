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

#include "utils.h"

#include <stdbool.h>

Chars string_to_chars(JNIEnv* jni_environment, jstring string) {
	JNIEnv native_interface = *jni_environment;
 	return native_interface->GetStringUTFChars(jni_environment, string, false);
}

void release_string(JNIEnv* jni_environment, jstring string, Chars chars) {
	JNIEnv native_interface = *jni_environment;
	native_interface->ReleaseStringUTFChars(jni_environment, string, chars);
}

jstring create_string(JNIEnv* jni_environment, Chars chars) {
	JNIEnv native_interface = *jni_environment;
	return native_interface->NewStringUTF(jni_environment, chars);
}

jobject pointer_to_buffer(JNIEnv* jni_environment, void* pointer, jlong size) {
	JNIEnv native_interface = *jni_environment;
	return native_interface->NewDirectByteBuffer(jni_environment, pointer, size);
}

void* buffer_to_pointer(JNIEnv* jni_environment, jobject buffer) {
	JNIEnv native_interface = *jni_environment;
	return native_interface->GetDirectBufferAddress(jni_environment, buffer);
}

int get_array_length(JNIEnv* jni_environment, jobjectArray array) {
	JNIEnv native_interface = *jni_environment;
	return native_interface->GetArrayLength(jni_environment, array);
}

jobject get_array_object_element(JNIEnv* jni_environment, jobjectArray array, int index) {
	JNIEnv native_interface = *jni_environment;
	return native_interface->GetObjectArrayElement(jni_environment, array, index);
}
