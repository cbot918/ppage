linux cmd技巧分享1
「可以執行靠任一個文字檔, 把變數讀到作業系統環境裡」
環境: linux/mac原生可用, 我是在windows裡面用cmder模擬linux環境)
-

ex1: 
建一個 a.txt
```
echo "hi1"
```
執行這個檔案 
$ . a.txt (bash a.txt / source a.txt 應該同效果)
// hi1

ex2: 
建一個 b.txt
```
alias testb="echo hi2"
```
執行這個檔案  $ . b.txt
然後直接  $ testb
// hi2

ex3:
建一個 c.txt 
```
test_func(){ echo hi3 } 
```
$ . c.txt
$ test_func
// hi3

結論：ex3的技巧很好用, 可以把幾個連續要做的動作包成function, 然後在小黑窗裡面執行
例如操作docker container的時候把container先停掉再刪除
drmc(){
    docker container stop $1
    docker container rm $1
}
$ drmc container_name
// container be removed