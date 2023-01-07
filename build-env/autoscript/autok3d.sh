#update apt
sudo apt update

# setup docker
sudo apt install docker.io -y

# setup k3d
curl -s https://raw.githubusercontent.com/k3d-io/k3d/main/install.sh | bash

# setup kubectl
sudo snap install kubectl --classic



kubectl version
k3d --version

