# Include so file in android studio

## jniLibs

create jniLibs folder in src/main, and copy .so files into.

## libs

create libs folder in app, and copy .so files into.

```groovy
// copy code in app/build.gradle
android {
	sourceSets {
		main {
			jniLibs.srcDirs = ['libs']
		}
	}
}
```