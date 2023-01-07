TABSTOP="set tabstop=2"
SHIFTWIDTH="set shiftwidth=2"
AUTOINDENT="set autoindent"
TARGET=$HOME/.vimrc


setup_vim(){
	rm $TARGET
	touch $TARGET
	echo $TABSTOP >> $TARGET
	echo $SHIFTWIDTH >> $TARGET
	echo $AUTOINDENT >> $TARGET
}
setup_vim