function Box(name, age){
    this.name = name
    this.age = age
    this.run = function(){
        return `${this.name} is ${this.age} years`
    }
    this.setName = function(name){
        this.name = name
    }
}

const log = console.log

const b1 = new Box("yale","300")
log(b1.run())
b1.setName('node')
log(b1.run())

const o = new Object()
Box.call(o, 'yale918','3000')

log(o.run())
log( o instanceof Box)


function Box1(){
    
    Box1.prototype = {
        constructor:Box1,
        name:"name",
        age:"age",
        run: function(){
            return `${this.name} is ${this.age} years`
        },
        run2: function(arg){
            return `${arg} is ${this.age} years`
        },
    };

    // Box1.prototype.name = "name"
    // Box1.prototype.age = "age"
    // Box1.prototype.run = function(){
    //     return `${this.name} is ${this.age} years`
    // }
    // Box1.prototype.run2 = function(arg){
    //     return `${arg} is ${this.age} years`
    // }
}

const b11 = new Box1()
b11.name = "newName"
log(b11.run2(b11.name))
log(b11.run2(b11.__proto__.name))


// const b12 = new Box1()
// log(b12.run())