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

package pl.pitcer.janot.notify;

public final class Notify {

	private Notify() {
		throw new UnsupportedOperationException("Cannot create an instance of this class");
	}

	public static boolean init(String appName) {
		return NativeNotify.init(appName);
	}

	public static void uninit() {
		NativeNotify.uninit();
	}

	public static boolean isInitted() {
		return NativeNotify.isInitted();
	}

	public static String getAppName() {
		return NativeNotify.getAppName();
	}

	public static void setAppName(String appName) {
		NativeNotify.setAppName(appName);
	}

	public static Notification createNotification() {
		return new NotificationImpl();
	}

	public static Notification createNotification(String summary, String body, String icon) {
		return new NotificationImpl(summary, body, icon);
	}
}
