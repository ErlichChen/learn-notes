/*
     * 变量:========>
     * 操作的数据都是在内存中操作
     * js中存储数据使用变量的方式(名字,值--->数据)
     * js中声明变量都用var---->存储数据,数据应该有对应的数据类型
     * js中的字符串类型的值都用双引号或者单引号
     *
     * 存储一个数字10
     * 变量的声明及赋值
     * var num=10;
     * 存储一个名字
     * var name='小黑';
     *
     * */

    /*
     *
     * 变量---作用,存储数据的或者是操作数据
     *
     * 变量声明(有var 有变量名字,没有值)
     *
     * 变量初始化(有var 有变量名字,有值)
     *
     * 变量声明的方式:
     * var 变量名字;
     *
     * */

    //var number;//变量的声明,此时是没有赋值的,
    //一次性声明多个变量
    //var x,y,z,k,j;//都是声明,没有赋值

    //变量的初始化(变量声明的同时并且赋值了)
    //   = 的意义:赋值的含义
    //存储一个数字10
    var number = 10;
    //存储一个5
    var number2 = 5;
    //存储一个人的名字
    var name = "小黑";
    //存储真(true)
    var flag = true;
    //存储一个null--->相当于是空
    var nll = null;
    //存储一个对象
		var obj = new Object();

		    //变量的交换的第一个思路:使用第三方的变量进行交换
    //    var num1=10;
    //    var num2=20;
    //   //把num1这个变量的值取出来放在temp变量中
    //    var temp=num1;
    //   //把num2这个变量的值取出来放在num1变量中
    //    num1=num2;
    //   //把temp变量的值取出来放在num2变量中
    //    num2=temp;
    //    console.log(num1);//20
    //    console.log(num2);//10


    //第二种方式交换:一般适用于数字的交换


    //    var num1 = 10;
    //    var num2 = 20;
    //    //把num1的变量中的值和num2变量中的值,取出来相加,重新赋值给num1这个变量
    //    num1 = num1 + num2;//30
    //    //num1变量的值和num2变量的值取出来,相减的结果重新赋值给num2
    //    num2 = num1 - num2;//10
    //    //num1变量的值和num2变量的值取出来,相减的结果重新赋值给num1
    //    num1 = num1 - num2;//20
    //    console.log(num1, num2);


    //Ctrl+Alt+L----->格式化代码的(设置代码有很好的格式,代码是错误的,这个快捷键是没有效果)

    //注意；变量的名字是不能重名

    //    var num1=10;
    //    var num1=20;
    //    console.log(num1);

    //扩展的变量的交换:只需要看代码,不需要理解---位运算
    var num1 = 10;
    var num2 = 20;
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
		console.log(num1, num2);

		 //声明变量并初始化
    //    var num=10;
    //js中的数据类型有哪些?
    //js中的原始数据类型:number,string,boolean,null,undefined,object
    /*
     * number:数字类型(整数和小数)
     * string:字符串类型(的值一般都是用单引号或者是双引号括起来)  "34"
     * boolean:布尔类型(值只有两个,true(真1),false(假0))
     * null:空类型,值只有一个:null,一个对象指向为空了,此时可以赋值为null
     * undefined:未定义,值只有一个:undefined
     * 什么情况下的结果是undefined
     * 变量声明了,没有赋值,结果是undefined
     * 函数没有明确返回值,如果接收了,结果也是undefined
     * 如果一个变量的结果是undefined和一个数字进行计算,结果:NaN不是一个数字,也没有意义
     * object:对象---->
     *
     * */

    //    var num;
    //    console.log(num+10);//NaN-----not an number---->不是一个数字


    //    var num;
    //    console.log(num);


    //如何获取这个变量的数据类型是什么? 使用typeof 来获取
    //typeof 的使用的语法
    /*
     * 都可以获取这个变量的数据类型是什么!
     * typeof 变量名
     * typeof(变量名)
     *
     *
     *
     * */


    var num = 10;
    var str = "小白";
    var flag = true;
    var nll = null;
    var undef;
    var obj = new Object();
    //是使用typeof 获取变量的类型
    console.log(typeof num);//number
    console.log(typeof str);//string
    console.log(typeof flag);//boolean
    console.log(String(nll));//是null
    console.log(typeof nll);//不是null
    console.log(typeof undef);//undefined
    console.log(typeof obj);//object
    console.log(typeof(num));
    //
    //
    //    console.log("10");
    //    console.log(10);
