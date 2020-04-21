# Android Shape

```xml
<?xml version="1.0" encoding="utf-8"?>
<shape
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:shape=["rectangle" | "oval" | "line" | "ring"] >
    <corners
        android:radius="integer"
        android:topLeftRadius="integer"
        android:topRightRadius="integer"
        android:bottomLeftRadius="integer"
        android:bottomRightRadius="integer" />
    <gradient
        android:angle="integer"
        android:centerX="float"
        android:centerY="float"
        android:centerColor="integer"
        android:endColor="color"
        android:gradientRadius="integer"
        android:startColor="color"
        android:type=["linear" | "radial" | "sweep"]
        android:useLevel=["true" | "false"] />
    <padding
        android:left="integer"
        android:top="integer"
        android:right="integer"
        android:bottom="integer" />
    <size
        android:width="integer"
        android:height="integer" />
    <solid
        android:color="color" />
    <stroke
        android:width="integer"
        android:color="color"
        android:dashWidth="integer"
        android:dashGap="integer" />
</shape>
```

The following attributes are used only when android:shape="ring"：

**android:innerRadius** The radius for the inner part of the ring.
**android:innerRadiusRatio** The radius for the inner part of the ring, expressed as a ratio of the ring's width.
**android:thickness** The thickness of the ring.
**android:thicknessRatio** The thickness of the ring, expressed as a ratio of the ring's width.
**android:useLevel** "true" if this is used as a LevelListDrawable

```java
Resources res = getResources();
Drawable shape = ResourcesCompat.getDrawable(res, R.drawable.gradient_box, getTheme());

TextView tv = (TextView)findViewById(R.id.textview);
tv.setBackground(shape);
```

```kotlin
val shape: Drawable? = getDrawable(resources, R.drawable.gradient_box, getTheme())

val tv: TextView = findViewById(R.id.textview)
tv.background = shape
```
