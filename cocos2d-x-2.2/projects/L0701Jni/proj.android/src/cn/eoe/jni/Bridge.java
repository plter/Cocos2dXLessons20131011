package cn.eoe.jni;

public class Bridge {

	public static native void startListen();
	
	private static void onCCInit(){
		if (getListener()!=null) {
			getListener().onCCInit();
		}
	}
	
	
	public static native void addImage(String img);
	
	public static void setListener(Listener listener) {
		Bridge.listener = listener;
	}
	
	public static Listener getListener() {
		return listener;
	}
	
	private static Listener listener = null;
}
