# Handle Time data

## Moment

[Moment](http://momentjs.com/docs/)

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

```js
// Current Time
var now = moment();

// The time string matches IOS 8601 format
var day = monent("2019-02-18");

// The time string with time format
moment("2019-02-18", "MM-DD-YYYY");
moment("2019-02-18", "MM-DD-YYYY").isValid();
moment("2019-02-18", ["MM-DD-YYYY", "YYYY-MM-DD"]);

// Calculate minimum birthday
birth = moment.utc(birthday, moment.ISO_8601).format('MMM DD, YYYY');
```

![timeformat-1](https://github.com/ErlichChen/learning-notes/blob/master/nodejs/timeformat-1.png)
![timeformat-2](https://github.com/ErlichChen/learning-notes/blob/master/nodejs/timeformat-2.png)
![timeformat-3](https://github.com/ErlichChen/learning-notes/blob/master/nodejs/timeformat-3.png)

## Moment Timezone

[Moment Timezone](http://momentjs.com/timezone/docs/)

```js
var day = moment("2019-02-18T12:00:00Z");
day.tz('America/Los_Angeles').format('ha z');
```

## Luxon

[Luxon](https://moment.github.io/luxon/)