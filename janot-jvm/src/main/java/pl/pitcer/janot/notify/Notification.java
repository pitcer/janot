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

public interface Notification {

	int EXPIRES_DEFAULT_TIMEOUT = -1;
	int EXPIRES_NEVER_TIMEOUT = 0;

	boolean update(String summary, String body, String icon);

	boolean show();

	boolean show(ByteBuffer error);

	void setTimeout(int timeout);

	void setCategory(String category);

	void setUrgency(NotificationUrgency urgency);

	void setImageFromPixbuf(ByteBuffer pixbuf);

	void setHint(String key, ByteBuffer value);

	void setAppName(String appName);

	void clearHints();

	void addAction(String action, String label, Object callback, Object userData, Object freeFunc);

	void clearActions();

	boolean close();

	boolean close(ByteBuffer error);

	int getClosedReason();
}
