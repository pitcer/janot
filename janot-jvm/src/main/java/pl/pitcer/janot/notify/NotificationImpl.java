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

class NotificationImpl implements Notification {

	private ByteBuffer notification;

	NotificationImpl() {
		this("", "", "");
	}

	NotificationImpl(String summary, String body, String icon) {
		this.notification = NativeNotification.newInstance(summary, body, icon);
	}

	@Override
	public boolean update(String summary, String body, String icon) {
		return NativeNotification.update(this.notification, summary, body, icon);
	}

	@Override
	public boolean show() {
		return show(null);
	}

	@Override
	public boolean show(ByteBuffer error) {
		return NativeNotification.show(this.notification, error);
	}

	@Override
	public void setTimeout(int timeout) {
		NativeNotification.setTimeout(this.notification, timeout);
	}

	@Override
	public void setCategory(String category) {
		NativeNotification.setCategory(this.notification, category);
	}

	@Override
	public void setUrgency(NotificationUrgency urgency) {
		int ordinal = urgency.ordinal();
		NativeNotification.setUrgency(this.notification, ordinal);
	}

	@Override
	public void setImageFromPixbuf(ByteBuffer pixbuf) {
		NativeNotification.setImageFromPixbuf(this.notification, pixbuf);
	}

	@Override
	public void setHint(String key, ByteBuffer value) {
		NativeNotification.setHint(this.notification, key, value);
	}

	@Override
	public void setAppName(String appName) {
		NativeNotification.setAppName(this.notification, appName);
	}

	@Override
	public void clearHints() {
		NativeNotification.clearHints(this.notification);
	}

	@Override
	public void addAction(String action, String label, Object callback, Object userData, Object freeFunc) {
		NativeNotification.addAction(this.notification, action, label, callback, userData, freeFunc);
	}

	@Override
	public void clearActions() {
		NativeNotification.clearActions(this.notification);
	}

	@Override
	public boolean close() {
		return close(null);
	}

	@Override
	public boolean close(ByteBuffer error) {
		return NativeNotification.close(this.notification, error);
	}

	@Override
	public int getClosedReason() {
		return NativeNotification.getClosedReason(this.notification);
	}
}
