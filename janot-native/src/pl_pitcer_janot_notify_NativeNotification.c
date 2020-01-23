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
#include "notification_action.h"

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

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setTimeout(JNIEnv* env, jclass class, jobject notification, jint timeout) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	notify_notification_set_timeout(notify_notification, timeout);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setCategory(JNIEnv* env, jclass class, jobject notification, jstring category) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	Chars category_chars = string_to_chars(env, category);
	notify_notification_set_category(notify_notification, category_chars);
	release_string(env, category, category_chars);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setUrgency(JNIEnv* env, jclass class, jobject notification, jint urgency) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	notify_notification_set_urgency(notify_notification, urgency);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setImageFromPixbuf(JNIEnv* env, jclass class, jobject notification, jobject pixbuf);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setHint(JNIEnv* env, jclass class, jobject notification, jstring key, jobject value);

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setAppName(JNIEnv* env, jclass class, jobject notification, jstring app_name) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	Chars app_name_chars = string_to_chars(env, app_name);
	notify_notification_set_category(notify_notification, app_name_chars);
	release_string(env, app_name, app_name_chars);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_clearHints(JNIEnv* env, jclass class, jobject notification) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	notify_notification_clear_hints(notify_notification);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_addAction(JNIEnv* env, jclass class, jobject notification, jstring action, jstring label, jobject callback) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	Chars action_chars = string_to_chars(env, action);
	Chars label_chars = string_to_chars(env, label);
	CallbackData* callback_data = allocate_callback_data(env, callback);
	notify_notification_add_action(notify_notification, action_chars, label_chars, NOTIFY_ACTION_CALLBACK(callback_function), callback_data, G_FREE_FUNC(free_user_data_function));
	release_string(env, action, action_chars);
	release_string(env, label, label_chars);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_clearActions(JNIEnv* env, jclass class, jobject notification) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	notify_notification_clear_actions(notify_notification);
}

JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_close(JNIEnv* env, jclass class, jobject notification, jobject error) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	gboolean result = notify_notification_close(notify_notification, NULL);
	return (jboolean) result;
}

JNIEXPORT jint JNICALL Java_pl_pitcer_janot_notify_NativeNotification_getClosedReason(JNIEnv* env, jclass class, jobject notification) {
	NotifyNotification* notify_notification = buffer_to_pointer(env, notification);
	return notify_notification_get_closed_reason(notify_notification);
}
