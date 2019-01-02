# Dagger2

## 引入依赖库

```groovy
compile 'com.google.dagger.dagger:2.xx'
annotationProcessor 'com.google.dagger:dagger-compiler:2.xx'
```

## 创建Module

```java
@Module
public class MainModule {
  @Providers
  A providerA() {
    return new A();
  }
}
```

## 创建Component

```java
@Component(modules = {MainModule.class})
public intreface MainComponent {
  void inject(MainActivity activity);
}
```

## 生成DaggerComponent



## 将Component与Activity/Fragment绑定

```java
public class MainActivity extends AppCompatActivity {
  
  @Inject
  A a;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    DaggerMainConponent.create().inject(this);

    DaggerMainConponent.builder().build().inject(this);

    a.eat();
    
  }
}
```