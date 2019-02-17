# Handle Time data

## Moment

[Moment](http://momentjs.cn/docs/)

```js
var moment = require('monent');
monent().format();
```

```html
<script src="moment.js"></script>
<script>
    moment().format();
</script>
```

## Moment

```js
// Current Time
var now = moment();

// The time string matches IOS 8601 format
var day = monent("2019-02-18");

// The time string with time format
moment("2019-02-18", "MM-DD-YYYY");
moment("2019-02-18", "MM-DD-YYYY").isValid();
moment("2019-02-18", ["MM-DD-YYYY", "YYYY-MM-DD"]);
```

![timeformat-1](https://github.com/ErlichChen/learning-notes/blob/master/nodejs/timeformat-1.png)
![timeformat-2](https://github.com/ErlichChen/learning-notes/blob/master/nodejs/timeformat-2.png)
![timeformat-3](https://github.com/ErlichChen/learning-notes/blob/master/nodejs/timeformat-3.png)

## Moment Timezone

[Moment Timezone](http://momentjs.cn/timezone/docs/)

