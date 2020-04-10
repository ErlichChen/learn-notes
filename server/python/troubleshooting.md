# Troubleshooting

## Could not import the lzma module when you import pandas

#### Error message

```bash
/usr/local/python3/lib/python3.7/site-packages/pandas/compat/__init__.py:85: UserWarning: Could not import the lzma module. Your installed Python is incomplete. Attempting to use lzma compression will result in a RuntimeError.
  warnings.warn(msg)
```

1. install lzma module

```bash
pip install backports.lzma
```

2. edit lzma.py

```python
# old code
from _lzma import *
from _lzma import _encode_filter_properties, _decode_filter_properties

# new code
try:
    from _lzma import *
    from _lzma import _encode_filter_properties, _decode_filter_properties
except ImportError:
    from backports.lzma import *
    from backports.lzma import _encode_filter_properties, _decode_filter_properties
```