


(async ()=>{
    function timer(){
        this.wait = function(delay){
            return new Promise((resolve,reject)=>{
                setTimeout(resolve,delay)
            })
        }
    }
    const t = new timer()


    const log = console.log
    log("hi")
    await t.wait(3000)
    log("hello")
})();