// library





function YPromise(executor){

    this.status = 'pending'
    this.value = null
    this.reason = null
    this.onFulfilledCallbacks = []
    this.onRejectedCallbacks = []

    this.resolve = value =>{
        if (this.status === 'pending') {
            this.status = 'fulfilled'
            this.value = value
            this.onFulfilledCallbacks.forEach(fn => fn())
        }
    }

    this.reject = reason =>{
        if (this.status === 'pending') {
            this.status = 'rejected'
            this.reason = reason
            this.onFulfilledCallbacks.forEach(fn => fn())
        }
    }
    
    try {
        executor(this.resolve,this.reject)
    } catch (err) {
        this.reject(err)
    }

    this.then = function(onFulfilled, onRejected) {
        return new YPromise((resolve, reject) => {
            
            if (this.status === 'fulfilled') {
                setTimeout(()=>{
                    const x = onFulfilled(this.value)
                    x instanceof YPromise ? x.then(resolve, reject) : resolve(x)
                })
            }
            if (this.status === 'rejected'){
                setTimeout(() => {
                    const x = onRejected(this.reason)
                    x instanceof YPromise ? x.then(resolve, reject) : resolve(x)
                  })
            }
            if (this.status === 'pending') {
                this.onFulfilledCallbacks.push(() => { // 将成功的回调函数放入成功数组
                  setTimeout(() => {
                    const x = onFulfilled(this.value)
                    x instanceof YPromise ? x.then(resolve, reject) : resolve(x)
                  })
                })
                this.onRejectedCallbacks.push(() => { // 将失败的回调函数放入失败数组
                  setTimeout(() => {
                    const x = onRejected(this.reason)
                    x instanceof YPromise ? x.then(resolve, reject) : resolve(x)
                  })
                })
              }
        })
    }

}

function p1() {
    return new YPromise((resolve, reject) => {
        setTimeout(resolve, 1000, 1)
    })
}

function p2() {
    return new YPromise((resolve, reject) => {
        setTimeout(resolve, 1000, 3)
    })
}

// p1().then(res => {
//     console.log(res) // 1
//     return p2()
// }).then(ret => {
//     console.log(ret) // 2
// })



function timer(){
    this.wait = function(delay){
        return new Promise((resolve,reject)=>{
            setTimeout(resolve,delay)
        })
    }
}

const t = new timer()


function fetch(input){
    this.then = (fn)=>{
        // console.log(input)
        return new fetch(fn(input))
    }
    this.wait = (delay)=>{
        // await t.wait(delay)
        return new fetch(input)
    }
    // this.wait = (delay)=>{
    //     return new YPromise((resolve)=>{
    //         setTimeout(resolve,delay)
    //         return new fetch(input)
    //     })
    // }
}


let f = new fetch(3)

f
.then(x=>x+1)
.then(x=>{
    console.log(x)
    return x
})
.then(x=>x+2)
.then(console.log)


// f = new fetch(3)

// f
// .then(console.log)
// .then(x=>x+1)
// .wait(1000)
// .then(console.log)
// .then(x=>x+2)
// // .wait(2000)
// .then(console.log)






