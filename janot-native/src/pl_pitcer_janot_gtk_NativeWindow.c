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

#include "pl_pitcer_janot_gtk_NativeWindow.h"

#include <gtk/gtk.h>
#include "utils.h"

JNIEXPORT jobject JNICALL Java_pl_pitcer_janot_gtk_NativeWindow_newInstance(JNIEnv* jni_environment, jclass class, jint type) {
	GtkWidget* window_widget = gtk_window_new(type);
	return pointer_to_buffer(jni_environment, window_widget, sizeof(GtkWidget));
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_gtk_NativeWindow_setTitle(JNIEnv* jni_environment, jclass class, jobject window_widget_buffer, jstring title) {
	void* pointer = buffer_to_pointer(jni_environment, window_widget_buffer);
	GtkWindow* window = GTK_WINDOW(pointer);
	Chars title_chars = string_to_chars(jni_environment, title);
	gtk_window_set_title(window, title_chars);
	release_string(jni_environment, title, title_chars);
}
