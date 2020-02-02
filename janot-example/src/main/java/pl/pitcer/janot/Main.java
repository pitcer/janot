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

package pl.pitcer.janot;

import pl.pitcer.janot.gtk.Button;
import pl.pitcer.janot.gtk.Gtk;
import pl.pitcer.janot.gtk.Window;
import pl.pitcer.janot.notify.Notification;
import pl.pitcer.janot.notify.Notify;

public final class Main {

	public static void main(String[] args) {
		Gtk.init(args);
		Notify.init("janot");
		createWindow();
		Gtk.main();
	}

	private static void createWindow() {
		Window window = new Window();
		window.setTitle("Example");
		window.setBorderWidth(100);
		window.setDestroyCallback(Main::quit);
		Button button = new Button();
		button.setLabel("Click me!");
		button.setClickedCallback(Main::sendNotification);
		window.add(button);
		window.showAll();
	}

	private static void sendNotification() {
		Notification notification = new Notification();
		notification.update("Example", "Example notification", "dialog-information");
		notification.addAction("open-window-action", "Open new window", action -> createWindow());
		notification.show();
	}

	private static void quit() {
		Notify.uninit();
		Gtk.mainQuit();
	}
}
