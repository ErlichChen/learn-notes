# Installation

## Install using brew on Mac

```bash
brew install mongodb

# support TLS/SSL
brew install mongodb --with-openssl

# install latest version
brew install mongodb --devel
```

## Run and connection

```bash
# default db folder
mkdir -p /data/db

# run db server
mongod --dbpath=/data/db

# connect db server
mongo
```