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