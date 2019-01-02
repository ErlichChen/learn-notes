# Some Gradle error

## Download gradle timeout

Download gradle bin file from ![official address](http://services.gradle.org/distributions) manually.
Change distributionUrl property in gradle-wrapper.properties to

```groovy
distributionBase=GRADLE_USER_HOME
distributionPath=wrapper/dists
zipStoreBase=GRADLE_USER_HOME
zipStorePath=wrapper/dists
distributionUrl=gradle-x.xx-bin.zip
```

Then, make a copy of gradle-x.xx.zip in gradle/wrapper/.