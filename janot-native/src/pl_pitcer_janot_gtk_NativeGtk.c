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

#include "pl_pitcer_janot_gtk_NativeGtk.h"

#include <gtk/gtk.h>
#include "utils.h"

void fill_arguments(int length, Chars arguments_chars[length], JNIEnv* env, jobjectArray arguments) {
	for (int index = 0; index < length; index++) {
		jstring argument = get_array_object_element(env, arguments, index);
		Chars argument_chars = string_to_chars(env, argument);
		arguments_chars[index] = argument_chars;
	}
}

void release_arguments(int length, Chars arguments_chars[length], JNIEnv* env, jobjectArray arguments) {
	for (int index = 0; index < length; index++) {
		jstring argument = get_array_object_element(env, arguments, index);
		Chars argument_chars = arguments_chars[index];
		release_string(env, argument, argument_chars);
	}
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_gtk_NativeGtk_init(JNIEnv* env, jclass class, jobjectArray args) {
	int length = get_array_length(env, args);
	Chars arguments_chars[length];
	fill_arguments(length, arguments_chars, env, args);
	gtk_init(&length, (char***) &arguments_chars);
	release_arguments(length, arguments_chars, env, args);
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_gtk_NativeGtk_main(JNIEnv* env, jclass class) {
	gtk_main();
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_gtk_NativeGtk_mainQuit(JNIEnv* env, jclass class) {
	gtk_main_quit();
}
