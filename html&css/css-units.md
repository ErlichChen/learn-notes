# CSS Units

## rem

```html
<body>
  <div class="test">Test</div>
</body>
```

```css
body {
  font-size: 14px;
}
div {
  font-size: 1.2em; // calculated at 14px * 1.2, or 16.8px
}
```

```html
<body>
  <div>
    Test <!-- 14 * 1.2 = 16.8px -->
    <div>
        Test <!-- 16.8 * 1.2 = 20.16px -->
        <div>
        Test <!-- 20.16 * 1.2 = 24.192px -->
        </div>
      </div>
  </div>
</body>
```

```css
html {
  font-size: 14px;
}
div {
  font-size: 1.2rem;
}
``