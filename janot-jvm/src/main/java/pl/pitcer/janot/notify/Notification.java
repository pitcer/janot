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

public class Notification {

	public static final int EXPIRES_DEFAULT_TIMEOUT = -1;
	public static final int EXPIRES_NEVER_TIMEOUT = 0;

	private ByteBuffer notification;

	public Notification() {
		this("", "", "");
	}

	public Notification(String summary, String body, String icon) {
		this.notification = NativeNotification.newInstance(summary, body, icon);
	}

	public boolean update(String summary, String body, String icon) {
		return NativeNotification.update(this.notification, summary, body, icon);
	}

	public boolean show() {
		return show(null);
	}

	public boolean show(ByteBuffer error) {
		return NativeNotification.show(this.notification, error);
	}

	public void setTimeout(int timeout) {
		NativeNotification.setTimeout(this.notification, timeout);
	}

	public void setCategory(String category) {
		NativeNotification.setCategory(this.notification, category);
	}

	public void setUrgency(NotificationUrgency urgency) {
		int ordinal = urgency.ordinal();
		NativeNotification.setUrgency(this.notification, ordinal);
	}

	public void setImageFromPixbuf(ByteBuffer pixbuf) {
		NativeNotification.setImageFromPixbuf(this.notification, pixbuf);
	}

	public void setHint(String key, ByteBuffer value) {
		NativeNotification.setHint(this.notification, key, value);
	}

	public void setAppName(String appName) {
		NativeNotification.setAppName(this.notification, appName);
	}

	public void clearHints() {
		NativeNotification.clearHints(this.notification);
	}

	public void addAction(String action, String label, NotificationCallback callback) {
		NativeNotification.addAction(this.notification, action, label, callback);
	}

	public void clearActions() {
		NativeNotification.clearActions(this.notification);
	}

	public boolean close() {
		return close(null);
	}

	public boolean close(ByteBuffer error) {
		return NativeNotification.close(this.notification, error);
	}

	public int getClosedReason() {
		return NativeNotification.getClosedReason(this.notification);
	}
}
