# Disable back button

```java
public boolean onKeyDown(int keyCode, KeyEvent event) {
	if (keyCode == KeyEvent.KEYCODE_BACK) {
		return true;
	}
	return false;
}
```