
CONTAINER_NAME="ex_webc"

docker container stop $CONTAINER_NAME
docker container rm $CONTAINER_NAME

docker network rm yale-test