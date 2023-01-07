function timer(){
    this.wait = function(delay){
        return new Promise((resolve,reject)=>{
            setTimeout(resolve,delay)
        })
    }
}

(async()=>{
    const t = new timer()
    console.log("hee")
})();