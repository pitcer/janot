package pl.pitcer.janot;

public final class Janot {

	static {
		System.loadLibrary("janot-native");
	}

	private Janot() {
		throw new UnsupportedOperationException("Cannot create an instance of this class");
	}

	public static native void helloJanot();

	public static native void sendNotification(String summary, String body, String icon);
}
