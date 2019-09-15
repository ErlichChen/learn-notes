# CountDownTimer

Schedule a countdown until a time in the future, with regular notifications on intervals along the way.

```java
new CountDownTimer(10000, 1000) {

	public void onTick(long millisUntilFinished) {
		Log.i(TAG, "seconds remaining: " + millisUntilFinished / 1000);
	}

	public void onFinish() {
		Log.i(TAG, "done!");
	}
}.start();
```