# Build Linux Kernel

## Docker

### Get docker image

```shell
# clearlinux
docker pull clearlinux
# ubuntu
docker pull ubuntu
```

### Create docker container and link the container

```shell
docker create -t clearlinux
docker start -a -i image-id
```

### Copy files to docker

```shell
docker cp /opt/test/ mycontainer:/opt/testnew/file.txt
```