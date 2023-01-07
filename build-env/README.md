prerequesties:
不排斥用ubuntu跟virtualbox


0.1 clientVM 看 ip
$ ip address

0.5 hostVM 看 ip
$ ifconfig / ipconfig

1. clientVM 裝 go: 
$ sudo snap install go

2. 起gin server: 參考官網code

3. 開防火牆 
$ vim /etc/services

4. Vbox Manager 開 port forward

5. hostVM inti ssh-key:
$ ssh-keygen -t rsa -b 4096

6. host send ssh-key to client 
$ scp _source.pub _id@_ip:_destination/.ssh/_name.pub

7. ssh進主機
$ ssh _id@_ip 

8. http request看結果
curl _ip:_port 
