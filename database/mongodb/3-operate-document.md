# Operate document

## insert document

```bash
use testdb
show collections

# insert
db.testcol.insert({
	userid: 001
})
```

## remove document

```bash
# remove
db.testcol.remove({ userid: 001 })
```

## update document

```bash
# update
db.testcol.update({ userid: 001 }, { $set: {userid: 002 }})
```

## find document

```bash
# find
db.testcol.find().pretty()

# =
db.testcol.find({ userid: 001 }).pretty()

# <
db.testcol.find({ userid:{$lt:001} }).pretty()

# <=
db.testcol.find({ userid:{$lte:001} }).pretty()

# >
db.testcol.find({ userid:{$gt:001} }).pretty()

# <=
db.testcol.find({ userid:{$gte:001} }).pretty()

# !=
db.testcol.find({ userid:{$ne:001} }).pretty()

# and
db.testcol.find({ userid: 001, id: 002 }).pretty()

# or
db.testcol.find({ $or:[{ userid: 001 }, {id: 002 }] }).pretty()
```