

##git
alias gcbot='git config --global user.name "cbot918" && git config --global user.email "cbot918@gmail.com"'
alias gnode='git config --global user.name "nodev918" && git config --global user.email "nodev918@gmail.com"'


push_nodev918(){
    cd ..
    tar -cvf ppage.tar ppage
    docker cp ppage.tar git:/app
    cd ppage
}


## network

listp(){
	netstat -nao | findstr :$1
}

killp(){
	taskkill /PID $1 /F
}






##docker 
# read
dlsi(){
    docker images | grep $1  
}

dlsca(){
    docker ps -a | grep $1
}

dlsc(){
    docker ps | grep $1
}

# remove 
drmc(){
    docker container stop $1
    docker container rm $1
}

drmi(){
    docker image rm $1
}

#run
drun(){
    docker run -it -d --name $2 $1 
}

#exec
dshsh(){
    docker start $1 && docker exec -it $1 sh
}

dshba(){
    docker start $1 && docker exec -it $1 bash
}

#once instance
pio(){
	docker run -it --rm  alpine sh
}

ubuo(){
	docker run -it --rm ubuntu bash
}

#quick instance
pi(){
	docker run -it --name alpine alpine sh
}

ubu(){
	docker run -it --name ubuntu ubuntu bash
}
