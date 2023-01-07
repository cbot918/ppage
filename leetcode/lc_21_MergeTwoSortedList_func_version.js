const log = console.log

class ListNode{
    constructor(val=0,next=null){
        this.val = val
        this.next = next
    }
}


// function ListNode(val=0, next=null){
//     this.val = val
//     this.next = next
// }

// l = new ListNode(1,new ListNode(2))
// log(l.next.val)

class List {
    constructor(arr){
        this.head = null
        this.current = null
        let first = true

        arr.forEach(el => {
            if(first){
                this.current = new ListNode(el)
                this.head = this.current
                first = false
            } else {
                let newone = new ListNode(el)
                // log(newone.val)
                this.current.next = newone
                this.current = this.current.next
            }
        });
    }

    get_head(){
        return this.head
    }

    show_list(){
        let current = this.head

        while(true){
            
            if(current.next === null){
                log(current.val)
                break
            }else{
                log(current.val)
                current = current.next
            }
        }
    }
}



// function List(arr){
//     this.head = null
//     this.current = null
//     let first = true

//     arr.forEach(el => {
//         if(first){
//             this.current = new ListNode(el)
//             this.head = this.current
//             first = false
//         } else {
//             let newone = new ListNode(el)
//             // log(newone.val)
//             this.current.next = newone
//             this.current = this.current.next
//         }
//     });

//     function get_head(){
//         return this.head
//     }
//     function show_list(){
//         let current = this.head
//         log(current)
//         while(true){
//             log(current.val)
//             if(typeof(current.next) === 'undefined'){
//                 break
//             }else{
//                 current = current.next
//             }
//         }
//     }
//     return {
//         get_head,
//         show_list
//     }
    
// }


l1 = new List([1,2,3,4])
l1.show_list()