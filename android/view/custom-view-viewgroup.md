# 自定义View&ViewGroup

## UI绘制流程

1. Activity.java

```java
public void setContentView(@LayoutRes int layoutResID) {
	// set the activity content from a layout resource.
	// The resource will be inflated, adding all top-level views to the activity.
	getWindow().setContentView(layoutResID); // 1
	initWindowDecorActionBar();
}
```

2. getWindow() Window的实现类是PhoneWindow

```java
// com.android.internal.policy
@Override
public void setContentView(int layoutResID) {
	// Note: FEATURE_CONTENT_TRANSITIONS may be set in the process of installing the window
	// decor, when theme attributes and the like are crystalized. Do not check the feature
	// before this happens.
	if (mContentParent == null) {
		installDecor(); // 2
	}
	mLayoutInflater.inflate(layoutResID, mContentParent); // 6
}
```

```java
private void installDecor() {
	if (mDecor == null) {
		mDecor = generateDecor(); // 3
		mDecor.setDescendantFocusability(ViewGroup.FOCUS_AFTER_DESCENDANTS);
		mDecor.setIsRootNamespace(true);
		if (!mInvalidatePanelMenuPosted && mInvalidatePanelMenuFeatures != 0) {
				mDecor.postOnAnimation(mInvalidatePanelMenuRunnable);
		}
	}
	if (mContentParent == null) {
		mContentParent = generateLayout(mDecor); // 4
}
```

```java
protected ViewGroup generateLayout(DecorView decor) {//⑤
	View in = mLayoutInflater.inflate(layoutResource, null);
	decor.addView(in, new ViewGroup.LayoutParams(MATCH_PARENT, MATCH_PARENT));
	mContentRoot = (ViewGroup) in;
}
```

## onMeasure, onLayout, onDraw
measure：测量，测量自己有多大，如果是ViewGroup的话会同时测量里面的子控件的大小
layout：摆放里面的子控件bounds(left,top,right,bottom)
draw：绘制 (直接继承了view一般都会重写onDraw)


## View 源代码

1. view的requestLayout()方法开始，递归地不断往上找父容器，最终找到DecorView
2. 执行了DecorView的ViewRootImp类的performTranversal()方法 （ViewRootImp类：是PhoneWindow和DecorView的桥梁）

3.
```java
performTranversal(){
	 // Ask host how big it wants to be
	performMeasure(childWidthMeasureSpec, childHeightMeasureSpec);
	performLayout(lp, desiredWindowWidth, desiredWindowHeight);
	performDraw();
}
```

4.
```java
private void performMeasure(int childWidthMeasureSpec, int childHeightMeasureSpec) {
	Trace.traceBegin(Trace.TRACE_TAG_VIEW, "measure");
	try {
		mView.measure(childWidthMeasureSpec, childHeightMeasureSpec);
	} finally {
		Trace.traceEnd(Trace.TRACE_TAG_VIEW);
	}
}
```







------------------------ViewGroup.java总结：-----------------------
一、measure的过程
如何去合理的测量一颗View树？
如果ViewGroup和View都是直接指定的宽高，我还要测量吗？
正是因为谷歌设计的自适应尺寸机制(比如Match_parent,wrap_content),造成了宽高不确定，所以就需要进程测量measure过程。
measure过程会遍历整颗View树，然后依次测量每一个View的真实的尺寸。(树的遍历--先序遍历)

MeasureSpec：测量规格
int 32位：010111100011100
拿前面两位当做mode，后面30位当做值。
	1.mode：
		1） EXACTLY: 精确的。比如给了一个确定的值 100dp
		2)  AT_MOST: 根据父容器当前的大小，结合你指定的尺寸参考值来考虑你应该是多大尺寸，需要计算（Match_parent,wrap_content就是属于这种）
		3)  UNSPECIFIED: 最多的意思。根据当前的情况，结合你制定的尺寸参考值来考虑，在不超过父容器给你限定的只存的前提下，来测量你的一个恰好的内容尺寸。
			用的比较少，一般见于ScrollView，ListView（大小不确定，同时大小还是变的。会通过多次测量才能真正决定好宽高。）
	2.value：宽高的值。

经过大量测量以后，最终确定了自己的宽高，需要调用：setMeasuredDimension(w,h)

写自定义控件的时候，我们要去获得自己的宽高来进行一些计算，必须先经过measure，才能获得到宽高---不是getWidth(),而是getMeasuredWidth()
也就是当我们重写onMeasure的时候，我们需要在里面调用child.measure()才能获取child的宽高。

从规格当中获取mode和value：
	final int widthMode = MeasureSpec.getMode(widthMeasureSpec);
        final int heightMode = MeasureSpec.getMode(heightMeasureSpec);
        int widthSize = MeasureSpec.getSize(widthMeasureSpec);
        int heightSize = MeasureSpec.getSize(heightMeasureSpec);
反过来将mode和value合成一个规格呢：
	MeasureSpec.makeMeasureSpec(resultSize, resultMode);

ViewGroup:
	设计它的目的是什么？
	1）作为容器处理焦点问题。
	2）作为容器处理事件分发问题；
	3）控制容器添加View的流程：addView()，removeView()
	4）抽出了一些容器的公共的工具方法：measureChildren，measureChild,measureChildWidthMargins方法。


## 自定义View measure

### 继承自View的子类
		只需要重写onMeasure测量好自己的宽高就可以了。
		最终调用setMeasuredDimension()保存好自己的测量宽高。
		套路：
		int mode = MeasureSpec.getMode(widthMeasureSpec);
		int Size = MeasureSpec.getSize(widthMeasureSpec);
		int viewSize = 0;
		switch(mode){
			case MeasureSpec.EXACTLY:
				viewSize = size;//当前view的尺寸就为父容器的尺寸
				break;
			case MeasureSpec.AT_MOST:
				viewSize = Math.min(size, getContentSize());//当前view的尺寸就为内容尺寸和费容器尺寸当中的最小值。
				break;
			case MeasureSpec.UNSPECIFIED:
				viewSize = getContentSize();//内容有多大，久设置多大尺寸。
				break;
			default:
				break;
		}
		//setMeasuredDimension(width, height);
		setMeasuredDimension(size);

### 继承自ViewGroup的子类：
		不但需要重写onMeasure测量自己，还要测量子控件的规格大小。

		可以直接使用ViewGroup的工具方法来测量里面的子控件，也可以自己来实现这一套子控件的测量（比如：RelativeLayout）
	套路：
		//1.测量自己的尺寸
		ViewGroup.onMeasure();
			//1.1 为每一个child计算测量规格信息(MeasureSpec)
			ViewGroup.getChildMeasureSpec();
			//1.2 将上面测量后的结果，传给每一个子View，子view测量自己的尺寸
			child.measure();

			//1.3 子View测量完，ViewGroup就可以拿到这个子View的测量后的尺寸了
			child.getChildMeasuredSize();//child.getMeasuredWidth()和child.getMeasuredHeight()
			//1.4ViewGroup自己就可以根据自身的情况(Padding等等),来计算自己的尺寸
			ViewGroup.calculateSelfSize();
		//2.保存自己的尺寸
		ViewGroup.setMeasuredDimension(size);




----------------------------------------------



二、layout的过程


三、draw的过程

	ViewGroup的onDraw方法默认是不会调用的，因为在ViewGroup构造方法里面就默认设置了
	setFlags(WILL_NOT_DRAW, DRAW_MASK);//原因是因为ViewGroup本来就没东西显示，除了设置了背景，这样就是为了效率。
	如果需要它执行onDraw可以，设置背景或者如下：
	setWillNotDraw(false);



作业：如何让一个ScrollView里面的ListView全部展开？
有一种解决办法就是继承ListView，重写onMeasure方法：
public void onMeasure(){
  int expandSpec = MeasureSpec.makeMeasureSpec(Integer.MAX_VALUE >> 2, MeasureSpec.AT_MOST);
  super.onMeasure(widthMeasureSpec, expandSpec);
}
为什么要这么做？1.设置mode为 MeasureSpec.AT_MOST？2.value为Integer.MAX_VALUE >> 2？


