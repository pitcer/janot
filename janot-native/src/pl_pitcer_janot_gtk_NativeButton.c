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

#include "pl_pitcer_janot_gtk_NativeButton.h"

#include <gtk/gtk.h>
#include "jni_utils.h"
#include "g_utils.h"
#include "callback_data.h"

JNIEXPORT jobject JNICALL Java_pl_pitcer_janot_gtk_NativeButton_newInstance(JNIEnv* jni_environment, jclass class) {
	GtkWidget* button_widget = gtk_button_new();
	return pointer_to_buffer(jni_environment, button_widget, sizeof(GtkWidget));
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_gtk_NativeButton_setLabel(JNIEnv* jni_environment, jclass class, jobject button_buffer, jstring label) {
	void* pointer = buffer_to_pointer(jni_environment, button_buffer);
	GtkButton* button = GTK_BUTTON(pointer);
	Chars label_chars = string_to_chars(jni_environment, label);
	gtk_button_set_label(button, label_chars);
	release_string(jni_environment, label, label_chars);
}

static void clicked_callback_function(GtkWidget* object, gpointer user_data) {
	CallbackData* callback_data = user_data;
	call_void_callback(callback_data, "onClicked", "()V");
}

static void destroy_data_function(gpointer data, GClosure* closure) {
	CallbackData* callback_data = data;
	delete_callback_reference(callback_data);
	free(callback_data);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_gtk_NativeButton_setClickedCallback(JNIEnv* jni_environment, jclass class, jobject button_buffer, jobject callback) {
	void* pointer = buffer_to_pointer(jni_environment, button_buffer);
	GObject* object = G_OBJECT(pointer);
	CallbackData* callback_data = allocate_callback_data(jni_environment, callback);
	g_signal_connect_data(object, "clicked", G_CALLBACK(clicked_callback_function), callback_data, G_CLOSURE_NOTIFY(destroy_data_function), 0);
}
