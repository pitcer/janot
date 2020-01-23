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

import java.nio.ByteBuffer;

final class NativeNotification {

	static {
		System.loadLibrary("janot-native");
	}

	private NativeNotification() {
		throw new UnsupportedOperationException("Cannot create an instance of this class");
	}

	static native ByteBuffer newInstance(String summary, String body, String icon);

	static native boolean update(ByteBuffer notification, String summary, String body, String icon);

	static native boolean show(ByteBuffer notification, Object error);

	static native void setTimeout(ByteBuffer notification, int timeout);

	static native void setCategory(ByteBuffer notification, String category);

	static native void setUrgency(ByteBuffer notification, int urgency);

	static native void setImageFromPixbuf(ByteBuffer notification, ByteBuffer pixbuf);

	static native void setHint(ByteBuffer notification, String key, ByteBuffer value);

	static native void setAppName(ByteBuffer notification, String appName);

	static native void clearHints(ByteBuffer notification);

	static native void addAction(ByteBuffer notification, String action, String label, NotificationCallback callback);

	static native void clearActions(ByteBuffer notification);

	static native boolean close(ByteBuffer notification, Object error);

	static native int getClosedReason(ByteBuffer notification);
}
