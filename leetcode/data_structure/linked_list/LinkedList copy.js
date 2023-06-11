function Node(){
  this.data = data
  this.next= null
}

function LinkedList() {
  this.head = null
  this.tail = null
  this.length = 0

  this.append = (data)=>{
    const newNode = new Node(data)
    if (this.isEmpty()){
      this.head = newNode
      this.tail = newNode
    } else {
      this.tail.next = newNode
      this.tail = newNode
    }
    this.length += 1
  }

  this.isEmpty = () => {
    return this.length === 0
  }

  this.insert = (index, data) => {
    if (index >= this.length) {
      this.append(data)
      return
    } 
    
    const newNode = new Node(data)
    if (index <= 0){
      newNode.next = this.head
      this.head = newNode
    } else {
      const prevNode = this.getNode(index - 1)
      const currNode = prevNode.next
      prevNode.next = newNode
      newNode.next = currNode
    }
    this.lenth += 1
  }

  

}

