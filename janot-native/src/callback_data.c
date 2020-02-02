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

#include "callback_data.h"

#include <stdlib.h>

typedef struct callback_data {
	JNIEnv* jni_environment;
	jobject callback;
} CallbackData;

CallbackData* allocate_callback_data(JNIEnv* jni_environment, jobject callback) {
	CallbackData* callback_data = malloc(sizeof(CallbackData));
	callback_data->jni_environment = jni_environment;
	callback_data->callback = create_global_reference(jni_environment, callback);
	return callback_data;
}

void delete_callback_reference(CallbackData* callback_data) {
	JNIEnv* jni_environment = callback_data->jni_environment;
	jobject callback = callback_data->callback;
	delete_global_reference(jni_environment, callback);
}

void call_void_callback(CallbackData* callback_data, Chars name, Chars signature, ...) {
	JNIEnv* jni_environment = callback_data->jni_environment;
	jobject callback = callback_data->callback;
	va_list arguments;
	va_start(arguments, signature);
	call_java_void_method(jni_environment, name, signature, callback, arguments);
	va_end(arguments);
}

JNIEnv* get_jni_environment(CallbackData* callback_data) {
	return callback_data->jni_environment;
}

jobject get_callback(CallbackData* callback_data) {
	return callback_data->callback;
}
