# Custom Annotations in Android

## For Java

### define an annotation

```java
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.FIELD)
public @interface BindView {
	int value();
}
```

## annotation processor

```java
public class NewIntentProcessor extends AbstractProcessor {

    @Override
    public synchronized void init(ProcessingEnvironment processingEnv) {}

    @Override
    public boolean process(Set<? extends TypeElement> set, RoundEnvironment roundEnv) {}

    @Override
    public Set<String> getSupportedAnnotationTypes() {}

    @Override
    public SourceVersion getSupportedSourceVersion() {}
}
```

### resources file

create resources/META-INF/services/java.annotation.processing.Processor file, and add processor package path name in it.

### JavaPoet

## touble shooting

gradle plugin version below 3.2.0 and gradle wrapper version below 4.10.1 are good. The latest gradle does't work well with kotlin annotation.
