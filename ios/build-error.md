# Building Error

## iOS Xcode 最新构建版本缺少合规证明

* 检查

iTounes Connect -> 功能 -> 加密

* 修改info.plist

```html
<key>ITSAppUsesNonExemptEncryption</key><false/>
```

## Invalid App Store Icon

1. Click & open the App Store icon (1024*1024) in preview app.

2. Export it by unticking the Alpha channel.

3. Replace the current App Store icon with the newly exported icon image.

4. Validate and upload.