/**
 * Functions
 * In JavaScript, functions are first-class objects, they have properties and methods
 */

// declare the function
let obj1 = {
	name: "name1"
}
console.log(obj1);
function func1(obj) {
	obj.name = "name2";
}
func1(obj1);
console.log(obj1);


 //通过函数
    //求两个数字的和
//     function consoleSum() {//函数定义
//       var num1 = 100;
//       var num2 = 200;
//       var sum = num1 + num2;
//       console.log(sum);
//     }
//     //调用
//     consoleSum();


//     //求三个数字的和
//     function consoleSum2() {
//       var num1 = 10;
//       var num2 = 20;
//       var num3 = 30;
//       var sum = num1 + num2 + num3;
//       console.log(sum);
//     }
//     consoleSum2();

//     //求两个数字的最大值
//     function consoleMax() {
//       var x = 10;
//       var y = 20;
//       console.log(x > y ? x : y);
//     }
//     consoleMax();

//     //求三个数字的最大值
//     function consoleMax2() {
//       var x = 10;
//       var y = 20;
//       var z = 30;
//       var max = x > y ? (x > z ? x : z) : (y > z ? y : z);//嵌套的三元表达式
//       console.log(max);
//     }

//     consoleMax2();
//     //求1-100之间所有数字的和
//     function everySum() {
//       var sum=0;
//       for(var i=1;i<=100;i++){
//         sum+=i;
//       }
//       console.log(sum);
//     }
//     everySum();
//     //求1-100之间所有偶数的和
//     function everyEvenSum() {
//       var sum=0;
//       for(var i=1;i<=100;i++){
//         if(i%2==0){
//           sum+=i;
//         }
//       }
//       console.log(sum);
//     }
//     everyEvenSum();

//     //求一个数组的和
//     function consoleArraySum() {
//       var sum=0;
//       var arr=[10,20,30,40,50];
//       for(var i=0;i<arr.length;i++){
//         sum+=arr[i];
//       }
//       console.log(sum);
//     }
// 		consoleArraySum();

// 		//set:设置
//     //get:获取
//     //函数的返回值:在函数内部有return关键字,并且在关键字后面有内容,这个内容被返回了
//     //当函数调用之后,需要这个返回值,那么就定义变量接收,即可

//     /*
//     *
//     * 如果一个函数中有return ,那么这个函数就有返回值
//     * 如果一个函数中没有return,那么这个函数就没有返回值
//     * 如果一个函数中没有明确的返回值,那么调用的时候接收了,结果就是undefined
//     * (没有明确返回值:函数中没有return,函数中有return,但是return后面没有任何内容)
//     * 函数没有返回值,但是在调用的时候接收了,那么结果就是undefined
//     * 变量声明了,没有赋值,结果也是undefined
//     * 如果一个函数有参数,有参数的函数
//     * 如果一个函数没有参数,没有参数的函数
//     * 形参的个数和实参的个数可以不一致
//     * return 下面的代码是不会执行的
//     *
//     *
//     *
//     * */


// 	 function f1(x,y) {
// 		var sum= x+y;
// 		return sum;
// 		console.log("助教才是最帅的");
// 		return 100;
// 	}
// 	var result=f1(10,20);
// 	console.log(result);




// //    function getSum(x, y) {
// //      var sum = x + y;
// //      return sum;//把和返回
// //
// //    }
// //    //函数调用
// //    var result=getSum(10, 20);
// //    console.log(result+10);



// 	//函数定义: 有参数有返回值的函数
// //    function getSum(x, y) {
// //      return  x + y;//把和返回
// //    }
// //    //函数调用
// //    var result=getSum(10, 20);
// //    console.log(result+10);



// 	//有参数,有返回值的函数
// //    function f1(x,y) {
// //      return x+y;
// //    }
// //    //有参数,无返回值的函数
// //    function f2(x) {
// //      console.log(x);
// //    }
// //    //无参数,有返回值的函数
// //    function f3() {
// //      return 100;
// //    }
// //    //无参数无返回值的函数
// //    function f4() {
// //      console.log("萨瓦迪卡");
// //    }
// //
// //
// //    var sum=f1(10);
// //    console.log(sum);//

//     //求两个数字的和:获取任意的两个数字的和
//     function getSum(x, y) {
//       return x + y;
//     }
//     console.log(getSum(10, 20));
//     //求1-100之间所有的数字的和
//     //    function geteverySum() {
//     //      var sum=0;
//     //      for(var i=1;i<=100;i++){
//     //        sum+=i;
//     //      }
//     //      return sum;
//     //    }
//     //    console.log(geteverySum());


//     //- 求1-n之间所有数的和
//     function geteverySum(n) {
//       var sum = 0;
//       for (var i = 1; i <= n; i++) {
//         sum += i;
//       }
//       return sum;
//     }
//     console.log(geteverySum(10));


//     //    - 求n-m之间所有数的和


//     function geteverySum2(n, m) {
//       var sum = 0;
//       for (var i = n; i <= m; i++) {
//         sum += i;
//       }
//       return sum;
//     }
//     console.log(geteverySum2(1, 100));

//     //求圆的面积
//     function getS(r) {
//       return Math.PI * r * r;
//     }
//     console.log(getS(5));


//     //    - 求2个数中的最大值
//     //    - 求3个数中的最大值
//     //    - 判断一个数是否是素数(质数)


//     //    function f1() {
//     //      console.log("考尼奇瓦");
//     //      return 100;
//     //    }
//     //    //f1函数调用,把函数的返回值输出了
//     //    console.log(f1());

//     //
//     //    function f1() {
//     //      console.log("考尼奇瓦");
//     //      return 100;
//     //    }
//     //    console.log(f1);//输出的f1函数名字-----是f1函数的代码