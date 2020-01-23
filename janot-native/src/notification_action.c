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

#include "notification_action.h"

#include "utils.h"

#define CALLBACK_FUNCTION_NAME "onAction"
#define CALLBACK_FUNCTION_SIGNATURE "(Ljava/lang/String;)V"

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

void callback_function(NotifyNotification* notification, char* action, gpointer user_data) {
	CallbackData* callback_data = user_data;
	JNIEnv* jni_environment = callback_data->jni_environment;
	jobject callback = callback_data->callback;
	jstring action_string = create_string(jni_environment, action);
	call_java_void_method(jni_environment, CALLBACK_FUNCTION_NAME, CALLBACK_FUNCTION_SIGNATURE, callback, action_string);
	delete_global_reference(jni_environment, callback);
	free(callback_data);
}

void free_user_data_function(gpointer data) {
	CallbackData* callback_data = data;
	JNIEnv* jni_environment = callback_data->jni_environment;
	jobject callback = callback_data->callback;
	delete_global_reference(jni_environment, callback);
	free(callback_data);
}
