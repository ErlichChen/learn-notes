/**
 * Control flow
 */

/**
 * increment and decrement operation
 */

console.log("----- pre increment -----");
var x1   = 1;
var y1   = ++x1;
console.log("x1: " + x1);
console.log("y1: " + y1);
var sum1 = ++x1 + 1;
console.log("sum1: " + sum1)

console.log("----- post increment -----");
var x2   = 1;
var y2   = x2++;
console.log("x2: " + x2);
console.log("y2: " + y2);
var sum2 = x2++ + 1;
console.log("sum2: " + sum2);

/**
 * if - else statement
 */

var num1 = 1;
var num2 = 2;
if (num1 > num2) {
	console.log("num1 > num2: " + (num1 > num2));
}

var str1 = "str";
if(str1 === "str"){
	console.log("str1 == \"str\"" + (str1 === "str"));
}



    //提示用户请输入年龄----
//    var age=prompt("请您输入您的年龄");//弹框---并且有输入,输入的内容在age变量中
//    console.log(age);//最终的结果是字符串的类型



    //案例1:
//    var age = parseInt(prompt("请您输入年龄"));
//    //判断
//    if (age >= 18) {
//      console.log("可以看电影了,嘎嘎...");
//    } else {
//      console.log("看什么看,回家写作业去");
//    }



    //练习2:判断这个数字是奇数还是偶数

    var number=parseInt(prompt("请输入一个数字"));
    if(number%2==0){
      console.log("偶数");
    }else{
      console.log("奇数");
    }
		var score = Number(prompt("请您输入成绩"));//有bug
    if (!isNaN(score)) {//如果为true就说明 不是数字
      if (score > 90 && score <= 100) {
        console.log("A级");
      } else if (score > 80) {
        console.log("B级");
      } else if (score > 70) {
        console.log("C级");
      } else if (score >= 60) {
        console.log("D级");
      } else {
        console.log("E级");
      }
    } else {
      console.log("您输入有误");
    }

    //练习:判断一个年份是不是闰年
    //定义变量存储一个年份
    var year = 2017;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
      console.log("闰年");
    } else {
      console.log("平年");
    }