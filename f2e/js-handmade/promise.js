// const chain = {
//     then: function(value){
//         return chain
//     }
// }


// chain.then(()=>{console.log("hi")}).then(()=>{console.log("hello")})


function timer(){
    this.wait = function(delay){
        return new Promise((resolve,reject)=>{
            setTimeout(resolve,delay)
        })
    }
}
const log = console.log
const t = new timer()

// (async()=>{
//     log("1")
//     await t.wait(2000)
//     log("2")
// })()

(async()=>{
    console.log("hee")
})();
//  (async ()=>{
//     log("1")
//     await t.wait(2000)
//     log("2")
// })()




function fetch(input){
    console.log("init fetch")
    return {
        then: function(fn){
            console.log("then")
            return fetch(fn(input))
        },
        the: function(fn){
            console.log("the")
            return fetch(fn(input))
        },
        wait: function(fn){
            console.log(`in wait`)
            return fetch(fn(input))
        }
        
    }
}



// fetch(1)
//     .wait(x=>x)
//     .wait(x=>x)
//     .then(console.log)

    // .then(x=>{
    //     console.log(x)
    //     return x+1
    // })
    // .the(x=>x)
    // .then(x=>{
    //     console.log(x)
    //     return x+2
    // })
    // .wait(x=>x)
    // .then(x=>{
    //     console.log(x)
    //     return x+3
    // })


    // .wait(x=>x)
    // .then(console.log)

