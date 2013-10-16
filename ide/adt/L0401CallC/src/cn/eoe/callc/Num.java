package cn.eoe.callc;

public class Num {

	public native int getNum();
	public native int max(int a,int b);
	
	static{
		System.loadLibrary("CallC");
	}
}
