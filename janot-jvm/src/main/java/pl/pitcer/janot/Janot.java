package pl.pitcer.janot;

public final class Janot {

	static {
		System.loadLibrary("janot-native");
	}

	public static native void helloJanot();
}
