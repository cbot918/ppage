# golang
BINARY="go1.19.5.linux-amd64.tar.gz"
install-go(){
    curl -OL "https://go.dev/dl/$BINARY"
    sudo rm -rf /usr/local/go
    sudo tar -C /usr/local -xzf go1.19.5.linux-amd64.tar.gz
    rm $BINARY
    echo 'export PATH=$PATH:/usr/local/go/bin' >> $HOME/.bashrc
    source $HOME/.bashrc
    echo "[*] auto check go-version"
    go version
}
install-go

# nodejs 
NODE_VERSION="16.19.0"
install-node(){
    # pre-install: nvm
    curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.34.0/install.sh | bash
    echo "[*] auto check nvm-version"
    source ~/.bashrc
    nvm --version
    ## $ nvm current
    ## $ nvm ls-remote
    ## $ nvm install 

    # install: node
    nvm install $NODE_VERSION
    nvm use $NODE_VERSION
    echo "[*] auto check node-version"
    node --version
}
install-node



# # python3
# install-py(){
#     # python3 is default installed
#     sudo apt install python3-pip
# }
# install-py



# install-ruby(){
#     echo skip-install-ruby
# }
# install-ruby
