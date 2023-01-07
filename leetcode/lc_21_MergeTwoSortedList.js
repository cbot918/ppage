
const log = console.log

class ListNode{
    constructor(val=0,next=null){
        this.val = val
        this.next = next
    }
}

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

function show_list(head){
    let current = head

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

function solution(list1, list2){
    let current = new ListNode()
    let head = new ListNode()
    head = current
    while(list1 && list2){
        if (list1.val < list2.val){
            current.next = list1
            current = list1
            list1 = list1.next
        } else {
            current.next = list2
            current = list2
            list2 = list2.next
        }
    }

    if ( list1 || list2 ){
        current.next = list1? list1:list2
    }
    return head.next
    
}


let l1 = new List([1,2,3,4])

let l2 = new List([2,3,4,5,6,7])

let solved_head = solution(l1.get_head(),l2.get_head())
log(solved_head)
show_list(solved_head)