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

#include "pl_pitcer_janot_notify_NativeNotification.h"

#include <libnotify/notification.h>
#include "utils.h"

JNIEXPORT jobject JNICALL Java_pl_pitcer_janot_notify_NativeNotification_newInstance(JNIEnv* env, jclass class, jstring summary, jstring body, jstring icon) {
	Chars summary_chars = string_to_chars(env, summary);
	Chars body_chars = string_to_chars(env, body);
	Chars icon_chars = string_to_chars(env, icon);
	NotifyNotification* notify_notification = notify_notification_new(summary_chars, body_chars, icon_chars);
	release_string(env, summary, summary_chars);
	release_string(env, body, body_chars);
	release_string(env, icon, icon_chars);
	return pointer_to_buffer(env, notify_notification, sizeof(NotifyNotification));
}

JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_update(JNIEnv* env, jclass class, jobject notification, jstring summary, jstring body, jstring icon) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	Chars summary_chars = string_to_chars(env, summary);
	Chars body_chars = string_to_chars(env, body);
	Chars icon_chars = string_to_chars(env, icon);
	gboolean result = notify_notification_update(notify_notification, summary_chars, body_chars, icon_chars);
	release_string(env, summary, summary_chars);
	release_string(env, body, body_chars);
	release_string(env, icon, icon_chars);
	return (jboolean) result;
}

JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_show(JNIEnv* env, jclass class, jobject notification, jobject error) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	gboolean result = notify_notification_show(notify_notification, NULL);
	return (jboolean) result;
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setTimeout(JNIEnv* env, jclass class, jobject, jint);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setCategory(JNIEnv* env, jclass class, jobject, jstring);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setUrgency(JNIEnv* env, jclass class, jobject, jobject);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setImageFromPixbuf(JNIEnv* env, jclass class, jobject, jobject);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setHint(JNIEnv* env, jclass class, jobject, jstring, jobject);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setAppName(JNIEnv* env, jclass class, jobject, jstring);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_clearHints(JNIEnv* env, jclass class, jobject);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_addAction(JNIEnv* env, jclass class, jobject, jstring, jstring, jobject, jobject, jobject);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_clearActions(JNIEnv* env, jclass class, jobject);

JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_close(JNIEnv* env, jclass class, jobject, jobject);

JNIEXPORT jint JNICALL Java_pl_pitcer_janot_notify_NativeNotification_getClosedReason(JNIEnv* env, jclass class, jobject);
