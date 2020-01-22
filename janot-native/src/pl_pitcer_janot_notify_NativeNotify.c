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

#include "pl_pitcer_janot_notify_NativeNotify.h"

#include <libnotify/notify.h>
#include "utils.h"

JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotify_init(JNIEnv *env, jclass class, jstring app_name) {
	Chars app_name_chars = string_to_chars(env, app_name);
	gboolean result = notify_init(app_name_chars);
	release_string(env, app_name, app_name_chars);
	return (jboolean) result;
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotify_uninit(JNIEnv *env, jclass class) {
	notify_uninit();
}

JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotify_isInitted(JNIEnv *env, jclass class) {
	gboolean result = notify_is_initted();
	return (jboolean) result;
}

JNIEXPORT jstring JNICALL Java_pl_pitcer_janot_notify_NativeNotify_getAppName(JNIEnv *env, jclass class) {
	Chars app_name_chars = notify_get_app_name();
	return create_string(env, app_name_chars);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotify_setAppName(JNIEnv *env, jclass class, jstring app_name) {
	Chars app_name_chars = string_to_chars(env, app_name);
	notify_set_app_name(app_name_chars);
}
