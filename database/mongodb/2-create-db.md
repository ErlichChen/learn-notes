# Create and operate database

## create database

```bash
# create
use testdb

# current db
db
show dbs
```

## detele database

```bash
show dbs

# delete
use testdb
db.dropDatebase()
```

## create collection

```bash
use testdb

# create
db.createCollection("testcol")
# or
db.createCollection("testcol", {
	capped: true,
	autoIndexId: true,
	size: 6142800,
	max: 10000
})
```

## delete collection

```bash
use testdb
show collections

# delete
db.testcol.drop()
```