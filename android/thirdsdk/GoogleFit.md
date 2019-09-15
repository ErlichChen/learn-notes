# Google Fit

[Google Fit](https://developers.google.com/fit/android/get-started)

## Step 1: Get a Google Account

To use the Google Fit APIs, you need a [Google Account](https://accounts.google.com/signup/v2/webcreateaccount?continue=https%3A%2F%2Faccounts.google.com%2FManageAccount&hl=zh-CN&flowName=GlifWebSignIn&flowEntry=SignUp).

## Step 2: Get Google Play services

Google Fit is available on Android devices with Google Play services 7.0 or higher.

## Step 3: Get an OAuth 2.0 client ID

If you haven't already enabled the fitness API and obtained an OAuth 2.0 client ID, follow [it](https://developers.google.com/fit/android/get-api-key?hl=zh-CN).

## Step 4: Configure your project

check the latest fitness version.

```groove
dependencies {
    compile 'com.google.android.gms:play-services-fitness:16.0.1'
    compile 'com.google.android.gms:play-services-auth:16.0.1'
}
```

## Step 5: Connect to the fitness service

[Sensors Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/SensorsClient?hl=zh-CN)
[Recording Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/RecordingClient?hl=zh-CN)
[History Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/HistoryClient?hl=zh-CN)
[Sessions Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/SessionsClient?hl=zh-CN)
[Goals Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/GoalsClient?hl=zh-CN)
[BLE Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/BleClient?hl=zh-CN)
[Config Client](https://developers.google.com/android/reference/com/google/android/gms/fitness/ConfigClient?hl=zh-CN)

## Example

### 1. Create a FitnessOptions instance.

```java
FitnessOptions fitnessOptions = FitnessOptions.builder()
    .addDataType(DataType.TYPE_STEP_COUNT_DELTA, FitnessOptions.ACCESS_READ)
    .addDataType(DataType.AGGREGATE_STEP_COUNT_DELTA, FitnessOptions.ACCESS_READ)
    .build();
```

### 2. Check if the user has previously granted the necessary data access.

```java
if (!GoogleSignIn.hasPermissions(GoogleSignIn.getLastSignedInAccount(this), fitnessOptions)) {
GoogleSignIn.requestPermissions(
	this, // your activity
	GOOGLE_FIT_PERMISSIONS_REQUEST_CODE,
	GoogleSignIn.getLastSignedInAccount(this),
	fitnessOptions);
} else {
	accessGoogleFit();
}
```

### 3. If the authorization flow is required, handle the user's response.

```java
@Override
protected void onActivityResult(int requestCode, int resultCode, Intent data) {
	if (resultCode == Activity.RESULT_OK) {
    if (requestCode == GOOGLE_FIT_PERMISSIONS_REQUEST_CODE) {
        accessGoogleFit();
    }
	}
}
```

### 4. After the user has authorized access to the data requested, create the desired GoogleApi client to read and write historic fitness data.

```java
private void accessGoogleFit() {
Calendar cal = Calendar.getInstance();
cal.setTime(new Date());
long endTime = cal.getTimeInMillis();
cal.add(Calendar.YEAR, -1);
long startTime = cal.getTimeInMillis();

DataReadRequest readRequest = new DataReadRequest.Builder()
	.aggregate(DataType.TYPE_STEP_COUNT_DELTA, DataType.AGGREGATE_STEP_COUNT_DELTA)
	.setTimeRange(startTime, endTime, TimeUnit.MILLISECONDS)
	.build();

Fitness.getHistoryClient(this, GoogleSignIn.getLastSignedInAccount(this))
	.readData(readRequest)
	.addOnSuccessListener(new OnSuccessListener<DataReadResponse>() {
			@Override
			public void onSuccess(DataReadResponse dataReadResponse) {
					Log.d(LOG_TAG, "onSuccess()");
			}
	})
	.addOnFailureListener(new OnFailureListener() {
			@Override
			public void onFailure(@NonNull Exception e) {
					Log.e(LOG_TAG, "onFailure()", e);
			}
	})
	.addOnCompleteListener(new OnCompleteListener<DataReadResponse>() {
			@Override
			public void onComplete(@NonNull Task<DataReadResponse> task) {
					Log.d(LOG_TAG, "onComplete()");
			}
	});
}
```
