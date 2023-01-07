TABSTOP="set tabstop=2"
SHIFTWIDTH="set shiftwidth=2"
AUTOINDENT="set autoindent"
TARGET=$(pwd)/.vimrc

GIT_USER_NAME="nodev918"
GIT_USER_EMAIL="devnode77@gmail.com"


setup_vim(){
	rm $TARGET
	touch $TARGET
	echo $TABSTOP >> $TARGET
	echo $SHIFTWIDTH >> $TARGET
	echo $AUTOINDENT >> $TARGET
}

setup_bash_refresh(){
	echo "
# refresh ~/.bash_profile
if [ -f ~/.bash_profile ]; then
	. ~/.bash_profile
fi
	" >> ~/.bash_rc
}
setup_bash_refresh

echo "過程會初始化.vimrc, 確定的話輸入 y 按 enter"
read user_determine

if [ $user_determine == "y" ]
then
	setup_vim
	echo "初始化完成, 開啟vim檢查有無正確設定"
else
	echo "好ㄅ,保留原始.vimrc"
fi

sudo apt install make -y

git config --global user.name $GIT_USER_NAME
git config --global user.email $GIT_USER_EMAIL



